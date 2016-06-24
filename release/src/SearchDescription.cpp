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
 * SearchDescription.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "mlclient/SearchDescription.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/InvalidFormatException.hpp"

#include "mlclient/ext/easylogging++.h"

#include <string>
#include <iostream>

namespace mlclient {

class SearchDescription::Impl {
public:
  Impl() : start(1), pageLength(10) {
    LOG(DEBUG) << "    SearchDescription::Impl::defaultConstructor @" << &*this;
    GenericTextDocumentContent* qtdc = new GenericTextDocumentContent();
    qtdc->setContent("{}");
    query = std::unique_ptr<GenericTextDocumentContent>(qtdc);
    GenericTextDocumentContent* otdc = new GenericTextDocumentContent();
    otdc->setContent("{}");
    options = std::unique_ptr<GenericTextDocumentContent>(otdc);
    std::string* qt = new std::string("");
    queryText = std::unique_ptr<std::string>(qt);
    LOG(DEBUG) << "    SearchDescription::Impl::defaultConstructor @" << &*this << " complete";
  }

  ~Impl() {
    ;
  }

  std::unique_ptr<ITextDocumentContent> query;
  std::unique_ptr<ITextDocumentContent> options;
  std::unique_ptr<std::string> queryText;
  long start;
  long pageLength;
}; // end SearchDescription::Impl class


SearchDescription::SearchDescription() : mImpl(new Impl) {
  LOG(DEBUG) << "    SearchDescription::defaultConstructor @" << &*this;
}

SearchDescription::~SearchDescription() {
  LOG(DEBUG) << "    SearchDescription::destructor @ " << &*this;
  delete mImpl;
  mImpl = NULL;
  LOG(DEBUG) << "    SearchDescription::destructor @ " << &*this << " complete.";
}


void SearchDescription::setOptions(ITextDocumentContent& options) {
  mImpl->options = std::unique_ptr<ITextDocumentContent>(new GenericTextDocumentContent(options)); // copy constructor
}
const ITextDocumentContent& SearchDescription::getOptions() const {
  return *(mImpl->options.get());
}
void SearchDescription::setQuery(ITextDocumentContent& query) {
  mImpl->query = std::unique_ptr<ITextDocumentContent>(new GenericTextDocumentContent(query)); // copy constructor
}
const ITextDocumentContent& SearchDescription::getQuery() const {
  return *(mImpl->query.get());
}
void SearchDescription::setQueryText(std::string qtext) {
  mImpl->queryText = std::unique_ptr<std::string>(new std::string(qtext));
}
const std::string& SearchDescription::getQueryText() const {
  return *(mImpl->queryText.get());
}
ITextDocumentContent* SearchDescription::getPayload() const {
  TIMED_FUNC(SearchDescription_getPayload);
  LOG(DEBUG) << "    Entering getPayload()";
  // if options has not been initialised, leave blank, but set mime type as same as query
  if (mImpl->options.get()->getMimeType().empty()) {
    mImpl->options.get()->setMimeType(mImpl->query.get()->getMimeType());
  }
  LOG(DEBUG) << "    set mime type";
  // we could also have options, but no query (using qtext instead)
  if (mImpl->query.get()->getMimeType().empty()) {
    mImpl->query.get()->setMimeType(mImpl->options.get()->getMimeType());
  }
  LOG(DEBUG) << "    set query";
  // or just a blank query and options!
  if (mImpl->options.get()->getMimeType().empty() && mImpl->query.get()->getMimeType().empty()) {
    mImpl->options.get()->setMimeType(IDocumentContent::MIME_JSON);
    mImpl->query.get()->setMimeType(IDocumentContent::MIME_JSON);
  }
  LOG(DEBUG) << "    reset mime type";
  if ( !(0==IDocumentContent::MIME_JSON.compare(mImpl->query.get()->getMimeType()) && 0==IDocumentContent::MIME_JSON.compare(mImpl->options.get()->getMimeType()))
       &&
       !(0==IDocumentContent::MIME_XML.compare(mImpl->query.get()->getMimeType()) && 0==IDocumentContent::MIME_XML.compare(mImpl->options.get()->getMimeType()))
     ) {

    LOG(DEBUG) << "    MIME TYPES DO NOT MATCH - THROWING EXCEPTION: Query mime: " << mImpl->query.get()->getMimeType()
              << ", options MIME: " << mImpl->options.get()->getMimeType();
    throw new InvalidFormatException;
  }
  std::string elements[12] = {
      "{\"search\": {\"query\":", "<search>",
      "}}","</search>",
      "\"qtext\": \"","<qtext>",
      "\"", "</qtext>",
      ",\"options\":","",
      "},",""
  };
  LOG(DEBUG) << "    got elements";
  int offset = 0; // default to JSON
  if (0==IDocumentContent::MIME_XML.compare(mImpl->query.get()->getMimeType())) {
    offset = 1;
  }
  std::string payloadString =
      elements[0+offset] +
        mImpl->query.get()->getContent() + elements[8+offset] +
        mImpl->options.get()->getContent() + elements[10+offset]  +
        elements[4+offset] + *(mImpl->queryText.get()) + elements[6+offset] +
      elements[2+offset];
  LOG(DEBUG) << "    got payload string: " << payloadString;
  GenericTextDocumentContent* payload = new GenericTextDocumentContent;
  payload->setMimeType(mImpl->query.get()->getMimeType());
  payload->setContent(std::move(payloadString));
  LOG(DEBUG) << "    got payload doc";
  LOG(DEBUG) << "    End getPayload()";
  return payload;
}

void SearchDescription::setStart(const long start) {
  mImpl->start = start;
}

const long SearchDescription::getStart() const {
  return mImpl->start;
}

void SearchDescription::setPageLength(const long pageLength) {
  mImpl->pageLength = pageLength;
}

const long SearchDescription::getPageLength() const {
  return mImpl->pageLength;
}

} // end namespace mlclient
