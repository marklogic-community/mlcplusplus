/*
 * SearchResultSetTest.hpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#ifndef TEST_SEARCHBUILDERTEST_HPP_
#define TEST_SEARCHBUILDERTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "Connection.hpp"


using namespace mlclient;

class SearchBuilderTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(SearchBuilderTest);
    CPPUNIT_TEST(testAll);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testAll(void);
private:
  IConnection* ml;
};

#endif /* TEST_SEARCHBUILDERTEST_HPP_ */
