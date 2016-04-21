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
  CPPUNIT_TEST(TestUsernameRealmAndPassword);
  CPPUNIT_TEST(TestUserRealmPassNonceCnonce);
  CPPUNIT_TEST(TestMethodAndURI);
  CPPUNIT_TEST(TestMethodURIAndBodyHash);
  CPPUNIT_TEST(TestResponse1);
  CPPUNIT_TEST(TestResponse2);
  CPPUNIT_TEST_SUITE_END();
private:

  void TestUsernameRealmAndPassword();
  void TestUserRealmPassNonceCnonce();
  void TestMethodAndURI();
  void TestMethodURIAndBodyHash();
  void TestResponse1();
  void TestResponse2();
};

#endif	/* AUTHORIZATIONBUILDERTEST_HPP */

