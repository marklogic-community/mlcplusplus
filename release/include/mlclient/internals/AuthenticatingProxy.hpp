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
 *  AuthenticatingProxy.h
 *  Created by Paul Hoehne on 5/29/14.
 */

#ifndef AUTHENTICATING_PROXY
#define AUTHENTICATING_PROXY

#include "mlclient/internals/Credentials.hpp"

#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/HttpHeaders.hpp"

#include <map>
#include <functional>
#include <cstdint>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

namespace mlclient {

namespace internals {

const mlclient::HttpHeaders blankHeaders;

/**
 * \brief AuthenticatingProxy to handle authenticated calls to MarkLogic
 *
 * This class proxies the calls to MarkLogic, handling authentication as
 * necessary.  It includes both synchronous and asynchronous methods to allow
 * users to select the method of invocation most suited to their application.
 *
 * \note Some concepts contained run against "REST" principles.  This is
 * not only a REST library and is meant to be used as a general MarkLogic
 * C++ library.  It should be backward compatible with non RESTful end points
 * as well as REST.
 */
class AuthenticatingProxy {



public:    
  ///
  /// Constructor
  ///
  AuthenticatingProxy();

  ///
  /// Add credentials to the authenticating proxy
  ///
  /// \param c The Credentials.
  ///
  void addCredentials(const Credentials& c);

  ///
  /// Returns a read-only copy of the credentials used by the proxy.
  ///
  /// \return The credentials
  ///
  const Credentials& getCredentials(void) const;

  ///
  /// Invokes a synchronous GET operation on the MarkLogic server.
  ///
  /// \param host The hostname or IP address ("127.0.0.1")
  /// \param path The path to invoke ("/v1/documents?uri=/foo/bar.xml")
  /// \param headers The HTTP headers to include in the invocation
  /// \return The Response object
  ///
  Response* getSync(const std::string& host,
      const std::string& path,
      const mlclient::HttpHeaders& headers = blankHeaders);

  /**
   * \brief A Synchronous HTTP POST to a remote MarkLogic REST API URL
   *
   * \param[in] host The hostname or IP Address to communicate with
   * \param[in] path The URL path (E.g. /v1/documents) to invoke
   * \param[in] body The content to send as the POST body
   * \param[in\ headers The HTTP Headers to use (Optional. Defaults to a blank set of headers)
   * \return A Response pointer that the call is responsible for deleting
   */
  Response* postSync(const std::string& host,
      const std::string& path,
      const IDocumentContent& body,
      const mlclient::HttpHeaders& headers = blankHeaders);

  /**
   * \brief A Synchronous HTTP PUT to a remote MarkLogic REST API URL
   *
   * \param[in] host The hostname or IP Address to communicate with
   * \param[in] path The URL path (E.g. /v1/documents) to invoke
   * \param[in] body The content to send as the PUT body
   * \param[in\ headers The HTTP Headers to use (Optional. Defaults to a blank set of headers)
   * \return A Response pointer that the call is responsible for deleting
   */
  Response* putSync(const std::string& host,
      const std::string& path,
      const IDocumentContent& body,
      const mlclient::HttpHeaders& headers = blankHeaders);

  /**
   * \brief A Synchronous HTTP DELETE to a remote MarkLogic REST API URL
   *
   * \param[in] host The hostname or IP Address to communicate with
   * \param[in] path The URL path (E.g. /v1/documents) to invoke
   * \param[in\ headers The HTTP Headers to use (Optional. Defaults to a blank set of headers)
   * \return A Response pointer that the call is responsible for deleting
   */
  Response* deleteSync(const std::string& host,
       const std::string& path,
       const mlclient::HttpHeaders& headers = blankHeaders);
private:
   AuthenticatingProxy(const AuthenticatingProxy& rhs); // hide copy constructor - not a valid operation


   /* Copies Microsoft CPPREST headers to useful mlclient::HttpHeaders class */
   static void copyHeaders(const web::http::http_headers& from, mlclient::HttpHeaders& to);

   Response* doRequest(const std::string& mthd,const std::string& host,const std::string& path,const HttpHeaders& headers,Response* response,const IDocumentContent* body = nullptr);

   Credentials credentials;
   uint32_t attempts;
};

} // end namespace internals

} // end namespace mlclient

#endif /* defined(AUTHENTICATING_PROXY) */
