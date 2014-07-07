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
#include "MLCrypto.hpp"
#include "AuthorizationBuilder.hpp"

const boost::regex realm_re("[R|r]ealm=\"(\\w+)\"");
const boost::regex qop_re("qop=\"(\\w+)\"");
const boost::regex nonce_re("nonce=\"([a-z0-9]+)\"");
const boost::regex opaque_re("opaque=\"([a-z0-9]+)\"");
const std::string AUTHORIZATION_HEADER_NAME = "Authorization";
const std::string WWW_AUTHENTICATE_HEADER = "WWW-Authenticate";

Credentials::Credentials() : _nonce_count(0) {
    _cnonce = RandomCnonce();
}

Credentials::Credentials(const std::string& user, const std::string& pass) :
    _user(std::wstring(user.begin(), user.end())), _pass(pass.begin(), pass.end()),
    _nonce_count(0)
{
    _cnonce = RandomCnonce();
}

Credentials::Credentials(const std::wstring& user, const std::wstring& pass) :
    _user(user), _pass(pass), _nonce_count(0)
{
    _cnonce = RandomCnonce();
}

Credentials::Credentials(const std::string& username, const std::string& password,
        const std::string& cnonce, const uint32_t& nc) : 
        _user(username.begin(), username.end()), 
        _pass(password.begin(), password.end()), 
        _cnonce(cnonce), 
        _nonce_count(nc)
{
  
}

std::string Credentials::RandomCnonce() const 
{
  MLCrypto crypto;
  boost::uuids::uuid random_uuid = boost::uuids::random_generator()();
  std::string my_random_uuid = boost::uuids::to_string(random_uuid);
  return crypto.Md5(my_random_uuid);
}


Credentials::~Credentials() {
    
}

bool Credentials::Authenticating() const {
    return false;
}

void Credentials::ParseWWWAthenticateHeader(const std::string& raw) {
    boost::smatch matches;
    if (boost::regex_search(raw, matches, realm_re)) {
        _realm = matches[1];
    } else {
        _realm.clear();
    }
    
    if(boost::regex_search(raw, matches, qop_re)) {
        _qop = matches[1];
    } else {
        _qop.clear();
    }
    
    if (boost::regex_search(raw, matches, nonce_re)) {
        _nonce = matches[1];
    } else {
        _nonce.clear();
    }
    
    if (boost::regex_search(raw, matches, opaque_re)) {
        _opaque = matches[1];
    } else {
        _opaque.clear();
    }
}

void Credentials::Authenticate(std::string method, 
    std::string uri, 
    http::http_headers& raw_headers, 
    std::map<std::string, std::string>& headers) 
{
    header_t input_headers;
    for(auto& iter : raw_headers) {
        input_headers[iter.first] = iter.second;
    }
    Authenticate(method, uri, input_headers, headers);
}

/*
 * Digest username="admin", 
 * realm="public", 
 * nonce="9ca86b1d41652cdc4c2d14d2043d2c25", 
 * uri="/", 
 * response="7af18aeaf1b3e96ade1fcde51aad422e", 
 * opaque="c8fb41173a096fd0", 
 * qop=auth, 
 * nc=00000001, 
 * cnonce="72315add23f0224a"
 */
void Credentials::Authenticate(std::string method, std::string uri, 
    header_t& response_headers, header_t& headers) 
{
    std::ostringstream oss;
    AuthorizationBuilder builder;
    ParseWWWAthenticateHeader(response_headers[WWW_AUTHENTICATE_HEADER]);
    _nonce_count++;
    
    std::ostringstream temp;
    std::string username(_user.begin(), _user.end());
    std::string password(_pass.begin(), _pass.end());
    
    std::string a1 = builder.UsernameRealmAndPassword(username, _realm, password);
    std::string a2 = builder.MethodAndURL(method, uri);
    
    oss << std::setfill('0') << std::setw(8) << _nonce_count;
    std::string nc = oss.str();
    
    std::string response = builder.Response(a1, _nonce, oss.str(), _cnonce, 
        _qop, a2);
    
    oss.str("");
    oss << "Digest";
    oss << " username=\"" << username << "\"";
    oss << " realm=\"" << _realm << "\"";
    oss << " nonce=\"" << _nonce << "\"";
    oss << " uri=\"" << uri << "\"";
    oss << " response=\"" << response << "\"";
    oss << " opaque=\"" << _opaque << "\"";
    oss << " qop=" << _qop;
    oss << " nc=" << nc;
    oss << " cnonce=\"" << _cnonce << "\"";
            
    headers[AUTHORIZATION_HEADER_NAME] = oss.str();    
}

void Credentials::SetCredentials(std::string uri, header_t& headers) {
    
}

std::string Credentials::Nonce(void) const {
    return _nonce;
}

std::string Credentials::Qop(void) const {
    return _qop;
}

std::string Credentials::Opaque(void) const {
    return _opaque;
}

std::string Credentials::Realm(void) const {
    return _realm;
}

std::string Credentials::Uri(void) const {
    return _uri;
}
