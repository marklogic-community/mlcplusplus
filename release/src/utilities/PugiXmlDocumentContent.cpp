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

IDocumentContent* PugiXmlContainerNode::getChildContent() const {
  throw new mlclient::InvalidFormatException("XML Container is not a string");
}






class PugiXmlArrayNode::Impl {
public:
  Impl(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& parent,const std::string& key) : doc(doc),parent(parent), key(key) {
    ;
  };
  std::shared_ptr<pugi::xml_document> doc;
  pugi::xml_node parent;
  std::string key;
};




PugiXmlArrayNode::PugiXmlArrayNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& parent,const std::string& key) : mImpl(new Impl(doc,parent,key)) {
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
  throw mlclient::InvalidFormatException("XML Array is not an object");
}

IDocumentNode* PugiXmlArrayNode::at(const std::string& key) const {
  throw mlclient::InvalidFormatException("XML Array does not support string key subscripts");
}
IDocumentNode* PugiXmlArrayNode::at(const int32_t idx) const {
  const auto& children = mImpl->parent.children(mImpl->key.c_str());
  pugi::xml_named_node_iterator iter = children.begin();
  const auto& end = children.end();
  int32_t i = 0;
  for (;i <= idx && iter != end;++iter) {
    if (i == idx) {
      return new PugiXmlDocumentNode(mImpl->doc,*iter);
    }
    i++;
  }
  return nullptr;
}

StringList PugiXmlArrayNode::keys() const {
  throw mlclient::InvalidFormatException("XML Array does not support string key subscripts");
}

int32_t PugiXmlArrayNode::size() const {
  const auto& children = mImpl->parent.children(mImpl->key.c_str());
  pugi::xml_named_node_iterator iter = children.begin();
  const auto& end = children.end();
  int32_t i = 0;
  for (;iter != end;++iter) {
    i++;
  }
  return i;
}



class PugiXmlObjectNode::Impl {
public:
  Impl(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& obj) : doc(doc),obj(obj) {
    ;
  };

  std::shared_ptr<pugi::xml_document> doc;
  pugi::xml_node obj;
};

PugiXmlObjectNode::PugiXmlObjectNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& obj) : mImpl(new Impl(doc,obj)) {
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
  throw mlclient::InvalidFormatException("XML Container is not an array");
}
IDocumentNode* PugiXmlObjectNode::asObject() const {
  return (IDocumentNode*)const_cast<PugiXmlObjectNode*>(this);
}

IDocumentNode* PugiXmlObjectNode::at(const std::string& key) const {
  LOG(DEBUG) << "at(" << key << ") called on '" << mImpl->obj.name() << "' of type: " << mImpl->obj.type();
  return mlclient::utilities::createNode(mImpl->doc,mImpl->obj,key); // TODO ensure this returns attributes and not just elements
}
IDocumentNode* PugiXmlObjectNode::at(const int32_t idx) const {
  throw mlclient::InvalidFormatException("XML Container Object does not support integer subscripts");
}

StringList PugiXmlObjectNode::keys() const {
  StringList names;
  const auto& children = mImpl->obj.children();
  pugi::xml_node_iterator iter = children.begin();
  const auto& end = children.end();
  for (;iter != end;++iter) {
    names.push_back(iter->name());
  }
  const auto& attrs = mImpl->obj.attributes();
  pugi::xml_attribute_iterator atIter = attrs.begin();
  const auto& atEnd = attrs.end();
  for (;atIter != atEnd;++atIter) {
    names.push_back(atIter->name());
  }
  return names;
}

int32_t PugiXmlObjectNode::size() const {
  throw mlclient::InvalidFormatException("XML Container Object does not support integer subscripts");
}

IDocumentContent* PugiXmlObjectNode::getChildContent() const {
  PugiXmlDocumentContent* ct = new PugiXmlDocumentContent;
  
  std::ostringstream oss;
  mImpl->obj.print(oss);
  std::shared_ptr<pugi::xml_document> newDoc = std::make_shared<pugi::xml_document>();
  newDoc->load_string(oss.str().c_str());
  
  ct->setContent(newDoc);

  return ct;
}






class PugiXmlAttributeNode::Impl {
  public:
  Impl(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_attribute& attr) : doc(doc),attr(attr) {
    ;
  };

