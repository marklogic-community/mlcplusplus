//
//  AuthenticatingProxyTest.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include <cppunit/extensions/HelperMacros.h>
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

using namespace mlclient;

void AuthenticatingProxyTest::TestGet(void) {
  Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;

  ap.AddCredentials(c);

  Response response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");
  
  ResponseType rt = response.GetResponseType();
  if (rt == ResponseType::JSON) { std::cout << "This is a standard response." << std::endl; }
  

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response.GetResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  
}

void AuthenticatingProxyTest::TestGet2Tap(void) {
  Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;

  ap.AddCredentials(c);

  Response response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  
  response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
}

void AuthenticatingProxyTest::TestAddCredentials(void) {
    mlclient::internals::AuthenticatingProxy ap;
    Credentials c("joe", "pass");
    
    ap.AddCredentials(c);
}

void AuthenticatingProxyTest::TestPostJSON(void) {
  Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
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
  
  response = ap.Get("http://192.168.57.148:8003", val, headers);
  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());
  CPPUNIT_ASSERT(ResponseCodes::OK == response.GetResponseCode());
  
  web::json::value responded_value = response.Json();
  std::string expected = responded_value["hello"].as_string();
  
  CPPUNIT_ASSERT(expected == std::string("world"));
  
}

void AuthenticatingProxyTest::TestPutJSON(void) {
  Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
  ap.AddCredentials(c);
  
  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");
  
  Response response = ap.Post("http://192.168.57.148:8003", 
      "/v1/documents?extension=json&directory=/document/test/",
      payload);  
  std::string location = response.GetResponseHeaders()["Location"];
  
  header_t headers;
  
  payload[utility::string_t("hello")] = web::json::value::string("Mars");
  
  response = ap.Put("http://192.168.57.148:8003", location, payload);
  CPPUNIT_ASSERT_MESSAGE("Failed put", ResponseCodes::NO_CONTENT == response.GetResponseCode());
  
  response = ap.Get("http://192.168.57.148:8003", location);
  
  web::json::value responded_value = response.Json();
  std::string expected = responded_value["hello"].as_string();
  
  CPPUNIT_ASSERT_MESSAGE("Incorrect response in resultant data", expected == std::string("Mars"));
  
}

void AuthenticatingProxyTest::TestDelete(void) {
  Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
  ap.AddCredentials(c);
  
  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");
  
  Response response = ap.Post("http://192.168.57.148:8003", 
      "/v1/documents?extension=json&directory=/document/test/",
      payload);  
  std::string location = response.GetResponseHeaders()["Location"];
    
  
  response = ap.Delete("http://192.168.57.148:8003", location);
  CPPUNIT_ASSERT_MESSAGE("Failed delete", ResponseCodes::NO_CONTENT == response.GetResponseCode());
  
  response = ap.Get("http://192.168.57.148:8003", location);  
  CPPUNIT_ASSERT_MESSAGE("There should be nothing there", ResponseCodes::NOT_FOUND == response.GetResponseCode());
  
}
