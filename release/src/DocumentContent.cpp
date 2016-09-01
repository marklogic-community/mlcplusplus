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
 * DocumentContent.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "mlclient/DocumentContent.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/logging.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <map>

namespace mlclient {

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


IDocumentNode::IDocumentNode() {
  ;
}

IDocumentNode::~IDocumentNode() {
  ;
}

IDocumentNavigator::IDocumentNavigator() {
  ;
}

IDocumentNavigator::~IDocumentNavigator() {
  ;
}


IDocumentContent::IDocumentContent() {
  //TIMED_FUNC(IDocumentContent_defaultConstructor);
  LOG(DEBUG) << "    IDocumentContent::defaultConstructor @" << &*this;
}

IDocumentContent::~IDocumentContent() {
  //TIMED_FUNC(IDocumentContent_destructor);
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this << " complete.";
}




ITextDocumentContent::ITextDocumentContent() {
  //TIMED_FUNC(ITextDocumentContent_defaultConstructor);
  LOG(DEBUG) << "    ITextDocumentContent::defaultConstructor @" << &*this;
}

ITextDocumentContent::~ITextDocumentContent() {
  //TIMED_FUNC(ITextDocumentContent_destructor);
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
    TIMED_FUNC(GenericTextDocumentContent_Impl_defaultConstructor);
    LOG(DEBUG) << "    GenericTextDocumentContent::Impl::defaultConstructor @" << &*this;
    content = std::unique_ptr<std::string>(new std::string("{}")); // MUST BE INITIALISED
    mimeType = "application/json";
  }
  ~Impl() {
    ;
  }
  std::unique_ptr<std::string> content;
  std::string mimeType;
};


GenericTextDocumentContent::GenericTextDocumentContent() : ITextDocumentContent::ITextDocumentContent(), mImpl(new Impl) {
  TIMED_FUNC(GenericTextDocumentContent_defaultConstructor);
  LOG(DEBUG) << "    GenericTextDocumentContent::defaultConstructor @" << &*this;
  ;
}
GenericTextDocumentContent::GenericTextDocumentContent(const GenericTextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  TIMED_FUNC(GenericTextDocumentContent_copyGenericConstructor);
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  std::ostringstream oss;
  oss << *(doc.mImpl->content);
  mImpl->content = std::unique_ptr<std::string>(new std::string(oss.str())); // copy constructor
  mImpl->mimeType = doc.getMimeType();
}
GenericTextDocumentContent::GenericTextDocumentContent(const ITextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  TIMED_FUNC(GenericTextDocumentContent_copyITextConstructor);
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  std::ostringstream oss;
  oss << doc.getContent();
  mImpl->content = std::unique_ptr<std::string>(new std::string(oss.str())); // copy constructor
  mImpl->mimeType = doc.getMimeType();
}
GenericTextDocumentContent::~GenericTextDocumentContent() {
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " : " << *(mImpl->content.get());
  delete mImpl;
  mImpl = NULL;
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " complete.";
}
void GenericTextDocumentContent::setContent(std::string content) {
  TIMED_FUNC(GenericTextDocumentContent_setContent);
  LOG(DEBUG) << "GenericTextDocumentContent::setContent: " << content;
  mImpl->content = std::unique_ptr<std::string>(new std::string(content)); // Force copy constructor
}
std::string GenericTextDocumentContent::getContent() const {
  TIMED_FUNC(GenericTextDocumentContent_getContent);
  return *(mImpl->content); // Forces copy constructor
}
int GenericTextDocumentContent::getLength() const {
  return mImpl->content->size();
}

std::ostream* GenericTextDocumentContent::getStream() const {
  TIMED_FUNC(GenericTextDocumentContent_getStream);
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->content.get();
  return os;
}

std::string GenericTextDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void GenericTextDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

IDocumentNavigator* GenericTextDocumentContent::navigate(bool firstElementAsRoot) const {
  throw new mlclient::InvalidFormatException("GenericDocumentContent does not yet support navigation");
}



class FileDocumentContent::Impl {
public:
  Impl(std::string f) : file(f), mime("application/json"), fs(), mimeMap() {

    mimeMap.insert(std::pair<std::string,std::string>("xml","application/xml"));
    mimeMap.insert(std::pair<std::string,std::string>("json","application/json"));
    mimeMap.insert(std::pair<std::string,std::string>("txt","application/text"));

    mimeMap.insert(std::pair<std::string,std::string>("jpg","image/jpeg"));
    mimeMap.insert(std::pair<std::string,std::string>("png","image/png"));
    mimeMap.insert(std::pair<std::string,std::string>("gif","image/gif"));
    mimeMap.insert(std::pair<std::string,std::string>("doc","application/msword"));
    mimeMap.insert(std::pair<std::string,std::string>("docx","application/vnd.openxmlformats-officedocument.wordprocessingml.document"));
    mimeMap.insert(std::pair<std::string,std::string>("ppt","application/vnd.ms-powerpoint"));
    mimeMap.insert(std::pair<std::string,std::string>("pptx","application/vnd.openxmlformats-officedocument.presentationml.presentation"));

    // get file extension
    std::string ext = file.substr(file.find_last_of(".") + 1);
    // TODO to lower case this extension
    // derive mime type
    auto loc = mimeMap.find(ext);
    if (mimeMap.end() != loc) {
      mime = loc->second;
    }
  }
  ~Impl() {
    ; // fstream automatically destroyed
  }

  std::string file;
  std::string mime;
  std::ifstream fs;

private:
  std::map<std::string,std::string> mimeMap; // TODO handle this statically
};


FileDocumentContent::FileDocumentContent(std::string file) : mImpl(mlclient::make_unique<Impl>(file)) {
  ;
}

FileDocumentContent::~FileDocumentContent() {
  ;
}

std::ostream* FileDocumentContent::getStream() const {
  std::string str(getContent());
  std::ostringstream* os = new std::ostringstream;
  (*os) << str;
  return os;
}

std::string FileDocumentContent::getContent() const {
  mImpl->fs.open(mImpl->file,std::fstream::in);
  std::string str;

  mImpl->fs.seekg(0, std::ios::end);
  str.reserve(mImpl->fs.tellg());
  mImpl->fs.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(mImpl->fs)),
             (std::istreambuf_iterator<char>()));

  mImpl->fs.close();

  return str;
}

std::string FileDocumentContent::getMimeType() const {
  return mImpl->mime;
}

void FileDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mime = mt; // TODO enforce to lower case on this input
}



} // end mlclient namespace
