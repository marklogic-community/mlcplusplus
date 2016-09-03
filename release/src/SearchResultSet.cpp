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
#include "mlclient/NoCredentialsException.hpp"

#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
#include "mlclient/utilities/PugiXmlHelper.hpp"

#include "mlclient/logging.hpp"

// We can use the following, because cpprest is an internal API dependency
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include <cpprest/json.h>
#include <string>

namespace mlclient {



class SearchResultSet::Impl {
public:
  Impl(SearchResultSet* set,IConnection* conn,SearchDescription* desc) : mConn(conn), mInitialDescription(desc),
    mResults(), mFetchException(nullptr), mIter(new SearchResultSetIterator(set)), mCachedEnd(nullptr), start(0),
    pageLength(0), total(0),totalTime(""), queryResolutionTime(""),snippetResolutionTime(""),m_maxResults(0), lastFetched(-1),
    fetchTask(nullptr) /*, fetchMtx(), resultsMtx()*/ {

    //TIMED_FUNC(SearchResultSet_Impl_constructor);
    LOG(DEBUG) << "In SearchResultSet::Impl ctor";
    LOG(DEBUG) << "mInitialDescription: " << mInitialDescription->getPayload()->getContent();
  }

  void incrementIter(web::json::array::const_iterator iter) {
    //TIMED_FUNC(SearchResultSet_Impl_incrementIter);
    ++iter;
  }

  bool iterCompare(web::json::array::const_iterator& iter,const web::json::array::const_iterator& jsonArrayIterEnd) {
    //TIMED_FUNC(SearchResultSet_Impl_iterCompare);
    return (iter != jsonArrayIterEnd);
  }

