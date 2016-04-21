/* 
 * File:   AuthorizationBuilderTest.cpp
 * Author: phoehne
 * 
 * Created on June 26, 2014, 6:05 PM
 */

#include <string>
#include <iostream>
#include <sstream>
#include <cstdint>
#include <iomanip>
#include <openssl/md5.h>

#include "AuthorizationBuilderTest.hpp"
#include "internals/AuthorizationBuilder.hpp"
#include "internals/MLCrypto.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AuthorizationBuilderTest);

using namespace mlclient;

void AuthorizationBuilderTest::testUsernameRealmAndPassword() {
  std::string username = "joeuser";
  std::string realm = "myrealm";
  std::string password = "password";

  std::ostringstream oss;
  uint8_t buffer[16];

  oss << username << ":" << realm << ":" << password;

  MD5_CTX _context;
  MD5_Init(&_context);
  MD5_Update(&_context, oss.str().c_str(), oss.str().size());
  MD5_Final(buffer, &_context);

  std::ostringstream hex_ss;
  hex_ss << std::hex;
  for (size_t i = 0; i < 16; i++) { 
    hex_ss << std::setfill('0') << std::setw(2) << (int)buffer[i]; 
  }

  internals::AuthorizationBuilder builder;
  CPPUNIT_ASSERT_EQUAL(hex_ss.str(), builder.usernameRealmAndPassword(username, realm, password));
}

void AuthorizationBuilderTest::testUserRealmPassNonceCnonce() {
  internals::MLCrypto crypto;
  std::string username = "joe";
  std::string realm = "realm";
  std::string password = "password";
  std::string nonce = "012345";
  std::string cnonce = "000001";

  std::string part_1 = crypto.md5(username + ":" + realm + ":" + password);
  std::string hash = crypto.md5(part_1 + ":" + nonce + ":" + cnonce);

  internals::AuthorizationBuilder builder;

  CPPUNIT_ASSERT_EQUAL(hash, builder.userRealmPassNonceCnonce(username, realm,
      password, nonce, cnonce));
}


void AuthorizationBuilderTest::testMethodAndURI() {
  internals::MLCrypto crypto;

  std::string method = "GET";
  std::string uri = "http://foo.bar.com/some/uri.html";
  std::string hash = "fbf2a47e19579171f6587884a7c7cd88";

  internals::AuthorizationBuilder builder;
  CPPUNIT_ASSERT_EQUAL(hash, builder.methodAndURL(method, uri));
}

void AuthorizationBuilderTest::testMethodURIAndBodyHash() {
  std::string hash = "8e8c36970df5e7371dfda6202a6720be";
  internals::MLCrypto crypto;

  std::string method = "GET";
  std::string uri = "http://foo.bar.com/some/uri.html";
  std::string bodyHash = crypto.md5("body");

  internals::AuthorizationBuilder builder;
  CPPUNIT_ASSERT_EQUAL(hash, builder.methodURLAndBodyHash(method, uri, bodyHash));
}

/*
 * username="admin", 
 * realm="public", 
 * nonce="9ca86b1d41652cdc4c2d14d2043d2c25", 
 * uri="/", 
 * response="7af18aeaf1b3e96ade1fcde51aad422e", 
 * opaque="c8fb41173a096fd0", 
 * qop=auth, 
 * nc=00000001, 
 * cnonce="72315add23f0224a"
 */
void AuthorizationBuilderTest::testResponse1() {
  std::string hash = "ec817aae17c45b164882ecaa9491c6e2";
  std::string username = "admin";
  std::string realm = "public";
  std::string password = "password";
  std::string uri="/";
  std::string method = "GET";
  std::string opaque = "c8fb41173a096fd0";
  std::string qop = "auth";
  std::string nonce_count = "00000001";
  std::string cnonce = "72315add23f0224a";
  std::string nonce = "9ca86b1d41652cdc4c2d14d2043d2c25";

  std::string hash1, hash2;

  internals::AuthorizationBuilder builder;
  hash1 = builder.usernameRealmAndPassword(username, realm, password);
  hash2 = builder.methodAndURL(method, uri);
  std::string response = builder.response(hash1, nonce, nonce_count, cnonce, qop,
      hash2);

  CPPUNIT_ASSERT_EQUAL(hash, response);
}

void AuthorizationBuilderTest::testResponse2() {
  std::string hash = "f2aecff82351aae06344385e4a3add6e";
  std::string username = "admin";
  std::string realm = "public";
  std::string password = "password";
  std::string uri="/";
  std::string method = "GET";
  std::string nonce = "9ca86b1d41652cdc4c2d14d2043d2c25";

  std::string hash1, hash2;

  internals::AuthorizationBuilder builder;
  hash1 = builder.usernameRealmAndPassword(username, realm, password);
  hash2 = builder.methodAndURL(method, uri);

  std::string response = builder.response(hash1, nonce, hash2);

  CPPUNIT_ASSERT_EQUAL(hash, response);
}
