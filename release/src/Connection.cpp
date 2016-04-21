

#include "Connection.hpp"
#include "Response.hpp"
#include "CWrapper.hpp"
#include "internals/Credentials.hpp"
#include "internals/AuthenticatingProxy.hpp"

namespace mlclient {


Connection::Connection() : _proxy() {
	_serverUrl = "http://localhost:8002";
}

Connection::~Connection() {
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
	Connection::configure(hostname,port,username,password,false);
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  _serverUrl = std::string("http") + (usessl ? "s" : "") + "://" + hostname + ":" + port;
  internals::Credentials c(username, password);
  _proxy.AddCredentials(c);
}









// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
std::unique_ptr<Response> Connection::doGet(const std::string& pathAndQuerystring) {
	return Connection::_proxy.Get(_serverUrl, pathAndQuerystring);
}
std::unique_ptr<Response> Connection::doPut(const std::string& pathAndQuerystring,const web::json::value& payload) {
	return _proxy.Put(_serverUrl,
		pathAndQuerystring,
	    payload);
}
std::unique_ptr<Response> Connection::doPost(const std::string& pathAndQuerystring,const web::json::value& payload) {
	return _proxy.Post(_serverUrl,
			"/v1/search",
		    payload);
}
// TODO XML payload
// TODO multipart payload
std::unique_ptr<Response> Connection::doDelete(const std::string& path) {
	return _proxy.Delete(_serverUrl,path);
}












std::unique_ptr<Response> Connection::getDocument(const std::string& uri) {
  return Connection::_proxy.Get(_serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules

  //return response;
}

// TODO XML version
std::unique_ptr<Response> Connection::saveDocument(const std::string& uri,const web::json::value& payload) {
    //payload[U("hello")] = web::json::value::string("world");

  return _proxy.Put(_serverUrl,
    "/v1/documents?extension=json&uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing
    payload);
}

/*
Response Connection::saveAllDocuments(const std::string& uris[], const web::json::value payload[]) {
  // TODO multi part mime
}*/

std::unique_ptr<Response> Connection::_dosearch(const web::json::value& combined) {
	web::json::value search = web::json::value::object();
	search[U("search")] = web::json::value(combined);

	return _proxy.Post(_serverUrl,
		"/v1/search",
	    search);
}

std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const web::json::value& options) {
	web::json::value combined = web::json::value::object();
	combined[U("query")] = web::json::value(searchQuery);
	combined[U("options")] = web::json::value(options);
	return Connection::_dosearch(combined);
}


std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const std::string& qtext) {
	web::json::value combined = web::json::value::object();
	combined[U("query")] = web::json::value(searchQuery);
    combined[U("qtext")] = web::json::value(qtext);
	return Connection::_dosearch(combined);
}

std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options) {
    // combined query
	web::json::value combined = web::json::value::object();
	combined[U("query")] = web::json::value(searchQuery);
    combined[U("qtext")] = web::json::value(qtext);
	combined[U("options")] = web::json::value(options);

	return Connection::_dosearch(combined);
}

// TODO overload the above method to allow for null options

}
