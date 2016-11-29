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
 * PugiXmlDocumentContent.hpp
 *
 *  Created on: 30 Jul 2016
 *      Author: adamfowler
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_PUGIXMLDOCUMENTCONTENT_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_PUGIXMLDOCUMENTCONTENT_HPP_


#include <mlclient/mlclient.hpp>
#include <mlclient/DocumentContent.hpp>
#include <mlclient/ext/pugixml/pugixml.hpp>

namespace mlclient {

namespace utilities {

/**
 * \brief Document Traversal API generic container for Pugi XML
 *
 * See IDocumentNode for details.
 *
 * \since 8.0.2
 */
class PugiXmlContainerNode : public IDocumentNode {
public:
  MLCLIENT_API PugiXmlContainerNode();
  MLCLIENT_API virtual ~PugiXmlContainerNode();

  MLCLIENT_API bool isNull() const override;
  MLCLIENT_API bool isBoolean() const override;
  MLCLIENT_API bool isInteger() const override;
  MLCLIENT_API bool isDouble() const override;
  MLCLIENT_API bool isString() const override;

  MLCLIENT_API bool asBoolean() const override;
  MLCLIENT_API int32_t asInteger() const override;
  MLCLIENT_API double asDouble() const override;
  MLCLIENT_API std::string asString() const override;
  MLCLIENT_API IDocumentContent* getChildContent() const override;
};

/**
 * \brief Document Traversal API array container for Pugi XML
 *
 * See IDocumentNode for details.
 *
 * \since 8.0.2
 */
class PugiXmlArrayNode : public PugiXmlContainerNode {
public:
  MLCLIENT_API PugiXmlArrayNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& parent,const std::string& key);
  MLCLIENT_API virtual ~PugiXmlArrayNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \brief Document Traversal API Object container for Pugi XML
 *
 * See IDocumentNode for details.
 *
 * \since 8.0.2
 */
class PugiXmlObjectNode : public PugiXmlContainerNode {
public:
  MLCLIENT_API PugiXmlObjectNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& root);
  MLCLIENT_API virtual ~PugiXmlObjectNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;

  MLCLIENT_API IDocumentContent* getChildContent() const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

class PugiXmlAttributeNode : public PugiXmlContainerNode {
  public:
  MLCLIENT_API PugiXmlAttributeNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_attribute& attr);
  MLCLIENT_API virtual ~PugiXmlAttributeNode();

  MLCLIENT_API bool isNull() const override;
  MLCLIENT_API bool isBoolean() const override;
  MLCLIENT_API bool isInteger() const override;
  MLCLIENT_API bool isDouble() const override;
  MLCLIENT_API bool isString() const override;
  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API bool asBoolean() const override;
  MLCLIENT_API int32_t asInteger() const override;
  MLCLIENT_API double asDouble() const override;
  MLCLIENT_API std::string asString() const override;
  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;

  MLCLIENT_API IDocumentContent* getChildContent() const override;

  private:
    class Impl;
    Impl* mImpl;
};

/**
 * \class PugiXmlDocumentNode
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief Represents a Node within a pugi::xml::document instance.
 */
class PugiXmlDocumentNode : public IDocumentNode {
public:
  MLCLIENT_API PugiXmlDocumentNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& result);
  MLCLIENT_API PugiXmlDocumentNode(std::shared_ptr<pugi::xml_document> doc,const pugi::xml_node& root,const std::string& key);
  MLCLIENT_API PugiXmlDocumentNode(PugiXmlDocumentNode&& from);
  MLCLIENT_API virtual ~PugiXmlDocumentNode();

  MLCLIENT_API bool isNull() const override;
  MLCLIENT_API bool isBoolean() const override;
  MLCLIENT_API bool isInteger() const override;
  MLCLIENT_API bool isDouble() const override;
  MLCLIENT_API bool isString() const override;
  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API bool asBoolean() const override;
  MLCLIENT_API int32_t asInteger() const override;
  MLCLIENT_API double asDouble() const override;
  MLCLIENT_API std::string asString() const override;
  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;

