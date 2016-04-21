//
//  Response.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef RESPONSE_H
#define RESPONSE_H

#include <cstdint>
#include <cpprest/json.h>
#include <cpprest/http_headers.h>
#include <cpprest/http_client.h>

#include <pugixml.hpp>

#include "ResponseCodes.hpp"
#include "internals/Types.hpp"

#include "MLCPlusPlus.hpp"

namespace mlclient {

using namespace utility;

///
/// Response class
///
/// Encapsulates a response from a MarkLogic server.  Note that a response
/// can be XML, JSON, text, or binary content.  Currently, this uses the
/// PugiXML library for handling XML content, Casablanca for handling
/// JSON and stores text/binary as a bag of bytes.
///
class Response {
  ResponseCodes _response_code; /*!< The response code 200/400/404, etc */
  ResponseType  _response_type; /*!< The response type text,xml,binary, etc. */
  web::http::http_headers      _headers;       /*!< The response headers */
  std::unique_ptr<std::string> _content;

  ///
  /// Parses the content type header to guess the content type of the
  /// response
  ///
  /// \param The raw header value (i.e. 'text/plain')
  ResponseType ParseContentTypeHeader(const std::string& content);
public:
  ///
  /// Constructor
  ///
  ResponseType ResponseType(void) const;

  Response();
  ~Response();

  ///
  /// Sets the HTTP response code for the Response.  This is normally set
  /// when the response is received.  It should not be set otherwise.
  ///
  /// \param code The HTTP response code
  ///
  void SetResponseCode(const ResponseCodes& code);

  ///
  /// Sets the type of response received (XML, JSON, Binary, etc.)  This is
  /// normally set when the response is received.  It should not be set
  /// otherwise.
  ///
  /// \param type The type of response
  ///
  void SetResponseType(const enum ResponseType& type);

  ///
  /// Sets the headers received as part of the response.  This is set when
  /// the response is received but should not be set otherwise.
  ///
  /// \param headers The HTTP response headers
  ///
  void SetResponseHeaders(const web::http::http_headers& headers);

  ///
  /// Sets the headers received as part of the response.  This is set when
  /// the response is received but should not be set otherwise.
  ///
  /// \param headers The HTTP response headers
  ///
  //void SetResponseHeaders(const web::http::http_headers& headers);

  ///
  /// Returns the HTTP response code for the response.
  ///
  /// \return The HTTP response code
  ///
  ResponseCodes GetResponseCode(void) const;

  ///
  /// Returns the type of response (text, xml, json, etc.)
  ///
  /// \return The type of response.
  ///
  enum ResponseType GetResponseType(void) const;

  ///
  /// Returns the headers that were returned with the response.
  ///
  /// \return The HTTP response headers
  ///
  web::http::http_headers GetResponseHeaders(void) const;


  ///
  /// For binary responses, reads up to max_size bytes into buffer, starting
  /// at a given offset.  For example, if an image is returned, it can be
  /// saved to a file, reading 4 k chunks.  The actual number of bytes
  /// read is returned.
  ///
  /// \return The number of bytes read
  ///
  size_t Read(void* buffer, const size_t& max_size, const size_t off = 0);

  ///
  /// For text responses, returns the response content as a string.
  ///
  /// \return The UTF-8 string
  ///
  std::string& String() const;

  ///
  /// For XML responses, returns a document using the libxml2 library.
  ///
  /// \return The response document
  ///
  const pugi::xml_document& Xml() const;
  //void SetXml(const pugi::xml_document& doc);

  ///
  /// For JSON  responses, returns the document using the Casablanca JSON
  /// object represenation.
  ///
  /// \return The JSON object
  ///
  web::json::value Json() const; // uses copy semantics, not reference - peculiarity of the cpprest library

  //void SetJson(const web::json::value& json);
  void SetContent(std::unique_ptr<std::string> content); // move ownership to this class - use std::move(str) in the caller


private:

  // prevent compiler automatically defining the copy constructor and assignment operator:-
  Response(const Response&);
  Response& operator= (const Response&);



  friend class ResponseTest;
};

}

#endif /* defined(__Scratch__Response__) */



