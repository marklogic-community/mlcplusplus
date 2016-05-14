//
//  ConnectionDocumentCrudTest.cpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionDocumentCrudTest.hpp"
#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "NoCredentialsException.hpp"

#include <string>

#include "easylogging++.h"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionDocumentCrudTest);


void ConnectionDocumentCrudTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ConnectionDocumentCrudTest::setUp";
  // set up connection
  ml = ConnectionFactory::getConnection();
  json = "{\"first\":\"value1\",\"second\":\"value2\"}";
  xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<doc><first>value1</first><second>value2</second></doc>";
  text = "Some very nice text document";
  jsonUri = "/mlclient/tests/ConnectionDocumentCrudTest/doc.json";
  xmlUri = "/mlclient/tests/ConnectionDocumentCrudTest/doc.xml";
  textUri = "/mlclient/tests/ConnectionDocumentCrudTest/doc.txt";
}

void ConnectionDocumentCrudTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ConnectionDocumentCrudTest::tearDown";
  // delete all content
  delete ml;
  ml = NULL;
}

void ConnectionDocumentCrudTest::testSaveJson(void) {
  TIMED_FUNC(testSaveJson);
  LOG(DEBUG) << " Entering testSaveJson";

  // Note not using the Json or Xml helpers as we're not testing them here
  GenericTextDocumentContent tdc;
  tdc.setMimeType("application/json");
  tdc.setContent(json);
  const std::unique_ptr<Response> response = ml->saveDocument(jsonUri,tdc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 201 Created",ResponseCode::CREATED == response->getResponseCode());
}

void ConnectionDocumentCrudTest::testGetJson(void) {
  TIMED_FUNC(testGetJson);
  LOG(DEBUG) << " Entering testGetJson";
  const std::unique_ptr<Response> response = ml->getDocument(jsonUri);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());

  //CPPUNIT_ASSERT_MESSAGE("The JSON response content is modified compared to the original", 0 == json.compare(response->getContent()));

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
}

void ConnectionDocumentCrudTest::testDeleteJson(void) {
  TIMED_FUNC(testDeleteJson);
  LOG(DEBUG) << std::endl << " Entering testDeleteJson";
  const std::unique_ptr<Response> response = ml->deleteDocument(jsonUri);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 204 No Content",ResponseCode::NO_CONTENT == response->getResponseCode());
}

void ConnectionDocumentCrudTest::testSaveXml(void) {
  TIMED_FUNC(testSaveXml);
  LOG(DEBUG) << " Entering testSaveXml";
  // Note not using the Json or Xml helpers as we're not testing them here
  GenericTextDocumentContent tdc;
  tdc.setMimeType("application/xml");
  tdc.setContent(xml);
  const std::unique_ptr<Response> response = ml->saveDocument(xmlUri,tdc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 201 Created",ResponseCode::CREATED == response->getResponseCode());
}

void ConnectionDocumentCrudTest::testGetXml(void) {
  TIMED_FUNC(testGetXml);
  LOG(DEBUG) << " Entering testGetXml";
  const std::unique_ptr<Response> response = ml->getDocument(xmlUri);

  ResponseType rt = response->getResponseType();
  LOG(DEBUG) << "  Response Type: " << rt;
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a XML response", ResponseType::XML  == response->getResponseType());

  //CPPUNIT_ASSERT_MESSAGE("The XML response content is modified compared to the original", 0 == xml.compare(response->getContent()));
  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
}


void ConnectionDocumentCrudTest::testDeleteXml(void) {
  TIMED_FUNC(testDeleteXml);
  LOG(DEBUG) << " Entering testDeleteXml";
  const std::unique_ptr<Response> response = ml->deleteDocument(xmlUri);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 204 No Content",ResponseCode::NO_CONTENT == response->getResponseCode());
}


void ConnectionDocumentCrudTest::testSaveText(void) {
  TIMED_FUNC(testSaveText);
  LOG(DEBUG) << " Entering testSaveText";
  // Note not using the Json or Xml helpers as we're not testing them here
  GenericTextDocumentContent tdc;
  tdc.setMimeType("plain/text");
  tdc.setContent(text);
  const std::unique_ptr<Response> response = ml->saveDocument(textUri,tdc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 201 Created",ResponseCode::CREATED == response->getResponseCode());
}

void ConnectionDocumentCrudTest::testGetText(void) {
  TIMED_FUNC(testGetText);
  LOG(DEBUG) << " Entering testGetText";
  const std::unique_ptr<Response> response = ml->getDocument(textUri);

  ResponseType rt = response->getResponseType();
  LOG(DEBUG) << "  Response Type: " << rt;
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a TEXT response", ResponseType::TEXT  == response->getResponseType());

  //CPPUNIT_ASSERT_MESSAGE("The TEXT response content is modified compared to the original", 0 == text.compare(response->getContent()));
  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
}


void ConnectionDocumentCrudTest::testDeleteText(void) {
  TIMED_FUNC(testDeleteText);
  LOG(DEBUG) << " Entering testDeleteText";
  const std::unique_ptr<Response> response = ml->deleteDocument(textUri);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 204 No Content",ResponseCode::NO_CONTENT == response->getResponseCode());
}
