//
// Copyright (c) MarkLogic Corporation. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/// \file ConnectionWrapper.h
/// \brief A header file to provide a C wrapping of the Connection C++ class
/// \since 8.0.0
/// \author Adam Fowler <adam.fowler@marklogic.com>
/// \date 2016-04-18
///

#ifndef CONNECTIONWRAPPER_H
#define CONNECTIONWRAPPER_H

#include <mlclient/ResponseWrapper.h>
#include <mlclient/mlclient.hpp>

///
/// \typedef CConnection A wrapper for a C++ Connection instance's void* pointer.
///
/// \brief A type used to wrap the void* for the C++ Connection object.
///
/// Use this type in your C code instead of Connection.
///
typedef void CConnection;

#ifdef __cplusplus
extern "C" {
#endif

// constructor
///
/// \brief Creates a new blank CConnection instance.
///
/// \note Caller is responsible for the pointer. Use ml_connection_delete to safely clean it up.
///
/// \return A CConnection type instance pointer.
///
MLCLIENT_API CConnection * ml_connection_new();
// destructor
///
/// \brief Safely deletes a CConnection instance
///
/// \param t The CConnection pointer to delete.
///
MLCLIENT_API void ml_connection_delete(CConnection *t);

// member functions

///
/// \brief Configured the CConnection given the specified properties.
///
/// See Connection::configure for details.
///
/// \note Assumes digest authentication is being used.
///
/// \param conn The CConnection pointer to modify
/// \param hostname The MarkLogic Server hostname string
/// \param port The MarkLogic Server REST API port as a string
/// \param username The connection username (plain text) to use. E.g. admin or someuser
/// \param password The connection password (plain text) to use.
/// \param usessl Whether to use SSL or not. (I.e. https instead of http)
///
MLCLIENT_API void ml_connection_configure(const CConnection *conn,const char *hostname, const char *port, const char *username, const char *password, const int usessl);

// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
///
/// \brief Performs a generic GET request to a MarkLogic REST API (or extension) endpoint.
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_doGet(const CConnection *conn,const char *pathAndQuerystring);
///
/// \brief Performs a generic PUT request to a MarkLogic REST API (or extension) endpoint.
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_doPut(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
///
/// \brief Performs a generic POST request to a MarkLogic REST API (or extension) endpoint.
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_doPost(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
///
/// \brief Performs a generic DELETE request to a MarkLogic REST API (or extension) endpoint.
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_doDelete(const CConnection *conn,const char *path);


// Wrapped and supported functions
///
/// \brief Fetches a document by URI from MarkLogic server, on the specified connection instance
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_getDocument(const CConnection *conn,const char *uri);
///
/// \brief Saves a document by URI from MarkLogic server, on the specified connection instance
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_saveDocument(const CConnection *conn,const char *uri,const char *payload);

///
/// \brief Deletes a document by URI from MarkLogic server, on the specified connection instance
/// \since 8.0.2
/// \date 2016-05-23
///
MLCLIENT_API CResponse * ml_connection_deleteDocument(const CConnection *conn,const char *uri);

///
/// \brief Performs a search on MarkLogic server, using the specified connection instance
/// \since 8.0.0
/// \date 2016-04-18
///
MLCLIENT_API CResponse * ml_connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,const char *options);



#ifdef __cplusplus
}
#endif





#endif
