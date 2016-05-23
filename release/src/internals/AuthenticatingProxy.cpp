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
 *  AuthenticatingProxy.cpp
 *  Created by Paul Hoehne on 29 May 2014.
 *  Modified by Adam Fowler on 21 Apr 2016
 */

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
#include "../HttpHeaders.hpp"
#include "AuthenticatingProxy.hpp"
#include "Credentials.hpp"

#include "../ext/easylogging++.h"

#include <string>

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
}

void AuthenticatingProxy::copyHeaders(const web::http::http_headers& from, mlclient::HttpHeaders& to) {
  std::map<std::string,std::string> headers;
  for (auto& it : from) {
    to.setHeader(it.first,it.second);
  }
}


void AuthenticatingProxy::addCredentials(const internals::Credentials &c)
{
  credentials = c;
}

const Credentials& AuthenticatingProxy::getCredentials() const {
  return credentials;
}

Response* AuthenticatingProxy::doRequest(const std::string& method,const std::string& host,const std::string& path,const HttpHeaders& headers, Response* response,const IDocumentContent* body) {

  http_client raw_client(U(host));

  std::string responseAuthHeaderValue = "";

  std::map<std::string,std::string> hs = headers.getHeaders();

  try {
    http::http_request req(method);
    http_headers restHeaders = req.headers();
    // copy additional headers - e.g. Accept: or Content-type: (For POST/PUT)
    for (auto& iter : hs) {
      if (restHeaders.has(iter.first)) { // TODO verify that map doesn't handle duplicates for us. If it does, remove this check.
        restHeaders.remove(iter.first);
      }
      restHeaders.add(iter.first, iter.second);
    }
    if (!restHeaders.has("Accept")) {
      restHeaders.add("Accept","application/json"); // default to JSON response type for MarkLogic
    }
    req.set_request_uri(path);

    if (credentials.canAuthenticate()) {
      restHeaders.add(AUTHORIZATION_HEADER_NAME, credentials.authenticate(("" + method), path));
    }

    if (nullptr != body) {
      req.set_body(U(body->getContent()),U(body->getMimeType()));
    }

    /*
    std::map<std::string,std::string>::const_iterator iter;
    // print out headers for debug
    LOG(DEBUG) << "Listing initial request headers:-";
    for (auto& iter : req.headers()) {
      LOG(DEBUG) << " header: " << iter.first << " = " << iter.second;
    }
    LOG(DEBUG) << "Finishing listing request headers.";
    */

    pplx::task<http_response> hr = raw_client.request(req);

    http_response raw_response = hr.get();
    try
    {
      response->setResponseCode((ResponseCode)raw_response.status_code());
      HttpHeaders h;
      AuthenticatingProxy::copyHeaders(raw_response.headers(),h);
      response->setResponseHeaders(h); // THIS DOESN'T SET ANYTHING
      responseAuthHeaderValue = raw_response.headers()[WWW_AUTHENTICATE_HEADER];

      /*
      LOG(DEBUG) << "Listing response object headers:-";
      for (auto& iter : response->getResponseHeaders().getHeaders()) {
        LOG(DEBUG) << " header name: " << iter.first;
        LOG(DEBUG) << "  value = " << iter.second;
      }
      LOG(DEBUG) << "Finishing listing response object headers.";
      */

      //std::unique_ptr<std::string> c(new std::string(raw_response.extract_string().get()));
      response->setContent(new std::string(raw_response.extract_string().get())); // TODO handle binary response types
    }
    catch (const http_exception& e)
    {
      // Print error.
      std::wostringstream ss;
      ss << "There was an error extracting content from response: " << e.what() << std::endl;
      LOG(WARNING) << ss.str();
    }

  } catch(std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  if (response->getResponseCode() == ResponseCode::UNAUTHORIZED) {
    //LOG(DEBUG) << "UNAUTHORIZED";
    /*
    LOG(DEBUG) << "Listing headers fetched from response:-";
    for (auto& iter : response_headers.getHeaders()) {
      LOG(DEBUG) << " header: " << iter.first << " = " << iter.second;
    }
    LOG(DEBUG) << "Finishing listing headers fetched from response.";
    */

    try {
      http::http_request req(http::methods::GET);
      req.set_request_uri(path);

      // print out all headers from response
/*
      LOG(DEBUG) << "Listing Unauth response headers:-";
      for (auto& iter : response_headers.getHeaders()) {
        LOG(DEBUG) << " header: " << iter.first << " = " << iter.second;
      }
      LOG(DEBUG) << "Finishing listing unauth response headers.";
      LOG(DEBUG) << "Value of www authenticate: " << WWW_AUTHENTICATE_HEADER;
      */


      std::map<std::string,std::string>::const_iterator iter;
      std::map<std::string,std::string> hs = headers.getHeaders();
      http_headers restHeaders = req.headers();
      for (auto& iter : hs) {
        if (restHeaders.has(iter.first)) {
          restHeaders.remove(iter.first);
        }
        restHeaders.add(iter.first, iter.second);
      }
      if (!restHeaders.has("Accept")) {
        restHeaders.add("Accept","application/json"); // default to JSON response type for MarkLogic
      }
      restHeaders.add(
          AUTHORIZATION_HEADER_NAME,
          U(credentials.authenticate(("" + method), path, responseAuthHeaderValue) )
      );

      if (nullptr != body) {
        req.set_body(U(body->getContent()),U(body->getMimeType()));
      }
      /*
      LOG(DEBUG) << "Listing request headers post auth calculation:-";
      for (auto& iter : req.headers()) {
        LOG(DEBUG) << " header: " << iter.first << " = " << iter.second;
      }
      LOG(DEBUG) << "Finishing listing request headers.";
      */

      http_response raw_response = raw_client.request(req).get();

      try
      {
        //LOG(DEBUG) << "Final response...";

        response->setResponseCode((ResponseCode)raw_response.status_code());
        HttpHeaders h;
        AuthenticatingProxy::copyHeaders(raw_response.headers(),h);
        response->setResponseHeaders(h);
        response->setContent(new std::string(raw_response.extract_string().get()));
      }
      catch (const web::http::http_exception& e)
      {
        // Print error.
        std::wostringstream ss;
        ss << "There was an error!!!!" << e.what() << std::endl;
        std::wcout << ss.str();
      }

    } catch(std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return response; // return the same inout parameter to indicate more obviously that we change it
}

Response* AuthenticatingProxy::getSync(const std::string& host,
    const std::string& path,
    const mlclient::HttpHeaders& headers)
{
  TIMED_FUNC(AuthenticatingProxy_getSync);
  Response* response = new Response;

  // do initial request
  this->doRequest(http::methods::GET,host,path,headers,response,nullptr);

  return response;
}


Response* AuthenticatingProxy::postSync(const std::string& host,
    const std::string& path,
    const IDocumentContent& body,
    const mlclient::HttpHeaders& headers)
{
  TIMED_FUNC(AuthenticatingProxy_postSync);
  LOG(DEBUG) << "    Entering postSync";
  Response* response = new Response;

  doRequest(http::methods::POST,host,path,headers,response,&body);
  LOG(DEBUG) << "    Leaving postSync";

  return response;
}

Response* AuthenticatingProxy::putSync(const std::string& host,
    const std::string& path,
    const IDocumentContent& body,
    const mlclient::HttpHeaders& headers)
{
  TIMED_FUNC(AuthenticatingProxy_putSync);
  Response* response = new Response;

  doRequest(http::methods::PUT,host,path,headers,response,&body);

  return response;
}

Response* AuthenticatingProxy::deleteSync(const std::string& host,
    const std::string& path,
    const mlclient::HttpHeaders& headers)
{
  TIMED_FUNC(AuthenticatingProxy_deleteSync);
  Response* response = new Response;

  doRequest(http::methods::DEL,host,path,headers,response,nullptr);

  return response;
}

} // end internals namespace

} // end mlclient namespace
