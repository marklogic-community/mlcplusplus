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

#include "easylogging++.h"

namespace mlclient {

// DOCUMENT CONTENT
/*
class DocumentContent::Impl {
public:
  Impl() : mimeType("") {
    LOG(DEBUG) << "    DocumentContent::Impl::defaultConstructor @" << &*this;
  }
  ~Impl() {
    LOG(DEBUG) << "    DocumentContent::Impl::destructor @" << &*this << " complete.";
  }
  std::string mimeType;
};
*/
/**
 * \brief An enumeration for use with the DocumentContent class.
 *
 * A set of mime types that are needed internally in the MarkLogic C++ API. Other mime types are available.
 * These are for convenience to API developers, and prevent hard coding, and shield the API from server
 * side changes in the future.
 *
 * \note You can provide any string for mimeType - you are NOT limited to these enum values.
 */
const std::string IDocumentContent::MIME_JSON = "application/json";    /// Standard MarkLogic JSON mime type. Used for all configuration API calls
const std::string IDocumentContent::MIME_XML = "application/xml";       /// Standard MarkLogic XML mime type. Used for non-JSON configuration API calls, search options, etc.


IDocumentContent::IDocumentContent() {
  LOG(DEBUG) << "    DocumentContent::defaultConstructor @" << &*this;
}

IDocumentContent::~IDocumentContent() {
  LOG(DEBUG) << "    DocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    DocumentContent::destructor @" << &*this << " complete.";
}
/*
std::string DocumentContent::getMimeType() const {
  return std::string(mbImpl->mimeType); // forces copy constructor
}

void DocumentContent::setMimeType(const std::string& mt) {
  mbImpl->mimeType = std::string(mt); // invokes copy constructor
}

*/




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
    LOG(DEBUG) << "    TextDocumentContent::Impl::defaultConstructor @" << &*this;
    content = std::unique_ptr<std::string>(new std::string("")); // MUST BE INITIALISED
  }
  ~Impl() {
    ;
  }
  std::unique_ptr<std::string> content;
  std::string mimeType;
};


TextDocumentContent::TextDocumentContent() : IDocumentContent::IDocumentContent(), mImpl(new Impl) {
  LOG(DEBUG) << "    TextDocumentContent::defaultConstructor @" << &*this;
  ;
}
TextDocumentContent::TextDocumentContent(const TextDocumentContent& doc) : IDocumentContent::IDocumentContent(doc), mImpl(new Impl) {
  LOG(DEBUG) << "    TextDocumentContent::copyConstructor @ " << &*this;
  mImpl->content = std::unique_ptr<std::string>(new std::string(*(doc.mImpl->content.get())));
}
TextDocumentContent::~TextDocumentContent() {
  LOG(DEBUG) << "    TextDocumentContent::destructor @ " << &*this << " : " << *(mImpl->content.get());
  delete mImpl;
  mImpl = NULL;
  //DocumentContent::~DocumentContent();
  LOG(DEBUG) << "    TextDocumentContent::destructor @ " << &*this << " complete.";
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
  TIMED_FUNC(TextDocument_getStream);
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->content.get();
  //std::ostringstream& osref = os; // TODO verify this works with no dangling reference
  return os;
}

std::string TextDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void TextDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

} // end mlclient namespace
