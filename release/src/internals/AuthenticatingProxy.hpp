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
#include <cstdint>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
//#include <libxml/parser.h>
#include "../Response.hpp"
#include "../ResponseCodes.hpp"
#include "Credentials.hpp"
#include "Types.hpp"

#include "../MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {
using namespace web::http;

const http_headers blank_headers;

///
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
///
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
    void AddCredentials(const Credentials& c);
    
    ///
    /// Returns a read-only copy of the credentials used by the proxy.
    ///
    /// \return The credentials
    ///
    const Credentials& GetCredentials(void) const;
    
    ///
    /// Invokes a synchronous GET operation on the MarkLogic server.
    ///
    /// \param host The hostname or IP address ("127.0.0.1")
    /// \param path The path to invoke ("/v1/documents?uri=/foo/bar.xml")
    /// \param headers The HTTP headers to include in the invocation
    /// \return The Response object
    ///
    const Response& Get(const std::string& host,
                 const std::string& path,
                 const http_headers& headers = blank_headers);
            
    void Get_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler,
                   const http_headers& headers = blank_headers);
    
    
    const Response& Post(const std::string& host,
                  const std::string& path,
                  const json::value& body,
                  const http_headers& headers = blank_headers);
    /*
    Response Post(const std::string& host, 
                  const std::string& path,
                  const xmlDocPtr body,
                  const http_headers& headers = blank_headers);
                  */
    const Response& Post(const std::string& host,
                  const std::string& path,
                  const std::wstring& text_body,
                  const http_headers& headers = blank_headers);
    const Response& Post(const std::string& host,
                  const std::string& path,
                  const uint8_t* data, 
                  const size_t& size,
                  const http_headers& headers = blank_headers);
    const Response& PostFile(const std::string& host,
                      const std::string& path,
                      const std::string& file_path,
                      const http_headers& headers = blank_headers);
    
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const http_headers& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const http_headers& headers,
                   const std::function<void(const Response&)> handler);
    void Post_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
    
    const Response& Put(const std::string& host,
                 const std::string& path,
                 const std::wstring& text_body,
                 const http_headers& headers = blank_headers);
    const Response& Put(const std::string& host,
                 const std::string& path,
                 const json::value& text_body,
                 const http_headers& headers = blank_headers);
    /*
    Response& Put(const std::string& host,
                 const std::string& path,
                 const xmlDocPtr& xml_body,
                 const http_headers& headers = blank_headers);
                 */
    const Response& Put(const std::string& host,
                 const std::string& path,
                 const uint8_t* data, 
                 const size_t& size,
                 const http_headers& headers = blank_headers);
    
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const http_headers& headers,
                   const params_t& body,
                   const std::function<void(const Response&)> handler);
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const http_headers& headers,
                   const std::function<void(const Response&)> handler);
    void Put_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler);
    
    const Response& Delete(const std::string& host,
                 const std::string& path,
                 const http_headers& headers = blank_headers);
    
    void Delete_Async(const std::string& host,
                   const std::string& path,
                   const std::function<void(const Response&)> handler,
                   const http_headers& headers = blank_headers);

private:
    AuthenticatingProxy(const AuthenticatingProxy& rhs); // hide copy constructor - not a valid operation
    //AuthenticatingProxy& operator= (const AuthenticatingProxy& rhs); // hide assignment operator - not a valid operation


    Credentials _credentials;
    uint32_t _attempts;
};

}

}

#endif /* defined(__Scratch__AuthenticatingProxy__) */
