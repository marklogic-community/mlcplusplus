//
//  ConnectionDocumentCrudTest.cpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include <cppunit/extensions/HelperMacros.h>
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

using namespace mlclient;

void ConnectionDocumentCrudTest::TestGetJson(void) {
  Connection* ml = ConnectionFactory::getConnection();

  Response response = ml->getDocument("/some/doc.json");

  ResponseType rt = response.GetResponseType();
  if (rt == ResponseType::JSON) { std::cout << "This is a standard response." << std::endl; }
  // TODO XML support

  CPPUNIT_ASSERT_MESSAGE("The response is not a JSON response", ResponseType::JSON  == response.GetResponseType());
  CPPUNIT_ASSERT(ResponseType::JSON  == response.GetResponseType());

}
