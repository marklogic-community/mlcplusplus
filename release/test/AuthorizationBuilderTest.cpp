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
#include "AuthorizationBuilder.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(AuthorizationBuilderTest);

void AuthorizationBuilderTest::TestUsernameRealmAndPassword() {
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
    for (size_t i = 0; i < 16; i++) { hex_ss << buffer[i]; }
    
    AuthorizationBuilder builder;
    std::string ha1 = builder.UsernameRealmAndPassword(username, realm, password);
    
    CPPUNIT_ASSERT_EQUAL(oss.str(), ha1);
}
