/* 
 * File:   ResponseTest.cpp
 * Author: phoehne
 * 
 * Created on July 8, 2014, 11:01 AM
 */

#include "ResponseTest.hpp"
#include "Response.hpp"
#include <cpprest/json.h>

CPPUNIT_TEST_SUITE_REGISTRATION(ResponseTest);

using namespace mlclient;

ResponseTest::ResponseTest() {
}

ResponseTest::ResponseTest(const ResponseTest& orig) {
}

ResponseTest::~ResponseTest() {
}

void ResponseTest::testParseContentTypeHeader() {
  std::string example_header = "application/json; charset=utf-8";

  Response response;

  ResponseType type = response.parseContentTypeHeader(example_header);
  CPPUNIT_ASSERT_EQUAL(ResponseType::JSON, type);  
}


