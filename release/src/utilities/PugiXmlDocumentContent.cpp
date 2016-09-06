/*
 * PugiXmlDocumentContent.cpp
 *
 *  Created on: 30 Jul 2016
 *      Author: adamfowler
 */

#include <mlclient/utilities/PugiXmlDocumentContent.hpp>
#include <mlclient/logging.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <mlclient/ext/pugixml/pugixml.hpp>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <regex>

namespace mlclient {

namespace utilities {


const std::regex RE_INTEGER("^[0-9]+$");
const std::regex RE_DOUBLE("^[0-9]+\\.[0-9]+$");

PugiXmlContainerNode::PugiXmlContainerNode() {
  ;
}
PugiXmlContainerNode::~PugiXmlContainerNode() {
  ;
}

bool PugiXmlContainerNode::isNull() const {
  return false;
}
bool PugiXmlContainerNode::isBoolean() const {
  return false;
}
bool PugiXmlContainerNode::isInteger() const {
  return false;
}
bool PugiXmlContainerNode::isDouble() const {
  return false;
}
bool PugiXmlContainerNode::isString() const {
  return false;
}

bool PugiXmlContainerNode::asBoolean() const {
  throw new mlclient::InvalidFormatException("XML Container is not a boolean");
}
int32_t PugiXmlContainerNode::asInteger() const {
  throw new mlclient::InvalidFormatException("XML Container is not a integer");
}
double PugiXmlContainerNode::asDouble() const {
  throw new mlclient::InvalidFormatException("XML Container is not a double");
}
std::string PugiXmlContainerNode::asString() const {
  throw new mlclient::InvalidFormatException("XML Container is not a string");
}

class PugiXmlArrayNode::Impl {
public:
  Impl(const pugi::xml_node& parent,const std::string& key) : parent(parent), key(key) {
    ;
  };

  pugi::xml_node parent;
  std::string key;
};

PugiXmlArrayNode::PugiXmlArrayNode(const pugi::xml_node& parent,const std::string& key) : mImpl(new Impl(parent,key)) {
  ;
}
PugiXmlArrayNode::~PugiXmlArrayNode() {
  delete mImpl;
  mImpl = NULL;
}
bool PugiXmlArrayNode::isArray() const {
  return true;
}
bool PugiXmlArrayNode::isObject() const {
  return false;
}

IDocumentNode* PugiXmlArrayNode::asArray() const {
  return (IDocumentNode*)const_cast<PugiXmlArrayNode*>(this);
}
IDocumentNode* PugiXmlArrayNode::asObject() const {
  throw mlclient::InvalidFormatException("JSON Container is not an object");
}

IDocumentNode* PugiXmlArrayNode::at(const std::string& key) const {
  throw mlclient::InvalidFormatException("JSON Container Array does not support string key subscripts");
}
IDocumentNode* PugiXmlArrayNode::at(const int32_t idx) const {
  const auto& children = mImpl->parent.children(mImpl->key.c_str());
  pugi::xml_named_node_iterator iter = children.begin();
  const auto& end = children.end();
  int32_t i = 0;
  for (;i <= idx && iter != end;++iter) {
    if (i == idx) {
      return new PugiXmlDocumentNode(*iter);
    }
    i++;
  }
  return nullptr;
}



class PugiXmlObjectNode::Impl {
public:
  Impl(const pugi::xml_node& obj) : obj(obj) {
    ;
  };

  pugi::xml_node obj;
};

PugiXmlObjectNode::PugiXmlObjectNode(const pugi::xml_node& obj) : mImpl(new Impl(obj)) {
  ;
}
PugiXmlObjectNode::~PugiXmlObjectNode() {
  delete mImpl;
  mImpl = NULL;
}
bool PugiXmlObjectNode::isArray() const {
  return false;
}
bool PugiXmlObjectNode::isObject() const {
  return true;
}

IDocumentNode* PugiXmlObjectNode::asArray() const {
  throw mlclient::InvalidFormatException("JSON Container is not an array");
}
IDocumentNode* PugiXmlObjectNode::asObject() const {
  return (IDocumentNode*)const_cast<PugiXmlObjectNode*>(this);
}

IDocumentNode* PugiXmlObjectNode::at(const std::string& key) const {
  LOG(DEBUG) << "at(" << key << ") called on '" << mImpl->obj.name() << "' of type: " << mImpl->obj.type();
  return mlclient::utilities::createNode(mImpl->obj,key);
}
IDocumentNode* PugiXmlObjectNode::at(const int32_t idx) const {
  throw mlclient::InvalidFormatException("JSON Container Object does not support integer subscripts");
}







class PugiXmlDocumentNode::Impl {
public:
  Impl(const pugi::xml_node& root) : root(root) {
    ;
  };
  Impl(const pugi::xml_node& parent,const std::string& key) : root(parent.child(key.c_str())) {
    ;
  };

