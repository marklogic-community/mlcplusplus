/*
 * DocumentContent.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include <string>
#include <iostream>
#include <sstream>

namespace mlclient {

// DOCUMENT CONTENT

class DocumentContent::Impl {
public:
  Impl() : mimeType("") {
    ;
  }
  ~Impl() {
    ;
  }
  std::string mimeType;
};

/**
 * \brief An enumeration for use with the DocumentContent class.
 *
 * A set of mime types that are needed internally in the MarkLogic C++ API. Other mime types are available.
 * These are for convenience to API developers, and prevent hard coding, and shield the API from server
 * side changes in the future.
 *
 * \note You can provide any string for mimeType - you are NOT limited to these enum values.
 */
const std::string DocumentContent::MIME_JSON = "application/json";    /// Standard MarkLogic JSON mime type. Used for all configuration API calls
const std::string DocumentContent::MIME_XML = "application/xml";       /// Standard MarkLogic XML mime type. Used for non-JSON configuration API calls, search options, etc.


DocumentContent::DocumentContent() : mImpl(new Impl) {
  ;
}

DocumentContent::~DocumentContent() {
  delete mImpl;
  mImpl = NULL;
}

std::string DocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void DocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = mt; // invokes copy constructor
}






/*


// BINARY DOCUMENT CONTENT

class BinaryDocumentContent::Impl {
public:
  Impl() : content("") {
    ;
  }
  ~Impl() {
    ;
  }
  char* content; // TODO proper binary holder
};



BinaryDocumentContent::BinaryDocumentContent() : mImpl(new Impl) {
  ;
}
BinaryDocumentContent::~BinaryDocumentContent() {
  delete mImpl;
  mImpl = NULL;
}
void BinaryDocumentContent::setContent(std::string content) {
  // TODO BinaryDocumentContent::setContent
}
std::string& BinaryDocumentContent::getContent() {
  return BinaryDocumentContent::getContent(mlclient::BinaryEncoding::HEX);
}
std::string& BinaryDocumentContent::getContent(const enum BinaryEncoding& encoding) {
  // TODO BinaryDocumentContent::getContent(BinaryEncoding)
}
void BinaryDocumentContent::setContent(char* binary,int offset,int length) {
  // TODO BinaryDocumentContent::setContent(binary)
}
int BinaryDocumentContent::getLength() {
  // TODO return impl content length
}



*/






// TEXT DOCUMENT CONTENT

class TextDocumentContent::Impl {
public:
  Impl() {
    content = std::unique_ptr<std::string>(new std::string("")); // MUST BE INITIALISED
  }
  ~Impl() {
    ;
  }
  std::unique_ptr<std::string> content;
};


TextDocumentContent::TextDocumentContent() : DocumentContent::DocumentContent(), mImpl(new Impl) {
  ;
}
TextDocumentContent::~TextDocumentContent() {
  delete mImpl;
  mImpl = NULL;
}
void TextDocumentContent::setContent(std::string content) {
  mImpl->content = std::unique_ptr<std::string>(new std::string(content)); // Force copy constructor
}
std::string TextDocumentContent::getContent() const {
  return std::string(*(mImpl->content)); // Forces copy constructor
}
int TextDocumentContent::getLength() const {
  return mImpl->content.get()->size();
}

std::ostream* TextDocumentContent::getStream() const {
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->content.get();
  //std::ostringstream& osref = os; // TODO verify this works with no dangling reference
  return os;
}

} // end mlclient namespace
