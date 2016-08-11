
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionValuesTest.hpp"
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/utilities/ResponseHelper.hpp"

#include <string>

#include "mlclient/logging.hpp"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionValuesTest);


void ConnectionValuesTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE ConnectionValuesTest::setUp";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void ConnectionValuesTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE ConnectionValuesTest::tearDown";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void ConnectionValuesTest::testValues(void) {
  TIMED_FUNC(testValues);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering ConnectionValuesTest::testValues";

  const Response* response = ml->values("ageavg","mlcplusplustest01");

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
    double result = mlclient::utilities::ResponseHelper::getAggregateResult(*response,"avg"); // Aggregate name, NOT configuration name within options (BUG?)
    LOG(DEBUG) << "  Double aggregate result(Rounded by output stream - value IS correct): " << result; // gets rounded as standard by IO stream
    CPPUNIT_ASSERT_MESSAGE("Response is in error",!inError);
    CPPUNIT_ASSERT_MESSAGE("Result is -1 (values result not found in response)",-1 != result);
  }

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  delete response;
}

void ConnectionValuesTest::testValuesExtension(void) {
  TIMED_FUNC(testValuesExtension);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering ConnectionValuesTest::testValuesExtension";


  SearchDescription* desc = new SearchDescription; // default empty search object
  SearchBuilder* builder = new SearchBuilder;
  IQuery* colQuery = builder->collectionQuery(std::vector<std::string>{"zoo"});
  ITextDocumentContent* searchDoc = builder->toDocument();
  LOG(DEBUG) << "got search doc from builder";
  LOG(DEBUG) << "testValuesExtension search content: " << searchDoc->getContent();
  desc->setQuery(*searchDoc);
  LOG(DEBUG) << "  Got a SearchDescription object instance";

  const Response* response = ml->valuesExtension("customvalues","ageavg","mlcplusplustest01",*desc);

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
    double result = mlclient::utilities::ResponseHelper::getAggregateResult(*response,"avg"); // Aggregate name, NOT configuration name within options (TODO log BUG for this)
    LOG(DEBUG) << "  Double aggregate result(Rounded by output stream - value IS correct): " << result; // gets rounded as standard by IO stream
    CPPUNIT_ASSERT_MESSAGE("Response is in error",!inError);
    CPPUNIT_ASSERT_MESSAGE("Result is -1 (values result not found in response)",-1 != result);
  }

  CPPUNIT_ASSERT_MESSAGE("REST API did not return HTTP 200 OK",ResponseCode::OK == response->getResponseCode());
  delete response;
}
