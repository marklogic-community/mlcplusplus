/*
 * SearchResultSet.cpp
 *
 *  Created on: 25 May 2016
 *      Author: adamfowler
 */

#include "mlclient/SearchResultSet.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/Response.hpp"

#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"

#include "mlclient/ext/easylogging++.h"

// We can use the following, because cpprest is an internal API dependency
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include <cpprest/http_client.h>

namespace mlclient {



class SearchResultSet::Impl {
public:
  Impl(SearchResultSet* set,IConnection* conn,SearchDescription* desc) : mConn(conn), mInitialDescription(desc),
    mResults(), mFetchException(nullptr), mIter(new SearchResultSetIterator(set)), mCachedEnd(nullptr), start(0),
    pageLength(0), total(0),totalTime(""), queryResolutionTime(""),snippetResolutionTime(""),m_maxResults(0) {
    TIMED_FUNC(SearchResultSet_Impl_constructor);
  }


  bool handleFetchResults(Response * resp) {
    TIMED_FUNC(SearchResultSet_Impl_handleFetchResults);
    //LOG(DEBUG) << "SearchResultSet::handleFetchResults Response value: " << resp->getContent();

    // TODO handle request errors

    const web::json::value& value = utilities::CppRestJsonHelper::fromResponse(*resp);


    // extract top level summary information for the result set
    snippetFormat = utility::conversions::to_utf8string(value.at(U("snippet-format")).as_string());
    total = value.at(U("total")).as_integer();
    pageLength = value.at(U("page-length")).as_integer();
    start = value.at(U("start")).as_integer();

    // extract metrics, if they exist
    // TODO better way to check for response metrics being present, without exception throwing
    try {
      const web::json::value& metrics = value.at(U("metrics"));
      queryResolutionTime = utility::conversions::to_utf8string(metrics.at(U("query-resolution-time")).as_string());
      snippetResolutionTime = utility::conversions::to_utf8string(metrics.at(U("snippet-resolution-time")).as_string());
      totalTime = utility::conversions::to_utf8string(metrics.at(U("total-time")).as_string());
    } catch (std::exception& me) {
      // no metrics element - possible due to search options
      // silently fail - not a huge issue
      // TODO flag this to support hasMetrics()
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   COULD NOT PARSE RESPONSE METRICS!!!" << me.what();
    }


    // take the response, and parse it
    // NOT NEEDED const web::json::value& resv = value.at(U("results"));
    const web::json::array& res = value.at(U("results")).as_array();
    //LOG(DEBUG) << "SearchResultSet::handleFetchResults We have a results JSON array";
    SearchResult::DETAIL detail(SearchResult::DETAIL::NONE);
    //std::string ct;
    mlclient::utilities::CppRestJsonDocumentContent* ct;
    std::string mimeType;
    std::string format;
    static std::string raw = "raw"; // always the same
    bool isRaw = (0 == (raw.compare(snippetFormat)));

    for (auto iter = res.begin(); iter != res.end(); ++iter) {
      //auto& rowdata = *iter;
      const web::json::object& row = iter->as_object();
      //LOG(DEBUG) << "Row: " << iter->as_string();
      //const web::json::object& row = iter.as_object();
      detail = SearchResult::DETAIL::NONE;
      mimeType = "";
      format = SearchResult::JSON;
      //ct = "";

      // if snippet-format = raw
      if (isRaw) {
      try {
        web::json::value ctVal = row.at(U("content")); // at is rvalue, moved to lvalue by json's move contructor
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got content";


        //ct = ctVal.as_string(); // not a string!!! It's a JSON object if the response and document are both JSON
        // assume just JSON for now to get it working TODO don't assume this in future!!!
        //std::ostringstream rss;
        //rss << ctVal;
        //ctVal.serialize(rss);
        //ct = rss.str();
        // TODO XML, text, binary content support too
        ct = new mlclient::utilities::CppRestJsonDocumentContent();
        ct->setMimeType(IDocumentContent::MIME_JSON);
        ct->setContent(ctVal); // passes reference to function in cpprestjsondocumentcontent


        mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got mimetype";
        format = utility::conversions::to_utf8string(row.at(U("format")).as_string());
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got format";
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row content: " << ct;

      } catch (std::exception& e) {
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row does not have content... trying snippet..." << e.what();
        // element doesn't exist - no result content, or has a snippet
      } // end content catch

      } else {

        try {
          web::json::value ctVal = row.at(U("matches"));
          // TODO XML, text, binary content support too
          ct = new mlclient::utilities::CppRestJsonDocumentContent();
          ct->setMimeType(IDocumentContent::MIME_JSON);
          ct->setContent(ctVal);
          //ct = utility::conversions::to_utf8string(ctVal.as_string());
          mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
          format = utility::conversions::to_utf8string(row.at(U("format")).as_string());
          //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got snippet content" << ct;
          detail = SearchResult::DETAIL::SNIPPETS;
        } catch (std::exception& ex) {
          // no snippet element, must be some sort of content...
          detail = SearchResult::DETAIL::CONTENT;
          LOG(DEBUG) << "SearchResultSet::handleFetchResults   Result is content less" << ex.what();
        }
      }

      // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
      SearchResult sr(row.at(U("index")).as_integer(), utility::conversions::to_utf8string(row.at(U("uri")).as_string()),
        utility::conversions::to_utf8string(row.at(U("path")).as_string()),row.at(U("score")).as_integer(),
        row.at(U("confidence")).as_double(),row.at(U("fitness")).as_double(),detail,ct,mimeType,format );
      mResults.push_back(std::move(sr));
    } // end loop

    return true;
  };

