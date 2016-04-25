//
//  AuthenticatingProxy.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//  Modified by Adam Fowler on 21 Apr 16
//

#include <string>
#include <iostream>

// JSON and HTTP includes
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <cpprest/http_headers.h>

// XML includes
#include <pugixml.hpp>

// our API includes
#include "../NoCredentialsException.hpp"
#include "../Response.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"

#include "../mlclient.hpp"

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

AuthenticatingProxy::AuthenticatingProxy() : attempts(0), credentials()
{
  //_credentials = new Credentials(); // should be declared virtual?;
}


void AuthenticatingProxy::addCredentials(const internals::Credentials &c)
{
  credentials = c;
}

const Credentials& AuthenticatingProxy::getCredentials() const {
  return credentials;
}

std::unique_ptr<Response> AuthenticatingProxy::getSync(const std::string& host,
    const std::string& path,
    const http_headers& headers)
{
  //auto && response = new Response;
  Response* response = new Response;
  http_headers request_headers = headers;
  http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::GET);
    req.set_request_uri(path);

    if (credentials.canAuthenticate()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, credentials.authenticate("GET", path));
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
      response->setResponseCode((ResponseCode)raw_response.status_code());
      response->setResponseHeaders(raw_response.headers());
      std::unique_ptr<std::string> c(new std::string(raw_response.extract_string().get()));
      response->setContent(std::move(c));
      //response->SetContent(std::move(std::string(raw_response.extract_string().get())));
    }
    catch (const http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error extracting content from response: " << e.what() << std::endl;
      std::wcout << ss.str();
    }

    /*
    hr.then([=](http_response raw_response) {
      raw_response.extract_json().then([=](pplx::task<json::value> previousTask)
      {
        try
        {
          response->SetJson(previousTask.get());
        }
        catch (const http_exception& e)
        {
          // Print error.
          std::wostringstream ss;
          ss << "There was an error on the first request!!!" << e.what() << std::endl;
          std::wcout << ss.str();
        }

      }).wait();

      response->SetResponseCode((ResponseCode)raw_response.status_code());
      response->SetResponseHeaders(raw_response.headers());
    }).wait();

     */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response->getResponseCode() == ResponseCode::UNAUTHORIZED) {
    http_headers response_headers = response->getResponseHeaders();

    try {
      http::http_request req(http::methods::GET);
      req.set_request_uri(path);

      std::string authHeader = to_utf8string(response_headers[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
          AUTHORIZATION_HEADER_NAME,
          U(credentials.authenticate("GET", path, authHeader) )
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
        //response->SetJson(raw_response.extract_json().get());

        response->setResponseCode((ResponseCode)raw_response.status_code());
        response->setResponseHeaders(raw_response.headers());
        std::unique_ptr<std::string> c(new std::string(raw_response.extract_string().get()));
        response->setContent(std::move(c));
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
              response->SetJson(previousTask.get());
            }
            catch (const web::http::http_exception& e)
            {
              // Print error.
              std::wostringstream ss;
              ss << "There was an error!!!!" << e.what() << std::endl;
              std::wcout << ss.str();
            }
        }).wait();

        response->SetResponseCode((ResponseCode)raw_response.status_code());
        response->SetResponseHeaders(raw_response.headers());
      }).wait();
       */

    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return std::unique_ptr<Response>(response);
}

/*
void AuthenticatingProxy::getAsync(const std::string& host,
    const std::string& path,
    const std::function<void(const Response&)> handler,
    const http_headers& headers)
{

}
*/

