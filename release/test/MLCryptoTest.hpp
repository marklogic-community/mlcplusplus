/* 
 * File:   MLCryptoTest.hpp
 * Author: phoehne
 *
 * Created on July 7, 2014, 10:35 AM
 */

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#ifndef MLCRYPTOTEST_HPP
#define	MLCRYPTOTEST_HPP

using namespace mlclient;

class MLCryptoTest : public CppUnit::TestCase {
public:
  MLCryptoTest();
  MLCryptoTest(const MLCryptoTest& orig);
  virtual ~MLCryptoTest();

  void testToHex();
  void testMd5();
private:

  CPPUNIT_TEST_SUITE(MLCryptoTest);
  CPPUNIT_TEST(testToHex);
  CPPUNIT_TEST(testMd5);
  CPPUNIT_TEST_SUITE_END();
};

#endif	/* MLCRYPTOTEST_HPP */

