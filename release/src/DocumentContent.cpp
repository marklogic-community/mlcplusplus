/*
 * DocumentContent.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include <string>

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


DocumentContent::DocumentContent() : mImpl(new Impl) {
  ;
}

DocumentContent::~DocumentContent() {
  delete mImpl;
  mImpl = NULL;
}

std::string DocumentContent::getMimeType() {
  return std::string(mImpl->mimeType);
}

void DocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = mt; // invokes copy constructor
}









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
std::string BinaryDocumentContent::getContent() {
  return BinaryDocumentContent::getContent(mlclient::BinaryEncoding::HEX);
}
std::string BinaryDocumentContent::getContent(const enum BinaryEncoding& encoding) {
  // TODO BinaryDocumentContent::getContent(BinaryEncoding)
}
void BinaryDocumentContent::setContent(char* binary,int offset,int length) {
  // TODO BinaryDocumentContent::setContent(binary)
}
int BinaryDocumentContent::getLength() {
  // TODO return impl content length
}










// TEXT DOCUMENT CONTENT

class TextDocumentContent::Impl {
public:
  Impl() : content("") {
    ;
  }
  ~Impl() {
    ;
  }
  std::string content;
};


TextDocumentContent::TextDocumentContent() : mImpl(new Impl) {
  ;
}
TextDocumentContent::~TextDocumentContent() {
  delete mImpl;
  mImpl = NULL;
}
void TextDocumentContent::setContent(std::string content) {
  mImpl->content = content;
}
std::string TextDocumentContent::getContent() {
  return mImpl->content;
}
int TextDocumentContent::getLength() {
  return mImpl->content.size();
}

} // end mlclient namespace
