//
//  TestCredentials.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef __Scratch__TestCredentials__
#define __Scratch__TestCredentials__

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace mlclient;

class TestCredentials : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(TestCredentials);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testParseWWWAuthenticateHeader);
  CPPUNIT_TEST(testAuthenticate);
  CPPUNIT_TEST(testAuthenticate2);
  CPPUNIT_TEST_SUITE_END();
public:
  void testConstructor(void);
  void testParseWWWAuthenticateHeader();
  void testAuthenticate();
  void testAuthenticate2();
};

#endif /* defined(__Scratch__TestCredentials__) */
