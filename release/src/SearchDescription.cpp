/*
 * SearchDescription.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "SearchDescription.hpp"
#include "DocumentContent.hpp"
#include "InvalidFormatException.hpp"
#include <string>

namespace mlclient {

class SearchDescription::Impl {
public:
  Impl() {
    TextDocumentContent* qtdc = new TextDocumentContent();
    query = std::unique_ptr<TextDocumentContent>(std::move(qtdc));
    TextDocumentContent* otdc = new TextDocumentContent();
    options = std::unique_ptr<TextDocumentContent>(std::move(otdc));
    std::string* qt = new std::string("");
    queryText = std::unique_ptr<std::string>(std::move(qt));
  }

  ~Impl() {
    ;
  }

  std::unique_ptr<TextDocumentContent> query;
  std::unique_ptr<TextDocumentContent> options;
  std::unique_ptr<std::string> queryText;
}; // end SearchDescription::Impl class


SearchDescription::SearchDescription() : mImpl(new Impl) {
  ;
}

SearchDescription::~SearchDescription() {
  delete mImpl;
  mImpl = NULL;
}


void SearchDescription::setOptions(TextDocumentContent& options) {
  mImpl->options = std::unique_ptr<TextDocumentContent>(std::move(&options)); // TODO check this & works
}
const TextDocumentContent& SearchDescription::getOptions() const {
  return *(mImpl->options.get());
}
void SearchDescription::setQuery(TextDocumentContent& query) {
  mImpl->query = std::unique_ptr<TextDocumentContent>(std::move(&query)); // TODO check this & works
}
const TextDocumentContent& SearchDescription::getQuery() const {
  return *(mImpl->query.get());
}
void SearchDescription::setQueryText(std::string qtext) {
  mImpl->queryText = std::unique_ptr<std::string>(new std::string(qtext));
}
const std::string& SearchDescription::getQueryText() const {
  return *(mImpl->queryText.get());
}
const TextDocumentContent& SearchDescription::getPayload() const {
  // if options has not been initialised, leave blank, but set mime type as same as query
  if ("" == mImpl->options.get()->getMimeType()) {
    mImpl->options.get()->setMimeType(mImpl->query.get()->getMimeType());
  }
  // we could also have options, but no query (using qtext instead)
  if ("" == mImpl->query.get()->getMimeType()) {
    mImpl->query.get()->setMimeType(mImpl->options.get()->getMimeType());
  }
  // or just a blank query and options!
  if ("" == mImpl->options.get()->getMimeType() && "" == mImpl->query.get()->getMimeType()) {
    mImpl->options.get()->setMimeType(DocumentContent::MIME_JSON);
    mImpl->query.get()->setMimeType(DocumentContent::MIME_JSON);
  }
  if ( !(DocumentContent::MIME_JSON == mImpl->query.get()->getMimeType() && DocumentContent::MIME_JSON == mImpl->options.get()->getMimeType())
       ||
       !(DocumentContent::MIME_XML == mImpl->query.get()->getMimeType() && DocumentContent::MIME_XML == mImpl->options.get()->getMimeType())
     ) {
    throw new InvalidFormatException;
  }
  std::string elements[8] = {
      "{\"search\": {", "<search>",
      "}}","</search>",
      "\"qtext\": \"","<qtext>",
      "\"", "</qtext>"
  };
  int offset = 0; // default to JSON
  if (DocumentContent::MIME_XML == mImpl->query.get()->getMimeType()) {
    offset = 1;
  }
  std::string payloadString = elements[0+offset] + mImpl->query.get()->getContent() + mImpl->options.get()->getContent() + elements[2+offset] +
      *(mImpl->queryText.get()) + elements[3+offset] + elements[1+offset];
  TextDocumentContent payload;
  payload.setMimeType(mImpl->query.get()->getMimeType());
  payload.setContent(std::move(payloadString));
  return std::move(payload);
}

} // end namespace mlclient