std::unique_ptr<Response> AuthenticatingProxy::postSync(const std::string& host,
    const std::string& path,
    const json::value& body,
    const http_headers& headers)
{
  Response* response = new Response;
  http_headers request_headers = headers;

  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::POST);
    req.set_request_uri(path);
    req.set_body(body);

    if (credentials.canAuthenticate()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, credentials.authenticate("POST", path));
    }


    http_response raw_response = raw_client.request(req).get();

    try
    {
      response->setResponseCode((ResponseCode)raw_response.status_code());
      response->setResponseHeaders(raw_response.headers());
      std::unique_ptr<std::string> c(new std::string(raw_response.extract_string().get()));
      response->setContent(std::move(c));
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
      response->SetResponseCode((ResponseCode)raw_response.status_code());
      response->SetResponseHeaders(raw_response.headers());

    }).wait();
     */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response->getResponseCode() == ResponseCode::UNAUTHORIZED) {
    http_headers response_headers = response->getResponseHeaders();

    try {
      http::http_request req(http::methods::POST);
      req.set_request_uri(path);
      req.set_body(json::value(body));

      http_headers respHeaders = response->getResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
          AUTHORIZATION_HEADER_NAME,
          U(credentials.authenticate("POST", path, authHeader) )
      );

      http_response raw_response = raw_client.request(req).get();

      try
      {
        response->setResponseCode((ResponseCode)raw_response.status_code());
        response->setResponseHeaders(raw_response.headers());
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
        response->SetResponseCode((ResponseCode)raw_response.status_code());
        response->SetResponseHeaders(raw_response.headers());
      }).wait();
       */

    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return std::unique_ptr<Response>(response);
}

/*
Response& AuthenticatingProxy::postSync(const std::string& host,
                  const std::string& path,
                  const xmlDocPtr body,
                  const http_headers& headers)
{
  Response result;

  return result;
}*/

std::unique_ptr<Response> AuthenticatingProxy::postSync(const std::string& host,
    const std::string& path,
    const std::wstring& text_body,
    const http_headers& headers)
{
  Response* result = new Response;

  // TODO MUST INITIALISE THIS RETURN VARIABLE

  return std::unique_ptr<Response>(result);
}

std::unique_ptr<Response> AuthenticatingProxy::postSync(const std::string& host,
    const std::string& path,
    const uint8_t* data,
    const size_t& size,
    const http_headers& headers)
{
  Response* response = new Response;

  return std::unique_ptr<Response>(response);
}
std::unique_ptr<Response> AuthenticatingProxy::postFileSync(const std::string& host,
    const std::string& path,
    const std::string& file_path,
    const http_headers& headers)
{
  Response* response = new Response;

  return std::unique_ptr<Response>(response);
}

/*

void AuthenticatingProxy::postAsync(const std::string& host,
    const std::string& path,
    const http_headers& headers,
    const params_t& body,
    const std::function<void(const Response&)> handler)
{

}

void AuthenticatingProxy::postAsync(const std::string& host,
    const std::string& path,
    const http_headers& headers,
    const std::function<void(const Response&)> handler)
{
  params_t blank_params;
  postAsync(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::postAsync(const std::string& host,
    const std::string& path,
    const std::function<void(const Response&)> handler)
{
  http_headers blank_headers;
  postAsync(host, path, blank_headers, handler);
}
*/
std::unique_ptr<Response> AuthenticatingProxy::putSync(const std::string& host,
    const std::string& path,
    const std::wstring& text_body,
    const http_headers& headers)
{
  Response* response = new Response;
  return std::unique_ptr<Response> (response);
}
std::unique_ptr<Response> AuthenticatingProxy::putSync(const std::string& host,
    const std::string& path,
    const json::value& json_body,
    const http_headers& headers)
{
  Response* response = new Response;
  http_headers request_headers = headers;

  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::PUT);
    req.set_request_uri(path);
    req.set_body(json_body);

    if (credentials.canAuthenticate()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, credentials.authenticate("PUT", path));
    }

    http_response raw_response = raw_client.request(req).get();

    try
    {
      response->setResponseCode((ResponseCode)raw_response.status_code());
      response->setResponseHeaders(raw_response.headers());
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
      response->SetResponseCode((ResponseCode)raw_response.status_code());
      response->SetResponseHeaders(raw_response.headers());
    }).wait();
     */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response->getResponseCode() == ResponseCode::UNAUTHORIZED) {
    http_headers response_headers = response->getResponseHeaders();

    try {
      http::http_request req(http::methods::PUT);
      req.set_request_uri(path);
      req.set_body(json::value(json_body));

      http_headers respHeaders = response->getResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
          AUTHORIZATION_HEADER_NAME,
          U(credentials.authenticate("PUT", path, authHeader) )
      );

      http_response raw_response = raw_client.request(req).get();

      try
      {
        response->setResponseCode((ResponseCode)raw_response.status_code());
        response->setResponseHeaders(raw_response.headers());
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
        response->SetResponseCode((ResponseCode)raw_response.status_code());
        response->SetResponseHeaders(raw_response.headers());
      }).wait();
       */

    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return std::unique_ptr<Response> (response);
}
/*
Response AuthenticatingProxy::putSync(const std::string& host,
             const std::string& path,
             const xmlDocPtr& xml_body,
             const http_headers& headers)
{
  Response result;
  return result;
}*/

