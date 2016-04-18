//
//  AuthenticatingProxy.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <string>
#include <iostream>
#include "../NoCredentialsException.hpp"
#include "../Response.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <cpprest/http_headers.h>
#include "../ResponseCodes.hpp"

#include "../MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {
using namespace web::http;

const utility::string_t AUTHORIZATION_HEADER_NAME = U("Authorization");
const utility::string_t WWW_AUTHENTICATE_HEADER = U("WWW-Authenticate");
const std::string WWW_AUTHENTICATE_HEADER_INT = "WWW-Authenticate";

const std::string DEFAULT_KEY = "__DEFAULT";

using namespace utility;                    // Common utilities like string conversions
using namespace utility::conversions;       // String conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
using namespace mlclient;

AuthenticatingProxy::AuthenticatingProxy() : _attempts(0), _credentials()
{
	//_credentials = new Credentials(); // should be declared virtual?;
}


void AuthenticatingProxy::AddCredentials(const internals::Credentials &c)
{
    _credentials = c;
}

const Credentials& AuthenticatingProxy::GetCredentials() const {
    return _credentials;
}

const Response& AuthenticatingProxy::Get(const std::string& host,
                                  const std::string& path,
                                  const http_headers& headers)
{
  static Response response;
  http_headers request_headers = headers;
  http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::GET);
    req.set_request_uri(path);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("GET", path));
    }
    
    http_headers::const_iterator iter;
    for (iter = headers.begin(); iter != headers.end(); iter++) {
      if (req.headers().has(iter->first)) {
        req.headers().remove(iter->first);
      }
      req.headers().add(iter->first, iter->second);
    }
    
    pplx::task<http_response> hr = raw_client.request(req);

    http_response raw_response = hr.get();
    try
    {
      //std::cout << "Raw response JSON: " << raw_response.extract_json().get() << std::endl;
      response.SetJson(raw_response.extract_json().get());
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }
    catch (const http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error on the first request!!!" << e.what() << std::endl;
      std::wcout << ss.str();
    }

    /*
    hr.then([=](http_response raw_response) {
      raw_response.extract_json().then([=](pplx::task<json::value> previousTask)
      {
        try
        {
          response.SetJson(previousTask.get());
        }
        catch (const http_exception& e)
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

    */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    http_headers response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::GET);
      req.set_request_uri(path);
      
      http_headers respHeaders = response.GetResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
        AUTHORIZATION_HEADER_NAME,
		U(_credentials.Authenticate("GET", path, authHeader) )
	  );
      
      http_headers::const_iterator iter;
      for (iter = headers.begin(); iter != headers.end(); iter++) {
        if (req.headers().has(iter->first)) {
          req.headers().remove(iter->first);
        }
        req.headers().add(iter->first, iter->second);
      }
      
      http_response raw_response = raw_client.request(req).get();

      try
      {
    	  response.SetJson(raw_response.extract_json().get());

          response.SetResponseCode((ResponseCodes)raw_response.status_code());
          response.SetResponseHeaders(raw_response.headers());
      }
      catch (const web::http::http_exception& e)
      {
        // Print error.
        std::wostringstream ss;
        ss << "There was an error!!!!" << e.what() << std::endl;
        std::wcout << ss.str();
      }
      /*
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
      */
      
    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}

void AuthenticatingProxy::Get_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler,
                                    const http_headers& headers)
{
    
}

const Response& AuthenticatingProxy::Post(const std::string& host,
                  const std::string& path,
                  const json::value& body,
                  const http_headers& headers)
{
  static Response response;
  http_headers request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::POST);
    req.set_request_uri(path);
    req.set_body(body);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("POST", path));
    }
    

    http_response raw_response = raw_client.request(req).get();

    try
    {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
    }
    catch (const web::http::http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error!!!!" << e.what() << std::endl;
      std::wcout << ss.str();
    }
    /*
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());

    }).wait();
    */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    http_headers response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::POST);
      req.set_request_uri(path);
      req.set_body(json::value(body));
      
      http_headers respHeaders = response.GetResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
        AUTHORIZATION_HEADER_NAME,
		U(_credentials.Authenticate("POST", path, authHeader) )
	  );

      http_response raw_response = raw_client.request(req).get();

      try
      {
          response.SetResponseCode((ResponseCodes)raw_response.status_code());
          response.SetResponseHeaders(raw_response.headers());
      }
      catch (const web::http::http_exception& e)
      {
        // Print error.
        std::wostringstream ss;
        ss << "There was an error!!!!" << e.what() << std::endl;
        std::wcout << ss.str();
      }
      /*
      raw_client.request(req).then([&response](http::http_response raw_response) {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
      }).wait();
      */
      
    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}

/*
Response& AuthenticatingProxy::Post(const std::string& host,
                  const std::string& path,
                  const xmlDocPtr body,
                  const http_headers& headers)
{
  Response result;
  
  return result;
}*/

const Response& AuthenticatingProxy::Post(const std::string& host,
                  const std::string& path,
                  const std::wstring& text_body,
                  const http_headers& headers)
{
  static Response result;

  // TODO MUST INITIALISE THIS RETURN VARIABLE
  
  return result;
}

