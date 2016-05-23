/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Credentials.cpp
 * Created by Paul Hoehne on 5/29/14.
 */

#include "Credentials.hpp"
#include <sstream>
#include <iomanip>
#include <regex> // replaces boost regex in C++11
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cpprest/http_client.h>
#include "MLCrypto.hpp"
#include "AuthorizationBuilder.hpp"

#include "../ext/easylogging++.h"

namespace mlclient {

namespace internals {
using namespace web::http;

const std::regex REALM_RE("[R|r]ealm=\"(\\w+)\"");
const std::regex QOP_RE("qop=\"(\\w+)\"");
const std::regex NONCE_RE("nonce=\"([a-z0-9]+)\"");
const std::regex OPAQUE_RE("opaque=\"([a-z0-9]+)\"");
const utility::string_t AUTHORIZATION_HEADER_NAME = U("Authorization");
const utility::string_t WWW_AUTHENTICATE_HEADER = U("WWW-Authenticate");

Credentials::Credentials() : nonce_count(0) {
  cnonce = generateRandomCnonce();
}

Credentials::Credentials(const std::string& user, const std::string& pass) :
        user(std::wstring(user.begin(), user.end())), pass(pass.begin(), pass.end()),
        nonce_count(0)
{
  cnonce = generateRandomCnonce();
}

Credentials::Credentials(const std::wstring& user, const std::wstring& pass) :
        user(user), pass(pass), nonce_count(0)
{
  cnonce = generateRandomCnonce();
}

Credentials::Credentials(const std::string& username, const std::string& password,
    const std::string& cnonce, const uint32_t& nc) :
            user(username.begin(), username.end()),
            pass(password.begin(), password.end()),
            cnonce(cnonce),
            nonce_count(nc)
{

}

std::string Credentials::generateRandomCnonce() const
{

  internals::MLCrypto crypto;
  boost::uuids::uuid random_uuid = boost::uuids::random_generator()();
  std::string my_random_uuid = boost::uuids::to_string(random_uuid);
  return crypto.md5(my_random_uuid);
}


Credentials::~Credentials() {

}

bool Credentials::canAuthenticate() const {
  return user != L"" && pass != L"" && nonce != "" && realm != "";
}

void Credentials::parseWWWAthenticateHeader(const std::string& raw) {
  std::smatch matches;
  if (std::regex_search(raw, matches, REALM_RE)) {
    realm = matches[1];
  } else {
    realm.clear();
  }

  if(std::regex_search(raw, matches, QOP_RE)) {
    qop = matches[1];
  } else {
    qop.clear();
  }

  if (std::regex_search(raw, matches, NONCE_RE)) {
    nonce = matches[1];
  } else {
    nonce.clear();
  }

  if (std::regex_search(raw, matches, OPAQUE_RE)) {
    opaque = matches[1];
  } else {
    opaque.clear();
  }
}

std::string Credentials::authenticate(const std::string& method, const std::string& uri, const std::string& auth_header) {
  parseWWWAthenticateHeader(auth_header);

  return authenticate(method, uri);
}

std::string Credentials::authenticate(const std::string& method, const std::string& uri) {
  std::ostringstream oss;
  internals::AuthorizationBuilder builder;
  nonce_count++;

  std::ostringstream temp;
  std::string username(user.begin(), user.end());
  std::string password(pass.begin(), pass.end());

  std::string a1 = builder.usernameRealmAndPassword(username, realm, password);
  std::string a2 = builder.methodAndURL(method, uri);

  oss << std::setfill('0') << std::setw(8) << nonce_count;
  std::string nc = oss.str();

  std::string response = builder.response(a1, nonce, oss.str(), cnonce,
      qop, a2);

  oss.str("");
  oss << " Digest";
  oss << " username=\"" << username << "\",";
  oss << " realm=\"" << realm << "\",";
  oss << " nonce=\"" << nonce << "\",";
  oss << " uri=\"" << uri << "\",";
  oss << " cnonce=\"" << cnonce << "\",";
  oss << " nc=" << nc << ",";
  oss << " qop=" << qop << ",";
  oss << " response=\"" << response << "\",";
  oss << " opaque=\"" << opaque << "\"";

  return U(oss.str());
}

std::string Credentials::getNonce(void) const {
  return nonce;
}

std::string Credentials::getQop(void) const {
  return qop;
}

std::string Credentials::getOpaque(void) const {
  return opaque;
}

std::string Credentials::getRealm(void) const {
  return realm;
}

} // end namespace internals

} // end namespace mlclient
