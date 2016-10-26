/**
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
 * \file CppRestJsonDocumentContent.cpp
 * \since 8.0.0
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Implements a JSON document content instance for use with Microsoft's cpprest API
 * \date 2016-05-01
 */

#include <cpprest/json.h>
#include <mlclient/utilities/CppRestJsonDocumentContent.hpp>
#include <mlclient/logging.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <iostream>
#include <string>
#include <sstream>

namespace mlclient {

namespace utilities {

CppRestJsonContainerNode::CppRestJsonContainerNode() {
  ;
}
CppRestJsonContainerNode::~CppRestJsonContainerNode() {
  ;
}

bool CppRestJsonContainerNode::isNull() const {
  return false;
}
bool CppRestJsonContainerNode::isBoolean() const {
  return false;
}
bool CppRestJsonContainerNode::isInteger() const {
  return false;
}
bool CppRestJsonContainerNode::isDouble() const {
  return false;
}
bool CppRestJsonContainerNode::isString() const {
  return false;
}

bool CppRestJsonContainerNode::asBoolean() const {
  throw new mlclient::InvalidFormatException("JSON Container is not a boolean");
}
int32_t CppRestJsonContainerNode::asInteger() const {
  throw new mlclient::InvalidFormatException("JSON Container is not a integer");
}
double CppRestJsonContainerNode::asDouble() const {
  throw new mlclient::InvalidFormatException("JSON Container is not a double");
}
std::string CppRestJsonContainerNode::asString() const {
  throw new mlclient::InvalidFormatException("JSON Container is not a string");
}

class CppRestJsonArrayNode::Impl {
public:
  Impl(web::json::array& arr) : array(arr) {
    ;
  };

  web::json::array& array;
};

CppRestJsonArrayNode::CppRestJsonArrayNode(web::json::array& arr) : mImpl(new Impl(arr)) {
  ;
}
CppRestJsonArrayNode::~CppRestJsonArrayNode() {
  delete mImpl;
  mImpl = NULL;
}
bool CppRestJsonArrayNode::isArray() const {
  return true;
}
bool CppRestJsonArrayNode::isObject() const {
  return false;
}

IDocumentNode* CppRestJsonArrayNode::asArray() const {
  return (IDocumentNode*)const_cast<CppRestJsonArrayNode*>(this);
}
IDocumentNode* CppRestJsonArrayNode::asObject() const {
  throw mlclient::InvalidFormatException("JSON Container is not an object");
}

IDocumentNode* CppRestJsonArrayNode::at(const std::string& key) const {
  throw mlclient::InvalidFormatException("JSON Container Array does not support string key subscripts");
}
IDocumentNode* CppRestJsonArrayNode::at(const int32_t idx) const {
  return new CppRestJsonDocumentNode(mImpl->array.at(idx));
}

StringList CppRestJsonArrayNode::keys() const {
  throw mlclient::InvalidFormatException("JSON Container Array does not support string key subscripts");
}
int32_t CppRestJsonArrayNode::size() const {
  return mImpl->array.size();
}


class CppRestJsonObjectNode::Impl {
public:
  Impl(web::json::object& obj) : obj(obj) {
    ;
  };

  web::json::object& obj;
};

CppRestJsonObjectNode::CppRestJsonObjectNode(web::json::object& obj) : mImpl(new Impl(obj)) {
  ;
}
CppRestJsonObjectNode::~CppRestJsonObjectNode() {
  delete mImpl;
  mImpl = NULL;
}
bool CppRestJsonObjectNode::isArray() const {
  return false;
}
bool CppRestJsonObjectNode::isObject() const {
  return true;
}

IDocumentNode* CppRestJsonObjectNode::asArray() const {
  throw mlclient::InvalidFormatException("JSON Container is not an array");
}
IDocumentNode* CppRestJsonObjectNode::asObject() const {
  return (IDocumentNode*)const_cast<CppRestJsonObjectNode*>(this);
}

IDocumentNode* CppRestJsonObjectNode::at(const std::string& key) const {
  return new CppRestJsonDocumentNode(mImpl->obj.at(utility::conversions::to_string_t(key)));
}
IDocumentNode* CppRestJsonObjectNode::at(const int32_t idx) const {
  throw mlclient::InvalidFormatException("JSON Container Object does not support integer subscripts");
}

StringList CppRestJsonObjectNode::keys() const {
  StringList keys;
  for(auto iter = mImpl->obj.cbegin(); iter != mImpl->obj.cend(); ++iter) {
        // Make sure to get the value as const reference otherwise you will end up copying
        // the whole JSON value recursively which can be expensive if it is a nested object.
        //const json::value &str = iter->first;
        keys.push_back(utility::conversions::to_utf8string(iter->first)); // we do want a copy of the key, so this is fine
        //const json::value &v = iter->second;

        // Perform actions here to process each string and value in the JSON object...
        //std::wcout << L"String: " << str.as_string() << L", Value: " << v.to_string() << endl;
  }
  return keys;
}
int32_t CppRestJsonObjectNode::size() const {
  throw mlclient::InvalidFormatException("JSON Container Object does not support integer subscripts");
}






class CppRestJsonDocumentNode::Impl {
public:
  Impl(web::json::value& root) : root(root) {
    ;
  };