  bool fetchNext() {
    TIMED_FUNC(SearchResultSet_Impl_fetchNext);
    // private method - called internally only
    // use start and pageLength to determine next start value
    // if total <= start + pageLenth - 1, then we are already at the end! So don't fetch.
    //LOG(DEBUG) << "In fetchNext()";
    if (total > start + pageLength - 1) {
      //LOG(DEBUG) << "Fetching next page...";
      // fetch more results
      // TODO support point in time query, so totals are always consistent
      //SearchDescription newDescription(mInitialDescription);
      //LOG(DEBUG) << "  Got new description";
      // override settings in search options for start value
      mInitialDescription->setStart(start + pageLength);
      if (0 != m_maxResults && m_maxResults < start + pageLength - 1) { // E.g. Page 2, 11 results => 11 < 11 + 10 - 1 => 11 < 20 (i.e. max result requires limiting this page's length)
        mInitialDescription->setPageLength(m_maxResults - start + 1); // E.g. Page 2, 11 results => 11 - 11 + 1 = 1 results max on page 2
      }
      //LOG(DEBUG) << "  set start on new description";

      Response* resp = mConn->search(*mInitialDescription);
      //LOG(DEBUG) << "  Completed search... calling handleFetchResults()";
      return handleFetchResults(resp);
    } else {
      //LOG(DEBUG) << "No more pages to fetch";
      ;
    }
    return true;
  };

  IConnection* mConn;
  SearchDescription* mInitialDescription;
  std::vector<SearchResult> mResults;
  std::exception* mFetchException;

  SearchResultSetIterator* mIter;
  SearchResultSetIterator* mCachedEnd;

  long start;
  long total;
  long pageLength;
  std::string snippetFormat;
  std::string queryResolutionTime; // W3C Duration String
  std::string snippetResolutionTime; // W3C Duration String
  std::string totalTime; // W3C Duration String