  pugi::xml_node root;
};


PugiXmlDocumentNode::PugiXmlDocumentNode(const pugi::xml_node& root) : mImpl(new Impl(std::move(root))) {
  LOG(DEBUG) << "PugiXmlDocumentNode::ctor for node named '" << root.name() << "'";
  LOG(DEBUG) << "  node text: " << root.text().get();
  LOG(DEBUG) << "  node impl text: " << mImpl->root.text().get();
  ;
}
PugiXmlDocumentNode::PugiXmlDocumentNode(const pugi::xml_node& root,const std::string& key) : mImpl(new Impl(root,key)) {
  LOG(DEBUG) << "PugiXmlDocumentNode::ctor(node,key) for node named '" << root.name() << "'";
  LOG(DEBUG) << "  node text: " << root.text().get();
  ;
}


PugiXmlDocumentNode::PugiXmlDocumentNode(PugiXmlDocumentNode&& from) : mImpl(from.mImpl) {
  from.mImpl = NULL;
}

PugiXmlDocumentNode::~PugiXmlDocumentNode() {
  delete mImpl;
  mImpl = NULL;
}

bool PugiXmlDocumentNode::isNull() const {
  return mImpl->root.type() == pugi::xml_node_type::node_null;
}
bool PugiXmlDocumentNode::isBoolean() const {
  return strcmp(mImpl->root.text().get(),"true")==0 || strcmp(mImpl->root.text().get(),"True")==0 || strcmp(mImpl->root.text().get() , "TRUE") == 0;
}
bool PugiXmlDocumentNode::isInteger() const {
  std::smatch matches;
  std::string str(mImpl->root.text().get());
  return std::regex_search(str,matches, RE_INTEGER);
}
bool PugiXmlDocumentNode::isDouble() const {
  std::smatch matches;
  std::string str(mImpl->root.text().get());
  return std::regex_search(str,matches, RE_DOUBLE);
}
bool PugiXmlDocumentNode::isString() const {
  return !isInteger() && !isDouble() && !isBoolean() && strcmp(mImpl->root.text().get(),"") != 0; // nasty hack
}
bool PugiXmlDocumentNode::isArray() const {
  return false;
}
bool PugiXmlDocumentNode::isObject() const {
  //bool isObj = !isInteger() && !isDouble() && !isBoolean() && (mImpl->root.type() == pugi::xml_node_type::node_element || mImpl->root.type() == pugi::xml_node_type::node_document);
  //LOG(DEBUG) << "isObject() result for '" << mImpl->root.name() << "'?: " << isObj;
  //return isObj;
  return false;
}

bool PugiXmlDocumentNode::asBoolean() const {
  return mImpl->root.text().as_bool();
}
int32_t PugiXmlDocumentNode::asInteger() const {
  return mImpl->root.text().as_int();
}
double PugiXmlDocumentNode::asDouble() const {
  return mImpl->root.text().as_double();
}
std::string PugiXmlDocumentNode::asString() const {
  return mImpl->root.text().get();
}
IDocumentNode* PugiXmlDocumentNode::asArray() const {
  return nullptr;
}
IDocumentNode* PugiXmlDocumentNode::asObject() const {
  return nullptr;
}

IDocumentNode* PugiXmlDocumentNode::at(const std::string& key) const {
  return mlclient::utilities::createNode(mImpl->root,key);
}
IDocumentNode* PugiXmlDocumentNode::at(const int32_t idx) const {
  const auto& iter = mImpl->root.children().begin();
  const auto& end = mImpl->root.children().end();
  for (int32_t i = 0;i <= idx && iter != end;i++) {
    if (i == idx) {
      return new PugiXmlDocumentNode(*iter);
    }
  }
  return nullptr;
}


IDocumentNode* createNode(pugi::xml_node& parent,const std::string& key) {
  const auto& range = parent.children(key.c_str());
  if (range.begin() == range.end() || (++(range.begin())) == range.end()) {
    // Could be an Object or a String
    bool isObject = false;
    pugi::xml_node child = parent.child(key.c_str());
    const auto& childRange = child.children();
    for (pugi::xml_node_iterator iter = childRange.begin();iter != childRange.end();++iter) {
      isObject = isObject || iter->type() == pugi::xml_node_type::node_element;
    }
    if (isObject) {
      LOG(DEBUG) << " This node is a Pugi XML object node (has one or more element children)";
      return new PugiXmlObjectNode(child);
    }
    LOG(DEBUG) << "Found an element with a single child of '" << key << "', creating PugiXmlDocumentNode...";
    return new PugiXmlDocumentNode(child);
  }
  // is an object if one or more children are themselves nodes
  LOG(DEBUG) << "Found an element with multiple children of '" << key << "', creating PugiXmlArrayNode...";
  for (pugi::xml_named_node_iterator iter = range.begin();iter != range.end();++iter) {
    LOG(DEBUG) << "  Child type: " << iter->type() << " name: " << iter->name();
  }
  // is array
  return new PugiXmlArrayNode(parent,key);
}





class PugiXmlDocumentNavigator::Impl {
public:
  Impl(const pugi::xml_document& root,bool firstElementAsRoot) : root(root), firstElementAsRoot(firstElementAsRoot) {
    ;
  };

