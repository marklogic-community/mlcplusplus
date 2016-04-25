

#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "internals/Credentials.hpp"
#include "internals/AuthenticatingProxy.hpp"

namespace mlclient {


class Connection::Impl {
public:
  Impl() : proxy()  {
    serverUrl = "http://localhost:8002";
  };

  ~Impl() {
    ;
  };

  std::string serverUrl;
  internals::AuthenticatingProxy proxy;

  // prevent compiler automatically defining the copy constructor and assignment operator:-
  //Connection(const Connection&);
  //Connection& operator= (const Connection&);

  /*
  std::unique_ptr<Response> dosearch(const web::json::value& combined) {
    web::json::value search = web::json::value::object();
    search[U("search")] = web::json::value(combined);

    return proxy.postSync(serverUrl,
        "/v1/search",
        search);
  };
  */

  /*

  // HIGH
  void applyTransformProperties();
  void applySearchProperties();
  */

private:

};


Connection::Connection() :mImpl(new Impl) {
}

Connection::~Connection() {
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
  Connection::configure(hostname,port,username,password,false);
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  mImpl->serverUrl = std::string("http") + (usessl ? "s" : "") + "://" + hostname + ":" + port;
  internals::Credentials c(username, password);
  mImpl->proxy.addCredentials(c);
}









// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
std::unique_ptr<Response> Connection::doGet(const std::string& pathAndQuerystring) {
  return mImpl->proxy.getSync(mImpl->serverUrl, pathAndQuerystring);
}
std::unique_ptr<Response> Connection::doPut(const std::string& pathAndQuerystring,const DocumentContent& payload) {
  return mImpl->proxy.putSync(mImpl->serverUrl,
      pathAndQuerystring,
      payload.getContent());
}
std::unique_ptr<Response> Connection::doPost(const std::string& pathAndQuerystring,const DocumentContent& payload) {
  return mImpl->proxy.postSync(mImpl->serverUrl,
      "/v1/search",
      payload);
}
// TODO XML payload
// TODO multipart payload
std::unique_ptr<Response> Connection::doDelete(const std::string& path) {
  return mImpl->proxy.deleteSync(mImpl->serverUrl,path);
}












std::unique_ptr<Response> Connection::getDocument(const std::string& uri) {
  return mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules

  //return response;
}

// TODO XML version
std::unique_ptr<Response> Connection::saveDocument(const std::string& uri,const DocumentContent& payload) {
  //payload[U("hello")] = web::json::value::string("world");

  return mImpl->proxy.putSync(mImpl->serverUrl,
      "/v1/documents?extension=json&uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing
      payload.getContent());
}

/*
Response Connection::saveAllDocuments(const std::string& uris[], const web::json::value payload[]) {
  // TODO multi part mime
}*/




std::unique_ptr<Response> Connection::search(const SearchDescription& desc) {
  return mImpl->proxy.postSync(mImpl->serverUrl,"/v1/search", desc.getPayload().getContent());
}


/*

std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const web::json::value& options) {
  web::json::value combined = web::json::value::object();
  combined[U("query")] = web::json::value(searchQuery);
  combined[U("options")] = web::json::value(options);
  return mImpl->dosearch(combined);
}


std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const std::string& qtext) {
  web::json::value combined = web::json::value::object();
  combined[U("query")] = web::json::value(searchQuery);
  combined[U("qtext")] = web::json::value(qtext);
  return mImpl->dosearch(combined);
}

std::unique_ptr<Response> Connection::search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options) {
  // combined query
  web::json::value combined = web::json::value::object();
  combined[U("query")] = web::json::value(searchQuery);
  combined[U("qtext")] = web::json::value(qtext);
  combined[U("options")] = web::json::value(options);

  return mImpl->dosearch(combined);
}
*/

// TODO overload the above method to allow for null options

}
