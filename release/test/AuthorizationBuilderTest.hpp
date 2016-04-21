/* 
 * File:   AuthorizationBuilderTest.hpp
 * Author: phoehne
 *
 * Created on June 26, 2014, 6:05 PM
 */

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#ifndef AUTHORIZATIONBUILDERTEST_HPP
#define	AUTHORIZATIONBUILDERTEST_HPP

using namespace mlclient;

class AuthorizationBuilderTest : public CppUnit::TestCase {
public:
  CPPUNIT_TEST_SUITE(AuthorizationBuilderTest);
  CPPUNIT_TEST(testUsernameRealmAndPassword);
  CPPUNIT_TEST(testUserRealmPassNonceCnonce);
  CPPUNIT_TEST(testMethodAndURI);
  CPPUNIT_TEST(testMethodURIAndBodyHash);
  CPPUNIT_TEST(testResponse1);
  CPPUNIT_TEST(testResponse2);
  CPPUNIT_TEST_SUITE_END();
private:

  void testUsernameRealmAndPassword();
  void testUserRealmPassNonceCnonce();
  void testMethodAndURI();
  void testMethodURIAndBodyHash();
  void testResponse1();
  void testResponse2();
};

#endif	/* AUTHORIZATIONBUILDERTEST_HPP */

