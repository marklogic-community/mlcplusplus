/*
 */

#include "FakeConnection.hpp"
#include <string>
#include <map>

#include "../easylogging++.h"

#include "../HttpHeaders.hpp"

namespace mlclient {

namespace internals {


//typedef std::map<char*, IDocumentContent*>::iterator DocMapIter; // Use::Iterator version as it's clearer

// strcmp equals function lambda for use by map.find()
//auto docUriComp = [](const char* p1,const char* p2) {
//  return (0 == strcmp(p1,p2));
//};

//typedef std::map<char*, IDocumentContent*, decltype(docUriComp)> UriDocumentMap;


class FakeConnection::Impl {
public:
  Impl() : databaseName("Documents"), serverUrl("http://localhost:8002"), documents() {
    ;
  };
  ~Impl() {
    ;
  };

  std::string serverUrl;
  std::string databaseName;
  //UriDocumentMap documents;
  std::map<std::string, IDocumentContent*> documents;
};

FakeConnection::FakeConnection() : mImpl(new Impl) {
  ; // TODO delete all contents of mImpl->documents safely (to be fair - this class is only used in testing)
}

FakeConnection::~FakeConnection() {
  delete mImpl;
  mImpl = NULL;
}


void FakeConnection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
  configure(hostname,port,username,password,false);
}

void FakeConnection::configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, bool usessl) {
  mImpl->serverUrl = std::string("http") + (usessl ? "s" : "") + "://" + hostname + ":" + port;
}

void FakeConnection::setDatabaseName(const std::string& db) {
  mImpl->databaseName = db;
}

std::string FakeConnection::getDatabaseName() {
  return mImpl->databaseName;
}

std::unique_ptr<Response> FakeConnection::doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_doPut);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_doPost);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::doGet(const std::string& pathAndQuerystring) {
  TIMED_FUNC(FakeConnection_doGet);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::doDelete(const std::string& pathAndQuerystring) {
  TIMED_FUNC(FakeConnection_doDelete);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::NO_CONTENT); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::saveDocument(const std::string& uri,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_saveDocument);
  LOG(DEBUG) << "  Entering FakeConnection::saveDocument";

  //IDocumentContent* dp = &(const_cast<IDocumentContent&>(payload));
  IDocumentContent* dp = &(const_cast<IDocumentContent&>(payload));
  mImpl->documents.insert(std::pair<std::string,IDocumentContent*>(uri,dp));

  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::getDocument(const std::string& uri) {
  TIMED_FUNC(FakeConnection_getDocument);
  LOG(DEBUG) << "  Entering FakeConnection::getDocument";

  LOG(DEBUG) << "    Fetching document with URI: " << uri;
  std::map<std::string,IDocumentContent*>::iterator it;
  it = mImpl->documents.find(uri);
  std::string ct("");
  std::string mime("");
  if (mImpl->documents.end() != it) {
    ct = ((IDocumentContent*)it->second)->getContent();
    mime = ((IDocumentContent*)it->second)->getMimeType();
  }
  //IDocumentContent& value = mImpl->documents[uri.c_str()];

  //LOG(DEBUG) << "    pointer value: " << value;

  Response* response = new Response;
  LOG(DEBUG) << "  Setting response code";

  response->setResponseCode(ResponseCode::OK);

  LOG(DEBUG) << "  Setting response content ptr";
  //std::unique_ptr<std::string> content(new std::string(ct));
  //response->setContent(std::move(content));
  response->setContent(new std::string(ct));
  LOG(DEBUG) << "  Setting response headers";
  HttpHeaders headers;
  headers.setHeader("Content-type",mime);
  response->setResponseHeaders(headers);

  LOG(DEBUG) << "  returning response ";
  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::deleteDocument(const std::string& uri) {
  TIMED_FUNC(FakeConnection_deleteDocument);
  LOG(DEBUG) << "  Entering FakeConnection::deleteDocument";

  std::map<std::string,IDocumentContent*>::iterator it;
  it = mImpl->documents.find(uri.c_str());
  if (mImpl->documents.end() != it) {
    // delete if found
    LOG(DEBUG) << "   URI found: " << uri;
    mImpl->documents.erase(it);
  } else {
    LOG(DEBUG) << "   URI not found: " << uri;
  }

  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return std::unique_ptr<Response> (response);
}

std::unique_ptr<Response> FakeConnection::search(const SearchDescription& desc) {
  TIMED_FUNC(FakeConnection_search);
  LOG(DEBUG) << "  Entering FakeConnection::search";

  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK);
  HttpHeaders headers;
  headers.setHeader("Content-type","application/json");
  response->setResponseHeaders(headers);
  std::ostringstream cos;
  cos <<
      "{\"response\": {" <<
        "\"start\": 1, \"page-length\": ";

  // return 10 or documents.length, whichever is smaller
  if (mImpl->documents.size() < 10) {
    cos << mImpl->documents.size();
  } else {
    cos << 10;
  }
  cos << ", \"results\": [";

  // loop over documents in map
  std::map<std::string,IDocumentContent*>::iterator it;
  int count = 0;
  for (it = mImpl->documents.begin();it != mImpl->documents.end() && count < 10;++it) {
    ++count; // iterate first as MarkLogic responses are 1 indexed, not 0 indexed
    if (count > 1) {
      cos << ",";
    }
    cos << "{\"index\": " << count << " , \"uri\": \"" << (it->first)
        << "\", \"score\": \"43648\" \"confidence\":\"0.418356\" \"fitness\":\"0.50947\"}";
  }

  cos << "] } }";
  //std::unique_ptr<std::string> cPtr(new std::string(cos.str()));
  //response->setContent(std::move(cPtr));
  response->setContent(new std::string(cos.str()));

  return std::unique_ptr<Response> (response);
}


} // end namespace internals

} // end namespace mlclient
