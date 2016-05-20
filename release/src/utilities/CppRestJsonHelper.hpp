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
 * CppRestJsonHelper.hpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_CPPRESTJSONHELPER_HPP_
#define SRC_UTILITIES_CPPRESTJSONHELPER_HPP_

// I don't mind exposing these in an optional helper class
#include <cpprest/http_client.h>
#include "../DocumentContent.hpp"
#include "../Response.hpp"

namespace mlclient {

/**
 * \brief A non-required utilities namespace. Be aware that classes in this namespace may have external dependencies. These are
 * documented in the class documentation.
 *
 * \since 8.0.0
 * \date 2016-04-24
 */
namespace utilities {

/**
 * \class CppRestJsonHelper
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \brief This class provides utility functions to handle JSON data.
 *
 * This is a non-instantiable class with static functions to handle conversion of data between raw cpprest web::json::value and IDocumentContent
 * objects.
 *
 * The fromResponse and toDocument functions are particularly useful when extracting information from a Response object.
 *
 * This class uses the CppRestJsonDocumentContent instance to directly wrap an underlying web::json::value instance.
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class CppRestJsonHelper {
public:
  CppRestJsonHelper() = delete;
  ~CppRestJsonHelper() = delete;

  /// \name cpprestjsonhelper_documentconversion IDocumentContent conversion functions
  /// @{
  /**
   * \brief Creates a IDocumentContent instance based on a cpprest API web::json::value instance
   *
   * \note Actually returns a CppRestJsonDocumentContent instance (A subclass of TextDocumentContent)
   *
   * \param json The web::json::value to create a IDocumentContent representation of
   * \return A IDocumentContent instance wrapping the value
   */
  static ITextDocumentContent* toDocument(const web::json::value json);
  /**
   * \brief Creates a web::json::value from a IDocumentContent instance.
   *
   * \warning Don't call this on a CppRestJsonDocumentContent instance - use CppRestJsonDocumentContent::getJson() instead
   * \throw An InvalidFormatException if the document does not have the mime type of application/json, or if there is a parse error.
   * \param doc The IDocumentContent instance to create a web::json::value from.
   * \return A Microsoft cpprest API web::json::value instance created from the IDocumentContent.
   */
  static web::json::value fromDocument(const IDocumentContent& doc);
  /// @}

  /// \name cpprestjsonhelper_responseconversion Response conversion functions
  /// @{
  /**
   * \brief Creates a web::json::value from a Response object
   * \throw An InvalidFormatException if the document does not have the mime type of application/json, or if there is a parse error.
   * \param resp The Response instance to create a web::json::value from.
   * \return A Microsoft cpprest API web::json::value instance created from the Response.
   */
  static web::json::value fromResponse(const Response& resp);
  /// @}

};

} // end utilities namespace

} // end mlclient namespace

#endif /* SRC_UTILITIES_CPPRESTJSONHELPER_HPP_ */
