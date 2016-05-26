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

SearchResultSet::SearchResultSet(IConnection* conn,SearchDescription& desc) : mConn(conn), mInitialDescription(desc), mResults(), mFetchException(nullptr) {
  ;
}

bool SearchResultSet::fetch() {
  try {
    // perform the request to search in the connection
    Response* resp = mConn->search(mInitialDescription);

    // TODO handle request errors

    // TODO extract top level summary information for the result set

    // take the response, and parse it
    const web::json::value& value = utilities::CppRestJsonHelper::fromResponse(*resp);
    const web::json::value& resv = value.at("results");
    const web::json::array& res = value.at("results").as_array();
    LOG(DEBUG) << "We have a results JSON array";
    SearchResult::DETAIL detail = SearchResult::DETAIL::NONE;
    std::string ct;
    std::string mimeType;
    std::string format;
    web::json::value ctVal;
    for (auto iter = resv.as_array().begin(); iter != resv.as_array().end(); ++iter)
    {
        auto& rowdata = *iter;
        const web::json::object& row = rowdata.as_object();
      //LOG(DEBUG) << "Row: " << iter->as_string();
      //const web::json::object& row = iter.as_object();
      detail = SearchResult::DETAIL::NONE;
      mimeType = "";
      format = SearchResult::JSON;
      ct = "";
      try {
        ctVal = row.at("content");
        ct = ctVal.as_string();
        mimeType = row.at("mimetype").as_string();
        format = row.at("format").as_string();
        LOG(DEBUG) << "  Row content: " << ct;

        // TODO parse as IDocumentContent, if relevant, for each result's content - or have helper class available to do it

        // otherwise, is either transform or content - so just set CONTENT
      } catch (std::exception& e) {
        LOG(DEBUG) << "  Row does not have content... trying snippet...";
        // element doesn't exist - no result content, or has a snippet

        // Determine what next element is...
        // if snippet array, then result content is snippet
        try {
          ctVal = row.at("matches");
          ct = ctVal.as_string();
          mimeType = row.at("mimetype").as_string();
          format = row.at("format").as_string();
          LOG(DEBUG) << "  Got snippet content" << ct;
          detail = SearchResult::DETAIL::SNIPPETS;
        } catch (std::exception& ex) {
          // no snippet element, must be some sort of content...
          detail = SearchResult::DETAIL::CONTENT;
          LOG(DEBUG) << "  Result is content less";
        }
      }

      // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
      mResults.push_back(SearchResult(row.at("index").as_integer(),row.at("uri").as_string(),row.at("path").as_string(),row.at("score").as_integer(),
          row.at("confidence").as_double(),row.at("fitness").as_double(),detail,ct,mimeType,format ));
    }

    delete(resp); // TODO ensure this does not invalidate any of our variables in search result set or searchresult instances

    return true;
  } catch (std::exception& ref) {
    mFetchException = &ref;
    return false;
  }
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

} // end namespace mlclient
