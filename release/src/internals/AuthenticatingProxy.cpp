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

#include "MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {

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
                                  const header_t& headers)
{
  Response response;
  header_t request_headers = headers;  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::GET);
    req.set_request_uri(path);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("GET", path));
    }
    
    header_t::const_iterator iter;
    for (iter = headers.begin(); iter != headers.end(); iter++) {
      if (req.headers().has(iter->first)) {
        req.headers().remove(iter->first);
      }
      req.headers().add(iter->first, iter->second);
    }
    
    raw_client.request(req).then([&response](http::http_response raw_response) {
      raw_response.extract_json().then([&response](pplx::task<web::json::value> previousTask)
      {
        try
        {
          response.SetJson(previousTask.get());
        }
        catch (const web::http::http_exception& e)
        {
          // Print error.
          std::wostringstream ss;
          ss << "There was an error on the first request!!!" << e.what() << std::endl;
          std::wcout << ss.str();
        }
        
      }).wait();
      
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    header_t response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::GET);
      req.set_request_uri(path);
      
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("GET", path, 
          response.GetResponseHeaders()[WWW_AUTHENTICATE_HEADER]));
      
      header_t::const_iterator iter;
      for (iter = headers.begin(); iter != headers.end(); iter++) {
        if (req.headers().has(iter->first)) {
          req.headers().remove(iter->first);
        }
        req.headers().add(iter->first, iter->second);
      }
      
      raw_client.request(req).then([&response](http::http_response raw_response) {
        raw_response.extract_json().then([&response](pplx::task<web::json::value> previousTask)
          {
            try
            {
              response.SetJson(previousTask.get());
            }
            catch (const web::http::http_exception& e)
            {
              // Print error.
              std::wostringstream ss;
              ss << "There was an error!!!!" << e.what() << std::endl;
              std::wcout << ss.str();
            }
        }).wait();
        
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
      }).wait();
      
    } catch(std::exception e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler,
                                    const header_t& headers)
{
    
}

Response AuthenticatingProxy::Post(const std::string& host, 
                  const std::string& path,
                  const json::value& body,
                  const header_t& headers)
{
  Response response;
  header_t request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::POST);
    req.set_request_uri(path);
    req.set_body(body);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("POST", path));
    }
    
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());

    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    header_t response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::POST);
      req.set_request_uri(path);
      req.set_body(body);
      
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("POST", path, 
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
Response AuthenticatingProxy::Post(const std::string& host, 
                  const std::string& path,
                  const xmlDocPtr body,
                  const header_t& headers)
{
  Response result;
  
  return result;
}

Response AuthenticatingProxy::Post(const std::string& host, 
                  const std::string& path,
                  const std::wstring& text_body,
                  const header_t& headers)
{
  Response result;
  
  return result;
}

Response AuthenticatingProxy::Post(const std::string& host, 
                  const std::string& path,
                  const uint8_t* data, 
                  const size_t& size,
                  const header_t& headers) 
{
  Response result;
  
  return result;
}
Response AuthenticatingProxy::PostFile(const std::string& host, 
                      const std::string& path,
                      const std::string& file_path,
                      const header_t& headers)
{
  Response result;
  
  return result;
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
             const std::wstring& text_body,
             const header_t& headers) 
{
  Response result;
  return result;
}
Response AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const json::value& json_body,
             const header_t& headers) 
{
  Response response;
  header_t request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::PUT);
    req.set_request_uri(path);
    req.set_body(json_body);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("PUT", path));
    }
    
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    header_t response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::PUT);
      req.set_request_uri(path);
      req.set_body(json_body);
      
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("PUT", path, 
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

Response AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const xmlDocPtr& xml_body,
             const header_t& headers) 
{
  Response result;
  return result;
}

Response AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const uint8_t* data, 
             const size_t& size,
             const header_t& headers) 
{
  Response result;
  return result;
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
                                     const header_t& headers)
{
  Response response;
  header_t request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::DEL);
    req.set_request_uri(path);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("DELETE", path));
    }
    
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
  } catch(std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    header_t response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::DEL);
      req.set_request_uri(path);
      
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("DELETE", path, 
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


void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const std::function<void(const Response&)> handler,
                                       const header_t& headers)
{
    
}

}

}