  web::json::value& root;
};


CppRestJsonDocumentNode::CppRestJsonDocumentNode(web::json::value& root) : mImpl(new Impl(root)) {
  std::ostringstream os;
  root.serialize(os);
  LOG(DEBUG) << "CppRestJsonDocumentNode:ctor node value: " << os.str();
  ;
}

CppRestJsonDocumentNode::CppRestJsonDocumentNode(CppRestJsonDocumentNode&& from) : mImpl(from.mImpl) {
  from.mImpl = NULL;
}

CppRestJsonDocumentNode::~CppRestJsonDocumentNode() {
  delete mImpl;
  mImpl = NULL;
}

bool CppRestJsonDocumentNode::isNull() const {
  return mImpl->root.is_null();
}
bool CppRestJsonDocumentNode::isBoolean() const {
  /*
  if (mImpl->root.is_boolean()) {
    LOG(DEBUG) << "CppRest library reports value IS a boolean";
    return true;
  }
  */
  if (!mImpl->root.is_string()) {
    return false;
  }
  std::string val(asString());
  return mImpl->root.is_string() && (("true" == val) || ("TRUE" == val) || ("True" == val));
}
bool CppRestJsonDocumentNode::isInteger() const {
  return mImpl->root.is_integer();
}
bool CppRestJsonDocumentNode::isDouble() const {
  return mImpl->root.is_double();
}
bool CppRestJsonDocumentNode::isString() const {
  if (!mImpl->root.is_string()) {
    return false;
  }
  std::string val(utility::conversions::to_utf8string(mImpl->root.as_string()));
  if ((("true" == val) || ("TRUE" == val) || ("True" == val))) {
    // boolean string
    return false;
  }
  return mImpl->root.is_string();
}
bool CppRestJsonDocumentNode::isArray() const {
  return mImpl->root.is_array();
}
bool CppRestJsonDocumentNode::isObject() const {
  return mImpl->root.is_object();
}

bool CppRestJsonDocumentNode::asBoolean() const {
  //return mImpl->root.as_bool();
  std::string val(asString());
  return ((("true" == val) || ("TRUE" == val) || ("True" == val)));
}
int32_t CppRestJsonDocumentNode::asInteger() const {
  return mImpl->root.as_integer();
}
double CppRestJsonDocumentNode::asDouble() const {
  return mImpl->root.as_double();
}
std::string CppRestJsonDocumentNode::asString() const {
  return utility::conversions::to_utf8string(mImpl->root.as_string());
}
IDocumentNode* CppRestJsonDocumentNode::asArray() const {
  return new CppRestJsonArrayNode(mImpl->root.as_array());
}
IDocumentNode* CppRestJsonDocumentNode::asObject() const {
  return new CppRestJsonObjectNode(mImpl->root.as_object());
}

IDocumentNode* CppRestJsonDocumentNode::at(const std::string& key) const {
  return new CppRestJsonDocumentNode(mImpl->root.at(utility::conversions::to_string_t(key)));
}
IDocumentNode* CppRestJsonDocumentNode::at(const int32_t idx) const {
  return new CppRestJsonDocumentNode(mImpl->root.at(idx));
}

StringList CppRestJsonDocumentNode::keys() const {
  web::json::object& obj = mImpl->root.as_object();
    StringList keys;
    for(auto iter = obj.cbegin(); iter != obj.cend(); ++iter) {
          // Make sure to get the value as const reference otherwise you will end up copying
          // the whole JSON value recursively which can be expensive if it is a nested object.
          //const json::value &str = iter->first;
          keys.push_back(utility::conversions::to_utf8string(iter->first)); // we do want a copy of the key, so this is fine
          //const json::value &v = iter->second;

          // Perform actions here to process each string and value in the JSON object...
          //std::wcout << L"String: " << str.as_string() << L", Value: " << v.to_string() << endl;
    }
    return keys;
}
int32_t CppRestJsonDocumentNode::size() const {
  throw mlclient::InvalidFormatException("JSON Document Object does not support integer subscripts");
}


class CppRestJsonDocumentNavigator::Impl {
public:
  Impl(web::json::value& root) : root(root) {
    ;
  };

