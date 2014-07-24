//
//  AuthenticatingProxyTest.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include <iostream>
#include <string>
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

  Response response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");
  
  ResponseType rt = response.GetResponseType();
  if (rt == ResponseType::JSON) { std::cout << "This is a standard response." << std::endl; }
  

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response.GetResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  
}

void AuthenticatingProxyTest::TestGet2Tap(void) {
  Credentials c("admin", "x8kia30");
  AuthenticatingProxy ap;

  ap.AddCredentials(c);

  Response response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  
  response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
}

void AuthenticatingProxyTest::TestAddCredentials(void) {
    AuthenticatingProxy ap;
    Credentials c("joe", "pass");
    
    ap.AddCredentials(c);
}

void AuthenticatingProxyTest::TestPostJSON(void) {
  Credentials c("admin", "x8kia30");
  AuthenticatingProxy ap;
  ap.AddCredentials(c);
  
  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");
    
  Response response = ap.Post("http://192.168.57.148:8003", 
      "/v1/documents?extension=json&directory=/document/test/",
      payload);
  
  CPPUNIT_ASSERT(ResponseCodes::CREATED == response.GetResponseCode());
  std::string val = response.GetResponseHeaders()["Location"];
  CPPUNIT_ASSERT(val != "");
  
  header_t headers;
  headers["Accept"] = "application/json";
  
  //response = ap.Get("http://192.168.57.148:8003", val, headers);
  //CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  //CPPUNIT_ASSERT(ResponseCodes::OK == response.GetResponseCode());
  
  //web::json::value responded_value = response.Json();
  //std::cout << std::endl << std::endl << responded_value.serialize() << std::endl;
  //std::string expected = responded_value["hello"].as_string();
  //std::cout << std::endl << std::endl;
  //std::cout << expected << std::endl;
  
  //CPPUNIT_ASSERT(expected == std::string("world"));
}
