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
//
//  ConnectionRawHttpTest.cpp
//  Created by Adam Fowler on 15 Nov 2016.
//

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionRawHttpTest.hpp"
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"

#include <string>

#include "mlclient/logging.hpp"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionRawHttpTest);


void ConnectionRawHttpTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ConnectionRawHttpTest::setUp";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void ConnectionRawHttpTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ConnectionRawHttpTest::tearDown";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void ConnectionRawHttpTest::testDoPost(void) {
  TIMED_FUNC(testDoPost);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering testDoPost";

  // Note not using the Json or Xml helpers as we're not testing them here
  SearchBuilder sb;
  ITextDocumentContent* itdc = sb.toDocument();
  const Response* response = ml->doPost("/v1/search",*itdc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 201 Created",ResponseCode::CREATED == response->getResponseCode());
  delete response;
}
