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
  virtual DocumentContent() = 0;
  virtual ~DocumentContent() = 0;

  // TODO copy constructor
  virtual void setContent(std::string content) = 0;
  // TODO set content as bytes
  virtual std::string getContent() = 0;

  virtual int getLength() = 0;

  std::string getMimeType();
  void setMimeType(const std::string& mt);

protected:
  class Impl;
  Impl* mImpl;
};

// TODO streaming operator


// SPECIALISATIONS
/**
 * This class is a specialisation of DocumentContent that holds all data in a string.
 */
class TextDocumentContent : DocumentContent {
public:
  TextDocumentContent();
  virtual ~TextDocumentContent() = 0;
  void setContent(std::string content);
  std::string getContent();
  int getLength();
  // TODO implement generic traversal API here, include binary support (for easy multi part mime handling)
private:
  class Impl;
  Impl* mImpl;
};


enum BinaryEncoding : int {
  HEX = 1, BINARY = 2
};

enum MimeType : std::string {
  JSON = "application/json",
  XML = "application/xml"
};



/**
 * This class is a specialisation of DocumentContent that holds binary data
 */
class BinaryDocumentContent : DocumentContent {
public:
  BinaryDocumentContent();
  virtual ~BinaryDocumentContent() = 0;
  void setContent(std::string content);
  std::string getContent(); // default to one encoding
  std::string getContent(const enum BinaryEncoding& encoding);
  void setContent(char* binary,int offset,int length); // TODO proper useful definition
  int getLength();
private:
  class Impl;
  Impl* mImpl;
};

} // end mlclient namespace

#endif /* SRC_DOCUMENTCONTENT_HPP_ */
