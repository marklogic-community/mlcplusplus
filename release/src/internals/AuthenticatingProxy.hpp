//
//  AuthenticatingProxy.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef AUTHENTICATING_PROXY
#define AUTHENTICATING_PROXY

#include <map>
#include <functional>
#include <cstdint>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include "../Response.hpp"
#include "../DocumentContent.hpp"
#include "Credentials.hpp"

#include "../mlclient.hpp"

namespace mlclient {

namespace internals {

const web::http::http_headers blankHeaders;

/**
/// AuthenticatingProxy to handle authenticated calls to MarkLogic
///
/// This class proxies the calls to MarkLogic, handling authentication as
/// necessary.  It includes both synchronous and asynchronous methods to allow
/// users to select the method of invocation most suited to their application.
///
/// Note that some concepts contained run against "REST" principles.  This is 
/// not only a REST library and is meant to be used as a general MarkLogic 
/// C++ library.  It should be backward compatible with non RESTful end points
/// as well as REST.
**/
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
  std::unique_ptr<Response> getSync(const std::string& host,
      const std::string& path,
      const web::http::http_headers& headers = blankHeaders);
/*
  void getAsync(const std::string& host,
      const std::string& path,
      const std::function<void(const Response&)> handler,
      const http_headers& headers = blankHeaders);
*/

  //std::unique_ptr<Response> postSync(const std::string& host,
  //    const std::string& path,
  //    const web::json::value& body,
  //    const web::http::http_headers& headers = blankHeaders);

  std::unique_ptr<Response> postSync(const std::string& host,
      const std::string& path,
      const IDocumentContent& body,
      const web::http::http_headers& headers = blankHeaders);
  /*
    Response Post(const std::string& host, 
                  const std::string& path,
                  const xmlDocPtr body,
                  const http_headers& headers = blankHeaders);
   */
  //std::unique_ptr<Response> postSync(const std::string& host,
  //    const std::string& path,
  //    const std::wstring& text_body,
  //    const web::http::http_headers& headers = blankHeaders);
/*
  std::unique_ptr<Response> postSync(const std::string& host,
      const std::string& path,
      const uint8_t* data,
      const size_t& size,
      const web::http::http_headers& headers = blankHeaders);
*/
  /*
  std::unique_ptr<Response> postFileSync(const std::string& host,
      const std::string& path,
      const std::string& file_path,
      const web::http::http_headers& headers = blankHeaders);
      */
/*
  void postAsync(const std::string& host,
      const std::string& path,
      const http_headers& headers,
      const params_t& body,
      const std::function<void(const Response&)> handler);

  void postAsync(const std::string& host,
      const std::string& path,
      const http_headers& headers,
      const std::function<void(const Response&)> handler);
  void postAsync(const std::string& host,
      const std::string& path,
      const std::function<void(const Response&)> handler);
*/
  //std::unique_ptr<Response> putSync(const std::string& host,
  //    const std::string& path,
  //    const std::wstring& text_body,
  //    const web::http::http_headers& headers = blankHeaders);

  std::unique_ptr<Response> putSync(const std::string& host,
      const std::string& path,
      const IDocumentContent& text_body,
      const web::http::http_headers& headers = blankHeaders);
  /*
    Response& Put(const std::string& host,
                 const std::string& path,
                 const xmlDocPtr& xml_body,
                 const http_headers& headers = blankHeaders);
   */
  /*
   std::unique_ptr<Response> putSync(const std::string& host,
       const std::string& path,
       const uint8_t* data,
       const size_t& size,
       const web::http::http_headers& headers = blankHeaders);
       */
/*
   void putAsync(const std::string& host,
       const std::string& path,
       const http_headers& headers,
       const params_t& body,
       const std::function<void(const Response&)> handler);
   void putAsync(const std::string& host,
       const std::string& path,
       const http_headers& headers,
       const std::function<void(const Response&)> handler);
   void putAsync(const std::string& host,
       const std::string& path,
       const std::function<void(const Response&)> handler);
*/
   std::unique_ptr<Response> deleteSync(const std::string& host,
       const std::string& path,
       const web::http::http_headers& headers = blankHeaders);
/*
   void deleteAsync(const std::string& host,
       const std::string& path,
       const std::function<void(const Response&)> handler,
       const http_headers& headers = blankHeaders);
*/
private:
   AuthenticatingProxy(const AuthenticatingProxy& rhs); // hide copy constructor - not a valid operation
   //AuthenticatingProxy& operator= (const AuthenticatingProxy& rhs); // hide assignment operator - not a valid operation


   Credentials credentials;
   uint32_t attempts;
};

}

}

#endif /* defined(AUTHENTICATING_PROXY) */
