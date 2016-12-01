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
 */
/**
 * \file DocumentContent.hpp
 *
 * \since 8.0.0
 * \date 2016-04-25
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Contains classes and enums to handle document content (not properties, permissions, uri etc.) for basic content
 * types (text,binary,json,xml) being used with MarkLogic Server
 */

#ifndef SRC_DOCUMENTCONTENT_HPP_
#define SRC_DOCUMENTCONTENT_HPP_

#include <mlclient/mlclient.hpp>
#include <string>
#include <iosfwd>

namespace mlclient {

/**
 * \brief This class represents the internal content of a Document. It can be XML, JSON, String or Binary (or a sub type thereof).
 *
 * This class can also be used to wrap search options and other JSON/XML based content.
 * There are only two specialisations of this class - text and binary - all more complex types are created by using
 * the \link CppRestJsonHelper \endlink and \link PugiXmlHelper \endlink to parse/create these types. E.g. a pugixml::document or web::json::value.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \note This is an abstract class designed for extending, and cannot be instantiated directly.
 */
class IDocumentContent {
public:
  // default constructor creation by compiler
  /**
   * The IDocumentContent constructor. Called implicitly by subclasses only.
   */
  MLCLIENT_API IDocumentContent();

  /**
   * A virtual destructor, ripe for overloading. REQUIRED to allow subclassing
   */
  MLCLIENT_API virtual ~IDocumentContent() = 0;

  /**
   * \brief Returns the content of this IDocumentContent as an istream.
   *
   * This allows streaming to a HTTP request, and works for binary and string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An ostream instance wrapping the content of this Document Content instance
   */
  MLCLIENT_API virtual std::istream* getStream() const = 0;

  /**
   * \brief Returns the content of this IDocumentContent as a std::string.
   *
   * This allows streaming of a HTTP request, with data encoded as a string.
   *
   * \return A string representing this content;
   */
  MLCLIENT_API virtual std::string getContent() const = 0;

  /**
   * \brief Returns the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \return The string representation of the MIME type. Does not include encoding (always assume UTF-8 for MarkLogic Server)
   */
  MLCLIENT_API virtual std::string getMimeType() const = 0;

  /**
   * \brief Sets the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \param[in] mt The mimetype string, not including encoding, for this Document Content. Assume always UTF-8 for MarkLogic Server)
   */
  MLCLIENT_API virtual void setMimeType(const std::string& mt) = 0;

  MLCLIENT_API static const std::string MIME_JSON; //< The value application/json
  MLCLIENT_API static const std::string MIME_XML; //< The value application/xml

};

// TODO streaming operator



/**
 * \brief Acts as a generic lightweight document element interface
 *
 * This is the base class for any Document Node within the Document Traversal API.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 */
class IDocumentNode {
public:
  MLCLIENT_API IDocumentNode();
  MLCLIENT_API virtual ~IDocumentNode();

  /**
   * \brief Does this document element have a blank value?
   *
   * \return True if the value is blank. E.g. {"data":""} or <data/>
   */
  MLCLIENT_API virtual bool isNull() const = 0;
  /**
   * \brief Whether this element or property is a boolean type
   *
   * \return True if of type boolean
   */
  MLCLIENT_API virtual bool isBoolean() const = 0;
  /**
   * \brief Whether this element or property is a integer type
   *
   * \return True if of type integer
   */
  MLCLIENT_API virtual bool isInteger() const = 0;
  /**
   * \brief Whether this element or property is a double type
   *
   * \return True if of type double
   */
  MLCLIENT_API virtual bool isDouble() const = 0;
  /**
   * \brief Whether this element or property is a string type
   *
   * \return True if of type string
   */
  MLCLIENT_API virtual bool isString() const = 0;
  /**
   * \brief Whether this element or property is an array type
   *
   * \return True if of type array
   */
  MLCLIENT_API virtual bool isArray() const = 0;
  /**
   * \brief Whether this element or property is an object type (i.e. a JSON object or an XML element with element content)
   *
   * \return True if of type Object
   */
  MLCLIENT_API virtual bool isObject() const = 0;

  /**
   * \brief Returns the boolean value of this element or property
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The boolean value
   */
  MLCLIENT_API virtual bool asBoolean() const = 0;
  /**
   * \brief Returns the integer value of this element or property
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The integer value
   */
  MLCLIENT_API virtual int32_t asInteger() const = 0;
  /**
   * \brief Returns the double value of this element or property
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The double value
   */
  MLCLIENT_API virtual double asDouble() const = 0;
  /**
   * \brief Returns the string value of this element or property
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The string value
   */
  MLCLIENT_API virtual std::string asString() const = 0;
  /**
   * \brief Returns the array value of this element or property (i.e. the child objects)
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The array value
   */
  MLCLIENT_API virtual IDocumentNode* asArray() const = 0;
  /**
   * \brief Returns the Object value of this element or property (i.e. the child object)
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The Node object value
   */
  MLCLIENT_API virtual IDocumentNode* asObject() const = 0;

