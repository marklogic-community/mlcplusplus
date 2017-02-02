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
    mimeType = IDocumentContent::MIME_JSON;
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

std::istream* GenericTextDocumentContent::getStream() const {
  TIMED_FUNC(GenericTextDocumentContent_getStream);
  std::istringstream* os = new std::istringstream(*(mImpl->content));
  //std::ostringstream* os = new std::ostringstream;
  //(*os) << mImpl->content.get();
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
  Impl(std::string f) : file(f), mime(IDocumentContent::MIME_JSON), fs(), mimeMap() {

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
    mimeMap.insert(std::make_pair(XML, IDocumentContent::MIME_XML));
    mimeMap.insert(std::make_pair(JSON, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(TXT, IDocumentContent::MIME_TXT));
    mimeMap.insert(std::make_pair(JPG, IDocumentContent::MIME_JPG));
    mimeMap.insert(std::make_pair(PNG, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(GIF, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(DOC, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(DOCX, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(PPT, IDocumentContent::MIME_JSON));
    mimeMap.insert(std::make_pair(PPTX, IDocumentContent::MIME_JSON));

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

std::istream* FileDocumentContent::getStream() const {
  std::ifstream* is = new std::ifstream(mImpl->file, std::ifstream::in);
  //std::string str(getContent());
  //std::ostringstream* os = new std::ostringstream;
  //(*os) << str;
  return is;
}

std::string FileDocumentContent::getContent() const {
  LOG(DEBUG) << "FileDocumentContent::getContent() entered";
  mImpl->fs.open(mImpl->file,std::fstream::in);
  std::string str;

  mImpl->fs.seekg(0, std::ios::end);
  str.reserve(mImpl->fs.tellg());
  mImpl->fs.seekg(0, std::ios::beg);

  str.assign((std::istreambuf_iterator<char>(mImpl->fs)),
             (std::istreambuf_iterator<char>()));

  mImpl->fs.close();

  LOG(DEBUG) << "FileDocumentContent::getContent() returning: " << str;

  return str;
}

std::string FileDocumentContent::getMimeType() const {
  return mImpl->mime;
}

void FileDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mime = mt; // TODO enforce to lower case on this input
}



} // end mlclient namespace
