
#ifndef TEST_CONNECTIONVALUESTEST_HPP_
#define TEST_CONNECTIONVALUESTEST_HPP_


#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include <string>

using namespace mlclient;

class ConnectionValuesTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionValuesTest);
    CPPUNIT_TEST(testValues);
    CPPUNIT_TEST(testValuesUDF);
    CPPUNIT_TEST(testValuesExtension);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testValues(void);
  void testValuesUDF(void);
  void testValuesExtension(void);
private:
  IConnection* ml;
};




#endif /* TEST_CONNECTIONVALUESTEST_HPP_ */
