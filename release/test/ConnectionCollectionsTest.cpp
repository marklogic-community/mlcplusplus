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
//  ConnectionCollectionsTest.cpp
//  Created by Adam Fowler on 08 Jun 2016.
//

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionCollectionsTest.hpp"
#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "NoCredentialsException.hpp"
#include "utilities/ResponseHelper.hpp"

#include <string>

#include "ext/easylogging++.h"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionCollectionsTest);


void ConnectionCollectionsTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ConnectionCollectionsTest::setUp";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void ConnectionCollectionsTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ConnectionCollectionsTest::tearDown";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void ConnectionCollectionsTest::testListTopLevelCollections(void) {
  TIMED_FUNC(testSaveJson);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering testListTopLevelCollections";

  const Response* response = ml->listRootCollections();

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();
  bool inError = mlclient::utilities::ResponseHelper::isInError(*response);
  if (inError) {
    LOG(DEBUG) << "  Response IS in error";
    LOG(DEBUG) << "    Message: " << mlclient::utilities::ResponseHelper::getErrorMessage(*response);
    LOG(DEBUG) << "    Detail: " << mlclient::utilities::ResponseHelper::getErrorDetailAsString(*response);
  } else {
    LOG(DEBUG) << "  Response is NOT in error";
    LOG(DEBUG) << "  Collection list:-";
    for (auto iter: mlclient::utilities::ResponseHelper::getSuggestions(*response)) {
      LOG(DEBUG) << "    " << iter;
    }
  }

  CPPUNIT_ASSERT_MESSAGE("Response is in error",!inError);

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  delete response;
}
