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
 */

#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "SearchDescription.hpp"
#include "internals/Credentials.hpp"
#include "internals/AuthenticatingProxy.hpp"

#include "easylogging++.h"

namespace mlclient {

/*
IConnection::IConnection() {
  LOG(DEBUG) << "    IConnection::defaultConstructor @" << &*this;
  LOG(DEBUG) << "    IConnection::defaultConstructor @" << &*this << " complete.";
}

IConnection::~IConnection() {
  LOG(DEBUG) << "    IConnection::destructor @" << &*this;
  LOG(DEBUG) << "    IConnection::destructor @" << &*this << " complete.";
}*/

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

//void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
//  Connection::configure(hostname,port,username,password,false);
//}

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
Response* Connection::doGet(const std::string& pathAndQuerystring) {
  TIMED_FUNC(Connection_doGet);
  return mImpl->proxy.getSync(mImpl->serverUrl, pathAndQuerystring);
}
Response* Connection::doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(Connection_doPut);
  return mImpl->proxy.putSync(mImpl->serverUrl,
      pathAndQuerystring,
      payload);
}
Response* Connection::doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(Connection_doPost);
  return mImpl->proxy.postSync(mImpl->serverUrl,
      "/v1/search",
      payload);
}

// TODO multipart payload
Response* Connection::doDelete(const std::string& path) {
  TIMED_FUNC(Connection_doDelete);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,path);
}












Response* Connection::getDocument(const std::string& uri) {
  TIMED_FUNC(Connection_getDocument);
  return mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules
}

// TODO XML version
Response* Connection::saveDocument(const std::string& uri,const IDocumentContent& payload) {
  TIMED_FUNC(Connection_saveDocument);
  return mImpl->proxy.putSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      payload);
}

Response* Connection::deleteDocument(const std::string& uri) {
  TIMED_FUNC(Connection_deleteDocument);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      );
}

/*
Response Connection::saveAllDocuments(const std::string& uris[], const web::json::value payload[]) {
  // TODO multi part mime
}*/




Response* Connection::search(const SearchDescription& desc) {
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
