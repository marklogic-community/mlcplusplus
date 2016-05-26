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

// We can use the following, because cpprest is an internal API dependency
#include "utilities/CppRestJsonHelper.hpp"
#include <cpprest/http_client.h>

namespace mlclient {

SearchResultSet::SearchResultSet(const IConnection& conn,const SearchDescription& desc) : mConn(conn), mInitialDescription(desc), mResults(), mFetchException(nullptr) {
  ;
}

bool SearchResultSet::fetch() {
  try {
    // perform the request to search in the connection
    Response* resp = mConn.search(mInitialDescription);

    // TODO handle request errors

    // TODO extract top level summary information for the result set

    // take the response, and parse it
    web::json::value& value = utilities::CppRestJsonHelper::fromResponse(*resp);
    web::json::value& sr = value.at("response").as_object();
    web::json::array& res = sr.at("result").as_array();
    web::json::object& row;
    SearchResult::DETAIL& detail = SearchResult::DETAIL::NONE;
    std::string& ct;
    web::json::value& ctVal;
    for (auto& iter: res) {
      row = iter.as_object();
      detail = SearchResult::DETAIL::NONE;
      ct = "";
      try {
        ctVal = row.at("result");
        ct = ctVal.as_string();

        // Determine what next element is...
        // if snippet array, then result content is snippet
        try {
          ctVal = row.at("snippet");
          detail = SearchResult::DETAIL::SNIPPETS;
        } catch (std::exception& ex) {
          // no snippet element, must be some sort of content...
          detail = SearchResult::DETAIL::CONTENT;
        }
        // otherwise, is either transform or content - so just set CONTENT
      } catch (std::exception& e) {
        // element doesn't exist - no result content
      }

      // TODO handle empty result or no search metrics in the below - at the moment they could throw!!!
      mResults.push_back(SearchResult(row.at("index").as_integer(),row.at("uri").as_string(),row.at("path").as_string(),row.at("score").as_integer(),
          row.at("confidence").as_double(),row.at("fitness").as_double(),ct,row.at("result").as_string() ));
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
