//
//  Response.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef RESPONSE_H
#define RESPONSE_H

#include "mlclient.hpp"
#include "ResponseCodes.hpp"

#include <cpprest/http_headers.h>

namespace mlclient {

///
/// Response class
///
/// Encapsulates a response from a MarkLogic server.  Note that a response
/// can be XML, JSON, text, or binary content.  Currently, this uses the
/// PugiXML library for handling XML content, Casablanca for handling
/// JSON and stores text/binary as a bag of bytes.
///
class Response {
public:
  ///
  /// Constructor
  ///
  ResponseType getResponseType(void) const;

  Response();
  ~Response();

  ///
  /// Sets the HTTP response code for the Response.  This is normally set
  /// when the response is received.  It should not be set otherwise.
  ///
  /// \param code The HTTP response code
  ///
  void setResponseCode(const ResponseCode& code);

  ///
  /// Sets the type of response received (XML, JSON, Binary, etc.)  This is
  /// normally set when the response is received.  It should not be set
  /// otherwise.
  ///
  /// \param type The type of response
  ///
  void setResponseType(const enum ResponseType& type);

  ///
  /// Sets the headers received as part of the response.  This is set when
  /// the response is received but should not be set otherwise.
  ///
  /// \param headers The HTTP response headers
  ///
  void setResponseHeaders(const web::http::http_headers& headers);

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
  ResponseCode getResponseCode(void) const;

  ///
  /// Returns the headers that were returned with the response.
  ///
  /// \return The HTTP response headers
  ///
  web::http::http_headers getResponseHeaders(void) const;


  ///
  /// For binary responses, reads up to max_size bytes into buffer, starting
  /// at a given offset.  For example, if an image is returned, it can be
  /// saved to a file, reading 4 k chunks.  The actual number of bytes
  /// read is returned.
  ///
  /// \return The number of bytes read
  ///
  size_t read(void* buffer, const size_t& max_size, const size_t off = 0);

  ///
  /// For text responses (including JSON and XML), returns the response content as a string.
  ///
  /// \return The UTF-8 string
  ///
  const std::string& getContent() const;

  //void SetJson(const web::json::value& json);
  void setContent(std::unique_ptr<std::string> content); // move ownership to this class - use std::move(str) in the caller

  // prevent compiler automatically defining the copy constructor and assignment operator:-
  Response(const Response&) = delete;
  Response& operator= (const Response&) = delete;

private:
  class Impl; // forward declare - PIMPL idiom
  Impl* mImpl;

  friend class ResponseTest; // TODO remove this - nasty
};

}

#endif /* defined(__Scratch__Response__) */



