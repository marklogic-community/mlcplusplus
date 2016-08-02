/*
 * PugiXmlDocumentContent.hpp
 *
 *  Created on: 30 Jul 2016
 *      Author: adamfowler
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_PUGIXMLDOCUMENTCONTENT_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_PUGIXMLDOCUMENTCONTENT_HPP_


#include "mlclient/mlclient.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/ext/pugixml/pugixml.hpp"

namespace mlclient {

namespace utilities {

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
};

class PugiXmlArrayNode : public PugiXmlContainerNode {
public:
  MLCLIENT_API PugiXmlArrayNode(const pugi::xml_node& parent,const std::string& key);
  MLCLIENT_API virtual ~PugiXmlArrayNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

class PugiXmlObjectNode : public PugiXmlContainerNode {
public:
  MLCLIENT_API PugiXmlObjectNode(const pugi::xml_node& root);
  MLCLIENT_API virtual ~PugiXmlObjectNode();

  MLCLIENT_API bool isArray() const override;
  MLCLIENT_API bool isObject() const override;

  MLCLIENT_API IDocumentNode* asArray() const override;
  MLCLIENT_API IDocumentNode* asObject() const override;

  MLCLIENT_API IDocumentNode* at(const std::string& key) const override;
  MLCLIENT_API IDocumentNode* at(const int32_t idx) const override;
private:
  class Impl; // forward declaration
  Impl* mImpl;
};

/**
 * \class PugiXmlDocumentNode
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-07-30
 *
 * \brief Represents a Node within a CppRestJsonDocumentContent's root web::json::value instance.
 */
class PugiXmlDocumentNode : public IDocumentNode {
public:
  MLCLIENT_API PugiXmlDocumentNode(const pugi::xml_node& result);
  MLCLIENT_API PugiXmlDocumentNode(const pugi::xml_node& root,const std::string& key);
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

private:
  class Impl; // forward declaration
  Impl* mImpl;
};


IDocumentNode* createNode(pugi::xml_node& parent,const std::string& key);


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
  PugiXmlDocumentNavigator(const pugi::xml_document& root);
  MLCLIENT_API PugiXmlDocumentNavigator(PugiXmlDocumentNavigator&& from);
  virtual ~PugiXmlDocumentNavigator();

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
  MLCLIENT_API void setContent(const pugi::xml_document& xml);

  /**
   * \brief Returns the content of this ITextDocumentContent as an ostream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An ostream instance wrapping the content of this Text Document Content instance
   */
  MLCLIENT_API std::ostream* getStream() const override;

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


  MLCLIENT_API IDocumentNavigator* navigate() const override;

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
