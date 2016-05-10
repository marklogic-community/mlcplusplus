/**
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

#include "easylogging++.h"

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
  delete ml;
  ml = NULL;
}

void ConnectionSearchTest::testEmptySearch() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " Entering testEmptySearch";
  SearchDescription desc; // default empty search object
  LOG(DEBUG) << "  Got a blank SearchDescription object instance";

  const std::unique_ptr<Response> response = ml->search(desc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response->getResponseType());

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
}
