/*
 * CppRestJsonHelper.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include <cpprest/http_client.h>
#include "CppRestJsonHelper.hpp"
#include "CppRestJsonDocumentContent.hpp"
#include "../DocumentContent.hpp"
#include "../Response.hpp"
#include "../InvalidFormatException.hpp"

#include <iostream>

namespace mlclient {

namespace utilities {

// DocumentContent conversion
DocumentContent* CppRestJsonHelper::toDocument(const web::json::value json) {
  CppRestJsonDocumentContent* tdc = new CppRestJsonDocumentContent;
  tdc->setContent(json);
  tdc->setMimeType("application/json");
  return tdc; // TODO ensure this doesn't get nixed. Note - uses copy constructor (may eat memory)
}

/**
 * Don't call this on a CppRestJsonDocumentContent instance - use CppRestJsonDocumentContent::getJson() instead
 */
web::json::value CppRestJsonHelper::fromDocument(const DocumentContent& dc) {
  std::ostringstream os;
  std::ostream* dcos(dc.getStream());
  os << dcos;
  delete dcos; // free pointer
  return web::json::value(os.str());
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

