//
//  Response.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <algorithm>
#include <boost/regex.hpp>

#include "ResponseCodes.hpp"
#include "Response.hpp"

using namespace web::http;

const boost::regex content_type_re("([a-zA-Z\\.]+)/([a-zA-Z\\.]+)");

ResponseType Response::ParseContentTypeHeader(const std::string& content) {
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
}

void Response::SetResponseCode(const ResponseCodes& code) {
  _response_code = code;    
}

void Response::SetResponseType(const enum ResponseType& type) {
  _response_type = type;    
}

void Response::SetResponseHeaders(const header_t& headers) {
  _headers = headers;   
}

void Response::SetResponseHeaders(const web::http::http_headers& headers) {
    _headers.clear();
    for (auto& iter : headers) {
      _headers[iter.first] = iter.second;
      if (iter.first == "Content-type" || iter.first == "Content-Type") {
        _response_type = ParseContentTypeHeader(iter.second);
      }
    }
}

ResponseCodes Response::GetResponseCode(void) const {
    return _response_code;
}

ResponseType Response::GetResponseType(void) const {
    return _response_type;
}

header_t Response::GetResponseHeaders(void) const {
    return _headers;
}

ResponseType Response::ResponseType(void) const {
    return ResponseType::TEXT;
}

/*
 * Read up to max size bytes into the response, starting at offset.
 */
size_t Response::Read(void* buffer, const size_t& max_size, const size_t off) {
    return 0;
}

/*
 * Tries to read back the response as a string.  Throws ResponseTypeException
 * if the response is not a string or string based.
 */
std::wstring Response::String() const {
    return L"";
}

/*
 * Tries to return the response as an XML.  Throws ResponseTypeException if it's
 * not XML.
 */
xmlDocPtr Response::Xml() const {
    return nullptr;
}

/*
 * Guess what this does.
 */
web::json::value Response::Json() const {
    return web::json::value(0);
}
