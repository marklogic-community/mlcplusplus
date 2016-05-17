//
//  Response.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef RESPONSE_H
#define RESPONSE_H

#include "HttpHeaders.hpp"

#include <iosfwd>

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
/// \class Response
/// \since 8.0.0
/// \date 2014-06-05
///
/// \brief Encapsulates a response from a MarkLogic server REST API.
///
/// Note that a response
/// can be XML, JSON, text, or binary content. This holds the raw response
/// - If you want to process the response use one of the utility classes
/// based on the output of the Content-type response header.
///
/// \note This class is deliberately low level. See the CppRestJsonHelper and PugiXmlHelper classes for how to extract
/// a DocumentContent object from a Response object.
///
class Response {
public:
  ///
  /// Constructor
  ///
  Response();
  ~Response();

  ///
  /// \brief Sets the HTTP response code for the Response.
  ///
  /// This is normally set
  /// when the response is received.  It should not be set otherwise.
  ///
  /// \param[in] code The HTTP response code
  ///
  void setResponseCode(const ResponseCode& code);

  /**
   * \brief Returns the ResponseType const for the response. This is XML, JSON, Binary, Text, or Unknown.
   *
   * \return A ResponseType enum value representing the MarkLogic response type class. This can be outputted as a string using the << operator.
   */
  ResponseType getResponseType(void) const;

  ///
  /// \brief Sets the type of response received (XML, JSON, Binary, etc.), set my this API internally.
  ///
  /// This is
  /// normally set when the response is received.  It should not be set
  /// otherwise.
  ///
  /// \param[in] type The type of response
  ///
  void setResponseType(const enum ResponseType& type);

  ///
  /// \brief Sets the headers received as part of the response.
  ///
  /// This is set when
  /// the response is received but should not be set otherwise.
  ///
  /// \param[in] headers The HTTP response headers
  ///
  void setResponseHeaders(const mlclient::HttpHeaders& headers);

  ///
  /// \brief Sets the headers received as part of the response.
  ///
  /// This is set when
  /// the response is received but should not be set otherwise.
  ///
  /// \param[in] headers The HTTP response headers
  ///
  //void SetResponseHeaders(const mlclient::HttpHeaders& headers);

  ///
  /// \brief Returns the HTTP response code for the response.
  ///
  /// \return The HTTP response code
  ///
  ResponseCode getResponseCode(void) const;

  ///
  /// \brief Returns the headers that were returned with the response.
  ///
  /// \return The HTTP response headers
  /// \todo Remove the dependency on the cpprest API
  ///
  mlclient::HttpHeaders getResponseHeaders(void) const;


  ///
  /// \brief Reads the raw response in to a buffer. Used for Binary responses.
  ///
  /// For binary responses, reads up to max_size bytes into buffer, starting
  /// at a given offset.  For example, if an image is returned, it can be
  /// saved to a file, reading 4 k chunks.  The actual number of bytes
  /// read is returned.
  ///
  /// \param[inout] buffer The untyped buffer to copy data in to
  /// \param[in] max_size The maximum amount of data in bytes to read in to the buffer
  /// \param[in] off The offset in the buffer after which this function starts writing data to
  /// \return The number of bytes read
  ///
  size_t read(void* buffer, const size_t& max_size, const size_t off = 0);

  ///
  /// \brief For text responses (including JSON and XML), returns the response content as a string.
  ///
  /// \return The UTF-8 string
  ///
  const std::string& getContent() const;

  //void SetJson(const web::json::value& json);
  /**
   * \brief Sets the string content for this Response
   *
   * This should only be set by the MarkLogic C++ API itself, never by a developer using the API.
   *
   * \note This function takes ownership of the content pointer using std::move
   *
   * \param[in] content A std::unique_ptr to take ownership of the std::string content of the response.
   */
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