  web::json::value& root;
};

CppRestJsonDocumentNavigator::CppRestJsonDocumentNavigator(web::json::value& root,bool firstElementAsRoot) : mImpl(new Impl(root)) {
  ;
}

CppRestJsonDocumentNavigator::CppRestJsonDocumentNavigator(CppRestJsonDocumentNavigator&& from) : mImpl(from.mImpl) {
  from.mImpl = NULL;
}
CppRestJsonDocumentNavigator::~CppRestJsonDocumentNavigator() {
  if (NULL != mImpl) {
    delete mImpl;
    mImpl = NULL;
  }
}

IDocumentNode* CppRestJsonDocumentNavigator::at(const std::string& key) const {
  return new CppRestJsonDocumentNode(mImpl->root.at(utility::conversions::to_string_t(key))); // uses move constructor
}


class CppRestJsonDocumentContent::Impl {
public:
  Impl() : value(web::json::value()) {
    TIMED_FUNC(CppRestJsonDocumentContent_Impl_defaultConstructor);
  };
  ~Impl() {
    TIMED_FUNC(CppRestJsonDocumentContent_Impl_destructor);
  };
  web::json::value value;
  std::string mimeType;
};

CppRestJsonDocumentContent::CppRestJsonDocumentContent() : mImpl(new Impl) {
  TIMED_FUNC(CppRestJsonDocumentContent_constructor);
}

CppRestJsonDocumentContent::~CppRestJsonDocumentContent() {
  TIMED_FUNC(CppRestJsonDocumentContent_destructor);
  delete mImpl;
}

std::istream* CppRestJsonDocumentContent::getStream() const {
  TIMED_FUNC(CppRestJsonDocumentContent_getStream);
  std::ostringstream* os = new std::ostringstream;
  //(*os) << mImpl->value;
  mImpl->value.serialize(*os);
  std::istringstream* is = new std::istringstream(os->str());
  delete os;
  return is;
}

const web::json::value& CppRestJsonDocumentContent::getJson() const {
  TIMED_FUNC(CppRestJsonDocumentContent_getJson);
  return mImpl->value;
}

void CppRestJsonDocumentContent::setContent(web::json::value& json) {
  TIMED_FUNC(CppRestJsonDocumentContent_setContent);
  mImpl->value = std::move(json); // move constructor
}

std::string CppRestJsonDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void CppRestJsonDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

int CppRestJsonDocumentContent::getLength() const {
  return getContent().size();
}

void CppRestJsonDocumentContent::setContent(std::string content) {
  TIMED_FUNC(CppRestJsonDocumentContent_setContent);
  std::ostringstream os;
  os << content;
  mImpl-> value = web::json::value::parse(utility::conversions::to_string_t(os.str()));
}

std::string CppRestJsonDocumentContent::getContent() const {
  TIMED_FUNC(CppRestJsonDocumentContent_getContent);
  std::ostringstream os;
  //os << mImpl->value;
  mImpl->value.serialize(os);
  return os.str();
}

IDocumentNavigator* CppRestJsonDocumentContent::navigate(bool firstElementAsRoot) const {
  return new CppRestJsonDocumentNavigator(mImpl->value,firstElementAsRoot);
}


} // end utilities namespace

} // end mlclient namespace
