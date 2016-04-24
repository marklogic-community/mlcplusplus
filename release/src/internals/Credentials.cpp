//
//  Credentials.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include "Credentials.hpp"
#include <sstream>
#include <iomanip>
#include <boost/regex.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cpprest/http_client.h>
#include "MLCrypto.hpp"
#include "AuthorizationBuilder.hpp"

#include "../mlclient.hpp"

namespace mlclient {

namespace internals {
using namespace web::http;

const boost::regex REALM_RE("[R|r]ealm=\"(\\w+)\"");
const boost::regex QOP_RE("qop=\"(\\w+)\"");
const boost::regex NONCE_RE("nonce=\"([a-z0-9]+)\"");
const boost::regex OPAQUE_RE("opaque=\"([a-z0-9]+)\"");
const utility::string_t AUTHORIZATION_HEADER_NAME = U("Authorization");
const utility::string_t WWW_AUTHENTICATE_HEADER = U("WWW-Authenticate");

Credentials::Credentials() : _nonce_count(0) {
  _cnonce = randomCnonce();
}

Credentials::Credentials(const std::string& user, const std::string& pass) :
        _user(std::wstring(user.begin(), user.end())), _pass(pass.begin(), pass.end()),
        _nonce_count(0)
{
  _cnonce = randomCnonce();
}

Credentials::Credentials(const std::wstring& user, const std::wstring& pass) :
        _user(user), _pass(pass), _nonce_count(0)
{
  _cnonce = randomCnonce();
}

Credentials::Credentials(const std::string& username, const std::string& password,
    const std::string& cnonce, const uint32_t& nc) :
            _user(username.begin(), username.end()),
            _pass(password.begin(), password.end()),
            _cnonce(cnonce),
            _nonce_count(nc)
{

}

std::string Credentials::randomCnonce() const
{

  internals::MLCrypto crypto;
  boost::uuids::uuid random_uuid = boost::uuids::random_generator()();
  std::string my_random_uuid = boost::uuids::to_string(random_uuid);
  return crypto.md5(my_random_uuid);
}


Credentials::~Credentials() {

}

bool Credentials::authenticating() const {
  return _user != L"" && _pass != L"" && _nonce != "" && _realm != "";
}

void Credentials::parseWWWAthenticateHeader(const std::string& raw) {
  boost::smatch matches;
  if (boost::regex_search(raw, matches, REALM_RE)) {
    _realm = matches[1];
  } else {
    _realm.clear();
  }

  if(boost::regex_search(raw, matches, QOP_RE)) {
    _qop = matches[1];
  } else {
    _qop.clear();
  }

  if (boost::regex_search(raw, matches, NONCE_RE)) {
    _nonce = matches[1];
  } else {
    _nonce.clear();
  }

  if (boost::regex_search(raw, matches, OPAQUE_RE)) {
    _opaque = matches[1];
  } else {
    _opaque.clear();
  }
}

std::string Credentials::authenticate(const std::string& method, const std::string& uri, const std::string& auth_header) {
  parseWWWAthenticateHeader(auth_header);

  return authenticate(method, uri);
}

std::string Credentials::authenticate(const std::string& method, const std::string& uri) {
  std::ostringstream oss;
  internals::AuthorizationBuilder builder;
  _nonce_count++;

  std::ostringstream temp;
  std::string username(_user.begin(), _user.end());
  std::string password(_pass.begin(), _pass.end());

  std::string a1 = builder.usernameRealmAndPassword(username, _realm, password);
  std::string a2 = builder.methodAndURL(method, uri);

  oss << std::setfill('0') << std::setw(8) << _nonce_count;
  std::string nc = oss.str();

  std::string response = builder.response(a1, _nonce, oss.str(), _cnonce,
      _qop, a2);

  oss.str("");
  oss << " Digest";
  oss << " username=\"" << username << "\",";
  oss << " realm=\"" << _realm << "\",";
  oss << " nonce=\"" << _nonce << "\",";
  oss << " uri=\"" << uri << "\",";
  oss << " cnonce=\"" << _cnonce << "\",";
  oss << " nc=" << nc << ",";
  oss << " qop=" << _qop << ",";
  oss << " response=\"" << response << "\",";
  oss << " opaque=\"" << _opaque << "\"";

  return U(oss.str());
}

std::string Credentials::nonce(void) const {
  return _nonce;
}

std::string Credentials::qop(void) const {
  return _qop;
}

std::string Credentials::opaque(void) const {
  return _opaque;
}

std::string Credentials::realm(void) const {
  return _realm;
}

}

}
