/*
 * PathNavigatorTest.hpp
 *
 *  Created on: 06 Dec 2016
 *      Author: adamfowler
 */

#ifndef TEST_PATHNAVIGATORTEST_HPP_
#define TEST_PATHNAVIGATORTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"


using namespace mlclient;

class PathNavigatorTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(PathNavigatorTest);
    CPPUNIT_TEST(testXmlPath);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testXmlPath(void);
private:
  IConnection* ml;
};

#endif /* TEST_PATHNAVIGATORTEST_HPP_ */
