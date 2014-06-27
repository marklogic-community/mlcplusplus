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

class AuthorizationBuilderTest : public CppUnit::TestCase {
public:
    CPPUNIT_TEST_SUITE(AuthorizationBuilderTest);
    CPPUNIT_TEST(TestUsernameRealmAndPassword);
    CPPUNIT_TEST_SUITE_END();
private:

    void TestUsernameRealmAndPassword();
};

#endif	/* AUTHORIZATIONBUILDERTEST_HPP */

