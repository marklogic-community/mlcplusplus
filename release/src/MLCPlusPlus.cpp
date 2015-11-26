//
//  MLCPlusPlus.cpp
//  MLCPlusPlus
//
//  Created by Adam Fowler on 04/Jun/2014.
//  Copyright (c) 2014 __MARKLOGIC__. All rights reserved.
//

#include "MLCPlusPlus.h"

Connection* Connection::_instance = nullptr;

Connection::Connection(void) {
    ;
}

Connection* Connection::Instance(void) {
    if (Connection::_instance == nullptr) {
        Connection::_instance = new Connection();
    }
    return Connection::_instance;
}

void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  _serverUrl = "http://" + hostname + ":" + port;
  Credentials c(username, password);
  _proxy.addCredentials(c)

}

Response get(std::string& uri) {
  Response response = _proxy.Get(_serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules

  return response;
}

// TODO XML version
Response save(std::string& uri,web::json::value payload) {
    //payload[utility::string_t("hello")] = web::json::value::string("world");

  Response response = ap.Put(_serverUrl,
    "/v1/documents?extension=json&uri=" + uri, // TODO directory (non uri) version TODO check for URL parsing
    payload);
  return response;
}


Response saveAll(std::string& uris[], web::json::value payload[]) {
  // TODO multi part mime 
}

Response search(web::json::value searchQuery,std::string& options) {
  Response response = ap.Post(_serverUrl,
    "/v1/search?options=" + options, // TODO check for URL parsing
    payload);
  return response;
}
