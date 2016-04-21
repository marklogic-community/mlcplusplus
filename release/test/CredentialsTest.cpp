//
//  TestCredentials.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <string>
#include "CredentialsTest.hpp"
#include "internals/Credentials.hpp"
#include <boost/regex.hpp>

const std::string TEST_HEADER = "Digest realm=\"public\", qop=\"auth\", nonce=\"79e3998e2a65a2bbb69c4027708f4bca\", opaque=\"5db0205ddeca8742\"";

const std::string AUTHENT_HEADER_NAME = "WWW-Authenticate";
const std::string AUTH_HEADER_NAME = "Authorization";

CPPUNIT_TEST_SUITE_REGISTRATION(TestCredentials);

using namespace mlclient;
using namespace mlclient::internals;

void TestCredentials::TestConstructor() {
  Credentials c1;
  Credentials c2("user", "pass");
  Credentials c3(L"user", L"pass");
}


void TestCredentials::TestParseWWWAuthenticateHeader() {
  Credentials c1;

  c1.ParseWWWAthenticateHeader(TEST_HEADER);

  CPPUNIT_ASSERT_EQUAL(std::string("public"), c1.Realm());
  CPPUNIT_ASSERT_EQUAL(std::string("auth"), c1.Qop());
  CPPUNIT_ASSERT_EQUAL(std::string("79e3998e2a65a2bbb69c4027708f4bca"), c1.Nonce());
  CPPUNIT_ASSERT_EQUAL(std::string("5db0205ddeca8742"), c1.Opaque());
}

void TestCredentials::TestAuthenticate() {
  Credentials c1("Joe", "password");
  header_t headers, output_headers;

  std::string result = c1.Authenticate("GET", "/some/path", TEST_HEADER);


  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("Digest")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("realm=\"public\"")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("nonce=\"79e3998e2a65a2bbb69c4027708f4bca\"")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("uri=\"/some/path\"")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("qop=auth")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("opaque=\"5db0205ddeca8742\"")));
  CPPUNIT_ASSERT(boost::regex_search(result, boost::regex("response=\"[a-z0-9]+\"")));
}

void TestCredentials::TestAuthenticate2() {
  std::string header = std::string("Digest realm=\"public\", qop=\"auth\", ") + 
      "nonce=\"c5d9544ee5f63a0b26b92224ea05bb30\", opaque=\"ef2f69bd929d0619\"";

  Credentials c1("admin", "x8kia30", "4724e19fc8d23421de47fd23300f74b0", 0);

  header_t headers, output_headers;
  headers[AUTHENT_HEADER_NAME] = header;
  std::string reply = c1.Authenticate("GET", "/v1/documents?uri=/document/test.json", 
      header);

  CPPUNIT_ASSERT(boost::regex_search(reply, 
      boost::regex("response=\"e36a1eaaea704f13d0fab930755b644e\"")));

}
