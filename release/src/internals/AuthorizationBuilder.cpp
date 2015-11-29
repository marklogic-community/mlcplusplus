/* 
 * File:   AuthorizationBuilder.cpp
 * Author: phoehne
 * 
 * Created on June 26, 2014, 6:00 PM
 */

#include "AuthorizationBuilder.hpp"
#include "MLCrypto.hpp"

#include "MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {

AuthorizationBuilder::AuthorizationBuilder() {
}

AuthorizationBuilder::AuthorizationBuilder(const AuthorizationBuilder& orig) {
}

AuthorizationBuilder::~AuthorizationBuilder() {
}

std::string AuthorizationBuilder::UsernameRealmAndPassword(const std::string& username, 
        const std::string& realm, const std::string& password) 
{
    std::string result = "";
    MLCrypto crypto;
    result = username + ":" + realm + ":" + password;
    return crypto.Md5(result);
}

std::string AuthorizationBuilder::UserRealmPassNonceCnonce(
        const std::string& username,
        const std::string& realm, 
        const std::string& password, 
        const std::string& nonce, 
        const std::string& cnonce) {
  std::string inner_hash = UsernameRealmAndPassword(username, realm, password);
  
  std::string outer_string = inner_hash + ":" + nonce + ":" + cnonce;
  MLCrypto crypto;
  
  return crypto.Md5(outer_string);
}

std::string AuthorizationBuilder::MethodAndURL(const std::string& method, 
    const std::string& url) 
{
  MLCrypto crypto;
  return crypto.Md5(method + ":" + url);
}

std::string AuthorizationBuilder::MethodURLAndBodyHash(const std::string& method, 
    const std::string& url, const std::string& bodyHash) 
{
  MLCrypto crypto;
  return crypto.Md5(method + ":" + url + ":" + bodyHash);
}

std::string AuthorizationBuilder::Response(const std::string& hash1, 
    const std::string& nonce, 
    const std::string& nonce_count, 
    const std::string& client_nonce, 
    const std::string& qop, 
    const std::string& hash2) 
{
  MLCrypto crypto;
  return crypto.Md5(hash1 + ":" + nonce + ":" + nonce_count + ":" + client_nonce +
      ":" + qop + ":" + hash2);
}

std::string AuthorizationBuilder::Response(const std::string& hash1, 
    const std::string& nonce, const std::string& hash2)
{
  MLCrypto crypto;
  return crypto.Md5(hash1 + ":" + nonce + ":" + hash2);
}

}

}
