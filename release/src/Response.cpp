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

#include <pugixml.hpp>

#include "ResponseCodes.hpp"
#include "Response.hpp"
#include "InvalidFormatException.hpp"

#include "MLCPlusPlus.hpp"

namespace mlclient {

using namespace web::http;
using namespace utility;

const boost::regex content_type_re("([a-zA-Z\\.]+)/([a-zA-Z\\.]+)");

Response::Response() : _response_code(ResponseCodes::UNKNOWN), _response_type(ResponseType::UNKNOWN) {
	// ignore compilation warning - we know they are each set individually later, due to the nature of HTTP response interrogation code.
	//_xml = pugi::xml_document;
}

Response::~Response() {
}

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
/*
void Response::SetResponseHeaders(const http_headers& headers) {
  _headers = headers;   
}*/

void Response::SetResponseHeaders(const http_headers& headers) {
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

http_headers Response::GetResponseHeaders(void) const {
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
std::string& Response::String() const {
    return *_content; // force copy cstor
}

/*
 * Tries to return the response as an XML.  Throws ResponseTypeException if it's
 * not XML.
 */
/*
xmlDocPtr Response::Xml() const {
    return nullptr;
}*/

const pugi::xml_document& Response::Xml() const {
	//static const pugi::xml_document& doc = _xml;
	//return doc;
	// TODO sanity check/warning for type of response
    if (_response_type == ResponseType::XML) {
  		  // get response raw text
		  //const std::string asstr = *_content.get();
		  //const std::string asstr = _content;
  		  //std::cout << "Content: " << asstr << std::endl;
  		  // parse in to XML object
  		  // set response XML
  		  static pugi::xml_document doc;
  		  static const pugi::xml_document& docref = doc;
  		  pugi::xml_parse_result result = doc.load_string(_content->c_str());

  		  if (result)
  		  {
  		      //std::cout << "XML [" << asstr << "] parsed without errors]\n\n"; // , attr value: [" << doc.child("node").attribute("attr").value()
  		      return docref;
  		  }
  		  else
  		  {
  		      std::cout << "XML [" << *_content << "] parsed with errors]\n";
  		      std::cout << "Error description: " << result.description() << "\n";
  		      std::cout << "Error offset: " << result.offset << " (error at [..." << *_content << "]\n\n";
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

void Response::SetContent(std::unique_ptr<std::string> content) {
	_content = std::move(content); // move ownership from function to object
	//std::cout << "SetContent: parameter: " << content << ", member variable: " << _content << std::endl;
}

/*
 * Guess what this does.
 */
web::json::value Response::Json() const {
    //return _json;
	// TODO sanity check/warning for type of response
//std::cout << "Response type: " << _response_type << std::endl;
    if (_response_type == ResponseType::JSON) {
    //std::cout << "Raw response JSON: " << _content << std::endl;
      return web::json::value::parse(*_content);
    } else {
      throw InvalidFormatException();
    }
}
/*
void Response::SetJson(const web::json::value& json) {
  _json = json;
}*/

}
