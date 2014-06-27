//
//  Credentials.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include "Credentials.hpp"
#include <sstream>
#include <boost/regex.hpp>
#include <openssl/md5.h>

const boost::regex realm_re("[R|r]ealm=\"(\\w+)\"");
const boost::regex qop_re("qop=\"(\\w+)\"");
const boost::regex nonce_re("nonce=\"([a-z0-9]+)\"");
const boost::regex opaque_re("opaque=\"([a-z0-9]+)\"");
const std::string AUTHORIZATION_HEADER_NAME = "Authorization";
const std::string WWW_AUTHENTICATE_HEADER = "WWW-Authenticate";

Credentials::Credentials() {
    
}

Credentials::Credentials(const std::string& user, const std::string& pass) :
    _user(std::wstring(user.begin(), user.end())), _pass(pass.begin(), pass.end())
{
    
}

Credentials::Credentials(const std::wstring& user, const std::wstring& pass) :
    _user(user), _pass(pass)
{
    
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

void Credentials::Authenticate(std::string method, std::string uri, http::http_headers& raw_headers, std::map<std::string, std::string>& headers) {
    header_t input_headers;
    for(auto& iter : raw_headers) {
        input_headers[iter.first] = iter.second;
    }
    Authenticate(method, uri, input_headers, headers);
}

void Credentials::Authenticate(std::string method, std::string uri, header_t& response_headers, header_t& headers) {
    std::ostringstream oss;
    
    ParseWWWAthenticateHeader(response_headers[WWW_AUTHENTICATE_HEADER]);
    
    std::ostringstream temp;
    std::string username(_user.begin(), _user.end());
    std::string password(_pass.begin(), _pass.end());
    
    temp << username << ":" << _realm << ":" << password;
    
    MD5_CTX md5_context;
    unsigned char username_realm_password_hash[16];
    
    MD5_Init(&md5_context);
    MD5_Update(&md5_context, temp.str().c_str(), temp.str().size());
    MD5_Final(username_realm_password_hash, &md5_context);
    
    oss << "Digest";
    oss << " username\"" << username << "\"";
    oss << " realm=\"" << _realm << "\"";
    oss << " nonce=\"" << _nonce << "\"";
    oss << " uri=\"" << uri << "\"";
    oss << " qop=\"" << _qop << "\"";
    oss << " opaque=\"" << _opaque << "\"";
    
    std::string _ha1;
    
    oss << "response=\"" << "abc" << "\"";
    
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
