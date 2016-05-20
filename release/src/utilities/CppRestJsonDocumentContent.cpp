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
 * \file CppRestJsonDocumentContent.cpp
 * \since 8.0.0
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Implements a JSON document content instance for use with Microsoft's cpprest API
 * \date 2016-05-01
 */

#include <cpprest/http_client.h>
#include "CppRestJsonDocumentContent.hpp"
#include <iostream>
#include <string>
#include <sstream>

namespace mlclient {

namespace utilities {

class CppRestJsonDocumentContent::Impl {
public:
  Impl() {
    value = web::json::value();
  };
  ~Impl() {
    ;
  };
  web::json::value value;
  std::string mimeType;
};

CppRestJsonDocumentContent::CppRestJsonDocumentContent() : mImpl(new Impl) {
  ;
}

CppRestJsonDocumentContent::~CppRestJsonDocumentContent() {
  delete mImpl;
}

std::ostream* CppRestJsonDocumentContent::getStream() const {
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->value;
  return os;
}

web::json::value& CppRestJsonDocumentContent::getJson() {
  return mImpl->value;
}

void CppRestJsonDocumentContent::setContent(const web::json::value& json) {
  mImpl->value = json;
}

std::string CppRestJsonDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void CppRestJsonDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

int CppRestJsonDocumentContent::getLength() const {
  return getContent().size();
}

void CppRestJsonDocumentContent::setContent(std::string content) {
  std::ostringstream os;
  os << content;
  mImpl-> value = web::json::value(os.str());
}

std::string CppRestJsonDocumentContent::getContent() const {
  std::ostringstream os;
  os << mImpl->value;
  return os.str();
}


} // end utilities namespace

} // end mlclient namespace
