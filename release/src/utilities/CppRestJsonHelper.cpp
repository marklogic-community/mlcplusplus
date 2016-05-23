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
#include "CppRestJsonHelper.hpp"
#include "CppRestJsonDocumentContent.hpp"
#include "../DocumentContent.hpp"
#include "../Response.hpp"
#include "../InvalidFormatException.hpp"

#include <iostream>

#include "../ext/easylogging++.h"

namespace mlclient {

namespace utilities {

// DocumentContent conversion
ITextDocumentContent* CppRestJsonHelper::toDocument(const web::json::value json) {
  TIMED_FUNC(CppRestJsonHelper_toDocument);
  CppRestJsonDocumentContent* tdc = new CppRestJsonDocumentContent;
  tdc->setContent(json);
  tdc->setMimeType("application/json");
  return tdc; // TODO ensure this doesn't get nixed. Note - uses copy constructor (may eat memory)
}

web::json::value CppRestJsonHelper::fromDocument(const IDocumentContent& dc) {
  TIMED_FUNC(CppRestJsonHelper_fromDocument);
  std::ostringstream os;
  std::ostream* dcos(dc.getStream());
  os << dcos;
  delete dcos; // free pointer
  return web::json::value(os.str());
}

// Response conversion
web::json::value CppRestJsonHelper::fromResponse(const Response& resp) {
  TIMED_FUNC(CppRestJsonHelper_fromResponse);
  if (resp.getResponseType() == ResponseType::JSON) {
    return web::json::value::parse(resp.getContent());
  } else {
    throw InvalidFormatException();
  }
}


} // end utilities namespace

} // end mlclient namespace

