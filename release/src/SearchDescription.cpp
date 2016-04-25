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
  Impl() : query(TextDocumentContent()), options(TextDocumentContent()), queryText("") {
    ;
  }

  ~Impl() {
    ;
  }

  TextDocumentContent& query;
  TextDocumentContent& options;
  std::string queryText;
}; // end SearchDescription::Impl class


SearchDescription::SearchDescription() : mImpl(new Impl) {
  ;
}

~SearchDescription::SearchDescription() {
  delete mImpl;
  mImpl = NULL;
}


void SearchDescription::setOptions(TextDocumentContent& options) {
  mImpl->options = options;
}
TextDocumentContent SearchDescription::getOptions() {
  return mImpl->options;
}
void SearchDescription::setQuery(TextDocumentContent& query) {
  mImpl->query = query;
}
TextDocumentContent SearchDescription::getQuery() {
  return mImpl->query;
}
void SearchDescription::setQueryText(std::string qtext) {
  mImpl->queryText = qtext;
}
std::string SearchDescription::getQueryText() {
  return mImpl->queryText;
}
DocumentContent& SearchDescription::getPayload() {
  // if options has not been initialised, leave blank, but set mime type as same as query
  if ("" == mImpl->options.getMimeType()) {
    mImpl->options.setMimeType(mImpl->query.getMimeType());
  }
  // we could also have options, but no query (using qtext instead)
  if ("" == mImpl->query.getMimeType()) {
    mImpl->query.setMimeType(mImpl->options.getMimeType());
  }
  // or just a blank query and options!
  if ("" == mImpl->options.getMimeType() && "" == mImpl->query.getMimeType()) {
    mImpl->options.setMimeType(MimeType::JSON);
    mImpl->query.setMimeType(MimeType::JSON);
  }
  if ( !(MimeType::JSON == mImpl->query.getMimeType() && MimeType::JSON == mImpl->options.getMimeType())
       ||
       !(MimeType::XML == mImpl->query.getMimeType() && MimeType::XML == mImpl->options.getMimeType())
     ) {
    throw InvalidFormatException;
  }
  std::string[] elements = {
      "{\"search\": {", "<search>",
      "}}","</search>",
      "\"qtext\": \"","<qtext>",
      "\"", "</qtext>"
  };
  int offset = 0; // default to JSON
  if (MimeType::XML == mImpl->query.getMimeType()) {
    offset = 1;
  }
  std::string payloadString = elements[0+offset] + mImpl->query + mImpl->options + elements[2+offset] +
      mImpl->queryText + elements[3+offset] + elements[1+offset];
  TextDocumentContent& payload = TextDocumentContent;
  payload.setMimeType(mImpl->query.getMimeType());
  payload.setContent(payloadString);
  return payload;
}

} // end namespace mlclient
