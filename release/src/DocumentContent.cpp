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
#include "mlclient/InvalidFormatException.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <map>
#include "mlclient/logging.hpp"

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
const std::string IDocumentContent::MIME_JSON("application/json");    /// Standard MarkLogic JSON mime type. Used for all configuration API calls
const std::string IDocumentContent::MIME_XML("application/xml");       /// Standard MarkLogic XML mime type. Used for non-JSON configuration API calls, search options, etc.
const std::string IDocumentContent::MIME_TXT("text/plain");
const std::string IDocumentContent::MIME_JPG("image/jpeg");
const std::string IDocumentContent::MIME_PNG("image/png");
const std::string IDocumentContent::MIME_GIF("image/gif");
const std::string IDocumentContent::MIME_DOC("application/msword");
const std::string IDocumentContent::MIME_DOCX("application/vnd.openxmlformats-officedocument.wordprocessingml.document");
const std::string IDocumentContent::MIME_PPT("application/vnd.ms-powerpoint");
const std::string IDocumentContent::MIME_PPTX("application/vnd.openxmlformats-officedocument.presentationml.presentation");

IDocumentNode::IDocumentNode() {
  return;
}

IDocumentNode::~IDocumentNode() {
  return;
}

IDocumentNavigator::IDocumentNavigator() {
  return;
}

IDocumentNavigator::~IDocumentNavigator() {
  return;
}


IDocumentContent::IDocumentContent() {
  //TIMED_FUNC(IDocumentContent_defaultConstructor);
  LOG(DEBUG) << "    IDocumentContent::defaultConstructor @" << &*this;
}

IDocumentContent::~IDocumentContent() {
  //TIMED_FUNC(IDocumentContent_destructor);
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    IDocumentContent::destructor @" << &*this << " complete.";
  return;
}




ITextDocumentContent::ITextDocumentContent() {
  //TIMED_FUNC(ITextDocumentContent_defaultConstructor);
  LOG(DEBUG) << "    ITextDocumentContent::defaultConstructor @" << &*this;
  return;
}

ITextDocumentContent::~ITextDocumentContent() {
  //TIMED_FUNC(ITextDocumentContent_destructor);
  LOG(DEBUG) << "    ITextDocumentContent::destructor @" << &*this;
  LOG(DEBUG) << "    ITextDocumentContent::destructor @" << &*this << " complete.";
  return;
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
  mImpl = nullptr;
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
    this->content = std::unique_ptr<std::string>(new std::string("{}")); // MUST BE INITIALISED
    this->mimeType = IDocumentContent::MIME_JSON;
    return;
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
  return;
}
GenericTextDocumentContent::GenericTextDocumentContent(const GenericTextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  TIMED_FUNC(GenericTextDocumentContent_copyGenericConstructor);
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  std::ostringstream oss;
  oss << *(doc.this->mImpl->content);
  this->mImpl->content = std::unique_ptr<std::string>(new std::string(oss.str())); // copy constructor
  this->mImpl->mimeType = doc.getMimeType();
  return;
}
GenericTextDocumentContent::GenericTextDocumentContent(const ITextDocumentContent& doc) : ITextDocumentContent::ITextDocumentContent(doc), mImpl(new Impl) {
  TIMED_FUNC(GenericTextDocumentContent_copyITextConstructor);
  LOG(DEBUG) << "    GenericTextDocumentContent::copyConstructor @ " << &*this;
  std::ostringstream oss;
  oss << doc.getContent();
  this->mImpl->content = std::unique_ptr<std::string>(new std::string(oss.str())); // copy constructor
  this->mImpl->mimeType = doc.getMimeType();
  return;
}
GenericTextDocumentContent::~GenericTextDocumentContent() {
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " : " << *(this->mImpl->content.get());
  delete mImpl;
  mImpl = nullptr;
  LOG(DEBUG) << "    GenericTextDocumentContent::destructor @ " << &*this << " complete.";
  return;
}
void GenericTextDocumentContent::setContent(std::string content) {
  TIMED_FUNC(GenericTextDocumentContent_setContent);
  LOG(DEBUG) << "GenericTextDocumentContent::setContent: " << content;
  this->mImpl->content = std::unique_ptr<std::string>(new std::string(content)); // Force copy constructor
  return;
}
std::string GenericTextDocumentContent::getContent() const {
  TIMED_FUNC(GenericTextDocumentContent_getContent);
  return *(this->mImpl->content); // Forces copy constructor
}
int GenericTextDocumentContent::getLength() const {
  return this->mImpl->content->size();
}

