//
//  AuthenticatingProxy.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef __Scratch__AuthenticatingProxy__
#define __Scratch__AuthenticatingProxy__

#include <map>
#include <functional>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "Credentials.hpp"
#include "Types.hpp"

class AuthenticatingProxy {
    Credentials _credentials;
        
public:
    void AddCredentials(const Credentials& c);
    Credentials GetCredentials(void) const;
    
    Response Get(const std::string& host,
                 const std::string& path,
                 const header_t& headers,
                 const params_t& body);
    Response Get(const std::string& host, const std::string& path, const header_t& headers);
    Response Get(const std::string& host, const std::string& path);
    
    void Get_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Get_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const std::function<void(const Response&)> handler);
    void Get_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
    
    Response Post(const std::string& host,
                 const std::string& path,
                 const header_t& headers,
                 const params_t& body);
    Response Post(const std::string& host, const std::string& path, const header_t& headers);
    Response Post(const std::string& host, const std::string& path);
    
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const std::function<void(const Response&)> handler);
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
    
    Response Put(const std::string& host,
                 const std::string& path,
                 const header_t& headers,
                 const params_t& body);
    Response Put(const std::string& host, const std::string& path, const header_t& headers);
    Response Put(const std::string& host, const std::string& path);
    
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const std::function<void(const Response&)> handler);
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
    
    Response Delete(const std::string& host,
                 const std::string& path,
                 const header_t& headers,
                 const params_t& body);
    Response Delete(const std::string& host, const std::string& path, const header_t& headers);
    Response Delete(const std::string& host, const std::string& path);
    
    void Delete_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Delete_Async(const std::string& host,
                   const std::string& path,
                   const header_t& headers,
                   const std::function<void(const Response&)> handler);
    void Delete_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
};

#endif /* defined(__Scratch__AuthenticatingProxy__) */
