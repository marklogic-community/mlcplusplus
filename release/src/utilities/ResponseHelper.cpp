/**
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \file ResponseHelper.cpp
 * \since 8.0.2
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Provides convenience functions to parse MarkLogic response objects
 * \date 2016-06-08
 */

#include <mlclient/utilities/ResponseHelper.hpp>
#include <mlclient/utilities/CppRestJsonHelper.hpp>

#include <mlclient/logging.hpp>
#include <mlclient/ValuesResult.hpp>

#include <cpprest/http_client.h>

#include <iostream>
#include <string>
#include <sstream>
#include <list>

namespace mlclient {

namespace utilities {

bool ResponseHelper::isInError(const Response& resp) {
  if (ResponseCode::BAD_REQUEST == resp.getResponseCode() || ResponseCode::FORBIDDEN == resp.getResponseCode() ||
      ResponseCode::UNAUTHORIZED == resp.getResponseCode() || ResponseCode::INTERNAL_SERVER_ERROR == resp.getResponseCode()) {
    return true;
  }
  // TODO check for logical error conditions, if any exist in addition to the above?
  return false;
}

std::string ResponseHelper::getErrorMessage(const Response& resp) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value& doc = CppRestJsonHelper::fromResponse(resp);
  const web::json::object& jsonObject = doc.as_object();
  const std::string message = utility::conversions::to_utf8string(jsonObject.at(U("errorResponse")).at(U("messageCode")).as_string());
  return message;
}

std::string ResponseHelper::getErrorDetailAsString(const Response& resp) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value& doc(CppRestJsonHelper::fromResponse(resp));
  const web::json::object& jsonObject(doc.as_object());
  const std::string message = utility::conversions::to_utf8string(jsonObject.at(U("errorResponse")).at(U("message")).as_string());
  return message;
}

std::vector<std::string> ResponseHelper::getSuggestions(const Response& resp) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value doc(CppRestJsonHelper::fromResponse(resp));
  const web::json::object jsonObject(doc.as_object());
  const web::json::array suggestionArray(jsonObject.at(U("suggestions")).as_array());
  std::vector<std::string> suggestions;
  for (auto& iter: suggestionArray) {
    suggestions.push_back(utility::conversions::to_utf8string(iter.as_string()));
  }
  return suggestions;
}

void ResponseHelper::getAggregateResults(const Response& resp,ValuesResult& vr) {
  const web::json::value doc(CppRestJsonHelper::fromResponse(resp));
  const web::json::object jsonObject(doc.as_object());
  const web::json::object valr(jsonObject.at(U("values-response")).as_object());
  const web::json::array aggArray(valr.at(U("aggregate-result")).as_array());

  for (auto& iter: aggArray) {
    const web::json::object agg = iter.as_object();
    std::string aggName = utility::conversions::to_utf8string(agg.at(U("name")).as_string());
    /*
    const auto& valIter = agg.find(U("_value"));
    if (valIter != agg.end()) {
      std::string doubleString = utility::conversions::to_utf8string(agg.at(U("_value")).as_string());
      double val;
      std::istringstream i(doubleString);
      double x;
      if (!(i >> x))
        val = -1; // format failure - TODO decide if we should throw an InvalidFormatException here
      val = x;
      ValuesResultAggregate vra;
      vra.type = ValuesResultAggregateType::SIMPLE_DOUBLE;
      vra.name = aggName;
      vra.value = val;
      vr.addAggregate(std::move(vra));
    } // end valIter if
    */
  } // end aggArray iter
}

void ResponseHelper::getComplexAggregateResults(const Response& resp,ValuesResult& vr) {
  const web::json::value doc(CppRestJsonHelper::fromResponse(resp));
  const web::json::object jsonObject(doc.as_object());
  const web::json::object valr(jsonObject.at(U("values-response")).as_object());
  const web::json::array aggArray(valr.at(U("aggregate-result")).as_array());

  for (auto& iter: aggArray) {
    const web::json::object agg = iter.as_object();
    std::string aggName = utility::conversions::to_utf8string(agg.at(U("name")).as_string());

    const auto& mapIter = agg.find(U("map"));
    if (mapIter != agg.end()) {
      // got a map
      // Check if it is a single, or an array, of maps
      web::json::value mapVal = agg.at(U("map"));

      ValuesResultAggregate vra;
      vra.type = ValuesResultAggregateType::COMPLEX_MAP_ARRAY;
      vra.name = aggName;
      vra.value = 0;
      vra.complexValue = std::map<std::string,std::string>();

      // loop through each map
      // extract each value and create our own map<string,string>
      // add value to results list

      if (mapVal.is_array()) {
        // multiple
        web::json::array mapArray = mapVal.as_array();
        for (auto& mapIter: mapArray) {
          const web::json::object mapObj = iter.as_object();
          /*
          const auto& entryIter = mapObj.find(U("entry"));
          for (;entryIter != mapObj.end();++(entryIter)) {
            //const web::json::object entryObj = entryIter->;
          }
          */
        }
      } else {
        if (mapVal.is_object()) {

        }
      }
      vr.addAggregate(std::move(vra));
    } else {
      const auto& valIter = agg.find(U("_value"));
      if (valIter != agg.end()) {
        // got a single value
        std::string doubleString = utility::conversions::to_utf8string(agg.at(U("_value")).as_string());
        double val;
        std::istringstream i(doubleString);
        double x;
        if (!(i >> x))
          val = -1; // format failure - TODO decide if we should throw an InvalidFormatException here
        val = x;
        ValuesResultAggregate vra;
        vra.type = ValuesResultAggregateType::SIMPLE_DOUBLE;
        vra.name = aggName;
        vra.value = val;
        vr.addAggregate(std::move(vra));
      } // end valIter if
    } // end mapIter if
  } // end aggArray iter
}

double ResponseHelper::getAggregateResult(const Response& resp,const std::string& aggName) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value doc(CppRestJsonHelper::fromResponse(resp));
  const web::json::object jsonObject(doc.as_object());
  const web::json::object vr(jsonObject.at(U("values-response")).as_object());
  const web::json::array aggArray(vr.at(U("aggregate-result")).as_array());

  for (auto& iter: aggArray) {
    const web::json::object agg = iter.as_object();
    if (0 == strcmp(aggName.c_str(), utility::conversions::to_utf8string(agg.at(U("name")).as_string()).c_str())) {
      std::string doubleString = utility::conversions::to_utf8string(agg.at(U("_value")).as_string()); // TODO possible to have non double response from range index aggregates???
      LOG(DEBUG) << "ResponseHelper::getAggregateResult: Double string: " << doubleString;
      // Encoded as a string in the response, NOT as a number - must convert in C++
      std::istringstream i(doubleString);
         double x;
         if (!(i >> x))
           return -1; // format failure - TODO decide if we should throw an InvalidFormatException here
         return x;
    }
  }
  return -1; // TODO return negative infinity, or some other such error result
}

} // end namespace utilities

} // end namespace mlclient
