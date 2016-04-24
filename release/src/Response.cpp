//
//  Response.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <algorithm>
#include <boost/regex.hpp>

#include <cpprest/http_headers.h>
#include "mlclient.hpp"

#include <pugixml.hpp>

#include "ResponseCodes.hpp"
#include "Response.hpp"
#include "InvalidFormatException.hpp"


namespace mlclient {

using namespace web::http;
using namespace utility;

const boost::regex content_type_re("([a-zA-Z\\.]+)/([a-zA-Z\\.]+)");

Response::Response() : responseCode(ResponseCode::UNKNOWN_CODE), responseType(ResponseType::UNKNOWN_TYPE) {
  // ignore compilation warning - we know they are each set individually later, due to the nature of HTTP response interrogation code.
  //_xml = pugi::xml_document;
}

Response::~Response() {
}

ResponseType Response::parseContentTypeHeader(const std::string& content) {
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

void Response::setResponseCode(const ResponseCode& code) {
  responseCode = code;
}

void Response::setResponseType(const enum ResponseType& type) {
  responseType = type;
}
/*
void Response::SetResponseHeaders(const http_headers& headers) {
  _headers = headers;   
}*/

void Response::setResponseHeaders(const http_headers& headers) {
  this->headers.clear();
  for (auto& iter : headers) {
    this->headers[iter.first] = iter.second;
    if (iter.first == "Content-type" || iter.first == "Content-Type") {
      responseType = parseContentTypeHeader(iter.second);
    }
  }
}

ResponseCode Response::getResponseCode(void) const {
  return responseCode;
}

ResponseType Response::getResponseType(void) const {
  return responseType;
}

http_headers Response::getResponseHeaders(void) const {
  return headers;
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
std::string& Response::asString() const {
  return *content; // force copy cstor
}

/*
 * Tries to return the response as an XML.  Throws ResponseTypeException if it's
 * not XML.
 */
/*
xmlDocPtr Response::Xml() const {
    return nullptr;
}*/

const pugi::xml_document& Response::asXml() const {
  //static const pugi::xml_document& doc = _xml;
  //return doc;
  // TODO sanity check/warning for type of response
  if (responseType == ResponseType::XML) {
    // get response raw text
    //const std::string asstr = *_content.get();
    //const std::string asstr = _content;
    //std::cout << "Content: " << asstr << std::endl;
    // parse in to XML object
    // set response XML
    static pugi::xml_document doc;
    static const pugi::xml_document& docref = doc;
    pugi::xml_parse_result result = doc.load_string(content->c_str());

    if (result)
    {
      //std::cout << "XML [" << asstr << "] parsed without errors]\n\n"; // , attr value: [" << doc.child("node").attribute("attr").value()
      return docref;
    }
    else
    {
      std::cout << "XML [" << *content << "] parsed with errors]\n";
      std::cout << "Error description: " << result.description() << "\n";
      std::cout << "Error offset: " << result.offset << " (error at [..." << *content << "]\n\n";
      // TODO throw something here
      throw InvalidFormatException();
    }
  } else {
    throw InvalidFormatException();
  }
}
/*
void Response::SetXml(const pugi::xml_document& doc) {
	_xml = doc;
}*/

void Response::setContent(std::unique_ptr<std::string> content) {
  this->content = std::move(content); // move ownership from function to object
  //std::cout << "SetContent: parameter: " << content << ", member variable: " << _content << std::endl;
}

/*
 * Guess what this does.
 */
web::json::value Response::asJson() const {
  //return _json;
  // TODO sanity check/warning for type of response
  //std::cout << "Response type: " << _response_type << std::endl;
  if (this->responseType == ResponseType::JSON) {
    //std::cout << "Raw response JSON: " << _content << std::endl;
    return web::json::value::parse(*content);
  } else {
    throw InvalidFormatException();
  }
}
/*
void Response::SetJson(const web::json::value& json) {
  _json = json;
}*/

}
