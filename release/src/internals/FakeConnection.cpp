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
 *
 */

#include "mlclient/internals/FakeConnection.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

#include "mlclient/logging.hpp"

#include "mlclient/HttpHeaders.hpp"

namespace mlclient {

namespace internals {


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
  std::map<std::string, IDocumentContent*> documents;
};

FakeConnection::FakeConnection() : mImpl(new Impl) {
  ; // TODO delete all contents of mImpl->documents safely (to be fair - this class is only used in testing)
}

FakeConnection::~FakeConnection() {
  delete mImpl;
  mImpl = NULL;
}

bool FakeConnection::connect() {
  return true;
}

void FakeConnection::disconnect() {
  ;
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

Response* FakeConnection::doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_doPut);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return response;
}

Response* FakeConnection::doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_doPost);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return response;
}

Response* FakeConnection::doGet(const std::string& pathAndQuerystring) {
  TIMED_FUNC(FakeConnection_doGet);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK); // otherwise blank

  return response;
}

Response* FakeConnection::doDelete(const std::string& pathAndQuerystring) {
  TIMED_FUNC(FakeConnection_doDelete);
  Response* response = new Response;

  response->setResponseCode(ResponseCode::NO_CONTENT); // otherwise blank

  return response;
}

Response* FakeConnection::saveDocumentContent(const std::string& uri,const IDocumentContent& payload) {
  TIMED_FUNC(FakeConnection_saveDocumentContent);
  LOG(DEBUG) << "  Entering FakeConnection::saveDocumentContent";

  IDocumentContent* dp = &(const_cast<IDocumentContent&>(payload));
  mImpl->documents.insert(std::make_pair(uri,dp));

  Response* response = new Response;

  response->setResponseCode(ResponseCode::CREATED); // otherwise blank
  response->setResponseType(ResponseType::UNKNOWN_TYPE); // explicit

  return response;
}

Response* FakeConnection::getDocument(const std::string& uri) {
  TIMED_FUNC(FakeConnection_getDocument);
  LOG(DEBUG) << "  Entering FakeConnection::getDocument";

  LOG(DEBUG) << "    Fetching document with URI: " << uri;
  std::map<std::string,IDocumentContent*>::iterator it;
  it = mImpl->documents.find(uri);
  std::string ct("");
  std::string mime("");
  if (mImpl->documents.end() != it) {
    LOG(DEBUG) << "    Found document with URI: " << uri;
    IDocumentContent* docPtr = it->second;
    ct = docPtr->getContent();
    mime = docPtr->getMimeType();
  }

  Response* response = new Response;
  LOG(DEBUG) << "  Setting response code";


  bool isBlank = 0 == ct.compare("");
  LOG(DEBUG) << "  Setting response content ptr";
  response->setContent(std::move(ct));
  LOG(DEBUG) << "  Setting response headers";
  if (isBlank) {
    // not found
    response->setResponseCode(ResponseCode::NOT_FOUND);
    response->setResponseType(ResponseType::UNKNOWN_TYPE);
  } else {
    // found
    HttpHeaders headers;
    headers.setHeader("Content-type",mime);
    response->setResponseHeaders(headers);
    response->setResponseCode(ResponseCode::OK);
    if (0 == mime.compare(IDocumentContent::MIME_JSON)) {
      response->setResponseType(ResponseType::JSON);
    } else if (0 == mime.compare(IDocumentContent::MIME_XML) ) {
      response->setResponseType(ResponseType::XML);
    } else if (0 == mime.compare("text/plain")) {
      response->setResponseType(ResponseType::TEXT);
    } else {
      response->setResponseType(ResponseType::BINARY);
    }
  }

  LOG(DEBUG) << "  returning response ";
  return response;
}

Response* FakeConnection::deleteDocument(const std::string& uri) {
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

  response->setResponseCode(ResponseCode::NO_CONTENT); // 204 = DELETED too and NO_CONTENT

  return response;
}

Response* FakeConnection::search(const SearchDescription& desc) {
  TIMED_FUNC(FakeConnection_search);
  LOG(DEBUG) << "  Entering FakeConnection::search";

  Response* response = new Response;

  response->setResponseCode(ResponseCode::OK);
  HttpHeaders headers;
  headers.setHeader("Content-type",IDocumentContent::MIME_JSON);
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
  response->setContent(std::move(cos.str()));
  response->setResponseType(ResponseType::JSON);

  return response;
}


} // end namespace internals

} // end namespace mlclient
