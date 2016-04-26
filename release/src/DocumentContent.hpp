/*
 * DocumentContent.hpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_DOCUMENTCONTENT_HPP_
#define SRC_DOCUMENTCONTENT_HPP_

#include <string>
#include "SearchDescription.hpp"

namespace mlclient {

/**
 * This class represents the internal content of a Document. It can be XML, JSON, String or Binary (or a sub type thereof).
 * This class can also be used to wrap search options and other JSON/XML based content.
 * There are only two specialisations of this class - text and binary - all more complex types are created by using
 * the ResponseUtility and JsonHelper and XmlHelper to parse/create these types. E.g. a pugixml::document or web::json::value.
 */
class DocumentContent {
public:
  // default constructor creation by compiler
  /**
   * A pure virtual constructor, ripe for overriding
   */
  virtual DocumentContent() = 0;
  /**
   * A pure virtual destructor, ripe for overloading
   */
  virtual ~DocumentContent() = 0;

  // TODO copy constructor
  /**
   * Specifies that all DocumentContent instances must allow their content to be set via a string. (Or string encoding - E.g. HEX for binary documents)
   */
  virtual void setContent(std::string content) = 0;
  // TODO set content as bytes
  /**
   * Specifies that all DocumentContent instances must return their content as a string, or string encoded.
   */
  virtual std::string getContent() = 0;

  /**
   * Returns the length (number of characters or bytes) of the content. Characters for Text, binary encoded string length for Binary (I.e. HEX character count)
   */
  virtual int getLength() = 0;

  /**
   * Returns the MIME type of this content. E.g. application/json or application/xml
   */
  std::string getMimeType();
  /**
   * Sets the MIME type of this content. E.g. application/json or application/xml
   */
  void setMimeType(const std::string& mt);

protected:
  class Impl;
  Impl* mImpl;
};

// TODO streaming operator


// SPECIALISATIONS
/**
 * This class is a specialisation of DocumentContent that holds all data in a string.
 * It is used as the data holding class for all JSON and XML documents.
 * There are no JSON or XML specialisations (Use the JSON and XML helper classes instead to create, modify, or introspect the JSON/XML.)
 */
class TextDocumentContent : DocumentContent {
public:
  /**
   * Constructs a blank text document with type set to JSON
   */
  TextDocumentContent();
  /**
   * Pure virtual destructor
   */
  virtual ~TextDocumentContent() = 0;
  /**
   * Sets the textual content for this document
   */
  void setContent(std::string content);
  /**
   * Returns the content as a string
   */
  std::string getContent();
  /**
   * Returns the number of characters in the content string (does not include C null characters)
   */
  int getLength();
  // TODO implement generic traversal API here, include binary support (for easy multi part mime handling)
private:
  class Impl;
  Impl* mImpl;
};

/**
 * An enumeration for use with the BinaryDocumentContent class
 */
enum BinaryEncoding : int {
  HEX = 1, BINARY = 2
};

/**
 * An enumeration for use with the DocumentContent class.
 * You can provide any string for mimeType - you are NOT limited to these enum values.
 */
enum MimeType : std::string {
  JSON = "application/json",
  XML = "application/xml"
};



/**
 * This class is a specialisation of DocumentContent that holds binary data.
 */

class BinaryDocumentContent : DocumentContent {
public:
  BinaryDocumentContent();
  virtual ~BinaryDocumentContent() = 0;
  /**
   * Sets the content from the given string. Defaults to HEX encoding.
   */
  void setContent(std::string content);
  /**
   * Returns the textual representation of this content. Defaults to HEX encoding TODO verify this is true for ML Server multipart mime
   */
  std::string getContent(); // default to one encoding
  /**
   * Returns the string representation(encoding) of the binary content, using the specified representation (HEX, BINARY, etc.)
   */
  std::string getContent(const enum BinaryEncoding& encoding);
  /**
   * Sets the content from a raw binary buffer. For use with an input stream. See the << operator for this class too.
   */
  void setContent(char* binary,int offset,int length); // TODO proper useful definition
  /**
   * Returns the number of characters in the TEXTUAL encoding of this binary document. (i.e. NOT raw byte length)
   */
  int getLength();
private:
  class Impl;
  Impl* mImpl;
};


// TODO << operator for BinaryDocumentContent

} // end mlclient namespace

#endif /* SRC_DOCUMENTCONTENT_HPP_ */