  const pugi::xml_document& root;
  bool firstElementAsRoot;
};

PugiXmlDocumentNavigator::PugiXmlDocumentNavigator(const pugi::xml_document& root,bool firstElementAsRoot) : mImpl(new Impl(root,firstElementAsRoot)) {
  ;
}

PugiXmlDocumentNavigator::PugiXmlDocumentNavigator(PugiXmlDocumentNavigator&& from) : mImpl(from.mImpl) {
  from.mImpl = NULL;
}
PugiXmlDocumentNavigator::~PugiXmlDocumentNavigator() {
  if (NULL != mImpl) {
    delete mImpl;
    mImpl = NULL;
  }
}

IDocumentNode* PugiXmlDocumentNavigator::at(const std::string& key) const {
  if (!mImpl->firstElementAsRoot) {
    return new PugiXmlDocumentNode(mImpl->root.root().child(key.c_str()));
  }
  // else call child on the top level element
  const auto& range = mImpl->root.root().children();
  for (pugi::xml_node_iterator iter = range.begin();iter != range.end();++(iter)) {
    if (pugi::xml_node_type::node_element == iter->type()) {
      return new PugiXmlDocumentNode(iter->child(key.c_str()));
    }
  }
  return nullptr; // empty XML document

  //return new PugiXmlDocumentNode(mImpl->root.root(),key);
}








class PugiXmlDocumentContent::Impl {
public:
  Impl() : value(new pugi::xml_document) {
    TIMED_FUNC(PugiXmlDocumentContent_Impl_defaultConstructor);
  };
  ~Impl() {
    TIMED_FUNC(PugiXmlDocumentContent_Impl_destructor);
  };
  const pugi::xml_document* value;
  std::string mimeType;
};

PugiXmlDocumentContent::PugiXmlDocumentContent() : mImpl(new Impl) {
  TIMED_FUNC(PugiXmlDocumentContent_constructor);
}

PugiXmlDocumentContent::~PugiXmlDocumentContent() {
  TIMED_FUNC(PugiXmlDocumentContent_destructor);
  delete mImpl;
}

std::istream* PugiXmlDocumentContent::getStream() const {
  TIMED_FUNC(PugiXmlDocumentContent_getStream);
  std::ostringstream* os = new std::ostringstream;
  //(*os) << mImpl->value;
  mImpl->value->save(*os);
  std::istringstream* is = new std::istringstream(os->str());
  delete os;
  return is;
}

const pugi::xml_document& PugiXmlDocumentContent::getXml() const {
  TIMED_FUNC(PugiXmlDocumentContent_getJson);
  return *(mImpl->value);
}

void PugiXmlDocumentContent::setContent(const pugi::xml_document& xml) {
  TIMED_FUNC(PugiXmlDocumentContent_setContent);
  mImpl->value = &xml; // move constructor
}

std::string PugiXmlDocumentContent::getMimeType() const {
  return std::string(mImpl->mimeType); // forces copy constructor
}

void PugiXmlDocumentContent::setMimeType(const std::string& mt) {
  mImpl->mimeType = std::string(mt); // invokes copy constructor
}

int PugiXmlDocumentContent::getLength() const {
  return getContent().size();
}

void PugiXmlDocumentContent::setContent(std::string content) {
  TIMED_FUNC(PugiXmlDocumentContent_setContent);
  std::ostringstream os;
  os << content;
  pugi::xml_document* doc = new pugi::xml_document;
  doc->load_string(os.str().c_str());
  mImpl->value = doc;
}

std::string PugiXmlDocumentContent::getContent() const {
  TIMED_FUNC(PugiXmlDocumentContent_getContent);
  std::ostringstream os;
  //os << mImpl->value;
  os << mImpl->value;
  return os.str();
}

IDocumentNavigator* PugiXmlDocumentContent::navigate(bool firstElementAsRoot) const {
  return new PugiXmlDocumentNavigator(*(mImpl->value),firstElementAsRoot);
}


} // end utilities namespace

} // end mlclient namespace
