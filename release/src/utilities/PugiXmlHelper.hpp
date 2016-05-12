/**
 * \file PugiXmlHelper.hpp
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_UTILITIES_PUGIXMLHELPER_HPP_
#define SRC_UTILITIES_PUGIXMLHELPER_HPP_

#include <pugixml.hpp>
#include "../Response.hpp"
#include "../DocumentContent.hpp"

namespace mlclient {

namespace utilities {

/**
 * \class PugiXmlHelper
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \brief Uses the pugixml library to provide convenience XML parsing functionality.
 *
 * Provides convenience conversions between pugi::xml_document and DocumentContent objects.
 *
 * \note This class introduces a dependency on the pugixml C++ library. You must install that to use this class.
 */
class PugiXmlHelper {
public:
  PugiXmlHelper() = delete;
  ~PugiXmlHelper() = delete;

  // DocumentContent conversion
  /**
   * \brief Converts a pugi::xml_document instance to a MarkLogic C++ API DocumentContent instance.
   * \param dc The pugi::xml_document instance to convert
   * \return The DocumentContent instance wrapping the XML content, with its mime type and content set
   */
  static TextDocumentContent* toDocument(const pugi::xml_document& dc);
  /**
   * \brief Extracts a pugi::xml_document instance from a DocumentContent object.
   *
   * This is useful when retrieving a document from MarkLogic Server and then processing the underlying XML.
   *
   * \throw InvalidFormatException If the DocumentContent does not have the application/xml mime type, or if parsing fails.
   *
   * \param dc The DocumentContent instance to extract the XML content from.
   * \return A pugi::xml_document instance (parsed XML) created from the DocumentContent object provided.
   */
  static pugi::xml_document* fromDocument(const IDocumentContent& dc);

  // Response conversion
  /**
   * \brief Extracts a pugi::xml_document instance directly from the Response object.
   *
   * \throw InvalidFormatException if the Response does not have a mime type of application/xml, or if a parsing error occurs.
   *
   * \param resp The MarkLogic C++ API Response object instance.
   * \return A pugi::xml_document instance (parsed XML tree) created from the Response.
   */
  static pugi::xml_document* fromResponse(const Response& resp);

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_PUGIXMLHELPER_HPP_ */