  MLCLIENT_API IDocumentContent* getChildContent() const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \brief Helper method to create an IDocumentNode instance from a pugi xml document node instance, and the name of its child.
 *
 * \param parent The parent PUGI XML node instance
 * \param key The name of the child key underneath the node provided
 * \return The IDocumentNode pointer instance (caller OWNS and must delete this instance)
 */
IDocumentNode* createNode(std::shared_ptr<pugi::xml_document> doc,pugi::xml_node& parent,const std::string& key);


/**
 * \class PugiXmlDocumentNavigator
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief Provides a navigator interface over a PugiXmlDocumentContent's root pugi::xml_document instance.
 */
class PugiXmlDocumentNavigator : public IDocumentNavigator {
public:
  /**
   * \brief Creates a Pugi XML based Document Navigator for the Document Traversal API
   *
   * \param root The PUGI XML document to wrap
   * \param firstElementAsRoot Whether to start with the root (document) element (false) or the first actual node element (true)
   */
  PugiXmlDocumentNavigator(std::shared_ptr<pugi::xml_document> doc,bool firstElementAsRoot = false);
  /**
   * \brief Move constructor for moving ownership of this instance.
   *
   * \param from The object instance to move the ownership of resources from
   */
  MLCLIENT_API PugiXmlDocumentNavigator(PugiXmlDocumentNavigator&& from);
  /**
   * \brief Pugi XML destructor
   */
  virtual ~PugiXmlDocumentNavigator();

  /**
   * \brief Returns the first child node of this node
   * 
   * Useful to fetch the immediate child, no matter its name
   *
   * \return The first child node below the root node. nullptr if it doesn't exist
   */
  MLCLIENT_API IDocumentNode* firstChild() const override;

  /**
   * \brief Returns the IDocumentNode at the specified key location
   *
   * See IDocumentNavigator for details.
   *
   * \param key The name of the node to return
   * \return The node at that named location. nullptr if it doesn't exist
   */
  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;

private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \class PugiXmlDocumentContent
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief An ITextDocumentContent instance that wraps a pugixml xml_parse object. (Derived from pugi::xml_document)
 *
 * Used by the PugiXmlHelper class
 *
 * \note This class has an internal dependency on the pugixml API. As this API is shipped within MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class PugiXmlDocumentContent : public ITextDocumentContent {
public:
  /**
   * \brief Default constructor
   */
  MLCLIENT_API PugiXmlDocumentContent();
  /**
   * \brief Virtual destructor to allow subclassing
   */
  MLCLIENT_API virtual ~PugiXmlDocumentContent();

  /// \name pugixmldocumentcontent_overrides Overridden functions from base class
  /// @{
  /**
   * \brief Sets the content of this document instance from a pugixml xml_document instance.
   *
   * \param json The pugixml xml_document instance to copy
   */
  MLCLIENT_API void setContent(std::shared_ptr<pugi::xml_document> xml);

  /**
   * \brief Returns the content of this ITextDocumentContent as an istream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An istream instance wrapping the content of this Text Document Content instance
   */
  MLCLIENT_API std::istream* getStream() const override;

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  MLCLIENT_API void setContent(std::string content) override;

  /**
   * \brief Returns the content as a string
   *
   * \return The string representation of the content.
   */
  MLCLIENT_API std::string getContent() const override;

  /**
   * \brief Returns the MIME type of this content.
   *
   * E.g. application/xml or similar form
   *
   * \return The string representation of the MIME type. Does not include encoding (always assume UTF-8 for MarkLogic Server)
   */
  MLCLIENT_API std::string getMimeType() const override;

  /**
   * \brief Sets the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \param[in] mt The mimetype string, not including encoding, for this Document Content. Assume always UTF-8 for MarkLogic Server)
   */
  MLCLIENT_API void setMimeType(const std::string& mt) override;


  /**
   * \brief Returns the number of characters in the content string.
   *
   * \note This number does not include C null characters - just std::string length
   *
   * \return The number of characters in the string. Does not include C null character.
   */
  MLCLIENT_API int getLength() const override;


  /**
   * \brief Returns an IDocumentNavigator instance, as per the Document Traversal API
   *
   * \param firstElementAsRoot Whether the root XML element is the Document node (false) or the first full XML element (true).
   * \return The IDocumentNavigator instance (caller OWNS the pointer, this class does not delete it)
   */
  MLCLIENT_API IDocumentNavigator* navigate(bool firstElementAsRoot = false) const override;

  /// @}

  /// \name pugixmldocumentcontent_functions These functions are new to this subclass.
  /// @{
  /**
   * \brief Returns the underlying pugixml xml_document object.
   *
   * \return The underlying pugixml xml_document object.
   */
  MLCLIENT_API const pugi::xml_document& getXml() const;
  /// @}

private:
  class Impl; // forward declaration
  Impl* mImpl;

};

} // end utilities namespace

} // end mlclient namespace




#endif /* INCLUDE_MLCLIENT_UTILITIES_PUGIXMLDOCUMENTCONTENT_HPP_ */