  MLCLIENT_API virtual IDocumentNode* at(const std::string& key) const = 0;
  MLCLIENT_API virtual IDocumentNode* at(const int32_t idx) const = 0;

  /**
   * \brief Returns whether the object at the root of the navigator's tree has a particular named sub element/property
   *
   * \param key the string key of the requested object
   * \return True if the key exists at the top level of the navigated document object
   */
  MLCLIENT_API virtual bool has(const std::string& key) const = 0;

  /**
   * \brief Returns the list of keys, if this node is an Object node.
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return A list of keys (a std::vector<std::string>)
   */
  MLCLIENT_API virtual StringList keys() const = 0;

  /**
   * \brief Returns the number of elements, if this node is an Array node.
   *
   * \throws InvalidFormatException if not of the right type
   *
   * \return The size of the array
   */
  MLCLIENT_API virtual int32_t size() const = 0;

  /**
   * \brief Returns the content of this element (not the element itself) as an IDocumentContent object
   *
   * \return The IDocumentContent* wrapper of the child content
   */
  MLCLIENT_API virtual IDocumentContent* getChildContent() const = 0;
};

/**
 * \brief Acts as a generic lightweight document interface
 *
 * This is the core class in the Document Traversal API. A Document Navigator provides a consistent interface
 * over both JSON and XML document content. This allows, for simple use cases, the developer to not know or
 * care what the underlying content type is of their document.
 *
 * Using this API the developer does not need to understand or know about the underlying XML or JSON libraries
 * being used by the C++ API. This is therefore a future proofed way of handling document content.
 *
 * Document Traversal is particularly useful when you don't know or care of the document format. E.g. if dealing
 * with internal MarkLogic document structures from the REST API (like search options), or if parsing search
 * result sets that contain document content.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 */
class IDocumentNavigator {
public:
  MLCLIENT_API IDocumentNavigator();
  MLCLIENT_API virtual ~IDocumentNavigator();

  /**
   * \brief Returns the first child node of this node
   * 
   * Useful to fetch the immediate child, no matter its name
   *
   * \return The first child node below the root node. nullptr if it doesn't exist
   */
  MLCLIENT_API virtual IDocumentNode* firstChild() const = 0;

  /**
   * \brief Returns the named element or property underneath the document object
   *
   * \param key the string key of the requested object
   * \return The IDocumentNode value of the requested element or property
   */
  MLCLIENT_API virtual IDocumentNode* at(const std::string& key) const = 0;

  /**
   * \brief Returns whether the object at the root of the navigator's tree has a particular named sub element/property
   *
   * \param key the string key of the requested object
   * \return True if the key exists at the top level of the navigated document object
   */
  MLCLIENT_API virtual bool has(const std::string& key) const = 0;
};











/**
 * \brief An overarching interface for a Text Document
 * \since 8.0.0
 * \date 2016-05-12
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */
class ITextDocumentContent : public IDocumentContent {
public:
  MLCLIENT_API ITextDocumentContent();
  MLCLIENT_API virtual ~ITextDocumentContent();

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  MLCLIENT_API virtual void setContent(std::string content) = 0;

  /**
   * \brief Returns the number of characters in the content string.
   *
   * \note This number does not include C null characters - just std::string length
   *
   * \return The number of characters in the string. Does not include C null character.
   */
  MLCLIENT_API virtual int getLength() const = 0;

  /**
   * \brief Returns a way to navigate the document
   *
   * See IDocumentNavigator for details
   *
   * \since 8.0.2
   * \date 2016-07-30
   */
  MLCLIENT_API virtual IDocumentNavigator* navigate(bool firstElementAsRoot = false) const = 0;

};






// SPECIALISATION TYPES - DEFAULT IMPLEMENTATIONS


/**
 * \brief This class is a specialisation of ITextDocumentContent (and thus IDocumentContent) that holds all data in a string.
 * \since 8.0.0
 * \date 2016-05-12
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 *
 * This class is used as the data holding class for all JSON and XML documents.
 * There are no JSON or XML specialisations (Use the JSON and XML helper classes in the \link utilities \endlink namespace
 * instead to create, modify, or introspect the JSON/XML.)
 */
class GenericTextDocumentContent : public ITextDocumentContent {
public:
  /**
   * \brief Constructs a blank text document
   *
   * The type will by default be set to JSON. Content will by default be an empty string.
   */
  MLCLIENT_API GenericTextDocumentContent();

  /**
   * \brief deep copy constructor
   */
  MLCLIENT_API GenericTextDocumentContent(const GenericTextDocumentContent& doc);

  /**
   * \brief deep copy constructor
   */
  MLCLIENT_API GenericTextDocumentContent(const ITextDocumentContent& doc);

  /**
   * \brief Pure virtual destructor
   */
  MLCLIENT_API virtual ~GenericTextDocumentContent();

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  MLCLIENT_API void setContent(std::string content) override;

