//
//  Credentials.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef __Scratch__Credentials__
#define __Scratch__Credentials__

#include <string>
#include <map>
#include <cstdint>
#include <cpprest/http_client.h>

#include "Types.hpp"

using namespace web;

class Credentials {
    std::wstring _user;
    std::wstring _pass;
    
    std::string _nonce;
    std::string _qop;
    std::string _opaque;
    std::string _realm;
    std::string _uri;
    std::string _cnonce;
    uint32_t _nonce_count;
    
protected:
    void Authenticate(std::string method, std::string uri, http::http_headers& raw_headers, header_t& headers);
    void Authenticate(std::string method, std::string uri, header_t& response_headers, header_t& headers);
    
    void SetCredentials(std::string uri, header_t& headers);
    std::string RandomCnonce(void) const;
public:
    Credentials();
    Credentials(const std::string& username, const std::string& password);
    Credentials(const std::wstring& username, const std::wstring& password);
    
    ~Credentials(void);
    
    bool Authenticating(void) const;
    
    void ParseWWWAthenticateHeader(const std::string& _raw);
    
    std::string Nonce(void) const;
    std::string Qop(void) const;
    std::string Opaque(void) const;
    std::string Realm(void) const;
    std::string Uri(void) const;
    
    friend class AuthenticatingProxy;
    friend class TestCredentials;
};

#endif /* defined(__Scratch__Credentials__) */