  long m_maxResults; // max number of results to return across all requests (total)
};






SearchResultSet::SearchResultSet(IConnection* conn,SearchDescription* desc) {
  TIMED_FUNC(SearchResultSet_SearchResultSet);
  mImpl = new SearchResultSet::Impl(this,conn,desc);
}

bool SearchResultSet::fetch() {
  TIMED_FUNC(SearchResultSet_fetch);
  try {
    // perform the request to search in the connection
    if (0 != mImpl -> m_maxResults && mImpl->m_maxResults < mImpl ->start + mImpl->pageLength - 1) { // E.g. Page 2, 11 results => 11 < 11 + 10 - 1 => 11 < 20 (i.e. max result requires limiting this page's length)
      mImpl->mInitialDescription->setPageLength(mImpl->m_maxResults - mImpl->start + 1); // E.g. Page 2, 11 results => 11 - 11 + 1 = 1 results max on page 2
    }
    Response* resp = mImpl->mConn->search(*mImpl->mInitialDescription);
    bool success = mImpl->handleFetchResults(resp);

    delete(resp); // TODO ensure this does not invalidate any of our variables in search result set or searchresult instances

    return success;
  } catch (std::exception& ref) {
    mImpl->mFetchException = &ref;
    return false;
  }
}

std::exception* SearchResultSet::getFetchException() {
  return mImpl->mFetchException;
}

void SearchResultSet::setMaxResults(long maxResults) {
  mImpl->m_maxResults = maxResults;
}

SearchResultSetIterator* SearchResultSet::begin() const {
  TIMED_FUNC(SearchResultSet_begin);
  //return mImpl->mResults.begin();
  SearchResultSetIterator* beginIter = mImpl->mIter->begin();
  mImpl->mCachedEnd = mImpl->mIter->end(); // cache end iterator to prevent poorly written code from instantiating many iterator instances
  return beginIter;
}

SearchResultSetIterator* SearchResultSet::end() const {
  TIMED_FUNC(SearchResultSet_end);
  return mImpl->mCachedEnd;
}


const long SearchResultSet::getStart() {
  return mImpl->start;
}
const long SearchResultSet::getTotal() {
  if (0 != mImpl->m_maxResults) { // may be returning less than is in the database
    if (mImpl->m_maxResults < mImpl->total) {
      return mImpl->m_maxResults;
    }
  }
  return mImpl->total;
}
const long SearchResultSet::getPageLength() {
  return mImpl->pageLength;
}
const std::string& SearchResultSet::getSnippetFormat() const {
  return mImpl->snippetFormat;
}
const std::string& SearchResultSet::getQueryResolutionTime() const {
  return mImpl->queryResolutionTime;
}
const std::string& SearchResultSet::getSnippetResolutionTime() const {
  return mImpl->snippetResolutionTime;
}
const std::string& SearchResultSet::getTotalTime() const {
  return mImpl->totalTime;
}


const long SearchResultSet::getPageCount() const {
  // TODO validate type safety of the below
  return (long)std::ceil(((double)mImpl->total) / ((double)mImpl->pageLength));
}









SearchResultSetIterator::SearchResultSetIterator() : mResultSet(nullptr), position(1) {
  ;
}

SearchResultSetIterator::SearchResultSetIterator(SearchResultSet* set) : mResultSet(set), position(1) {
  ;
}

SearchResultSetIterator::SearchResultSetIterator(SearchResultSet* set, long pos) : mResultSet(set), position(pos) {
  ;
}

SearchResultSetIterator* SearchResultSetIterator::begin() {
  TIMED_FUNC(SearchResultSetIterator_begin);
  int st = 1; // assume at least one result
  if (mResultSet->getTotal() == 0) {
    st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  }
  SearchResultSetIterator* iter = new SearchResultSetIterator(mResultSet, st);
  return iter;
}

SearchResultSetIterator* SearchResultSetIterator::end() {
  TIMED_FUNC(SearchResultSetIterator_end);
  int st = mResultSet->getTotal();
  if (mResultSet->getTotal() == 0) {
    st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  } else {
    st++; // past end of vector, if at least one result
  }
  SearchResultSetIterator* iter = new SearchResultSetIterator(mResultSet, st); // ensure end is PAST last result
  return iter;
}

bool SearchResultSetIterator::operator==(const SearchResultSetIterator& other) {
  return position == other.position;
}

bool SearchResultSetIterator::operator!=(const SearchResultSetIterator& other) {
  return position != other.position;
}

void SearchResultSetIterator::operator++() {
  TIMED_FUNC(SearchResultSetIterator_operatorPlusPlus);
  // see if we're at the very end. If so, do nothing
  // check to see if we're at the end of the current result set, and need to fetch more
  // otherwise, just increment position
  //LOG(DEBUG) << " incrementing, currently: " << position;

  if (position >= mResultSet->getTotal()) {
    // at end. No nothing
    //LOG(DEBUG) << "in final position of result set (total), not incrementing";
  }
  else {
    if ((mResultSet->getStart() + mResultSet->getPageLength() - 1) == position) {
      //LOG(DEBUG) << " fetching next set of results";
      // fetch next page
      bool ok = mResultSet->mImpl->fetchNext();
      // TODO do something if ok == false
    }
    //LOG(DEBUG) << "incrementing by 1";
  }
  ++position;
  //LOG(DEBUG) << " position now: " << position;
}

const SearchResult SearchResultSetIterator::operator*() {
  TIMED_FUNC(SearchResultSetIterator_operatorDereference);
  return mResultSet->mImpl->mResults.at(position - 1); // MarkLogic Server is 1 based, not 0
}


SearchResultSetIterator SearchResultSetIterator::operator=(const SearchResultSetIterator& other) {
  mResultSet = other.mResultSet;
  position = other.position;
  return other;
}

const SearchResult& SearchResultSetIterator::first() const {
  return mResultSet->mImpl->mResults.at(position - 1); // MarkLogic Server is 1 based, not 0
}





} // end namespace mlclient