  std::shared_ptr<pugi::xml_document> doc;
  pugi::xml_attribute attr;
};


PugiXmlAttributeNode::PugiXmlAttributeNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_attribute& attr) : mImpl(new Impl(doc,attr)) {
  ;
}

PugiXmlAttributeNode::~PugiXmlAttributeNode() {
  delete mImpl;
  mImpl = NULL;
}
bool PugiXmlAttributeNode::isNull() const {
  return strcmp(mImpl->attr.as_string(),"")==0;
}
bool PugiXmlAttributeNode::isBoolean() const {
  return strcmp(mImpl->attr.as_string(),"true")==0 || strcmp(mImpl->attr.as_string(),"True")==0 || strcmp(mImpl->attr.as_string() , "TRUE") == 0;
}
bool PugiXmlAttributeNode::isInteger() const {
  std::smatch matches;
  std::string str(mImpl->attr.as_string());
  return std::regex_search(str,matches, RE_INTEGER);
}
bool PugiXmlAttributeNode::isDouble() const {
  std::smatch matches;
  std::string str(mImpl->attr.as_string());
  return std::regex_search(str,matches, RE_DOUBLE);
}
bool PugiXmlAttributeNode::isString() const {
  return !isInteger() && !isDouble() && !isBoolean() && strcmp(mImpl->attr.as_string(),"") != 0; // nasty hack
}
bool PugiXmlAttributeNode::isArray() const {
  return false;
}
bool PugiXmlAttributeNode::isObject() const {
  //bool isObj = !isInteger() && !isDouble() && !isBoolean() && (mImpl->root.type() == pugi::xml_node_type::node_element || mImpl->root.type() == pugi::xml_node_type::node_document);
  //LOG(DEBUG) << "isObject() result for '" << mImpl->root.name() << "'?: " << isObj;
  //return isObj;
  return false;
}

bool PugiXmlAttributeNode::asBoolean() const {
  return mImpl->attr.as_bool();
}
int32_t PugiXmlAttributeNode::asInteger() const {
  return mImpl->attr.as_int();
}
double PugiXmlAttributeNode::asDouble() const {
  return mImpl->attr.as_double();
}
std::string PugiXmlAttributeNode::asString() const {
  return mImpl->attr.as_string();
}
IDocumentNode* PugiXmlAttributeNode::asArray() const {
  return nullptr;
}
IDocumentNode* PugiXmlAttributeNode::asObject() const {
  return nullptr;
}

IDocumentNode* PugiXmlAttributeNode::at(const std::string& key) const {
  throw mlclient::InvalidFormatException("XML attribute Object does not support string subscripts");
}
IDocumentNode* PugiXmlAttributeNode::at(const int32_t idx) const {
  throw mlclient::InvalidFormatException("XML attribute Object does not support integer subscripts");
}

StringList PugiXmlAttributeNode::keys() const {
  StringList names;
  return names;
}

int32_t PugiXmlAttributeNode::size() const {
  throw mlclient::InvalidFormatException("XML attribute Object does not support integer subscripts");
}

IDocumentContent* PugiXmlAttributeNode::getChildContent() const {
  throw mlclient::InvalidFormatException("XML attribute Object does not support child content");
}






class PugiXmlDocumentNode::Impl {
public:
  Impl(std::shared_ptr<pugi::xml_document> own_doc,const pugi::xml_node& root) : doc(own_doc),root(root) {
    ;
  };
  Impl(std::shared_ptr<pugi::xml_document> own_doc,const pugi::xml_node& parent,const std::string& key) : doc(own_doc),root(parent.child(key.c_str())) {
    ;
  };

  pugi::xml_node root;
  std::shared_ptr<pugi::xml_document> doc;
};


PugiXmlDocumentNode::PugiXmlDocumentNode(std::shared_ptr<pugi::xml_document> own_doc,const pugi::xml_node& root) : mImpl(new Impl(own_doc,root)) {
  LOG(DEBUG) << "PugiXmlDocumentNode::ctor for node named '" << root.name() << "'";
  LOG(DEBUG) << "  node text: " << root.text().get();
  LOG(DEBUG) << "  node impl text: " << mImpl->root.text().get();
  ;
}
PugiXmlDocumentNode::PugiXmlDocumentNode(std::shared_ptr<pugi::xml_document> own_doc,const pugi::xml_node& root,const std::string& key) : mImpl(new Impl(own_doc,root,key)) {
  LOG(DEBUG) << "PugiXmlDocumentNode::ctor(node,key) for node named '" << root.name() << "'";
  LOG(DEBUG) << "  node text: " << root.text().get();
  ;
}