  bool handleFetchResults(Response * resp) {
    //TIMED_FUNC(SearchResultSet_Impl_handleFetchResults);
    //LOG(DEBUG) << "SearchResultSet::handleFetchResults Response value: " << resp->getContent();

    // TODO handle request errors

    const web::json::value value(utilities::CppRestJsonHelper::fromResponse(*resp));

    //std::unique_lock<std::mutex> lck (resultsMtx,std::defer_lock);

    {
      //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processMetrics()");


    // extract top level summary information for the result set
    snippetFormat = utility::conversions::to_utf8string(value.at(U("snippet-format")).as_string());
    total = value.at(U("total")).as_integer();
    if (0 == m_maxResults) {
      //lck.lock();
      mResults.reserve(total);
      //lck.unlock();
    } else {
      //lck.lock();
      mResults.reserve(m_maxResults);
      //lck.unlock();
    }
    pageLength = value.at(U("page-length")).as_integer();
    start = value.at(U("start")).as_integer();

    // extract metrics, if they exist
    // TODO better way to check for response metrics being present, without exception throwing
    try {
      const web::json::value& metrics = value.at(U("metrics"));
      queryResolutionTime = utility::conversions::to_utf8string(metrics.at(U("query-resolution-time")).as_string());
      snippetResolutionTime = utility::conversions::to_utf8string(metrics.at(U("snippet-resolution-time")).as_string());
      totalTime = utility::conversions::to_utf8string(metrics.at(U("total-time")).as_string());
      //CLOG(INFO, "performance") << "Executed [marklogic::rest::search::queryResolutionTime()] in [" << queryResolutionTime.substr(2,queryResolutionTime.length() - 3) << " ms]";
      //CLOG(INFO, "performance") << "Executed [marklogic::rest::search::snippetResolutionTime()] in [" << snippetResolutionTime.substr(2,snippetResolutionTime.length() - 3) << " ms]";
      //CLOG(INFO, "performance") << "Executed [marklogic::rest::search::totalTime()] in [" << totalTime.substr(2,totalTime.length() - 3) << " ms]";
    } catch (std::exception& me) {
      // no metrics element - possible due to search options
      // silently fail - not a huge issue
      // TODO flag this to support hasMetrics()
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   COULD NOT PARSE RESPONSE METRICS!!!" << me.what();
    }

    } // end timed scope for metrics


    // TODO preallocate total results (or limit, if set and lower) in mImpl->mResults vector - speeds up append operations

    //SearchResult::DETAIL detail(SearchResult::DETAIL::NONE);
    static std::string raw("raw"); // always the same
    //std::string ct;

    {
      //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processResultSet()");


    // take the response, and parse it
    // NOT NEEDED const web::json::value& resv = value.at(U("results"));
    const web::json::array res(value.at(U("results")).as_array());
    //{
    //  TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::asArray()");

    //  const web::json::array resCount = value.at(U("results")).as_array(); // TODO remove once counted in PERF logger
    //}
    //LOG(DEBUG) << "SearchResultSet::handleFetchResults We have a results JSON array";
    bool isRaw = (0 == (raw.compare(snippetFormat)));

    web::json::array::const_iterator iter(res.begin());
    const web::json::array::const_iterator jsonArrayIterEnd(res.end()); // see if a single call saves us time... nope

    mlclient::IDocumentContent* ct;
    SearchResult::Detail detail;
    std::string mimeType;
    Format format;
    web::json::object row = web::json::value::object().as_object();

    {
      //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processResultSetLoopOnly()");

    for (; iter != jsonArrayIterEnd;++iter) {
      {
      //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processRow()");
      //auto& rowdata = *iter;
      row = iter->as_object();

      {
        //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processRowObject()");


      //LOG(DEBUG) << "Row: " << iter->as_string();
      //const web::json::object& row = iter.as_object();
      detail = SearchResult::Detail::NONE;
      mimeType = "";
      format = Format::JSON;
      web::json::value ctVal;
      //ct = "";

      // if snippet-format = raw
      if (isRaw) {
      try {
        //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processContent()");
        ctVal = row.at(U("content")); // at is rvalue, moved to lvalue by json's move contructor
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got content";

        mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got mimetype";
        std::string formatStr = utility::conversions::to_utf8string(row.at(U("format")).as_string());
        if ("json" == formatStr) {
          format = Format::JSON;
        } else if ("xml" == formatStr) {
          format = Format::XML;
        } else if ("binary" == formatStr) {
          format = Format::BINARY;
        } else if ("text" == formatStr) {
          format = Format::TEXT;
        } else {
          format = Format::NONE;
        }
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got format";
        //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row content: " << ct;

        ct = divineDocumentContent(formatStr,mimeType,ctVal);

      } catch (std::exception& e) {
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row does not have content... trying snippet..." << e.what();
        //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processContentEXCEPTION()");
        // element doesn't exist - no result content, or has a snippet
      } // end content catch

      } else {

        try {
          //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processMatches()");
          ctVal = row.at(U("matches"));

          mimeType = utility::conversions::to_utf8string(row.at(U("mimetype")).as_string());
          std::string formatStr = utility::conversions::to_utf8string(row.at(U("format")).as_string());
          //LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got snippet content" << ct;
          if ("json" == formatStr) {
            format = Format::JSON;
          } else if ("xml" == formatStr) {
            format = Format::XML;
          } else if ("binary" == formatStr) {
            format = Format::BINARY;
          } else if ("text" == formatStr) {
            format = Format::TEXT;
          } else {
            format = Format::NONE;
          }

          /*
          ct = new mlclient::utilities::CppRestJsonDocumentContent();
          ct->setMimeType(IDocumentContent::MIME_JSON);
          ct->setContent(ctVal);
          */
          ct = divineDocumentContent(formatStr,mimeType,ctVal);
          //ct = utility::conversions::to_utf8string(ctVal.as_string());


          detail = SearchResult::Detail::SNIPPETS;
        } catch (std::exception& ex) {
          // no snippet element, must be some sort of content...
          detail = SearchResult::Detail::CONTENT;
          LOG(DEBUG) << "SearchResultSet::handleFetchResults   Result is content less" << ex.what();
          //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::processMatchesEXCEPTION()");
        }
      }

      // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
      {
        //TIMED_SCOPE(SearchResultSet_Impl_handleFetchResult, "mlclient::SearchResultSet::Impl::handleFetchResult::appendToVector()");
      //SearchResult sr(row.at(U("index")).as_integer(), utility::conversions::to_utf8string(row.at(U("uri")).as_string()),
        //utility::conversions::to_utf8string(row.at(U("path")).as_string()),row.at(U("score")).as_integer(),
        //row.at(U("confidence")).as_double(),row.at(U("fitness")).as_double(),detail,ct,mimeType,format );

        //lck.lock();
      mResults.push_back(new SearchResult(row.at(U("index")).as_integer(), utility::conversions::to_utf8string(row.at(U("uri")).as_string()),
          utility::conversions::to_utf8string(row.at(U("path")).as_string()),row.at(U("score")).as_integer(),
          row.at(U("confidence")).as_double(),row.at(U("fitness")).as_double(),detail,ct,mimeType,format ));
      lastFetched = mResults.size() - 1;

      //lck.unlock();
      }
      }
      }
    } // end loop

    } // end timed scope loop only

    } // end process result set scope

    return true;
  };

