/*
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
 * CppRestJsonHelper.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include <cpprest/http_client.h>
#include <mlclient/utilities/CppRestJsonHelper.hpp>
#include <mlclient/utilities/CppRestJsonDocumentContent.hpp>
#include <mlclient/DocumentContent.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <mlclient/SearchResult.hpp>

#include <iostream>

#include <mlclient/logging.hpp>

namespace mlclient {

namespace utilities {

// DocumentContent conversion
ITextDocumentContent* CppRestJsonHelper::toDocument(web::json::value& json) {
  LOG(DEBUG) << "CppRestJsonHelper::toDocument(web::json::value&)";
  TIMED_FUNC(CppRestJsonHelper_toDocument);
  CppRestJsonDocumentContent* tdc = new CppRestJsonDocumentContent;
  tdc->setContent(json); // move constructor used
  tdc->setMimeType("application/json");
  return tdc; // TODO ensure this doesn't get nixed
}

ITextDocumentContent* CppRestJsonHelper::toDocument(const Response& resp) {
  LOG(DEBUG) << "CppRestJsonHelper::toDocument(Response&)";
  web::json::value val = CppRestJsonHelper::fromResponse(resp);
  return CppRestJsonHelper::toDocument(val);
}

const web::json::value CppRestJsonHelper::fromDocument(const CppRestJsonDocumentContent& dc) {
  TIMED_FUNC(CppRestJsonHelper_fromDocument_CppRestJsonDocumentContent);
  return dc.getJson();
}

const web::json::value CppRestJsonHelper::fromDocument(const IDocumentContent& dc) {
  TIMED_FUNC(CppRestJsonHelper_fromDocument_IDocumentContent);
  std::ostringstream os;
  os << dc.getStream()->get();
  return web::json::value::parse(utility::conversions::to_string_t(os.str()));
}

// Response conversion
web::json::value CppRestJsonHelper::fromResponse(const Response& resp) {
  LOG(DEBUG) << "CppRestJsonHelper::fromResponse(Response&)";
  TIMED_FUNC(CppRestJsonHelper_fromResponse);
  if (resp.getResponseType() == ResponseType::JSON) {
    return web::json::value::parse(utility::conversions::to_string_t(resp.getContent()));
  } else {
    LOG(DEBUG) << "CppRestJsonHelper::fromResponse(Response&): Invalid format, throwing exception";
    throw InvalidFormatException();
  }
}

web::json::value CppRestJsonHelper::fromString(const std::string& jsonString) {
  LOG(DEBUG) << "CppRestJsonHelper::fromString(std::string&)";
  TIMED_FUNC(CppRestJsonHelper_fromString);
  return web::json::value::parse(utility::conversions::to_string_t(jsonString));
}

std::vector<Permission> CppRestJsonHelper::permissionsFromResponse(const Response& resp) {
  web::json::value root = fromResponse(resp);
  web::json::value perms = root.at(utility::conversions::to_string_t("permissions"));
  web::json::array arr = perms.as_array();
  std::vector<Permission> permissions;
  for (auto iter = arr.begin();iter != arr.end();++iter) {
    web::json::value p = *iter;
    web::json::value caps = p.at(utility::conversions::to_string_t("capabilities"));
    web::json::array capArray = caps.as_array();
    for (auto capIter = capArray.begin();capIter != capArray.end();++capIter) {
      web::json::value cap = *capIter;
      permissions.push_back(
          std::move(
              Permission(utility::conversions::to_utf8string(p.at(utility::conversions::to_string_t("role-name")).as_string()),
                         toCapability(utility::conversions::to_utf8string(cap.as_string())))
          )
      );
    }
  }
  return permissions;
}

/*
web::json::value CppRestJsonHelper::fromSearchResult(const SearchResult& result) {
  TIMED_FUNC(CppRestJsonHelper_fromSearchResult);
  if (result.getFormat() == SearchResult::JSON) {
    return ((CppRestJsonDocumentContent)*(result.getDetailContent())).getJson();
  } else {
    throw InvalidFormatException();
  }
}
*/

} // end utilities namespace

} // end mlclient namespace
