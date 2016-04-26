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

#include <cpprest/http_headers.h>

namespace mlclient {


///
/// The type of response
///
//enum ResponseType : int; // UNKNOWN IS FIRST SO AS TO AVOID INCORRECTLY INSTANTIATED RESPONSE ISSUES

/**
 * The MarkLogic response type - Unknown (means the API hasn't been told by your own function calls!), XML, JSON, plain TEXT or BINARY.
 */
enum ResponseType : int { UNKNOWN_TYPE = 0, XML = 1, JSON = 2, TEXT = 3, BINARY = 4 };

std::ostream& operator << (std::ostream& os, const ResponseType& rt);
std::string& operator +(std::string& s, const ResponseType& rt);
//std::string& operator+(const char* orig,const ResponseType& rt);

const std::string translate(const ResponseType& rt);

/**
 * The various HTTP response codes. Defaults to UNKNOWN to prevent API failures.
 **/
enum ResponseCode : int {
       UNKNOWN_CODE                  = 0,
       CONTINUE                      = 100,
       OK                            = 200,
       CREATED                       = 201,
       ACCEPTED                      = 202,
       NO_CONTENT                    = 204,
       RESET_CONTENT                 = 205,
       PARTIAL_CONTENT               = 206,
       MULTIPLE_CHOICES              = 300,
       MOVED_PERMANENTLY             = 301,
       FOUND                         = 302,
       SEE_OTHER                     = 303,
       NOT_MODIFIED                  = 304,
       USE_PROXY                     = 305,
       TEMPORARY_REDIRECT            = 307,
       BAD_REQUEST                   = 400,
       UNAUTHORIZED                  = 401,
       PAYMENT_REQUIRED              = 402,
       FORBIDDEN                     = 403,
       NOT_FOUND                     = 404,
       METHOD_NOT_ALLOWED            = 405,
       NOT_ACCEPTABLE                = 406,
       PROXY_AUTHENTICATION_REQUIRED = 407,
       REQUEST_TIMEOUT               = 408,
       CONFLICT                      = 409,
       GONE                          = 410,
       LENGTH_REQUIRED               = 411,
       PRECONDITION_FAILED           = 412,
       REQUEST_ENTITY_TOO_LARGE      = 413,
       REQUEST_URI_TOO_LONG          = 414,
       UNSUPPORTED_MEDIA_TYPE        = 415,
       REQUEST_RANGE_BAD             = 416,
       EXPECTATION_FAILED            = 417,
       INTERNAL_SERVER_ERROR         = 500,
       NOT_IMPLEMENTED               = 501,
       BAD_GATEWAY                   = 502,
       SERVICE_UNAVAILABLE           = 503,
       GATEWAY_TIMEOUT               = 504,
       HTTP_VERSION_NOT_SUPPORTED    = 505
};


std::ostream& operator << (std::ostream& os, const ResponseCode& rc);
std::string& operator +(std::string& s, const ResponseCode& rc);
//std::string& operator+(const char* orig,const ResponseCode& rc);

const std::string translate(const ResponseCode& rt);




















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



