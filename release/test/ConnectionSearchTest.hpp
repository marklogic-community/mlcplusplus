/*
 * ConnectionSearchTest.hpp
 *
 *  Created on: 10 May 2016
 *      Author: adamfowler
 */

#ifndef TEST_CONNECTIONSEARCHTEST_HPP_
#define TEST_CONNECTIONSEARCHTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "NoCredentialsException.hpp"


using namespace mlclient;

class ConnectionSearchTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionSearchTest);
    CPPUNIT_TEST(testEmptySearch);
    CPPUNIT_TEST(testQueryText);
    CPPUNIT_TEST(testWordQuery);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testEmptySearch(void);
  void testQueryText(void);
  void testWordQuery(void);
private:
  Connection* ml;
  std::string json;
  std::string xml;
  std::string jsonUri;
  std::string xmlUri;
};


#endif /* TEST_CONNECTIONSEARCHTEST_HPP_ */
