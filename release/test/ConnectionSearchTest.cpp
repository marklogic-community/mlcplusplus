/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * \file ConnectionSearchTest.cpp
 *
 * \date 2016-05-10
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */


#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionSearchTest.hpp"
#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include "NoCredentialsException.hpp"

#include <string>

#include "ext/easylogging++.h"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionSearchTest);

void ConnectionSearchTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ConnectionSearchTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void ConnectionSearchTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ConnectionDocumentCrudTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void ConnectionSearchTest::testEmptySearch() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " Entering testEmptySearch";
  SearchDescription desc; // default empty search object
  LOG(DEBUG) << "  Got a blank SearchDescription object instance";

  const Response* response = ml->search(desc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response->getResponseType());

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  delete response;
}

void ConnectionSearchTest::testQueryText() {
  TIMED_FUNC(testQueryText);
  LOG(DEBUG) << " Entering testQueryText";
  SearchDescription desc; // default empty search object
  desc.setQueryText("wibble");
  LOG(DEBUG) << "  Got an initialised SearchDescription object instance";

  const Response* response = ml->search(desc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response->getResponseType());

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  delete response;
}


void ConnectionSearchTest::testWordQuery() {
  TIMED_FUNC(testWordQuery);
  LOG(DEBUG) << " Entering testWordQuery";
  SearchDescription desc; // default empty search object
  GenericTextDocumentContent queryDoc;
  queryDoc.setContent("\"query\": {\"word-query\":\"Antidisestablishmentarianism\"}");
  desc.setQuery(queryDoc);
  LOG(DEBUG) << "  Got an initialised SearchDescription object instance";

  const Response* response = ml->search(desc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response->getResponseType());

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  LOG(DEBUG) << " Leaving testWordQuery";
  delete response;
}

