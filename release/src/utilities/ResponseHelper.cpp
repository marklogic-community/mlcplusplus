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

#include <cpprest/http_client.h>
#include "ResponseHelper.hpp"
#include "CppRestJsonHelper.hpp"
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
  const std::string message = jsonObject.at("errorResponse").at("messageCode").as_string();
  return message;
}

std::string ResponseHelper::getErrorDetailAsString(const Response& resp) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value& doc = CppRestJsonHelper::fromResponse(resp);
  const web::json::object& jsonObject = doc.as_object();
  const std::string message = jsonObject.at("errorResponse").at("message").as_string();
  return message;
}

std::list<std::string> ResponseHelper::getSuggestions(const Response& resp) {
  // TODO add checks for JSON or XML - don't just assume JSON
  const web::json::value& doc = CppRestJsonHelper::fromResponse(resp);
  const web::json::object& jsonObject = doc.as_object();
  const web::json::array& suggestionArray = jsonObject.at("suggestions").as_array();
  std::list<std::string> suggestions;
  for (auto iter: suggestionArray) {
    suggestions.push_back(iter.as_string());
  }
  return suggestions;
}

} // end namespace utilities

} // end namespace mlclient
