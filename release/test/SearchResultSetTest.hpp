/*
 * SearchResultSetTest.hpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#ifndef TEST_SEARCHRESULTSETTEST_HPP_
#define TEST_SEARCHRESULTSETTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"


using namespace mlclient;

class SearchResultSetTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(SearchResultSetTest);
    CPPUNIT_TEST(testEmptySearch);
    CPPUNIT_TEST(testThreePages);
    CPPUNIT_TEST(testCustomSnippetXml);
    CPPUNIT_TEST(testCustomSnippetJson);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testEmptySearch(void);
  void testThreePages(void);
  void testCustomSnippetXml(void);
  void testCustomSnippetJson(void);
private:
  IConnection* ml;
};

#endif /* TEST_SEARCHRESULTSETTEST_HPP_ */
