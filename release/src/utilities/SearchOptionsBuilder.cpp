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
 * \file SearchBuilder.cpp
 * \since 8.0.2
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Provides convenience functions to parse MarkLogic response objects
 * \date 2016-06-09
 */

#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/utilities/SearchOptionsBuilder.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include <cpprest/http_client.h>
#include <iostream>
#include <string>
#include <sstream>
#include <list>

namespace mlclient {

namespace utilities {

class SearchOptionsBuilder::Impl {
public:
  Impl() : additionalQuery(),constraints(),transform("raw") {
    ;
  };

  std::string additionalQuery;
  std::vector<std::string> constraints;
  std::string transform;
};



SearchOptionsBuilder::SearchOptionsBuilder() : mImpl(new Impl) {
  ;
}



SearchOptionsBuilder* SearchOptionsBuilder::additionalQuery(const IQuery& query) {
  std::ostringstream oss;
  oss << query;
  mImpl->additionalQuery = oss.str();
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::containerConstraint(const IContainerRef& container) {
  std::ostringstream oss;
  oss << container;
  mImpl->constraints.push_back(oss.str());

  return this;
}


SearchOptionsBuilder* SearchOptionsBuilder::emptySnippet() {
  mImpl->transform = "empty";
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::rawSnippet() {
  mImpl->transform = "raw";
  return this;
}

void SearchOptionsBuilder::fromDocument(const ITextDocumentContent& doc) {
  // TODO complete this, parse, and extract values
}

ITextDocumentContent* SearchOptionsBuilder::toDocument() {
  std::ostringstream oss;
  oss << "{\"transform-results\": {\"apply\": \"" << mImpl->transform << "\"}";
  // TODO other JSON attributes
  GenericTextDocumentContent* tdc = new GenericTextDocumentContent;
  tdc->setContent(oss.str());
  tdc->setMimeType(IDocumentContent::MIME_JSON);
  return tdc;
}



} // end namespace utilities

} // end namespace mlclient