  /**
   * \brief Returns the content of this TextDocumentContent as an istream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An istream instance wrapping the content of this Text Document Content instance
   */
  MLCLIENT_API std::istream* getStream() const override;

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

  /**
   * \brief Returns a way to navigate the document
   *
   * \since 8.0.2
   * \date 2016-07-30
   *
   * \return The IDocumentNavigator instance to navigate this document with.
   */
  MLCLIENT_API IDocumentNavigator* navigate(bool firstElementAsRoot = false) const override;


private:
  class Impl;
  Impl* mImpl;
};

/**
 * \brief Wraps a file system file ready for its upload to MarkLogic Server
 *
 * \since 8.0.2
 */
class FileDocumentContent : public IDocumentContent {
public:
  MLCLIENT_API FileDocumentContent(std::string file);
  MLCLIENT_API virtual ~FileDocumentContent();

  /**
   * \brief Returns the content of this IDocumentContent as an istream.
   *
   * This allows streaming to a HTTP request, and works for binary and string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An istream instance wrapping the content of this Document Content instance
   */
  MLCLIENT_API std::istream* getStream() const override;

  /**
   * \brief Returns the content of this IDocumentContent as a std::string.
   *
   * This allows streaming of a HTTP request, with data encoded as a string.
   *
   * \return A string representing this content;
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

private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};

/**
 * \brief An enumeration for use with the BinaryDocumentContent class.
 *
 * There are many ways to encode a Binary document as a string. This enum allows them to be described.
 */
enum class BinaryEncoding : int {
  HEX = 1,     //< Hexadecimal representation i.e. as characters 0-F
  BIN = 2      //< As binary, rather than encoded. Used in multi-part mime
};




/**
 * \brief This class is a specialisation of IDocumentContent that holds binary data.
 * \since 8.0.0
 *
 * This class provides additional methods to make working with binary data more convenient.
 *
 * \note There are also operators like << available for streaming support.
 *
 * \warning This class is not yet implemented by a concrete class, or supported by the C++ API. It is here for reference only.
 */
//class IBinaryDocumentContent : public IDocumentContent {
//public:
  /**
   * \brief Default constructor. Initialises the binary content to an empty buffer, of zero length.
   */
  //IBinaryDocumentContent();

  /**
   * \brief Destructor. Will deallocate all contained buffered data
   */
  //virtual ~IBinaryDocumentContent();

  /**
   * \brief Sets the content from the given string.
   *
   * Used when receiving binary content as text from MarkLogic Server. E.g. as part of a multi part mime response.
   *
   * \note Defaults to HEX encoding.
   *
   * \param[in] content The string content to copy in to the buffer.
   */
  //void setContent(std::string content);

  /**
   * \brief Returns the textual representation of this content.
   *
   * Defaults to HEX encoding TODO verify this is true for ML Server multipart mime
   *
   * \return The content of this buffer encoded as a string (HEX encoding by default)
   */
  //std::string getContent() const override; // default to one encoding

  /**
   * \brief Returns the string representation(encoding) of the binary content, using the specified representation (HEX, BINARY, etc.)
   *
   * This is a specialist method for binary content. This allows the encoding to be specified by API calls that are aware of which
   * encoding is in use.
   *
   * \param[in] encoding The encoding to use. Defaults to HEX
   * \return The string representation of the binary content in the requested encoding.
   */
  //std::string getContentWithEncoding(const enum BinaryEncoding& encoding = BinaryEncoding::HEX);

  /**
   * \brief Sets the content from a raw binary buffer.
   *
   * For use with an input stream. See the << operator for this class too.
   *
   * TODO check parameters' validity, and document accordingly.
   */
  //void setContent(char* binary,int offset,int length); // TODO proper useful definition

  /**
   * \brief Returns the number of characters in the TEXTUAL encoding of this binary document. (i.e. NOT raw byte length)
   *
   * This is required in order to be compatible with API to send the data to a HTTP server.
   *
   * \return The integer length of the string encoding (not the binary buffer length) of this data.
   */
  //int getLength();



  /**
   * \brief Returns the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \return The string representation of the MIME type. Does not include encoding (always assume UTF-8 for MarkLogic Server)
   */
  //virtual std::string getMimeType() const override = 0;

  /**
   * \brief Sets the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \param[in] mt The mimetype string, not including encoding, for this Document Content. Assume always UTF-8 for MarkLogic Server)
   */
  //virtual void setMimeType(const std::string& mt) override = 0;



  /**
   * \brief Returns the content of this TextDocumentContent as an istream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An istream instance wrapping the content of this Text Document Content instance
   */
  //virtual std::istream* getStream() const override = 0;


//private:
//  class Impl;
//  Impl* mImpl;
//};


// TODO << operator for BinaryDocumentContent

} // end mlclient namespace

#endif /* SRC_DOCUMENTCONTENT_HPP_ */
