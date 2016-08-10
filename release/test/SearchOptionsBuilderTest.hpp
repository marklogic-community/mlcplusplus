/*
 * SearchoptionsBuilderTest.hpp
 *
 *  Created on: 10 Aug 2016
 *      Author: adamfowler
 */

#ifndef TEST_SEARCHOPTIONSBUILDERTEST_HPP_
#define TEST_SEARCHOPTIONSBUILDERTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"


using namespace mlclient;

class SearchOptionsBuilderTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(SearchOptionsBuilderTest);
    CPPUNIT_TEST(testAll);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testAll(void);
private:
  IConnection* ml;
};

#endif /* TEST_SEARCHOPTIONSBUILDERTEST_HPP_ */
