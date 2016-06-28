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

#include "mlclient/ext/easylogging++.h"

// We can use the following, because cpprest is an internal API dependency
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include <cpprest/http_client.h>

namespace mlclient {



class SearchResultSet::Impl {
public:
  Impl(SearchResultSet* set,IConnection* conn,SearchDescription& desc) : mConn(conn), mInitialDescription(desc),
    mResults(), mFetchException(nullptr), mIter(new SearchResultSetIterator(set)), start(0), pageLength(0), total(0),totalTime(""),
    queryResolutionTime(""),snippetResolutionTime("") {
    ;
  }


  bool handleFetchResults(Response * resp) {
    LOG(DEBUG) << "SearchResultSet::handleFetchResults Response value: " << resp->getContent();

    // TODO handle request errors

    const web::json::value& value = utilities::CppRestJsonHelper::fromResponse(*resp);


    // extract top level summary information for the result set
    snippetFormat = utility::conversions::to_utf8string(value.at(U("snippet-format")).as_string());
    total = value.at(U("total")).as_integer();
    pageLength = value.at(U("page-length")).as_integer();
    start = value.at(U("start")).as_integer();

    // extract metrics, if they exist
    try {
      const web::json::value& metrics = value.at(U("metrics"));
      queryResolutionTime = utility::conversions::to_utf8string(metrics.at(U("query-resolution-time")).as_string());
      snippetResolutionTime = utility::conversions::to_utf8string(metrics.at(U("snippet-resolution-time")).as_string());
      totalTime = utility::conversions::to_utf8string(metrics.at(U("total-time")).as_string());
    } catch (std::exception me) {
      // no metrics element - possible due to search options
      // silently fail - not a huge issue
      // TODO flag this to support hasMetrics()
    }


    // take the response, and parse it
    const web::json::value& resv = value.at(U("results"));
    const web::json::array& res = value.at(U("results")).as_array();
    LOG(DEBUG) << "SearchResultSet::handleFetchResults We have a results JSON array";
    SearchResult::DETAIL detail = SearchResult::DETAIL::NONE;
    std::string ct;
    std::string mimeType;
    std::string format;
    web::json::value ctVal;
    for (auto iter = res.begin(); iter != res.end(); ++iter) {
      auto& rowdata = *iter;
      const web::json::object& row = rowdata.as_object();
      //LOG(DEBUG) << "Row: " << iter->as_string();
      //const web::json::object& row = iter.as_object();
      detail = SearchResult::DETAIL::NONE;
      mimeType = "";
      format = SearchResult::JSON;
      ct = "";
      // TODO performance - replace these try-catches with checks of the top level snippet-format value
      try {
        ctVal = row.at(U("content"));
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got content";


        //ct = ctVal.as_string(); // not a string!!! It's a JSON object if the response and document are both JSON
        // assume just JSON for now to get it working TODO don't assume this in future!!!
        std::ostringstream rss;
        //rss << ctVal;
        ctVal.serialize(rss);
        ct = rss.str();


        mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got mimetype";
        format = utility::conversions::to_utf8string(row.at(U("format")).as_string());
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got format";
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row content: " << ct;

      } catch (std::exception& e) {
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row does not have content... trying snippet...";
        // element doesn't exist - no result content, or has a snippet

        // Determine what next element is...
        // if snippet array, then result content is snippet
        try {
          ctVal = row.at(U("matches"));
          ct = utility::conversions::to_utf8string(ctVal.as_string());
          mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
          format = utility::conversions::to_utf8string(row.at(U("format")).as_string());
          LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got snippet content" << ct;
          detail = SearchResult::DETAIL::SNIPPETS;
        } catch (std::exception& ex) {
          // no snippet element, must be some sort of content...
          detail = SearchResult::DETAIL::CONTENT;
          LOG(DEBUG) << "SearchResultSet::handleFetchResults   Result is content less";
        }
      } // end content catch

      // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
      SearchResult sr(row.at(U("index")).as_integer(), utility::conversions::to_utf8string(row.at(U("uri")).as_string()),
        utility::conversions::to_utf8string(row.at(U("path")).as_string()),row.at(U("score")).as_integer(),
        row.at(U("confidence")).as_double(),row.at(U("fitness")).as_double(),detail,ct,mimeType,format );
      mResults.push_back(std::move(sr));
    } // end loop

    return true;
  };

  bool fetchNext() {
    // private method - called internally only
    // use start and pageLength to determine next start value
    // if total <= start + pageLenth - 1, then we are already at the end! So don't fetch.
    if (total > start + pageLength - 1) {
      // fetch more results
      // TODO support point in time query, so totals are always consistent
      SearchDescription newDescription(mInitialDescription);
      // override settings in search options for start value
      newDescription.setStart(start + pageLength);

      Response* resp = mConn->search(newDescription);
      return handleFetchResults(resp);
    }
    return true;
  };

  IConnection* mConn;
  SearchDescription& mInitialDescription;
  std::vector<SearchResult> mResults;
  std::exception* mFetchException;

  SearchResultSetIterator* mIter;

  long start;
  long total;
  long pageLength;
  std::string snippetFormat;
  std::string queryResolutionTime; // W3C Duration String
  std::string snippetResolutionTime; // W3C Duration String
  std::string totalTime; // W3C Duration String
};






SearchResultSet::SearchResultSet(IConnection* conn,SearchDescription& desc) {
  mImpl = new SearchResultSet::Impl(this,conn,desc);
}

bool SearchResultSet::fetch() {
  try {
    // perform the request to search in the connection
    Response* resp = mImpl->mConn->search(mImpl->mInitialDescription);
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

SearchResultSet::const_iterator SearchResultSet::begin() const {
  //return mImpl->mResults.begin();
  return mImpl->mIter->begin();
}

SearchResultSet::const_iterator SearchResultSet::end() const {
  return mImpl->mIter->end();
}


const long SearchResultSet::getStart() {
  return mImpl->start;
}
const long SearchResultSet::getTotal() {
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

SearchResultSetIterator& SearchResultSetIterator::begin() {
  SearchResultSetIterator iter(mResultSet, 1);
  return std::move(iter);
}

SearchResultSetIterator& SearchResultSetIterator::end() {
  SearchResultSetIterator iter(mResultSet, mResultSet->getTotal());
  return std::move(iter);
}

bool SearchResultSetIterator::operator==(const SearchResultSetIterator& other) {
  return position == other.position;
}

void SearchResultSetIterator::operator++() {
  // see if we're at the very end. If so, do nothing
  // check to see if we're at the end of the current result set, and need to fetch more
  // otherwise, just increment position

  if (position >= mResultSet->getTotal()) {
    // at end. No nothing
  }
  else {
    if ((mResultSet->getStart() + mResultSet->getPageLength() - 1) == position) {
      // fetch next page
      bool ok = mResultSet->mImpl->fetchNext();
      // TODO do something if ok == false
    }
    ++position;
  }
}

const SearchResult SearchResultSetIterator::operator*() {
  return mResultSet->mImpl->mResults.at(position);
}


SearchResultSetIterator SearchResultSetIterator::operator=(const SearchResultSetIterator& other) {
  mResultSet = other.mResultSet;
  position = other.position;
  return other;
}







} // end namespace mlclient
