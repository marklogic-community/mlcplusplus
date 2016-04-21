/* 
 * File:   ResponseTest.hpp
 * Author: phoehne
 *
 * Created on July 8, 2014, 11:01 AM
 */

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#ifndef RESPONSETEST_HPP
#define	RESPONSETEST_HPP

using namespace mlclient;

class ResponseTest : public CppUnit::TestCase {
public:
  ResponseTest();
  ResponseTest(const ResponseTest& orig);
  virtual ~ResponseTest();

  void testParseContentTypeHeader();
private:
  CPPUNIT_TEST_SUITE(ResponseTest);
  CPPUNIT_TEST(testParseContentTypeHeader);
  CPPUNIT_TEST_SUITE_END();
};

#endif	/* RESPONSETEST_HPP */

