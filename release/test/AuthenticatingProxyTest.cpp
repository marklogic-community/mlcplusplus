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
#include "internals/AuthenticatingProxy.hpp"
#include "internals/Credentials.hpp"
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "internals/Types.hpp"
#include "NoCredentialsException.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AuthenticatingProxyTest);

using namespace mlclient;

void AuthenticatingProxyTest::testGet(void) {
  internals::Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;

  ap.addCredentials(c);

  const Response& response = ap.getSync("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  ResponseType rt = response.getResponseType();
  if (rt == ResponseType::JSON) { std::cout << "This is a standard response." << std::endl; }


  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response.getResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response.getResponseType());

}

void AuthenticatingProxyTest::testGet2Tap(void) {
  internals::Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;

  ap.addCredentials(c);

  const Response& response = ap.getSync("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response.getResponseType());

  const Response& response2 = ap.getSync("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  CPPUNIT_ASSERT(ResponseType::JSON  == response2.getResponseType());
}

void AuthenticatingProxyTest::testAddCredentials(void) {
  mlclient::internals::AuthenticatingProxy ap;
  internals::Credentials c("joe", "pass");

  ap.addCredentials(c);
}

void AuthenticatingProxyTest::testPostJSON(void) {
  internals::Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
  ap.addCredentials(c);

  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");

  const Response& response = ap.postSync("http://192.168.57.148:8003",
      "/v1/documents?extension=json&directory=/document/test/",
      payload);

  CPPUNIT_ASSERT(ResponseCode::CREATED == response.getResponseCode());
  std::string val = response.getResponseHeaders()["Location"];
  CPPUNIT_ASSERT(val != "");

  web::http::http_headers headers;
  headers["Accept"] = "application/json";

  const Response& response2 = ap.getSync("http://192.168.57.148:8003", val, headers);
  CPPUNIT_ASSERT(ResponseType::JSON  == response2.getResponseType());
  CPPUNIT_ASSERT(ResponseCode::OK == response2.getResponseCode());

  web::json::value responded_value = response2.asJson();
  std::string expected = responded_value["hello"].as_string();

  CPPUNIT_ASSERT(expected == std::string("world"));

}

void AuthenticatingProxyTest::testPutJSON(void) {
  internals::Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
  ap.addCredentials(c);

  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");

  const Response& response = ap.postSync("http://192.168.57.148:8003",
      "/v1/documents?extension=json&directory=/document/test/",
      payload);  
  std::string location = response.getResponseHeaders()["Location"];

  web::http::http_headers headers;

  payload[utility::string_t("hello")] = web::json::value::string("Mars");

  const Response& response2 = ap.putSync("http://192.168.57.148:8003", location, payload);
  CPPUNIT_ASSERT_MESSAGE("Failed put", ResponseCode::NO_CONTENT == response2.getResponseCode());

  const Response& response3 = ap.getSync("http://192.168.57.148:8003", location);

  web::json::value responded_value = response3.asJson();
  std::string expected = responded_value["hello"].as_string();

  CPPUNIT_ASSERT_MESSAGE("Incorrect response in resultant data", expected == std::string("Mars"));

}

void AuthenticatingProxyTest::testDelete(void) {
  internals::Credentials c("admin", "x8kia30");
  mlclient::internals::AuthenticatingProxy ap;
  ap.addCredentials(c);

  web::json::value payload;
  payload[utility::string_t("hello")] = web::json::value::string("world");

  const Response& response = ap.postSync("http://192.168.57.148:8003",
      "/v1/documents?extension=json&directory=/document/test/",
      payload);  
  std::string location = response.getResponseHeaders()["Location"];


  const Response& response2 = ap.deleteSync("http://192.168.57.148:8003", location);
  CPPUNIT_ASSERT_MESSAGE("Failed delete", ResponseCode::NO_CONTENT == response2.getResponseCode());

  const Response& response3 = ap.getSync("http://192.168.57.148:8003", location);
  CPPUNIT_ASSERT_MESSAGE("There should be nothing there", ResponseCode::NOT_FOUND == response3.getResponseCode());

}