  ITextDocumentContent* divineDocumentContent(const std::string& format,const std::string& mimeType,web::json::value& ctVal) {
    //ct = ctVal.as_string(); // not a string!!! It's a JSON object if the response and document are both JSON
    // assume just JSON for now to get it working TODO don't assume this in future!!!
    //std::ostringstream rss;
    //rss << ctVal;
    //ctVal.serialize(rss);
    //ct = rss.str();
    // TODO XML, text, binary content support too
    ITextDocumentContent* ct;
    if (0 == strcmp("xml",format.c_str())) {
      // XML
      ct = mlclient::utilities::PugiXmlHelper::toDocument(utility::conversions::to_utf8string(ctVal.as_string()));

    } else if (0 == strcmp("json",format.c_str())) {
      // JSON
      ct = new mlclient::utilities::CppRestJsonDocumentContent();
      ((mlclient::utilities::CppRestJsonDocumentContent*)ct)->setContent(ctVal); // passes reference to function in cpprestjsondocumentcontent

    } else if (0 == strcmp("text",format.c_str())) {
      // TEXT
      ct = new GenericTextDocumentContent;
      ((GenericTextDocumentContent*)ct)->setContent(utility::conversions::to_utf8string(ctVal.as_string()));
    } else if (0 == strcmp("binary",format.c_str())) {
      // BINARY
      LOG(DEBUG) << "WARNING: Binary document content not yet supported!!!";
      ct = new GenericTextDocumentContent;
      ((GenericTextDocumentContent*)ct)->setContent("Binary support has not yet been added to SearchResultSet.cpp");
    }
    ct->setMimeType(mimeType); // don't override the one the server tells us - may be an XML format (E.g. GML), but not application/xml.

    return ct;
  }

  bool fetchInitial() {
    LOG(DEBUG) << "In fetchInitial";
    LOG(DEBUG) << "mInitialDescription: " << mInitialDescription->getPayload()->getContent();
    // make this async
    Impl& mImpl = (*this);

    //std::unique_lock<std::mutex> lck (fetchMtx,std::defer_lock);
    //lck.lock();

    fetchTask = new pplx::task<void>([&mImpl] () {
      LOG(DEBUG) << "Began initial fetch task...";


    try {
      // perform the request to search in the connection
      if (0 != mImpl.m_maxResults && mImpl.m_maxResults < mImpl.start + mImpl.pageLength - 1) { // E.g. Page 2, 11 results => 11 < 11 + 10 - 1 => 11 < 20 (i.e. max result requires limiting this page's length)
        mImpl.mInitialDescription->setPageLength(mImpl.m_maxResults - mImpl.start + 1); // E.g. Page 2, 11 results => 11 - 11 + 1 = 1 results max on page 2
      }
      Response* resp = mImpl.mConn->search(*mImpl.mInitialDescription);
      bool success = mImpl.handleFetchResults(resp);
      LOG(DEBUG) << "Initial fetch task a success? : " << success;

      delete(resp); // TODO ensure this does not invalidate any of our variables in search result set or searchresult instances

      //return success;
    } catch (std::exception& ref) {
      mImpl.mFetchException = &ref;
      LOG(DEBUG) << "Exception in initial fetch task";
      //return false;
    }
    LOG(DEBUG) << "End initial fetch task";

    });
    // BLOCK for first result set to ensure all variables for the result set (E.g. total) are set up before next function calls
    // No way to avoid this blocking really.
    fetchTask->wait();

    //lck.unlock();

    return true;
  };

