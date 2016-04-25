//
//  Response.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <algorithm>
#include <boost/regex.hpp>

#include <cstdint>
#include <cpprest/http_headers.h>
#include <cpprest/http_client.h>
#include "mlclient.hpp"

#include "ResponseCodes.hpp"
#include "Response.hpp"


namespace mlclient {

using namespace web::http;
using namespace utility;

const boost::regex content_type_re("([a-zA-Z\\.]+)/([a-zA-Z\\.]+)");

class Response::Impl {
public:
  Impl() : responseCode(ResponseCode::UNKNOWN_CODE), responseType(ResponseType::UNKNOWN_TYPE)  {
    ;
  };
  ~Impl() {
    ;
  };


  ResponseCode responseCode; /*!< The response code 200/400/404, etc */
  ResponseType  responseType; /*!< The response type text,xml,binary, etc. */
  web::http::http_headers      headers;       /*!< The response headers */
  std::unique_ptr<std::string> content;


  ///
  /// Parses the content type header to guess the content type of the
  /// response
  ///
  /// \param The raw header value (i.e. 'text/plain')
  ResponseType parseContentTypeHeader(const std::string& content) {
    boost::smatch matches;
    enum ResponseType result = ResponseType::BINARY;
    if (boost::regex_search(content, matches, content_type_re)) {
      std::string major = matches[1];
      std::string minor = matches[2];

      if (major == "application" || major == "text") {
        if (minor == "json") {
          result = ResponseType::JSON;
        } else if(minor == "html" || minor == "xml") {
          result = ResponseType::XML;
        } else if(minor == "plain") {
          result = ResponseType::TEXT;
        }
      }
    }
    return result;
  };

};



Response::Response() : mImpl(new Impl) {
  // ignore compilation warning - we know they are each set individually later, due to the nature of HTTP response interrogation code.
  //_xml = pugi::xml_document;
}

Response::~Response() {
  delete mImpl;
  mImpl = NULL;
}


void Response::setResponseCode(const ResponseCode& code) {
  mImpl->responseCode = code;
}

void Response::setResponseType(const enum ResponseType& type) {
  mImpl->responseType = type;
}
/*
void Response::SetResponseHeaders(const http_headers& headers) {
  _headers = headers;   
}*/

void Response::setResponseHeaders(const http_headers& headers) {
  mImpl->headers.clear();
  for (auto& iter : headers) {
    mImpl->headers[iter.first] = iter.second;
    if (iter.first == "Content-type" || iter.first == "Content-Type") {
      mImpl->responseType = mImpl->parseContentTypeHeader(iter.second);
    }
  }
}

ResponseCode Response::getResponseCode(void) const {
  return mImpl->responseCode;
}

ResponseType Response::getResponseType(void) const {
  return mImpl->responseType;
}

http_headers Response::getResponseHeaders(void) const {
  return mImpl->headers;
}

/*
 * Read up to max size bytes into the response, starting at offset.
 */
size_t Response::read(void* buffer, const size_t& max_size, const size_t off) {
  return 0;
}

/*
 * Tries to read back the response as a string.  Throws ResponseTypeException
 * if the response is not a string or string based.
 */
const std::string& Response::getContent() const {
  return *(mImpl->content); // TODO check this - force copy cstor - WHY!?! const return type
}

void Response::setContent(std::unique_ptr<std::string> content) {
  mImpl->content = std::move(content); // move ownership from function to object
  //std::cout << "SetContent: parameter: " << content << ", member variable: " << _content << std::endl;
}


}