const Response& AuthenticatingProxy::Post(const std::string& host,
                  const std::string& path,
                  const uint8_t* data, 
                  const size_t& size,
                  const http_headers& headers)
{
  static Response result;
  
  return result;
}
const Response& AuthenticatingProxy::PostFile(const std::string& host,
                      const std::string& path,
                      const std::string& file_path,
                      const http_headers& headers)
{
  static Response result;
  
  return result;
}



void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const http_headers& headers,
                                     const params_t& body,
                                     const std::function<void(const Response&)> handler)
{
    
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                const std::string& path,
                const http_headers& headers,
                const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Post_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Post_Async(const std::string& host,
                                     const std::string& path,
                                     const std::function<void(const Response&)> handler)
{
    http_headers blank_headers;
    Post_Async(host, path, blank_headers, handler);
}

const Response& AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const std::wstring& text_body,
             const http_headers& headers)
{
  static Response result;
  return result;
}
const Response& AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const json::value& json_body,
             const http_headers& headers)
{
  static Response response;
  http_headers request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::PUT);
    req.set_request_uri(path);
    req.set_body(json_body);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("PUT", path));
    }

    http_response raw_response = raw_client.request(req).get();

    try
    {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
    }
    catch (const web::http::http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error!!!!" << e.what() << std::endl;
      std::wcout << ss.str();
    }
    /*
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
    */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    http_headers response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::PUT);
      req.set_request_uri(path);
      req.set_body(json::value(json_body));
      
      http_headers respHeaders = response.GetResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
        AUTHORIZATION_HEADER_NAME,
		U(_credentials.Authenticate("PUT", path, authHeader) )
	  );

      http_response raw_response = raw_client.request(req).get();

      try
      {
          response.SetResponseCode((ResponseCodes)raw_response.status_code());
          response.SetResponseHeaders(raw_response.headers());
      }
      catch (const web::http::http_exception& e)
      {
        // Print error.
        std::wostringstream ss;
        ss << "There was an error!!!!" << e.what() << std::endl;
        std::wcout << ss.str();
      }
      /*
      raw_client.request(req).then([&response](http::http_response raw_response) {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
      }).wait();
      */
      
    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}
/*
Response AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const xmlDocPtr& xml_body,
             const http_headers& headers)
{
  Response result;
  return result;
}*/

const Response& AuthenticatingProxy::Put(const std::string& host,
             const std::string& path,
             const uint8_t* data, 
             const size_t& size,
             const http_headers& headers)
{
  static Response result;
  // TODO MUST INITIALISE THIS OBJECT
  return result;
}


void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const http_headers& headers,
                                    const params_t& body,
                                    const std::function<void(const Response&)> handler)
{
    ;
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const http_headers& headers,
                                    const std::function<void(const Response&)> handler)
{
    params_t blank_params;
    Put_Async(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::Put_Async(const std::string& host,
                                    const std::string& path,
                                    const std::function<void(const Response&)> handler)
{
    http_headers blank_headers;
    Put_Async(host, path, blank_headers, handler);
}

const Response& AuthenticatingProxy::Delete(const std::string& host,
                                     const std::string& path,
                                     const http_headers& headers)
{
  static Response response;
  http_headers request_headers = headers;
  
  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::DEL);
    req.set_request_uri(path);
    
    if (_credentials.Authenticating()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, _credentials.Authenticate("DELETE", path));
    }

    http_response raw_response = raw_client.request(req).get();

    try
    {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
    }
    catch (const web::http::http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error!!!!" << e.what() << std::endl;
      std::wcout << ss.str();
    }
    /*
    raw_client.request(req).then([&response](http::http_response raw_response) {
      response.SetResponseCode((ResponseCodes)raw_response.status_code());
      response.SetResponseHeaders(raw_response.headers());
    }).wait();
    */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response.GetResponseCode() == ResponseCodes::UNAUTHORIZED) {
    http_headers response_headers = response.GetResponseHeaders();
    
    try {
      http::http_request req(http::methods::DEL);
      req.set_request_uri(path);
      
      http_headers respHeaders = response.GetResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
        AUTHORIZATION_HEADER_NAME,
		U(_credentials.Authenticate("DELETE", path, authHeader) )
	  );

      http_response raw_response = raw_client.request(req).get();

      try
      {
          response.SetResponseCode((ResponseCodes)raw_response.status_code());
          response.SetResponseHeaders(raw_response.headers());
      }
      catch (const web::http::http_exception& e)
      {
        // Print error.
        std::wostringstream ss;
        ss << "There was an error!!!!" << e.what() << std::endl;
        std::wcout << ss.str();
      }
      /*
      raw_client.request(req).then([&response](http::http_response raw_response) {
        response.SetResponseCode((ResponseCodes)raw_response.status_code());
        response.SetResponseHeaders(raw_response.headers());
      }).wait();
      */
      
    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
    
  return response;
}


void AuthenticatingProxy::Delete_Async(const std::string& host,
                                       const std::string& path,
                                       const std::function<void(const Response&)> handler,
                                       const http_headers& headers)
{
    
}

} // end internals namespace

} // end mlclient namespace
