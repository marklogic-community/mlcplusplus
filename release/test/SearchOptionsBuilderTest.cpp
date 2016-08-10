/*
 * SearchOptionsBuilderTest.cpp
 *
 *  Created on: 10 Aug 2016
 *      Author: adamfowler
 */


#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include "SearchOptionsBuilderTest.hpp"
#include "mlclient/utilities/SearchOptionsBuilder.hpp"

#include <cpprest/http_client.h>

#include "mlclient/logging.hpp"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(SearchOptionsBuilderTest);

void SearchOptionsBuilderTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE SearchOptionsBuilderTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void SearchOptionsBuilderTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE SearchOptionsBuilderTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

IDocumentContent* genOptions() {
  SearchBuilder sb;
  IQuery* colQuery = sb.collectionQuery(std::vector<std::string>{"zoo"});
  SearchOptionsBuilder builder;
  RangeOptions ro;
  ro.addFacetOptionWithValue(FacetOption::LIMIT,"10");
  JsonPropertyRef* elRef = new JsonPropertyRef;
  elRef->setProperty("age");
  ro.setContainer(elRef);
  ro.setType(RangeIndexType::INT);
  AggregateInfo aggInfo;
  aggInfo.setAggregate(AggregateBuiltIn::AVG);

  std::map<ValuesOption::t,std::string> vos;
  vos.insert(std::pair<ValuesOption::t,std::string>(ValuesOption::SKIP,"2"));
  builder.additionalQuery(*colQuery)->rawSnippet()->valuesRangeAggregate("ageavg",ro,aggInfo,vos);
  ITextDocumentContent* json = builder.toDocument(true);

  return json;
}

void SearchOptionsBuilderTest::testAll() {
  TIMED_FUNC(testAll);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchOptionsBuilderTest::testAll";

  IDocumentContent* json = genOptions();
  LOG(DEBUG) << "builder output: " << json->getContent();

  LOG(DEBUG) << "Attempting to parse JSON output";
  bool success = false;
  try {
    web::json::value val = web::json::value::parse(utility::conversions::to_string_t(json->getContent()));
    LOG(DEBUG) << "Parsed JSON output: " << val;
    success = true;
  } catch (std::exception & ex) {
    LOG(DEBUG) << "CAUGHT EXCEPTION: " << ex.what();
  }

  CPPUNIT_ASSERT_MESSAGE("Parsing of search options JSON was not successful",success);
}

void SearchOptionsBuilderTest::testSave() {
  TIMED_FUNC(testSave);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchOptionsBuilderTest::testSave";

  IDocumentContent* json = genOptions();
  LOG(DEBUG) << "builder output: " << json->getContent();

  LOG(DEBUG) << "Attempting to save JSON output to server";
  bool success = false;
  try {
    LOG(DEBUG) << "Saving options to server";
    Response* response = ml->saveSearchOptions("mlcplusplustest01",json);

    LOG(DEBUG) << "  Response Type: " << response->getResponseType();
    LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
    LOG(DEBUG) << "  Response Content: " << response->getContent();

    //CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response->getResponseType());
    //CPPUNIT_ASSERT(ResponseType::JSON  == response->getResponseType());
    // NB response is BLANK thus NO TYPE

    CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 204 Updated (aka No Content) or 201 Created",
        ResponseCode::CREATED == response->getResponseCode() || ResponseCode::NO_CONTENT == response->getResponseCode());

    delete response;
    success = true;
  } catch (std::exception & ex) {
    LOG(DEBUG) << "CAUGHT EXCEPTION: " << ex.what();
  }

  CPPUNIT_ASSERT_MESSAGE("Saving of search options JSON was not successful",success);
}


