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

#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/SearchDescription.hpp"

#include "mlclient/internals/Credentials.hpp"
#include "mlclient/internals/AuthenticatingProxy.hpp"

#include "mlclient/utilities/DocumentHelper.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"

#include "mlclient/logging.hpp"

#include <string>
#include <sstream>

namespace mlclient {

class Connection::Impl {
public:
  Impl() : proxy(), databaseName("Documents"), serverUrl("http://localhost:8002") {
    TIMED_FUNC(Connection_Impl_defaultConstructor);
    LOG(DEBUG) << "    Connection::Impl::defaultConstructor @" << &*this;
  };

  ~Impl() {
    ;
  };

  std::string serverUrl;
  std::string databaseName;
  internals::AuthenticatingProxy proxy;
};


Connection::Connection() : mImpl(new Impl) {
  TIMED_FUNC(Connection_defaultConstructor);
  LOG(DEBUG) << "    Connection::defaultConstructor @" << &*this;
}

Connection::~Connection() {
  TIMED_FUNC(Connection_destructor);
  delete mImpl;
}

void Connection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  TIMED_FUNC(Connection_configure);
  mImpl->serverUrl = std::string("http") + (usessl ? "s" : "") + "://" + hostname + ":" + port;
  internals::Credentials c(username, password);
  mImpl->proxy.addCredentials(c);
}

bool Connection::connect() {
  return true; // TODO test authentication scheme and pre-calculate auth where possible
}

void Connection::disconnect() {
  ; // TODO remove any TCP connections (if they have a keep-alive, they will still exist)
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
      pathAndQuerystring,
      payload);
}
Response* Connection::doDelete(const std::string& path) {
  TIMED_FUNC(Connection_doDelete);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,path);
}












Response* Connection::getDocument(const std::string& uri) {
  TIMED_FUNC(Connection_getDocument);
  return mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?uri=" + uri); // TODO escape URI for URL rules
}

Response* Connection::getDocument(Document& inout_document) {
  TIMED_FUNC(Connection_getDocument__Document);
  // TODO other categories too
  Response* resp = mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?category=content&uri=" + inout_document.getUri()); // TODO escape URI for URL rules
  mlclient::utilities::DocumentHelper::fromResponse(*resp,inout_document);
  return resp;
}

Response* Connection::getDocumentContent(Document& inout_document) {
  TIMED_FUNC(Connection_getDocument__Document);
  Response* resp = mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?category=content&uri=" + inout_document.getUri()); // TODO escape URI for URL rules
  mlclient::utilities::DocumentHelper::fromResponse(*resp,inout_document);
  return resp;
}

Response* Connection::getDocumentProperties(Document& inout_document) {
  TIMED_FUNC(Connection_getDocument__Document);
  Response* resp = mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?category=properties&uri=" + inout_document.getUri()); // TODO escape URI for URL rules
  inout_document.setProperties(mlclient::utilities::DocumentHelper::contentFromResponse(*resp));
  return resp;
}

Response* Connection::getDocumentPermissions(Document& inout_document) {
  TIMED_FUNC(Connection_getDocument__Document);
  Response* resp = mImpl->proxy.getSync(mImpl->serverUrl, "/v1/documents?category=permissions&uri=" + inout_document.getUri()); // TODO escape URI for URL rules
  std::vector<Permission> perms(mlclient::utilities::CppRestJsonHelper::permissionsFromResponse(*resp));
  inout_document.setPermissions(perms);
  return resp;
}

Response* Connection::saveDocumentContent(const std::string& uri,const IDocumentContent& payload) {
  TIMED_FUNC(Connection_saveDocumentContent);
  return mImpl->proxy.putSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri, // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      payload);
}

Response* Connection::saveDocuments(const DocumentSet& documents,const long startPosInclusive,
      const long endPosInclusive) {
  TIMED_FUNC(Connection_saveDocuments);
  return mImpl->proxy.multiPostSync(mImpl->serverUrl,"/v1/documents",documents,startPosInclusive,endPosInclusive);
}

Response* Connection::saveDocument(const Document& doc) {
  TIMED_FUNC(Connection_saveDocument__Document);
  DocumentSet set;
  set.push_back(doc);
  return mImpl->proxy.multiPostSync(mImpl->serverUrl,"/v1/documents",set,0,set.size() - 1);
  //return saveDocumentContent(doc.getUri(),*(doc.getContent()));
}

