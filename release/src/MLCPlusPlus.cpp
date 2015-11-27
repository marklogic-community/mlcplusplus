//
//  MLCPlusPlus.cpp
//  MLCPlusPlus
//
//  Created by Adam Fowler on 04/Jun/2014.
//  Copyright (c) 2014 __MARKLOGIC__. All rights reserved.
//

#include "MLCPlusPlus.hpp"


Connection::Connection(void) : _proxy(), _serverUrl("http://localhost:8002") {
    ;
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
	Connection::configure(hostname,port,username,password,false);
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  _serverUrl = "http" + (usessl ? "s" : "") + "://" + hostname + ":" + port;
  Credentials c(username, password);
  _proxy.AddCredentials(c);
}

Response Connection::get(const std::string& uri) {
  Response response = Connection::_proxy.Get(_serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules

  return response;
}

// TODO XML version
Response Connection::save(const std::string& uri,const web::json::value& payload) {
    //payload[utility::string_t("hello")] = web::json::value::string("world");

  Response response = _proxy.Put(_serverUrl,
    "/v1/documents?extension=json&uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing
    payload);
  return response;
}

/*
Response Connection::saveAll(const std::string& uris[], const web::json::value payload[]) {
  // TODO multi part mime 
}*/

Response Connection::search(const web::json::value& searchQuery,const std::string& options) {
  Response response = _proxy.Post(_serverUrl,
    "/v1/search?options=" + options, // TODO check for URL parsing
    searchQuery);
  return response;
}

Response Connection::search(const web::json::value& searchQuery,const web::json::value& options) {
	return Connection::search(searchQuery,(std::string&)nullptr,options);
}


Response Connection::search(const web::json::value& searchQuery,const std::string& qtext) {
	return Connection::search(searchQuery,qtext,(web::json::value)nullptr);
}

Response Connection::search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options) {
    // combined query
	web::json::value combined;
	if (searchQuery) {
	  combined[utility::string_t("query")] = searchQuery;
	}
	if (qtext) {
	  combined[utility::string_t("qtext")] = qtext;
	}
	if (options) {
	  combined[utility::string_t("options")] = options;
	}

	web::json::value search;
	search[utility::string_t("search")] = combined;

	Response response = _proxy.Post(_serverUrl,
		"/v1/search",
	    search);
	return response;
}
