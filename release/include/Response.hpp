//
//  Response.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef __Scratch__Response__
#define __Scratch__Response__

#include <cstdint>
#include <cpprest/json.h>
#include <cpprest/http_client.h>
#include <libxml2/libxml/tree.h>

#include "ResponseCodes.hpp"
#include "Types.hpp"


class Response {
    ResponseCodes _response_code;
    ResponseType  _response_type;
    header_t      _headers;
public:
    ResponseType ResponseType(void) const;
    
    void SetResponseCode(const ResponseCodes& code);
    void SetResponseType(const enum ResponseType& type);
    void SetResponseHeaders(const header_t& headers);
    void SetResponseHeaders(const web::http::http_headers& headers);
    
    ResponseCodes GetResponseCode(void) const;
    enum ResponseType GetResponseType(void) const;
    header_t GetResponseHeaders(void) const;
    
    
    /* 
     * Read up to max size bytes into the response, starting at offset.
     */
    size_t Read(void* buffer, const size_t& max_size, const size_t off = 0);
    
    /*
     * Tries to read back the response as a string.  Throws ResponseTypeException
     * if the response is not a string or string based.
     */
    std::wstring String() const;
    
    /*
     * Tries to return the response as an XML.  Throws ResponseTypeException if it's
     * not XML.
     */
    xmlDocPtr Xml() const;
    
    /*
     * Guess what this does.
     */
    web::json::value Json() const;
};

#endif /* defined(__Scratch__Response__) */
