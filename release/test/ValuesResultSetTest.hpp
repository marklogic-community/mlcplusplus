/**
 * \file ValuesResultSetTest.hpp
 *
 * \date 16 Aug 2016
 * \author adamfowler
 */

#ifndef TEST_VALUESRESULTSETTEST_HPP_
#define TEST_VALUESRESULTSETTEST_HPP_



#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"


using namespace mlclient;

class ValuesResultSetTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ValuesResultSetTest);
    CPPUNIT_TEST(testTwoAggregates);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testTwoAggregates(void);
private:
  IConnection* ml;
};



#endif /* TEST_VALUESRESULTSETTEST_HPP_ */