  // Returning false means no fetchTask is running or created, return true means we can safely call wait()
  bool fetchNext() {
    //TIMED_FUNC(SearchResultSet_Impl_fetchNext);
    LOG(DEBUG) << "In fetchNext";

    // TODO check if we need to wait for the last thread
    if (nullptr == fetchTask) {
      LOG(DEBUG) << "  Returning: fetchTask is null";
      return false;
    }
    if (!fetchTask->is_done()) {
      LOG(DEBUG) << "  Returning: fetchTask is still in progress";
      return true; // rely on caller in iterator checking and calling wait() on mImpl;
    }
    LOG(DEBUG) << "Previous fetch complete";

    // lastfetched is 0 based - E.g. 0-499
    // m_maxResults is 1 based - E.g. 1-500
    if (lastFetched >= m_maxResults - 1) {
      // No need to fetch any more
      LOG(DEBUG) << "lastFetched has reached maxResults - not fetching";
      return false;
    }

    LOG(DEBUG) << "Creating new fetch task...";

    //std::unique_lock<std::mutex> lck (fetchMtx,std::defer_lock);
    //lck.lock();

    // TODO make this async
    Impl& mImpl(*this);

    fetchTask = new pplx::task<void>([&mImpl] () {
      LOG(DEBUG) << "Started another fetchTask";

    // private method - called internally only
    // use start and pageLength to determine next start value
    // if total <= start + pageLenth - 1, then we are already at the end! So don't fetch.
    //LOG(DEBUG) << "In fetchNext()";
    if (mImpl.total > mImpl.start + mImpl.pageLength - 1) {
      LOG(DEBUG) << "Fetching next page...";
      // fetch more results
      // TODO support point in time query, so totals are always consistent
      SearchDescription newDescription = *(mImpl.mInitialDescription); // force copy
      LOG(DEBUG) << "  Got new description";
      // override settings in search options for start value
      newDescription.setStart(mImpl.start + mImpl.pageLength);
      if (0 != mImpl.m_maxResults && mImpl.m_maxResults < mImpl.start + mImpl.pageLength - 1) { // E.g. Page 2, 11 results => 11 < 11 + 10 - 1 => 11 < 20 (i.e. max result requires limiting this page's length)
        newDescription.setPageLength(mImpl.m_maxResults - mImpl.start + 1); // E.g. Page 2, 11 results => 11 - 11 + 1 = 1 results max on page 2
      }
      LOG(DEBUG) << "  set start on new description";
      //LOG(DEBUG) << "Validating search payload: " << newDescription.getPayload()->getContent();
      LOG(DEBUG) << " mConn is nullptr?: " << (nullptr == mImpl.mConn);
      LOG(DEBUG) << " mConn address: " << mImpl.mConn;

      Response* resp = mImpl.mConn->search(newDescription);
      //LOG(DEBUG) << "  Completed search... calling handleFetchResults()";
      mImpl.handleFetchResults(resp);

      // TODO delete resp???
    } else {
      LOG(DEBUG) << "No more pages to fetch";
      ;
    }
    //return true;
    LOG(DEBUG) << "Ended another fetchTask";


    }); // end task block
    //lck.unlock();

    return true;
  };

  SearchResult* getResult(long position) {
    //std::unique_lock<std::mutex> lck (resultsMtx,std::defer_lock);
    //lck.lock();
    SearchResult* res = mResults.at(position);
    //lck.unlock();
    return res;
  }

  const long getLastFetched() const {
    return lastFetched;
  };

