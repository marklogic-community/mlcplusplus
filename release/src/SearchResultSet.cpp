/*
 * SearchResultSet.cpp
 *
 *  Created on: 25 May 2016
 *      Author: adamfowler
 */

#include "SearchResultSet.hpp"
#include "SearchResult.hpp"
#include "Connection.hpp"
#include "SearchDescription.hpp"
#include "Response.hpp"

#include "ext/easylogging++.h"

// We can use the following, because cpprest is an internal API dependency
#include "utilities/CppRestJsonHelper.hpp"
#include <cpprest/http_client.h>

namespace mlclient {

SearchResultSet::SearchResultSet(IConnection* conn,SearchDescription& desc) : mConn(conn), mInitialDescription(desc),
    mResults(), mFetchException(nullptr), start(0), pageLength(0), total(0),totalTime(""),queryResolutionTime(""),snippetResolutionTime("") {
  ;
}

bool SearchResultSet::fetch() {
  try {
    // perform the request to search in the connection
    Response* resp = mConn->search(mInitialDescription);
    bool success = handleFetchResults(resp);

    delete(resp); // TODO ensure this does not invalidate any of our variables in search result set or searchresult instances

    return success;
  } catch (std::exception& ref) {
    mFetchException = &ref;
    return false;
  }
}

bool SearchResultSet::handleFetchResults(Response * resp) {
  LOG(DEBUG) << "SearchResultSet::handleFetchResults Response value: " << resp->getContent();

  // TODO handle request errors

  const web::json::value& value = utilities::CppRestJsonHelper::fromResponse(*resp);


  // extract top level summary information for the result set
  snippetFormat = value.at("snippet-format").as_string();
  total = value.at("total").as_integer();
  pageLength = value.at("page-length").as_integer();
  start = value.at("start").as_integer();

  // extract metrics, if they exist
  try {
    const web::json::value& metrics = value.at("metrics");
    queryResolutionTime = metrics.at("query-resolution-time").as_string();
    snippetResolutionTime = metrics.at("snippet-resolution-time").as_string();
    totalTime = metrics.at("total-time").as_string();
  } catch (std::exception me) {
    // no metrics element - possible due to search options
    // silently fail - not a huge issue
    // TODO flag this to support hasMetrics()
  }


  // take the response, and parse it
  const web::json::value& resv = value.at("results");
  const web::json::array& res = value.at("results").as_array();
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
      ctVal = row.at("content");
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got content";


      //ct = ctVal.as_string(); // not a string!!! It's a JSON object if the response and document are both JSON
      // assume just JSON for now to get it working TODO don't assume this in future!!!
      std::ostringstream rss;
      rss << ctVal;
      ct = rss.str();


      mimeType = row.at("mimetype").as_string();
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got mimetype";
      format = row.at("format").as_string();
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got format";
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row content: " << ct;

    } catch (std::exception& e) {
      LOG(DEBUG) << "SearchResultSet::handleFetchResults   Row does not have content... trying snippet...";
      // element doesn't exist - no result content, or has a snippet

      // Determine what next element is...
      // if snippet array, then result content is snippet
      try {
        ctVal = row.at("matches");
        ct = ctVal.as_string();
        mimeType = row.at("mimetype").as_string();
        format = row.at("format").as_string();
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Got snippet content" << ct;
        detail = SearchResult::DETAIL::SNIPPETS;
      } catch (std::exception& ex) {
        // no snippet element, must be some sort of content...
        detail = SearchResult::DETAIL::CONTENT;
        LOG(DEBUG) << "SearchResultSet::handleFetchResults   Result is content less";
      }
    } // end content catch

    // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
    SearchResult sr(row.at("index").as_integer(),row.at("uri").as_string(),row.at("path").as_string(),row.at("score").as_integer(),
        row.at("confidence").as_double(),row.at("fitness").as_double(),detail,ct,mimeType,format );
    mResults.push_back(std::move(sr));
  } // end loop

  return true;
}

bool SearchResultSet::fetchNext() {
  // private method - called internally only
  // use start and pageLength to determine next start value
  // if total <= start + pageLenth - 1, then we are already at the end! So don't fetch.
  if (total > start + pageLength - 1) {
    // fetch more results
    // TODO support point in time query, so totals are always consistent
    SearchDescription newDescription(mInitialDescription);
    // override settings in search options for start value
    //newDescription.setStart(start + pageLength);

    Response* resp = mConn->search(newDescription);
    return handleFetchResults(resp);
  }
  return true;
}

std::exception* SearchResultSet::getFetchException() {
  return mFetchException;
}

SearchResultSet::const_iterator SearchResultSet::begin() const {
  return mResults.begin();
}

SearchResultSet::const_iterator SearchResultSet::end() const {
  return mResults.end();
}


const long SearchResultSet::getStart() {
  return start;
}
const long SearchResultSet::getTotal() {
  return total;
}
const long SearchResultSet::getPageLength() {
  return pageLength;
}
const std::string& SearchResultSet::getSnippetFormat() const {
  return snippetFormat;
}
const std::string& SearchResultSet::getQueryResolutionTime() const {
  return queryResolutionTime;
}
const std::string& SearchResultSet::getSnippetResolutionTime() const {
  return snippetResolutionTime;
}
const std::string& SearchResultSet::getTotalTime() const {
  return totalTime;
}


} // end namespace mlclient
