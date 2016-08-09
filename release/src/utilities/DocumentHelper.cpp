/*
 * DocumentHelper.cpp
 *
 *  Created on: 9 Aug 2016
 *      Author: adamfowler
 */


#include <mlclient/utilities/DocumentHelper.hpp>
#include <mlclient/Document.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/DocumentContent.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <mlclient/utilities/CppRestJsonHelper.hpp>
#include <mlclient/utilities/PugiXmlHelper.hpp>

namespace mlclient {

namespace utilities {

// TODO handle multi-part mixed responses

Document* DocumentHelper::fromResponse(const Response& resp) {
  Document* doc = new Document;
  IDocumentContent* content = DocumentHelper::contentFromResponse(resp);
  doc->setContent(content);
  // TODO other fields, such as URI etc.

  return doc;
}

void DocumentHelper::fromResponse(const Response& resp,Document& doc) {
  IDocumentContent* content = DocumentHelper::contentFromResponse(resp);
  doc.setContent(content);
  // TODO other fields, such as URI etc.
}

IDocumentContent* DocumentHelper::contentFromResponse(const Response& resp) {
  if (resp.getResponseType() == ResponseType::XML) {
    return PugiXmlHelper::toDocument(resp);
  } else if (resp.getResponseType() == ResponseType::JSON) {
    return CppRestJsonHelper::toDocument(resp);
  } else if (resp.getResponseType() == ResponseType::TEXT) {
    GenericTextDocumentContent* dc = new GenericTextDocumentContent();
    dc->setMimeType(resp.getResponseHeaders().getHeader("Content-type"));
    dc->setContent(resp.getContent());
    return dc;
  } else {
    // not yet supported
    throw new InvalidFormatException;
  }
}


} // end utilities namespace

} // end mlclient namespace
