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

class TestCredentials : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(TestCredentials);
    CPPUNIT_TEST(TestConstructor);
    CPPUNIT_TEST(TestParseWWWAuthenticateHeader);
    CPPUNIT_TEST(TestAuthenticate);
    CPPUNIT_TEST(TestAuthenticate2);
    CPPUNIT_TEST_SUITE_END();
public:
    void TestConstructor(void);
    void TestParseWWWAuthenticateHeader();
    void TestAuthenticate();
    void TestAuthenticate2();
};

#endif /* defined(__Scratch__TestCredentials__) */
