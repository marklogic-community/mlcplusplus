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
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "Types.hpp"
#include "NoCredentialsException.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AuthenticatingProxyTest);

void AuthenticatingProxyTest::TestGet(void) {
  Credentials c("admin", "x8kia30");
  AuthenticatingProxy ap;

  ap.AddCredentials(c);

  Response response = ap.Get("http://192.168.57.148:8003", "/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  
}

void AuthenticatingProxyTest::TestAddCredentials(void) {
    AuthenticatingProxy ap;
    Credentials c("joe", "pass");
    
    ap.AddCredentials(c);
    
    
}
