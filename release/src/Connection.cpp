

#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include "internals/Credentials.hpp"
#include "internals/AuthenticatingProxy.hpp"

#include "easylogging++.h"

namespace mlclient {


class Connection::Impl {
public:
  Impl() : proxy(), databaseName("Documents"), serverUrl("http://localhost:8002") {
    LOG(DEBUG) << "    Connection::Impl::defaultConstructor @" << &*this;
  };

  ~Impl() {
    ;
  };

  std::string serverUrl;
  std::string databaseName;
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


Connection::Connection() : mImpl(new Impl) {
  LOG(DEBUG) << "    Connection::defaultConstructor @" << &*this;
}

Connection::~Connection() {
  delete mImpl;
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
  Connection::configure(hostname,port,username,password,false);
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  mImpl->serverUrl = std::string("http") + (usessl ? "s" : "") + "://" + hostname + ":" + port;
  internals::Credentials c(username, password);
  mImpl->proxy.addCredentials(c);
}

void Connection::setDatabaseName(const std::string& db) {
  mImpl->databaseName = db;
}

std::string Connection::getDatabaseName() {
  return mImpl->databaseName;
}







// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
std::unique_ptr<Response> Connection::doGet(const std::string& pathAndQuerystring) {
  TIMED_FUNC(Connection_doGet);
  return mImpl->proxy.getSync(mImpl->serverUrl, pathAndQuerystring);
}
std::unique_ptr<Response> Connection::doPut(const std::string& pathAndQuerystring,const DocumentContent& payload) {
  TIMED_FUNC(Connection_doPut);
  return mImpl->proxy.putSync(mImpl->serverUrl,
      pathAndQuerystring,
      payload);
}
std::unique_ptr<Response> Connection::doPost(const std::string& pathAndQuerystring,const DocumentContent& payload) {
  TIMED_FUNC(Connection_doPost);
  return mImpl->proxy.postSync(mImpl->serverUrl,
      "/v1/search",
      payload);
}

// TODO multipart payload
std::unique_ptr<Response> Connection::doDelete(const std::string& path) {
  TIMED_FUNC(Connection_doDelete);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,path);
}












std::unique_ptr<Response> Connection::getDocument(const std::string& uri) {
  TIMED_FUNC(Connection_getDocument);
  return mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules
}

// TODO XML version
std::unique_ptr<Response> Connection::saveDocument(const std::string& uri,const DocumentContent& payload) {
  TIMED_FUNC(Connection_saveDocument);
  return mImpl->proxy.putSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      payload);
}

std::unique_ptr<Response> Connection::deleteDocument(const std::string& uri) {
  TIMED_FUNC(Connection_deleteDocument);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      );
}

/*
Response Connection::saveAllDocuments(const std::string& uris[], const web::json::value payload[]) {
  // TODO multi part mime
}*/




std::unique_ptr<Response> Connection::search(const SearchDescription& desc) {
  TIMED_FUNC(Connection_search);
  return mImpl->proxy.postSync(mImpl->serverUrl,"/v1/search?format=json", *desc.getPayload());
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

} // end namespace mlclient
