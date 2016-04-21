/* 
 * File:   MLCryptoTest.cpp
 * Author: phoehne
 * 
 * Created on July 7, 2014, 10:35 AM
 */

#include <cstdint>
#include <string>
#include "MLCryptoTest.hpp"
#include "internals/MLCrypto.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(MLCryptoTest);

using namespace mlclient;
using namespace mlclient::internals;

MLCryptoTest::MLCryptoTest() {
}

MLCryptoTest::MLCryptoTest(const MLCryptoTest& orig) {
}

MLCryptoTest::~MLCryptoTest() {
}

void MLCryptoTest::testToHex() {
  MLCrypto crypto;

  uint8_t zero = 0;     std::string zero_str = "00";
  uint8_t one = 1;      std::string one_str = "01";
  uint8_t ten = 10;     std::string ten_str = "0a";
  uint8_t sixteen = 16; std::string sixteen_str = "10";

  CPPUNIT_ASSERT_EQUAL(zero_str, crypto.toHex(&zero, 1));
  CPPUNIT_ASSERT_EQUAL(one_str, crypto.toHex(&one, 1));
  CPPUNIT_ASSERT_EQUAL(ten_str, crypto.toHex(&ten, 1));
  CPPUNIT_ASSERT_EQUAL(sixteen_str, crypto.toHex(&sixteen, 1));
}

void MLCryptoTest::testMd5() {
  MLCrypto crypto;

  // MD5 of the word 'test'
  std::string expected = "098f6bcd4621d373cade4e832627b4f6";

  CPPUNIT_ASSERT_EQUAL(expected, crypto.md5("test"));
}