std::unique_ptr<Response> AuthenticatingProxy::putSync(const std::string& host,
    const std::string& path,
    const uint8_t* data,
    const size_t& size,
    const http_headers& headers)
{
  Response* response = new Response;
  // TODO MUST INITIALISE THIS OBJECT
  return std::unique_ptr<Response> (response);
}
/*

void AuthenticatingProxy::putAsync(const std::string& host,
    const std::string& path,
    const http_headers& headers,
    const params_t& body,
    const std::function<void(const Response&)> handler)
{
  ;
}

void AuthenticatingProxy::putAsync(const std::string& host,
    const std::string& path,
    const http_headers& headers,
    const std::function<void(const Response&)> handler)
{
  params_t blank_params;
  putAsync(host, path, headers, blank_params, handler);
}

void AuthenticatingProxy::putAsync(const std::string& host,
    const std::string& path,
    const std::function<void(const Response&)> handler)
{
  http_headers blank_headers;
  putAsync(host, path, blank_headers, handler);
}
*/

std::unique_ptr<Response> AuthenticatingProxy::deleteSync(const std::string& host,
    const std::string& path,
    const http_headers& headers)
{
  Response* response = new Response;
  http_headers request_headers = headers;

  http::client::http_client raw_client(U(host));

  try {
    http::http_request req(http::methods::DEL);
    req.set_request_uri(path);

    if (credentials.canAuthenticate()) {
      req.headers().add(AUTHORIZATION_HEADER_NAME, credentials.authenticate("DELETE", path));
    }

    http_response raw_response = raw_client.request(req).get();

    try
    {
      response->setResponseCode((ResponseCode)raw_response.status_code());
      response->setResponseHeaders(raw_response.headers());
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
      response->SetResponseCode((ResponseCode)raw_response.status_code());
      response->SetResponseHeaders(raw_response.headers());
    }).wait();
     */
  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response->getResponseCode() == ResponseCode::UNAUTHORIZED) {
    http_headers response_headers = response->getResponseHeaders();

    try {
      http::http_request req(http::methods::DEL);
      req.set_request_uri(path);

      http_headers respHeaders = response->getResponseHeaders();
      std::string authHeader = to_utf8string(respHeaders[WWW_AUTHENTICATE_HEADER]);

      req.headers().add(
          AUTHORIZATION_HEADER_NAME,
          U(credentials.authenticate("DELETE", path, authHeader) )
      );

      http_response raw_response = raw_client.request(req).get();

      try
      {
        response->setResponseCode((ResponseCode)raw_response.status_code());
        response->setResponseHeaders(raw_response.headers());
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
        response->SetResponseCode((ResponseCode)raw_response.status_code());
        response->SetResponseHeaders(raw_response.headers());
      }).wait();
       */

    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return std::unique_ptr<Response> (response);
}
/*

void AuthenticatingProxy::deleteAsync(const std::string& host,
    const std::string& path,
    const std::function<void(const Response&)> handler,
    const http_headers& headers)
{

}
*/

} // end internals namespace

} // end mlclient namespace