  void wait() {
    LOG(DEBUG) << "In wait()";
    //std::unique_lock<std::mutex> lck (fetchMtx,std::defer_lock);
    //lck.lock();
    if (fetchTask->is_done()) {
      LOG(DEBUG) << "  Returning: Task is complete";
      return;
    }
    LOG(DEBUG) << "  Waiting for completion";
    fetchTask->wait();
    //lck.unlock();
  };

  IConnection* mConn;
  SearchDescription* mInitialDescription;
  std::vector<SearchResult*> mResults;
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

  // count - E.g. 500
  long m_maxResults; // max number of results to return across all requests (total)

  // 0 based - i.e. for 500 results, at start it would be -1, at end it would 499
  long lastFetched;
  pplx::task<void>* fetchTask;
  //std::mutex fetchMtx;
  //std::mutex resultsMtx;
};






SearchResultSet::SearchResultSet(IConnection* conn,SearchDescription* desc) : mImpl(new Impl(this,conn,desc)) {
  //TIMED_FUNC(SearchResultSet_SearchResultSet);
  LOG(DEBUG) << "SearchResultSet ctor";
  LOG(DEBUG) << "mInitialDescription: " << desc->getPayload()->getContent();
  //mImpl = new SearchResultSet::Impl(this,conn,desc);
}

bool SearchResultSet::fetch() {
  //TIMED_FUNC(SearchResultSet_fetch);
  LOG(DEBUG) << "SearchResultSet::fetch";
  return mImpl->fetchInitial();
}

std::exception* SearchResultSet::getFetchException() {
  //TIMED_FUNC(SearchResultSet_getFetchException);
  return mImpl->mFetchException;
}

void SearchResultSet::setMaxResults(long maxResults) {
  //TIMED_FUNC(SearchResultSet_setMaxResults);
  mImpl->m_maxResults = maxResults;
  // TODO preallocate this size in mImpl->mResults vector
}

SearchResultSetIterator* SearchResultSet::begin() const {
  //TIMED_FUNC(SearchResultSet_begin);
  //return mImpl->mResults.begin();
  SearchResultSetIterator* beginIter = mImpl->mIter->begin();
  mImpl->mCachedEnd = mImpl->mIter->end(); // cache end iterator to prevent poorly written code from instantiating many iterator instances
  return beginIter;
}

SearchResultSetIterator* SearchResultSet::end() const {
  //TIMED_FUNC(SearchResultSet_end);
  return mImpl->mCachedEnd;
}


const long SearchResultSet::getStart() {
  //TIMED_FUNC(SearchResultSet_getStart);
  return mImpl->start;
}
const long SearchResultSet::getTotal() {
  //TIMED_FUNC(SearchResultSet_getTotal);
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
  //TIMED_FUNC(SearchResultSet_getPageCount);
  // TODO validate type safety of the below
  return (long)std::ceil(((double)mImpl->total) / ((double)mImpl->pageLength));
}









SearchResultSetIterator::SearchResultSetIterator() : mResultSet(nullptr), position(1) {
  //TIMED_FUNC(SearchResultSetIterator_defaultConstructor);
}

SearchResultSetIterator::SearchResultSetIterator(SearchResultSet* set) : mResultSet(set), position(1) {
  //TIMED_FUNC(SearchResultSetIterator_resultSetConstructor);
}

SearchResultSetIterator::SearchResultSetIterator(SearchResultSet* set, long pos) : mResultSet(set), position(pos) {
  //TIMED_FUNC(SearchResultSetIterator_resultSetPositionConstructor);
}

SearchResultSetIterator* SearchResultSetIterator::begin() {
  //TIMED_FUNC(SearchResultSetIterator_begin);
  long st = 1; // assume at least one result

  if (mResultSet->getTotal() == 0) {
    st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  }
  SearchResultSetIterator* iter = new SearchResultSetIterator(mResultSet, st);
  return iter;
}

SearchResultSetIterator* SearchResultSetIterator::end() {
  //TIMED_FUNC(SearchResultSetIterator_end);
  long st = mResultSet->getTotal();
  if (0 == st) {
    //st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  } else {
    st++; // past end of vector, if at least one result
  }
  SearchResultSetIterator* iter = new SearchResultSetIterator(mResultSet, st); // ensure end is PAST last result
  return iter;
}

bool SearchResultSetIterator::operator==(const SearchResultSetIterator& other) {
  //TIMED_FUNC(SearchResultSetIterator_operatorEquals);
  LOG(DEBUG) << "operator== position: " << position << ", other.position: " << other.position;
  return position == other.position;
}

bool SearchResultSetIterator::operator!=(const SearchResultSetIterator& other) {
  //TIMED_FUNC(SearchResultSetIterator_operatorInequals);
  LOG(DEBUG) << "operator!= position: " << position << ", other.position: " << other.position;
  return position != other.position;
}

void SearchResultSetIterator::operator++() {
  //TIMED_FUNC(SearchResultSetIterator_operatorPlusPlus);
  // see if we're at the very end. If so, do nothing
  // check to see if we're at the end of the current result set, and need to fetch more
  // otherwise, just increment position
  LOG(DEBUG) << " incrementing, currently: " << position;

  long lastFetched = mResultSet->mImpl->getLastFetched();
  if (-1 == lastFetched) {
    // wait for initial fetch
    LOG(DEBUG) << "No initial fetch happened (IMPOSSIBLE), waiting...";
    mResultSet->mImpl->wait();
    LOG(DEBUG) << "Awake!";
  }

  if (position >= mResultSet->getTotal()) {
    // at end. No nothing
    LOG(DEBUG) << "in final position of result set (total)";
  } else {
    // check if we've just started the next result set
    if (position > lastFetched) { // this is not lastFetched + 1 as we haven't incremented position yet!!! That gets done at the END of the function
      // need next result set NOW
      LOG(DEBUG) << "At end of result set - calling fetchNext...";
      if (mResultSet->mImpl->fetchNext()) {
        mResultSet->mImpl->wait();
      }
    }
    if (position > lastFetched + 1 - mResultSet->mImpl->pageLength) {
      // within 1 page of the end - go fetch more results
      LOG(DEBUG) << "On last page of result set - calling fetchNext (lastFetched currently: " << lastFetched << ", position currently: " << position << ", maxResults currently: " << mResultSet->mImpl->m_maxResults << ")...";
      mResultSet->mImpl->fetchNext();
    }

    /*
    // OLD fetch code - fetched and blocked at end of result set
    if ((mResultSet->getStart() + mResultSet->getPageLength() - 1) == position) {
      //LOG(DEBUG) << " fetching next set of results";
      // fetch next page
      bool ok = mResultSet->mImpl->fetchNext();
      // TODO do something if ok == false
    }
    //LOG(DEBUG) << "incrementing by 1";
    */
  }
  ++position;
  // sanity check position, and set to end if beyond it - ODBC layer in particular does this a lot.
  if (position > mResultSet->mImpl->total + 1) {
    position = mResultSet->mImpl->total + 1;
  }
  LOG(DEBUG) << " position now: " << position;
}

const SearchResult SearchResultSetIterator::operator*() {
  //TIMED_FUNC(SearchResultSetIterator_operatorDereference);
  //try {
    return *(mResultSet->mImpl->getResult(position - 1)); // MarkLogic Server is 1 based, not 0
  /*} catch (std::exception& e) {
    std::ostringstream os;
    os << "Exception trying to read index: " << (position - 1);
    std::cout << os.str() << std::endl;
    throw mlclient::NoCredentialsException(os.str().c_str());
  }*/
}


SearchResultSetIterator SearchResultSetIterator::operator=(const SearchResultSetIterator& other) {
  //TIMED_FUNC(SearchResultSetIterator_operatorAssignment);
  mResultSet = other.mResultSet;
  position = other.position;
  return other;
}

const SearchResult& SearchResultSetIterator::first() const {
  //TIMED_FUNC(SearchResultSetIterator_first);
  return *(mResultSet->mImpl->getResult(position - 1)); // MarkLogic Server is 1 based, not 0
}





} // end namespace mlclient
