//
//  AuthenticatingProxyTest.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#ifndef __Scratch__AuthenticatingProxyTest__
#define __Scratch__AuthenticatingProxyTest__


class AuthenticatingProxyTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(AuthenticatingProxyTest);
  CPPUNIT_TEST(testGet);
  CPPUNIT_TEST(testGet2Tap);
  CPPUNIT_TEST(testAddCredentials);
  CPPUNIT_TEST(testPostJSON);
  CPPUNIT_TEST(testPutJSON);
  CPPUNIT_TEST(testDelete);
  CPPUNIT_TEST_SUITE_END();
public:
  void testGet(void);
  void testAddCredentials(void);
  void testGet2Tap(void);
  void testPostJSON(void);
  void testPutJSON(void);
  void testDelete(void);
};

#endif /* defined(__Scratch__AuthenticatingProxyTest__) */
