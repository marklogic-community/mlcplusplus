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

#include <cpprest/http_client.h>
#include "SearchBuilder.hpp"
#include "SearchOptionsBuilder.hpp"
#include "CppRestJsonHelper.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <list>

namespace mlclient {

namespace utilities {

class SearchOptionsBuilder::Impl {
public:
  Impl() : value(web::json::value::object()) {
    value["options"] = web::json::value::object();
    value["options"]["constraints"] = web::json::value::array();
  };

  web::json::value value;
};



SearchOptionsBuilder::SearchOptionsBuilder() : mImpl(new Impl) {
  ;
}



SearchOptionsBuilder* SearchOptionsBuilder::additionalQuery(const IQuery& query) {
  std::ostringstream oss;
  oss << query;
  mImpl->value["options"]["additional-query"] = web::json::value(oss.str());
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::containerConstraint(const IContainerRef& container) {
  std::ostringstream oss;
  oss << container;
  web::json::array& arr = mImpl->value["options"]["constraints"].as_array();
  arr.at(arr.size()) = web::json::value(oss.str()); // validate this includes closing braces, and that we're appending correctly
  return this;
}


SearchOptionsBuilder* SearchOptionsBuilder::emptySnippet() {
  mImpl->value["options"]["transform-results"] = web::json::value("{\"apply\": \"empty\"}");
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::rawSnippet() {
  mImpl->value["options"]["transform-results"] = web::json::value("{\"apply\": \"raw\"}");
  return this;
}

void SearchOptionsBuilder::fromDocument(const ITextDocumentContent& doc) {
  mImpl->value = CppRestJsonHelper::fromDocument(doc);
}

ITextDocumentContent& SearchOptionsBuilder::toDocument() {
  return *CppRestJsonHelper::toDocument(mImpl->value);
}



} // end namespace utilities

} // end namespace mlclient
