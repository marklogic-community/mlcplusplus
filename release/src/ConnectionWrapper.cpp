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
#include "mlclient/ConnectionWrapper.h"
#include "mlclient/Connection.hpp"
#include "mlclient/CWrapper.hpp"
#include <cpprest/json.h>
#include <stdbool.h>

extern "C" {

// constructor and destructor
CConnection * ml_connection_new() {
  using namespace mlclient;
  Connection *t = new Connection();

  return (CConnection *)t;
}

void ml_connection_delete(CConnection *conn) {
  using namespace mlclient;
  Connection *t = (Connection *)conn;

  delete t;
}

void ml_connection_configure(const CConnection *conn,const char *hostname, const char *port,
    const char *username, const char *password, const int usessl) {
  using namespace mlclient;
  Connection *t = (Connection *)conn;
  t->configure(std::string(hostname),std::string(port),std::string(username),std::string(password),
      (0==usessl?false:true));
}

// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
CResponse * ml_connection_doGet(const CConnection *conn,const char *pathAndQuerystring) {
  using namespace mlclient;
  Connection *t = (Connection *)conn;
  return (CResponse*)(new CWrapper<Response>(t->doGet(std::string(pathAndQuerystring))));
}

CResponse * ml_connection_doPut(const CConnection *conn,const char *pathAndQuerystring,
    const char *payload) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  GenericTextDocumentContent tdc;
  tdc.setContent(std::string(payload));
  return (CResponse*)(new CWrapper<Response>(t->doPut(std::string(pathAndQuerystring),tdc)));
}

CResponse * ml_connection_doPost(const CConnection *conn,const char *pathAndQuerystring,
    const char *payload) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  GenericTextDocumentContent tdc;
  tdc.setContent(std::string(payload));
  return (CResponse*)(new CWrapper<Response>(t->doPost(std::string(pathAndQuerystring),tdc)));
}

CResponse * ml_connection_doDelete(const CConnection *conn,const char *path) {
  using namespace mlclient;
  Connection *t = (Connection *)conn;
  return (CResponse*)(new CWrapper<Response>(t->doDelete(std::string(path))));
}

// Wrapped and supported functions
CResponse * ml_connection_getDocument(const CConnection *conn,const char *uri) {
  using namespace mlclient;
  Connection *t = (Connection *)conn;
  CWrapper<Response>* resp = new CWrapper<Response>(std::move(t->getDocument(std::string(uri))));
  return (CResponse*)(resp);
}

CResponse * ml_connection_saveDocument(const CConnection *conn,const char *uri,const char *payload) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  GenericTextDocumentContent tdc;
  tdc.setContent(std::string(payload));
  return (CResponse*)(new CWrapper<Response>(t->saveDocumentContent(std::string(uri),tdc)));
}

CResponse * ml_connection_deleteDocument(const CConnection *conn,const char *uri) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  return (CResponse*)(new CWrapper<Response>(t->deleteDocument(std::string(uri))));
}

CResponse * ml_connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,
    const char *options) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  GenericTextDocumentContent sq;
  sq.setContent(std::string(searchQuery));
  GenericTextDocumentContent so;
  so.setContent(std::string(options));
  SearchDescription desc;
  desc.setOptions(so);
  desc.setQuery(sq);
  desc.setQueryText(std::string(qtext));
  return (CResponse*)(new CWrapper<Response>(t->search(desc)));
}


}
