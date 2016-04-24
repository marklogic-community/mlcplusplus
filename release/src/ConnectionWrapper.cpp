#include "ConnectionWrapper.h"
#include "Connection.hpp"
#include <cpprest/json.h>
#include <stdbool.h>
#include "CWrapper.hpp"

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
  return (CResponse*)(new CWrapper<Response>(t->doPut(std::string(pathAndQuerystring),json::value(std::string(payload)))));
}

CResponse * ml_connection_doPost(const CConnection *conn,const char *pathAndQuerystring,
    const char *payload) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  return (CResponse*)(new CWrapper<Response>(t->doPost(std::string(pathAndQuerystring),json::value(std::string(payload)))));
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
  return (CResponse*)(new CWrapper<Response>(t->saveDocument(std::string(uri),json::value(std::string(payload)))));
}

CResponse * ml_connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,
    const char *options) {
  using namespace mlclient;
  using namespace web;
  Connection *t = (Connection *)conn;
  return (CResponse*)(new CWrapper<Response>(t->search(json::value(std::string(searchQuery)),std::string(qtext),json::value(std::string(options)))));
}


}
