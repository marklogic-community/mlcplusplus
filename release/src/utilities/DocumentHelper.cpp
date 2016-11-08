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
#include <mlclient/logging.hpp>

namespace mlclient {

namespace utilities {

// TODO handle multi-part mixed responses

Document* DocumentHelper::fromResponse(const Response& resp) {
  LOG(DEBUG) << "DocumentHelper::fromResponse(Response&)";
  Document* doc = new Document;
  IDocumentContent* content = DocumentHelper::contentFromResponse(resp);
  doc->setContent(content);
  // TODO other fields, such as URI etc.

  return doc;
}

void DocumentHelper::fromResponse(const Response& resp,Document& doc) {
  LOG(DEBUG) << "DocumentHelper::fromResponse(Response&,Document&)";
  IDocumentContent* content = DocumentHelper::contentFromResponse(resp);
  doc.setContent(content);
  // TODO other fields, such as URI etc.
}

IDocumentContent* DocumentHelper::contentFromResponse(const Response& resp) {
  LOG(DEBUG) << "DocumentHelper::contentFromResponse";
  if (resp.getResponseType() == ResponseType::XML) {
    LOG(DEBUG) << "DocumentHelper::contentFromResponse: XML";
    return PugiXmlHelper::toDocument(resp);
  } else if (resp.getResponseType() == ResponseType::JSON) {
    LOG(DEBUG) << "DocumentHelper::contentFromResponse: JSON";
    return CppRestJsonHelper::toDocument(resp);
  } else if (resp.getResponseType() == ResponseType::TEXT) {
    LOG(DEBUG) << "DocumentHelper::contentFromResponse: Text";
    GenericTextDocumentContent* dc = new GenericTextDocumentContent();
    dc->setMimeType(resp.getResponseHeaders().getHeader("Content-type"));
    dc->setContent(resp.getContent());
    return dc;
  } else {
    LOG(DEBUG) << "DocumentHelper::contentFromResponse: Other (Invalid) Format";
    // not yet supported
    throw new InvalidFormatException;
  }
}


} // end utilities namespace

} // end mlclient namespace
