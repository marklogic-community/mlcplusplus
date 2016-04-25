/*
 * PugiXmlHelper.cpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#include "PugiXmlHelper.hpp"
#include "../DocumentContent.hpp"
#include "../Response.hpp"
#include <string>
#include <iostream>
#include <pugixml.hpp>

namespace mlclient {

namespace utilities {

// DocumentContent conversion
DocumentContent& PugiXmlHelper::toDocument(const pugi::xml_document& dc) {
  TextDocumentContent& tdc = TextDocumentContent();
  std::ostringstream os;
  os << dc;
  tdc.setContent(os.str());
  tdc.setMimeType("application/xml");
  return tdc; // TODO do we need to std::move this?
}
pugi::xml_document PugiXmlHelper::fromDocument(const DocumentContent& dc) {
  // TODO handle invalid cast exception


  pugi::xml_document& doc = pugi::xml_document();
  pugi::xml_parse_result result = doc.load_string(dc.getContent().c_str());

  if (result) {
    //std::cout << "XML [" << asstr << "] parsed without errors]\n\n"; // , attr value: [" << doc.child("node").attribute("attr").value()
    return doc;
  } else {
    std::cout << "XML [" << dc.getContent() << "] parsed with errors]\n";
    std::cout << "Error description: " << result.description() << "\n";
    std::cout << "Error offset: " << result.offset << " (error at [..." << dc.getContent() << "]\n\n";
    // TODO throw something here
    throw InvalidFormatException();
  }
}

// Response conversion
pugi::xml_document& PugiXmlHelper::fromResponse(const Response& resp) {
  if (resp.getResponseType() == ResponseType::XML) {
    pugi::xml_document& doc = pugi::xml_document;
    pugi::xml_parse_result result = doc.load_string(resp.getContent().c_str());

    if (result) {
      //std::cout << "XML [" << asstr << "] parsed without errors]\n\n"; // , attr value: [" << doc.child("node").attribute("attr").value()
      return doc;
    } else {
      std::cout << "XML [" << resp.getContent() << "] parsed with errors]\n";
      std::cout << "Error description: " << result.description() << "\n";
      std::cout << "Error offset: " << result.offset << " (error at [..." << resp.getContent() << "]\n\n";
      // TODO throw something here
      throw InvalidFormatException();
    }
  } else {
    throw InvalidFormatException();
  }
}

} // end namespace utilities

} // end namespace mlclient
