/*
 * CppRestJsonHelper.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include <cpprest/http_client.h>
#include "utilities/CppRestJsonHelper.hpp"
#include "../DocumentContent.hpp"
#include "InvalidFormatException.hpp"

namespace mlclient {

namespace utilities {

// DocumentContent conversion
DocumentContent& CppRestJsonHelper::toDocument(const web::json::value json) {
  TextDocumentContent& tdc = TextDocumentContent();
  std::string c(json.as_string());
  tdc.setContent(c);
  tdc.setMimeType("application/json");
  return tdc; // TODO ensure this doesn't get nixed
}

web::json::value CppRestJsonHelper::fromDocument(const DocumentContent& dc) {
  return web::json::value(dc.getContent());
}

// Response conversion
web::json::value CppRestJsonHelper::fromResponse(const Response& resp) {
  //std::cout << "Response type: " << _response_type << std::endl;
  if (resp.getResponseType() == ResponseType::JSON) {
    //std::cout << "Raw response JSON: " << _content << std::endl;
    return web::json::value::parse(resp.getContent());
  } else {
    throw InvalidFormatException();
  }
}


} // end utilities namespace

} // end mlclient namespace