Response* Connection::deleteDocument(const std::string& uri) {
  TIMED_FUNC(Connection_deleteDocument);
  return mImpl->proxy.deleteSync(mImpl->serverUrl,
      "/v1/documents?uri=" + uri // TODO directory (non uri) version // TODO check for URL parsing // TODO fix JSON hard coding here
      );
}

Response* Connection::search(const SearchDescription& desc) {
  TIMED_FUNC(Connection_search);
  LOG(DEBUG) << "In Connection::search";
  std::ostringstream urlss;
  urlss << "/v1/search?format=json";
  urlss << "&start=" << desc.getStart();
  urlss << "&pageLength=" <<  desc.getPageLength();
  LOG(DEBUG) << "  Got page length";
  ITextDocumentContent* payload = desc.getPayload();
  LOG(DEBUG) << "  Payload:-";
  LOG(DEBUG) << payload->getContent();
  return mImpl->proxy.postSync(mImpl->serverUrl,urlss.str(), *payload);
}

Response* Connection::searchExtension(const std::string& extensionName,const SearchDescription& desc) {
  TIMED_FUNC(Connection_searchExtension);
  LOG(DEBUG) << "In Connection::searchExtension";
  std::ostringstream urlss;
  urlss << "/v1/resources/" << extensionName << "?format=json";
  urlss << "&rs:start=" << desc.getStart();
  urlss << "&rs:pageLength=" <<  desc.getPageLength();
  LOG(DEBUG) << "  Got page length";
  ITextDocumentContent* payload = desc.getPayload();
  LOG(DEBUG) << "  Payload:-";
  LOG(DEBUG) << payload->getContent();
  return mImpl->proxy.postSync(mImpl->serverUrl,urlss.str(), *payload);
}

Response* Connection::saveSearchOptions(const std::string& name,const IDocumentContent* optionsDoc) {
  TIMED_FUNC(Connection_saveSearchOptions);
  LOG(DEBUG) << "In Connection::saveSearchOptions";
  std::ostringstream urlss;
  urlss << "/v1/config/query/" << name;
  return mImpl->proxy.putSync(mImpl->serverUrl,urlss.str(), *optionsDoc);
}

Response* Connection::values(const std::string& valuesName,const std::string& optionsName) {
  TIMED_FUNC(Connection_valuesAggregate);
  std::ostringstream urlss;
  urlss << "/v1/values/" << valuesName << "?options=" << optionsName;
  return mImpl->proxy.getSync(mImpl->serverUrl,urlss.str());
}

Response* Connection::valuesExtension(const std::string& extensionName,const std::string& valuesName,
    const std::string& optionsName,const SearchDescription& desc) {
  TIMED_FUNC(Connection_valuesAggregate);
  std::ostringstream urlss;
  urlss << "/v1/resources/" << extensionName;// << "?rs:values=" << valuesName << "&rs:options=" << optionsName;
  //ITextDocumentContent* payload = desc.getPayload();
  //LOG(DEBUG) << "  Payload:-";
  //LOG(DEBUG) << payload->getContent();
  return mImpl->proxy.getSync(mImpl->serverUrl,urlss.str());
  // TODO replace this with POST once working...
  //return mImpl->proxy.postSync(mImpl->serverUrl,urlss.str(),*payload);
}

Response* Connection::listRootCollections() {
  TIMED_FUNC(Connection_listRootCollections);
  return listCollections(""); // TODO Check this works and doesn't require a "/"
}

Response* Connection::listCollections(const std::string& parentCollection) {
  TIMED_FUNC(Connection_listCollections);
  std::ostringstream os;
  os << "{\"search\": {\"query\": {\"collection-query\" : {\"uri\": [\"" << parentCollection << "\"]}},";
  os << "\"options\": {\"default-suggestion-source\": {\"collection\": {\"prefix\":\"" << parentCollection << "\"}}}}}";
  GenericTextDocumentContent tdc;
  tdc.setMimeType(IDocumentContent::MIME_JSON);
  tdc.setContent(os.str());
  // TODO handle query for /some that matches /some/col1 returns just /col1 - should correct to /some/col1???
  // TODO Find out why Accept: application/json is not being sent correctly (it works in PostMan)
  return mImpl->proxy.postSync(mImpl->serverUrl,"/v1/suggest?format=json",tdc);
}

} // end namespace mlclient
