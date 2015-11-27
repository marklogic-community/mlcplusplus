//
//  ConnectionDocumentCrudTest.cpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include <iostream>
#include <string>
#include "MLCPlusPlus.hpp"
#include "AuthenticatingProxyTest.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "Types.hpp"
#include "NoCredentialsException.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionDocumentCrudTest);

void ConnectionDocumentCrudTest::TestGet(void) {
  Credentials c("admin", "x8kia30");
  AuthenticatingProxy ap;

  ap.AddCredentials(c);

  Response response = ap.Get("http://192.168.57.148:8003", "/v1/documents?uri=/document/test.json");

  ResponseType rt = response.GetResponseType();
  if (rt == ResponseType::JSON) { std::cout << "This is a standard response." << std::endl; }


  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response.GetResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());

}


void ConnectionDocumentCrudTest::TestDelete(void) {
  Credentials c("admin", "x8kia30");
  AuthenticatingProxy ap;
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