PugiXmlDocumentNode::PugiXmlDocumentNode(PugiXmlDocumentNode&& from) : mImpl(from.mImpl) {
  LOG(DEBUG) << "PugiXmlDocumentNode::copy ctor";
  from.mImpl = NULL;
}

PugiXmlDocumentNode::~PugiXmlDocumentNode() {
  if (NULL != mImpl) {
    delete mImpl;
  }
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
  return mlclient::utilities::createNode(mImpl->doc,mImpl->root,key);
}
IDocumentNode* PugiXmlDocumentNode::at(const int32_t idx) const {
  const auto& iter = mImpl->root.children().begin();
  const auto& end = mImpl->root.children().end();
  for (int32_t i = 0;i <= idx && iter != end;i++) {
    if (i == idx) {
      return new PugiXmlDocumentNode(mImpl->doc,*iter);
    }
  }
  return nullptr;
}

StringList PugiXmlDocumentNode::keys() const {
  // return XML element names and attribute names in a vector (StringList)
    StringList names;
    const auto& children = mImpl->root.children();
    pugi::xml_node_iterator iter = children.begin();
    const auto& end = children.end();
    for (;iter != end;++iter) {
      names.push_back(iter->name());
    }
    const auto& attrs = mImpl->root.attributes();
    pugi::xml_attribute_iterator atIter = attrs.begin();
    const auto& atEnd = attrs.end();
    for (;atIter != atEnd;++atIter) {
      names.push_back(atIter->name());
    }
    return names;
}
int32_t PugiXmlDocumentNode::size() const {
  throw mlclient::InvalidFormatException("XML Document Object does not support integer subscripts");
}

IDocumentContent* PugiXmlDocumentNode::getChildContent() const {
  PugiXmlDocumentContent* ct = new PugiXmlDocumentContent;
  
  std::ostringstream oss;
  mImpl->root.print(oss);
  std::shared_ptr<pugi::xml_document> newDoc = std::make_shared<pugi::xml_document>();
  newDoc->load_string(oss.str().c_str());
  ct->setContent(newDoc);
  
  //ct->setContent(mImpl->root.root());

  return ct;
}



IDocumentNode* createNode(std::shared_ptr<pugi::xml_document> doc,pugi::xml_node& parent,const std::string& key) {
  LOG(DEBUG) << "Trying to find child node or element named: " << key;
  const auto& range = parent.children(key.c_str());
  if (range.begin() == range.end() || (++(range.begin())) == range.end()) {
    // Could be an Object or a String
    bool isObject = false;
    pugi::xml_node child = parent.child(key.c_str());
    if (NULL != child) {
      const auto& childRange = child.children();
      for (pugi::xml_node_iterator iter = childRange.begin();iter != childRange.end();++iter) {
        isObject = isObject || iter->type() == pugi::xml_node_type::node_element;
      }
      if (isObject) {
        LOG(DEBUG) << " This node is a Pugi XML object node (has one or more element children)";
        return new PugiXmlObjectNode(doc,child);
      }
      LOG(DEBUG) << "Found an element with a single child of '" << key << "', creating PugiXmlDocumentNode...";
      return new PugiXmlDocumentNode(doc,child);
    } else {
      LOG(DEBUG) << "No child with name '" << key << "'";
    }
  }
  // May not have been found - check attributes
  const auto& attr = parent.attribute(key.c_str());
  if (NULL != attr) {
    LOG(DEBUG) << "Found an XML attribute";
    return new PugiXmlAttributeNode(doc,attr);
  }
  // is an object if one or more children are themselves nodes
  LOG(DEBUG) << "Found an element with multiple children of '" << key << "', creating PugiXmlArrayNode...";
  //for (pugi::xml_named_node_iterator iter = range.begin();iter != range.end();++iter) {
  //  LOG(DEBUG) << "  Child type: " << iter->type() << " name: " << iter->name();
  //}
  // is array
  return new PugiXmlArrayNode(doc,parent,key);
}





