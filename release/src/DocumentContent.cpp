/*
 * DocumentContent.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
//#include "internals/memory.hpp"
#include <string>
#include <iostream>
#include <sstream>
//#include <memory>

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
 * \brief An enumeration for use with the IDocumentContent class.
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
  LOG(DEBUG) << "    IDocumentContent::defaultConstructor @" << &*this;
}

IDocumentContent::~IDocumentContent() {
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this << " complete.";
}
/*
std::string DocumentContent::getMimeType() const {
  return std::string(mbImpl->mimeType); // forces copy constructor
}

void DocumentContent::setMimeType(const std::string& mt) {
  mbImpl->mimeType = std::string(mt); // invokes copy constructor
}

*/


ITextDocumentContent::ITextDocumentContent() {
  LOG(DEBUG) << "    ITextDocumentContent::defaultConstructor @" << &*this;
}

ITextDocumentContent::~ITextDocumentContent() {
  LOG(DEBUG) << "    ITextDocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    ITextDocumentContent::destructor @" << &*this << " complete.";
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

class GenericTextDocumentContent::Impl {
public:
  Impl() {
    LOG(DEBUG) << "    GenericTextDocumentContent::Impl::defaultConstructor @" << &*this;
    content = std::unique_ptr<std::string>(new std::string(std::string(""))); // MUST BE INITIALISED
  }
  ~Impl() {
    ;
  }
  std::unique_ptr<std::string> content;
  std::string mimeType;
};


GenericTextDocumentContent::GenericTextDocumentContent() : ITextDocumentContent::ITextDocumentContent(), mImpl(new Impl) {
  LOG(DEBUG) << "    GenericTextDocumentContent::defaultConstructor @" << &*this;
  ;
}
GenericTextDocumentContent::GenericTextDocumentContent(const GenericTextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  //mImpl->content = std::unique_ptr<std::string>(new std::string(*(doc.mImpl->content.get())));
  // DO COPY INSTEAD, IT'S SAFER - mImpl->content = std::move(doc.mImpl->content); // move constructor
  mImpl->content = std::unique_ptr<std::string>(new std::string(*(doc.mImpl->content.get()))); // copy constructor
}
GenericTextDocumentContent::GenericTextDocumentContent(const ITextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  mImpl->content = std::unique_ptr<std::string>(new std::string(doc.getContent())); // copy constructor
}
GenericTextDocumentContent::~GenericTextDocumentContent() {
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " : " << *(mImpl->content.get());
  delete mImpl;
  mImpl = NULL;
  //DocumentContent::~DocumentContent();
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " complete.";
}
void GenericTextDocumentContent::setContent(std::string content) {
  mImpl->content = std::unique_ptr<std::string>(new std::string(content)); // Force copy constructor
}
std::string GenericTextDocumentContent::getContent() const {
  return std::string(*(mImpl->content)); // Forces copy constructor
}
int GenericTextDocumentContent::getLength() const {
  return mImpl->content.get()->size();
}

std::ostream* GenericTextDocumentContent::getStream() const {
  TIMED_FUNC(GenericTextDocumentContent_getStream);
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->content.get();
  //std::ostringstream& osref = os; // TODO verify this works with no dangling reference
  return os;
}

std::string GenericTextDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void GenericTextDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

} // end mlclient namespace
