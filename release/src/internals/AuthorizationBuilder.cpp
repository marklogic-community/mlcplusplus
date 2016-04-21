/* 
 * File:   AuthorizationBuilder.cpp
 * Author: phoehne
 * 
 * Created on June 26, 2014, 6:00 PM
 */

#include "AuthorizationBuilder.hpp"
#include "MLCrypto.hpp"

#include "../MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {

AuthorizationBuilder::AuthorizationBuilder() {
}

AuthorizationBuilder::AuthorizationBuilder(const AuthorizationBuilder& orig) {
}

AuthorizationBuilder::~AuthorizationBuilder() {
}

std::string AuthorizationBuilder::usernameRealmAndPassword(const std::string& username,
    const std::string& realm, const std::string& password) {
  std::string result = "";
  MLCrypto crypto;
  result = username + ":" + realm + ":" + password;
  return crypto.md5(result);
}

std::string AuthorizationBuilder::userRealmPassNonceCnonce(
    const std::string& username,
    const std::string& realm,
    const std::string& password,
    const std::string& nonce,
    const std::string& cnonce) {
  std::string inner_hash = usernameRealmAndPassword(username, realm, password);

  std::string outer_string = inner_hash + ":" + nonce + ":" + cnonce;
  MLCrypto crypto;

  return crypto.md5(outer_string);
}

std::string AuthorizationBuilder::methodAndURL(const std::string& method,
    const std::string& url) {
  MLCrypto crypto;
  return crypto.md5(method + ":" + url);
}

std::string AuthorizationBuilder::methodURLAndBodyHash(const std::string& method,
    const std::string& url, const std::string& bodyHash) {
  MLCrypto crypto;
  return crypto.md5(method + ":" + url + ":" + bodyHash);
}

std::string AuthorizationBuilder::response(const std::string& hash1,
    const std::string& nonce, 
    const std::string& nonce_count, 
    const std::string& client_nonce, 
    const std::string& qop, 
    const std::string& hash2) {
  MLCrypto crypto;
  return crypto.md5(hash1 + ":" + nonce + ":" + nonce_count + ":" + client_nonce +
      ":" + qop + ":" + hash2);
}

std::string AuthorizationBuilder::response(const std::string& hash1,
    const std::string& nonce, const std::string& hash2){
  MLCrypto crypto;
  return crypto.md5(hash1 + ":" + nonce + ":" + hash2);
}

} // end internals namespace

} // end mlclient namespace