std::istream* GenericTextDocumentContent::getStream() const {
  TIMED_FUNC(GenericTextDocumentContent_getStream);
  std::istringstream* os = new std::istringstream(*(this->mImpl->content));
  //std::ostringstream* os = new std::ostringstream;
  //(*os) << this->mImpl->content.get();
  return os;
}

std::string GenericTextDocumentContent::getMimeType() const {
  return std::string(this->mImpl->mimeType); // forces copy constructor
}

void GenericTextDocumentContent::setMimeType(const std::string& mt) {
  this->mImpl->mimeType = std::string(mt); // invokes copy constructor
  return;
}

IDocumentNavigator* GenericTextDocumentContent::navigate(bool firstElementAsRoot) const {
  throw new mlclient::InvalidFormatException("GenericDocumentContent does not yet support navigation");
}



class FileDocumentContent::Impl {
public:
  Impl(const std::string & filename) : filename(filename), mime(IDocumentContent::MIME_JSON), fs(), mimeMap() {

	// Filename extension (XML).
    static const std::string XML("xml");
    // Filename extension (JSON).
    static const std::string JSON("json");
     // Filename extension (TXT).
    static const std::string TXT("txt");
	// Filename extension (JPG).
    static const std::string JPG("jpg");
 	// Filename extension (PNG).
    static const std::string PNG("png");
	// Filename extension (GIF).
    static const std::string GIF("gif");
	// Filename extension (DOC).
    static const std::string DOC("doc");
	// Filename extension (DOCX).
    static const std::string DOCX("docx");
	// Filename extension (PPT).
    static const std::string PPT("ppt");
	// Filename extension (PPTX).
    static const std::string PPTX("pptx");

    // Store the mappings between extensions and mime types.
    this->mimeMap.emplace(XML, IDocumentContent::MIME_XML);
    this->mimeMap.emplace(JSON, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(TXT, IDocumentContent::MIME_TXT);
    this->mimeMap.emplace(JPG, IDocumentContent::MIME_JPG);
    this->mimeMap.emplace(PNG, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(GIF, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(DOC, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(DOCX, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(PPT, IDocumentContent::MIME_JSON);
    this->mimeMap.emplace(PPTX, IDocumentContent::MIME_JSON);

    // get file extension
    // TODO to lower case this extension
    // derive mime type
    auto loc = this->mimeMap.find(this->filename.substr(this->filename.find_last_of(".") + 1));
    if (this->mimeMap.end() != loc) {
    	this->mime = loc->second;
    }
    return;
  }
  ~Impl() {
    return; // fstream automatically destroyed
  }

  std::string const filename;
  std::string mime; // TODO This really should be const.
  std::ifstream fs;

private:
  std::map<std::string,std::string> mimeMap; // TODO Handle this statically, and it should be const.
};


FileDocumentContent::FileDocumentContent(std::string file) : mImpl(mlclient::make_unique<Impl>(file)) {
	  return;
}

FileDocumentContent::~FileDocumentContent() {
	  return;
}

std::istream* FileDocumentContent::getStream() const {
  std::ifstream* is = new std::ifstream(this->mImpl->filename, std::ifstream::in);
  //std::string str(getContent());
  //std::ostringstream* os = new std::ostringstream;
  //(*os) << str;
  return is;
}

std::string FileDocumentContent::getContent() const {
  LOG(DEBUG) << "FileDocumentContent::getContent() entered";
  this->mImpl->fs.open(this->mImpl->filename, std::fstream::in);
  std::string str;

  this->mImpl->fs.seekg(0, std::ios::end);
  str.reserve(this->mImpl->fs.tellg());
  this->mImpl->fs.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(this->mImpl->fs)),
             (std::istreambuf_iterator<char>()));

  this->mImpl->fs.close();

  LOG(DEBUG) << "FileDocumentContent::getContent() returning: " << str;

  return str;
}

std::string FileDocumentContent::getMimeType() const {
  return this->mImpl->mime;
}

void FileDocumentContent::setMimeType(const std::string& mt) {
  this->mImpl->mime = mt; // TODO enforce to lower case on this input
  return;
}



} // end mlclient namespace
