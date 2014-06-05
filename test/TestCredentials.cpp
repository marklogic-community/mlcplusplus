//
//  TestCredentials.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <string>
#include "TestCredentials.hpp"
#include "Credentials.hpp"
#include <boost/regex.hpp>

const std::string TEST_HEADER = "Digest realm=\"public\", qop=\"auth\", nonce=\"79e3998e2a65a2bbb69c4027708f4bca\", opaque=\"5db0205ddeca8742\"";

const std::string AUTHENT_HEADER_NAME = "WWW-Authenticate";
const std::string AUTH_HEADER_NAME = "Authorization";

CPPUNIT_TEST_SUITE_REGISTRATION(TestCredentials);

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

void TestCredentials::TestAuthenicate() {
    Credentials c1("Joe", "password");
    header_t headers, output_headers;
    headers[AUTHENT_HEADER_NAME] = TEST_HEADER;
    
    c1.Authenticate("GET", "/some/path", headers, output_headers);
    
    CPPUNIT_ASSERT(output_headers.find(AUTH_HEADER_NAME) != output_headers.end());
    
    std::string auth_header = output_headers[AUTH_HEADER_NAME];
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("Digest")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("realm=\"public\"")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("nonce=\"79e3998e2a65a2bbb69c4027708f4bca\"")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("uri=\"/some/path\"")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("qop=\"auth\"")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("opaque=\"5db0205ddeca8742\"")));
    CPPUNIT_ASSERT(boost::regex_search(auth_header, boost::regex("response=\"[a-z0-9]+\"")));
    
    
    
}