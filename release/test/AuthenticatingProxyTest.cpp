//
//  AuthenticatingProxyTest.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include "AuthenticatingProxyTest.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"
#include "NoCredentialsException.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AuthenticatingProxyTest);

void AuthenticatingProxyTest::TestGet(void) {
    
    CPPUNIT_FAIL("Not Implemented");
}

void AuthenticatingProxyTest::TestAddCredentials(void) {
    AuthenticatingProxy ap;
    Credentials c("joe", "pass");
    
    ap.AddCredentials(c);
    
    
}