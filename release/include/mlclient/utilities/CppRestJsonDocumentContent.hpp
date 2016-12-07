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
 * CppRestJsonDocumentContent.hpp
 *
 * \date 2016-05-01
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \brief Provides a convenience Json IDocumentContent wrapper for use with Microsoft's CPP REST API
 */

#ifndef SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_
#define SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_

#include <mlclient/mlclient.hpp>
#include <mlclient/DocumentContent.hpp>
#include <cpprest/json.h>

namespace mlclient {

namespace utilities {

/**
 * \brief Document Traversal API generic JSON wrapper for a Document
 *
 * See IDocumentNode for details
 *
 * \since 8.0.2
 * \date 2016-07-30
 */
class CppRestJsonContainerNode : public IDocumentNode {
public:
  MLCLIENT_API CppRestJsonContainerNode();
  MLCLIENT_API virtual ~CppRestJsonContainerNode();

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
 * \brief Document Traversal API node for a JSON Array
 *
 * See IDocumentNode for details
 *
 * \since 8.0.2
 * \date 2016-07-30
 */
class CppRestJsonArrayNode : public CppRestJsonContainerNode {
public:
  MLCLIENT_API CppRestJsonArrayNode(web::json::array& root);
  MLCLIENT_API virtual ~CppRestJsonArrayNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;
  MLCLIENT_API bool has(const std::string& key) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};


/**
 * \brief Document Traversal API node for a JSON Object
 *
 * See IDocumentNode for details
 *
 * \since 8.0.2
 * \date 2016-07-30
 */
class CppRestJsonObjectNode : public CppRestJsonContainerNode {
public:
  MLCLIENT_API CppRestJsonObjectNode(web::json::object& root);
  MLCLIENT_API virtual ~CppRestJsonObjectNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;
  MLCLIENT_API bool has(const std::string& key) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;

  MLCLIENT_API IDocumentContent* getChildContent() const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \class CppRestJsonDocumentNode
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief Represents a Node within a CppRestJsonDocumentContent's root web::json::value instance.
 *
 * See IDocumentNode for details
 */
class CppRestJsonDocumentNode : public IDocumentNode {
public:
  MLCLIENT_API CppRestJsonDocumentNode(web::json::value& root);
  MLCLIENT_API CppRestJsonDocumentNode(CppRestJsonDocumentNode&& from);
  MLCLIENT_API virtual ~CppRestJsonDocumentNode();

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
  MLCLIENT_API bool has(const std::string& key) const override;

  MLCLIENT_API StringList keys() const override;
  MLCLIENT_API int32_t size() const override;

  MLCLIENT_API IDocumentContent* getChildContent() const override;

private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \class CppRestJsonDocumentNavigator
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief Provides a navigator interface over a CppRestJsonDocumentContent's root web::json::value instance.
 */
class CppRestJsonDocumentNavigator : public IDocumentNavigator {
public:
  CppRestJsonDocumentNavigator(web::json::value& root,bool firstElementAsRoot = false);
  MLCLIENT_API CppRestJsonDocumentNavigator(CppRestJsonDocumentNavigator&& from);
  virtual ~CppRestJsonDocumentNavigator();

  MLCLIENT_API IDocumentNode* firstChild() const override;
  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API bool has(const std::string& key) const override;

private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \class CppRestJsonDocumentContent
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-05-10
 *
 * \brief An ITextDocumentContent instance that wraps a Microsoft cpprest JSON value object.
 *
 * Used by the CppRestJsonHelper class
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class CppRestJsonDocumentContent : public ITextDocumentContent {
public:
  /**
   * \brief Default constructor
   */
  MLCLIENT_API CppRestJsonDocumentContent();
  /**
   * \brief Virtual destructor to allow subclassing
   */
  MLCLIENT_API virtual ~CppRestJsonDocumentContent();

  /// \name cpprestjsondocumentcontent_overrides Overridden functions from base class
  /// @{
  /**
   * \brief Sets the content of this document instance from a Microsoft cpprest API web::json::value instance.
   *
   * \param json The cpprest API web::json::value instance to copy
   */
  MLCLIENT_API void setContent(web::json::value& json);

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
   * E.g. application/json or application/xml
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


  MLCLIENT_API IDocumentNavigator* navigate(bool firstElementAsRoot = false) const override;

  /// @}

  /// \name cpprestjsondocumentcontent_functions These functions are new to this subclass.
  /// @{
  /**
   * \brief Returns the underlying Microsoft cpprest API web::json::value object.
   *
   * \return The underlying Microsoft cpprest web::json::value object.
   */
  MLCLIENT_API const web::json::value& getJson() const;
  /// @}

private:
  class Impl; // forward declaration
  Impl* mImpl;

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_ */
