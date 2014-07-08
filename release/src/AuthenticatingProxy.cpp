//
//  AuthenticatingProxy.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <string>
#include <iostream>
#include "NoCredentialsException.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include "ResponseCodes.hpp"

const std::string AUTHORIZATION_HEADER_NAME = "Authorization";
const std::string WWW_AUTHENTICATE_HEADER = "WWW-Authenticate";

const std::string DEFAULT_KEY = "__DEFAULT";

using namespace web;
using namespace utility;

AuthenticatingProxy::AuthenticatingProxy() : _attempts(0)
{

}


void AuthenticatingProxy::AddCredentials(const Credentials &c) 
{
    _credentials = c;
}

Credentials AuthenticatingProxy::GetCredentials() const {
    return _credentials;
}

Response AuthenticatingProxy::Get(const std::string& host,
                                  const std::string& path,
                                  const header_t& headers,
                                  const params_t& body)
{
  Response response;
  header_t request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    
    http::http_request req(http::methods::GET);
    req.set_request_uri(path);
    
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    _attempts++;
    if (_attempts > 2) {
      std::cerr << "Unauthorized response on the second login attempt" << std::endl;
      throw std::logic_error("Authenticating multiple times");
    }
    header_t response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::GET);
      req.set_request_uri(path);
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("GET", path, 
          response.GetResponseHeaders()[WWW_AUTHENTICATE_HEADER]));
      raw_client.request(req).then([&response](http::http_response raw_response) {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
      }).wait();
    } catch(std::exception e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}

Response AuthenticatingProxy::Get(const std::string& host, const std::string& path, 
    const header_t& headers) {
    params_t blank_parameters;
    return Get(host, path, headers, blank_parameters);
}

Response AuthenticatingProxy::Get(const std::string& host, const std::string& path) {
    header_t blank_headers;
    return Get(host, path, blank_headers);
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const params_t& body,
                                    const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Get_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler)
{
    header_t blank_heders;
    Get_Async(host, path, blank_heders, handler);
}

Response AuthenticatingProxy::Post(const std::string& host,
                                   const std::string& path,
                                   const header_t& headers,
                                   const params_t& body)
{
    Response response;
    
    return response;
}

Response AuthenticatingProxy::Post(const std::string& host, const std::string& path, 
    const header_t& headers)
{
    params_t blank_params;
    return Post(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Post(const std::string& host, const std::string& path)
{
    header_t blank_headers;
    return Post(host, path, blank_headers);
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const header_t& headers,
                                     const params_t& body,
                                     const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                const std::string& path,
                const header_t& headers,
                const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Post_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const std::function<void(const Response&)> handler)
{
    header_t blank_headers;
    Post_Async(host, path, blank_headers, handler);
}

Response AuthenticatingProxy::Put(const std::string& host,
                                  const std::string& path,
                                  const header_t& headers,
                                  const params_t& body)
{
    Response response;
    return response;
}

Response AuthenticatingProxy::Put(const std::string& host, const std::string& path, 
    const header_t& headers) {
    params_t blank_params;
    return Put(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Put(const std::string& host, const std::string& path) {
    header_t blank_headers;
    return Put(host, path, blank_headers);
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const params_t& body,
                                    const std::function<void(const Response&)> handler)
{
    ;
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const header_t& headers,
                                    const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Put_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler)
{
    header_t blank_headers;
    Put_Async(host, path, blank_headers, handler);
}

Response AuthenticatingProxy::Delete(const std::string& host,
                                     const std::string& path,
                                     const header_t& headers,
                                     const params_t& body)
{
    Response response;
    
    return response;
}

Response AuthenticatingProxy::Delete(const std::string& host, const std::string& path, 
    const header_t& headers) {
    params_t blank_params;
    return Delete(host, path, headers, blank_params);
}

Response AuthenticatingProxy::Delete(const std::string& host, const std::string& path)
{
    header_t blank_headers;
    return Delete(host, path, blank_headers);
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const header_t& headers,
                                       const params_t& body,
                                       const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const header_t& headers,
                                       const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Delete_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const std::function<void(const Response&)> handler)
{
    header_t headers;
    Delete_Async(host, path, headers, handler);
}
