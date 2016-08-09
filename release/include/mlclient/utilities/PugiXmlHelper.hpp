/**
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
 * \file PugiXmlHelper.hpp
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_UTILITIES_PUGIXMLHELPER_HPP_
#define SRC_UTILITIES_PUGIXMLHELPER_HPP_

#include "mlclient/mlclient.hpp"
#include "mlclient/ext/pugixml/pugixml.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"

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
 * Provides convenience conversions between pugi::xml_document and IDocumentContent objects.
 *
 * \note This class introduces a dependency on the pugixml C++ library. You must install that to use this class.
 */
class PugiXmlHelper {
public:
  PugiXmlHelper() = delete;
  ~PugiXmlHelper() = delete;

  // IDocumentContent conversion
  /**
   * \brief Converts a pugi::xml_document instance to a MarkLogic C++ API IDocumentContent instance.
   * \param dc The pugi::xml_document instance to convert
   * \return The IDocumentContent instance wrapping the XML content, with its mime type and content set
   */
  MLCLIENT_API static ITextDocumentContent* toDocument(const pugi::xml_document& dc);

  /**
   * \brief Converts a std::string instance to a MarkLogic C++ API IDocumentContent instance.
   * \param content The std::string instance to convert
   * \return The IDocumentContent instance wrapping the XML content, with its mime type and content set
   */
  MLCLIENT_API static ITextDocumentContent* toDocument(const std::string& content);

  MLCLIENT_API static ITextDocumentContent* toDocument(const Response& resp);

  /**
   * \brief Extracts a pugi::xml_document instance from a IDocumentContent object.
   *
   * This is useful when retrieving a document from MarkLogic Server and then processing the underlying XML.
   *
   * \throw InvalidFormatException If the IDocumentContent does not have the application/xml mime type, or if parsing fails.
   *
   * \param dc The IDocumentContent instance to extract the XML content from.
   * \return A pugi::xml_document instance (parsed XML) created from the IDocumentContent object provided.
   */
  MLCLIENT_API static pugi::xml_document* fromDocument(const IDocumentContent& dc);

  // Response conversion
  /**
   * \brief Extracts a pugi::xml_document instance directly from the Response object.
   *
   * \throw InvalidFormatException if the Response does not have a mime type of application/xml, or if a parsing error occurs.
   *
   * \param resp The MarkLogic C++ API Response object instance.
   * \return A pugi::xml_document instance (parsed XML tree) created from the Response.
   */
  MLCLIENT_API static pugi::xml_document* fromResponse(const Response& resp);

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_PUGIXMLHELPER_HPP_ */
