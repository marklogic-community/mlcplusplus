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

#include "mlclient/DocumentContent.hpp"
#include <cpprest/http_client.h>

namespace mlclient {

namespace utilities {

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
  CppRestJsonDocumentContent();
  /**
   * \brief Virtual destructor to allow subclassing
   */
  virtual ~CppRestJsonDocumentContent();

  /// \name cpprestjsondocumentcontent_overrides Overridden functions from base class
  /// @{
  /**
   * \brief Sets the content of this document instance from a Microsoft cpprest API web::json::value instance.
   *
   * \param json The cpprest API web::json::value instance to copy
   */
  void setContent(const web::json::value& json);

  /**
   * \brief Returns the content of this ITextDocumentContent as an ostream.
   *
   * This allows streaming to a HTTP request of this string content.
   *
   * \note The stream may be read from asynchronously, so do not destroy the underlying content after returning the stream.
   *
   * \return An ostream instance wrapping the content of this Text Document Content instance
   */
  std::ostream* getStream() const override;

  /**
   * \brief Sets the textual content for this document
   *
   * Assumes content string is non null
   *
   * \param[in] The string content to copy in to this object.
   */
  void setContent(std::string content) override;

  /**
   * \brief Returns the content as a string
   *
   * \return The string representation of the content.
   */
  std::string getContent() const override;

  /**
   * \brief Returns the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \return The string representation of the MIME type. Does not include encoding (always assume UTF-8 for MarkLogic Server)
   */
  std::string getMimeType() const override;

  /**
   * \brief Sets the MIME type of this content.
   *
   * E.g. application/json or application/xml
   *
   * \param[in] mt The mimetype string, not including encoding, for this Document Content. Assume always UTF-8 for MarkLogic Server)
   */
  void setMimeType(const std::string& mt) override;


  /**
   * \brief Returns the number of characters in the content string.
   *
   * \note This number does not include C null characters - just std::string length
   *
   * \return The number of characters in the string. Does not include C null character.
   */
  int getLength() const override;

  /// @}

  /// \name cpprestjsondocumentcontent_functions These functions are new to this subclass.
  /// @{
  /**
   * \brief Returns the underlying Microsoft cpprest API web::json::value object.
   *
   * \return The underlying Microsoft cpprest web::json::value object.
   */
  web::json::value& getJson();
  /// @}

private:
  class Impl; // forward declaration
  Impl* mImpl;

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_ */