class PugiXmlDocumentNavigator::Impl {
public:
  Impl(std::shared_ptr<pugi::xml_document> root,bool firstElementAsRoot) : root(root), firstElementAsRoot(firstElementAsRoot) {
    ;
  };

  std::shared_ptr<pugi::xml_document> root;
  bool firstElementAsRoot;
};

PugiXmlDocumentNavigator::PugiXmlDocumentNavigator(std::shared_ptr<pugi::xml_document> root,bool firstElementAsRoot) : mImpl(new Impl(root,firstElementAsRoot)) {
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

IDocumentNode* PugiXmlDocumentNavigator::firstChild() const {
  if (!mImpl->firstElementAsRoot) {
    return new PugiXmlDocumentNode(mImpl->root,mImpl->root->root().first_child());
  }
  return new PugiXmlDocumentNode(mImpl->root,mImpl->root->root().first_child().first_child());
}

IDocumentNode* PugiXmlDocumentNavigator::at(const std::string& key) const {
  if (!mImpl->firstElementAsRoot) {
    return new PugiXmlDocumentNode(mImpl->root,mImpl->root->root().child(key.c_str()));
  }
  // else call child on the top level element
  const auto& range = mImpl->root->children();
  int childCount = 0;
  for (pugi::xml_node_iterator iter = range.begin();iter != range.end();++(iter)) {
    if (pugi::xml_node_type::node_element == iter->type()) {
      const pugi::xml_node& chNode = iter->child(key.c_str());
      if (NULL != chNode) {
        childCount++;
        while (NULL != (const_cast<pugi::xml_node&>(chNode) = chNode.next_sibling(key.c_str()))) {
          childCount++;
        }
      }
    }
  }
  LOG(DEBUG) << "Child element count for " << key << " is " << childCount;
  if (1 == childCount) {
    return new PugiXmlDocumentNode(mImpl->root,range.begin()->child(key.c_str()));
  } else if (childCount > 1) {
    return new PugiXmlArrayNode(mImpl->root,mImpl->root->first_child(),key);
  }
  const pugi::xml_attribute& attr = mImpl->root->first_child().attribute(key.c_str());
  if (NULL != attr) {
    LOG(DEBUG) << "Found attribute under root document element";
    return new PugiXmlAttributeNode(mImpl->root,attr);
  }
  return nullptr; // empty XML document

  //return new PugiXmlDocumentNode(mImpl->root.root(),key);
}








class PugiXmlDocumentContent::Impl {
public:
  Impl() : value(std::make_shared<pugi::xml_document>()), mimeType(IDocumentContent::MIME_XML) {
    TIMED_FUNC(PugiXmlDocumentContent_Impl_defaultConstructor);
  };
  ~Impl() {
    TIMED_FUNC(PugiXmlDocumentContent_Impl_destructor);
  };
  std::shared_ptr<pugi::xml_document> value;
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

void PugiXmlDocumentContent::setContent(std::shared_ptr<pugi::xml_document> xml) {
  TIMED_FUNC(PugiXmlDocumentContent_setContent);
  mImpl->value = xml; // move constructor
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
  std::shared_ptr<pugi::xml_document> doc = std::make_shared<pugi::xml_document>();
  doc->load_string(os.str().c_str());
  mImpl->value = std::move(doc);
}

std::string PugiXmlDocumentContent::getContent() const {
  TIMED_FUNC(PugiXmlDocumentContent_getContent);
  std::ostringstream os;
  //os << mImpl->value;
  os << *(mImpl->value);
  return os.str();
}

IDocumentNavigator* PugiXmlDocumentContent::navigate(bool firstElementAsRoot) const {
  std::shared_ptr<pugi::xml_document> doc = std::make_shared<pugi::xml_document>();
  //doc.append_copy(mImpl->value);
  /*
  for (pugi::xml_node child = mImpl->value.first_child(); child; child = child.next_sibling()) {
    doc.append_copy(child);
  }
  */
  std::ostringstream oss;
  mImpl->value->print(oss);
  doc->load_string(oss.str().c_str());
  return new PugiXmlDocumentNavigator(doc,firstElementAsRoot);
}


} // end utilities namespace

} // end mlclient namespace
