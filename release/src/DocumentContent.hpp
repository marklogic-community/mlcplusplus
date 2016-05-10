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
 * \class DocumentContent
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-04-25
 * \note This is an abstract class designed for extending, and cannot be instantiated directly.
 */
class DocumentContent {
public:
  // default constructor creation by compiler
  /**
   * The DocumentContent constructor. Called implicitly by subclasses only.
   */
  DocumentContent();

  /**
   * A virtual destructor, ripe for overloading. REQUIRED to allow subclassing
   */
  virtual ~DocumentContent();

  /**
   * \brief Returns the content of this DocumentContent as an ostream.
   *
   * This allows streaming to a HTTP request, and works for binary and string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An ostream instance wrapping the content of this Document Content instance
   */
  virtual std::ostream* getStream() const = 0;

  /**
   * \brief Returns the content of this DocumentContent as a std::string.
   *
   * This allows streaming of a HTTP request, with data encoded as a string.
   *
   * \return A string representing this content;
   */
  virtual std::string getContent() const = 0;

  /**
   * \brief Returns the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \return The string representation of the MIME type. Does not include encoding (always assume UTF-8 for MarkLogic Server)
   */
  std::string getMimeType() const;

  /**
   * \brief Sets the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \param[in] mt The mimetype string, not including encoding, for this Document Content. Assume always UTF-8 for MarkLogic Server)
   */
  void setMimeType(const std::string& mt);

  static const std::string MIME_JSON; //< The value application/json
  static const std::string MIME_XML; //< The value application/xml

protected:
  class Impl;
  Impl* mImpl;
};

// TODO streaming operator


// INTERFACES
/**
 * \class Textable
 * \brief This is a marker (tagging) interface class that indicates a DocumentContent subclass can be interacted with as a string.
 *
 * Use of this class is for multiple inheritance where a custom class may implement DocumentContent, but may also need some API clients
 * to interact with it as a string.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-05-01
 */
//class Textable {
//public:
  /**
   * Pure virtual constructor
   */
  //virtual Textable();
  /**
   * \brief Pure virtual destructor. REQUIRED to allow subclassing
   */
  //virtual ~Textable();

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  //virtual void setContent(std::string content) = 0;

  /**
   * \brief Returns the content as a string
   *
   * \return The string representation of the content.
   */
  //virtual std::string& getContent() = 0;

  /**
   * \brief Returns the number of characters in the content string.
   *
   * \note This number does not include C null characters - just std::string length
   *
   * \return The number of characters in the string. Does not include C null character.
   */
  //virtual int getLength() = 0;
//};





// SPECIALISATIONS
/**
 * \brief This class is a specialisation of DocumentContent that holds all data in a string.
 *
 * This class is used as the data holding class for all JSON and XML documents.
 * There are no JSON or XML specialisations (Use the JSON and XML helper classes in the \link utilities \endlink namespace
 * instead to create, modify, or introspect the JSON/XML.)
 */
class TextDocumentContent : public DocumentContent {
public:
  /**
   * \brief Constructs a blank text document
   *
   * The type will by default be set to JSON. Content will by default be an empty string.
   */
  TextDocumentContent();
  /**
   * \brief Pure virtual destructor
   */
  virtual ~TextDocumentContent();

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  void setContent(std::string content);

  /**
   * \brief Returns the content of this TextDocumentContent as an ostream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An ostream instance wrapping the content of this Text Document Content instance
   */
  std::ostream* getStream() const;

  /**
   * \brief Returns the content as a string
   *
   * \return The string representation of the content.
   */
  std::string getContent() const;
  /**
   * \brief Returns the number of characters in the content string.
   *
   * \note This number does not include C null characters - just std::string length
   *
   * \return The number of characters in the string. Does not include C null character.
   */
  int getLength() const;


  // TODO implement generic traversal API here, include binary support (for easy multi part mime handling)
private:
  class Impl;
  Impl* mImpl;
};

/**
 * \brief An enumeration for use with the BinaryDocumentContent class.
 *
 * There are many ways to encode a Binary document as a string. This enum allows them to be described.
 */
enum BinaryEncoding : int {
  HEX = 1,     //< Hexadecimal representation i.e. as characters 0-F
  BIN = 2      //< As binary, rather than encoded. Used in multi-part mime
};




/**
 * \class BinaryDocumentContent
 * \brief This class is a specialisation of DocumentContent that holds binary data.
 *
 * This class provides additional methods to make working with binary data more convenient.
 *
 * \note There are also operators like << available for streaming support.
 */
class BinaryDocumentContent : public DocumentContent {
public:
  /**
   * \brief Default constructor. Initialises the binary content to an empty buffer, of zero length.
   */
  BinaryDocumentContent();
  /**
   * \brief Destructor. Will deallocate all contained buffered data
   */
  virtual ~BinaryDocumentContent();
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
  //std::string& getContent(); // default to one encoding
  /**
   * \brief Returns the string representation(encoding) of the binary content, using the specified representation (HEX, BINARY, etc.)
   *
   * This is a specialist method for binary content. This allows the encoding to be specified by API calls that are aware of which
   * encoding is in use.
   *
   * \param[in] encoding The encoding to use. Defaults to HEX
   * \return The string representation of the binary content in the requested encoding.
   */
  //std::string& getContent(const enum BinaryEncoding& encoding = BinaryEncoding::HEX);
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
private:
  class Impl;
  Impl* mImpl;
};


// TODO << operator for BinaryDocumentContent

} // end mlclient namespace

#endif /* SRC_DOCUMENTCONTENT_HPP_ */
