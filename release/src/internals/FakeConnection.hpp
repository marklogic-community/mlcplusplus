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
 * FakeConnection.hpp
 *
 *  Created on: 15 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_INTERNALS_FAKECONNECTION_HPP_
#define SRC_INTERNALS_FAKECONNECTION_HPP_

#include "../Connection.hpp"
#include "../Response.hpp"
#include "../DocumentContent.hpp"
#include "../SearchDescription.hpp"

namespace mlclient {

namespace internals {

/**
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-05-15
 *
 * \brief Implements the Fake idiom. Provides a Fake connection to MarkLogic for testing.
 *
 * This class operates on documents as if it were MarkLogic Server, storing them in memory.
 * Search methods return the first n records as requested in the SearchDescription (default: first 10).
 */
class FakeConnection : public IConnection {

public:
  /**
   * \brief Creates a Connection instance.
   *
   * Defaults connection to admin/admin, localhost, nossl, port 8002, and the Documents database.
   *
   * \since 8.0.0
   */
  FakeConnection();
  /**
   * Destroys a Connection instance.
   */
  ~FakeConnection();

  /// \name connection_configuration Connection configuration functions
  // @{

  /**
   * Configures this connection, providing connection override information - host, port, username, password and SSL usage
   *
   * \since 8.0.0
   *
   * \param[in] hostname The hostname or IP address of the MarkLogic Server (or load balancer) to connect to
   * \param[in] port A String representing the (numerical) port number of the MarkLogic Server (or load balancer) to connect to
   * \param[in] username The username of the used to connect to MarkLogic Server as
   * \param[in] password The plain text password used to authenticate the user to MarkLogic server with
   * \param[in] usessl A bool representation whether to use SSL (i.e. a HTTPS url) or not
   */
  void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password,
      const bool usessl = false) override;

  /**
   * \brief Sets the name of the database to query/update. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \param[in] The string name (not internal MarkLogic numeric ID) of the database to query.
   */
  void setDatabaseName(const std::string& db) override;

  /**
   * \brief Returns the database name we're querying/updating. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \return A string representation of the database name (not internal MarkLogic database numeric ID)
   */
  std::string getDatabaseName() override;


  /**
   * \brief Connects or tests the authentication in the connection. May not actually connect.
   * \note Should be called prior to any use of functions. Is not called for the developer
   */
  bool connect() override;

  /**
   * \brief Frees up resources held by the connection, until the next call to connect.
   * \note Should be called by a class' destructor
   */
  void disconnect() override;


  // @}

  /// \name http_raw RAW HTTP commands
  // @{

  /**
   * \brief Performs a HTTP GET Request against MarkLogic Server.
   *
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   *
   * Performs a RESTful HTTP GET request to an arbitrary URL on MarkLogic Server
   *
   * \since 8.0.0
   *
   * \param[in] pathAndQueryString the path and query string for the entire get request. E.g. /v1/search?options=myoptions
   * \return A unique_ptr for a \link Response \endlink instance. The caller is responsible for destroying the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \note This function is not limited to the REST API, and can be used for the management REST API or any arbitrary MarkLogic
   * web application URL.
   */
  Response* doGet(const std::string& pathAndQuerystring) override;

  /**
   * \brief Performs a HTTP PUT Request against MarkLogic Server.
   *
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   *
   * Performs a RESTful HTTP PUT request to an arbitrary URL on MarkLogic Server
   *
   * \since 8.0.0
   *
   * \param[in] pathAndQueryString the path and query string for the entire put request. E.g. /v1/search?options=myoptions
   * \param[in] payload The \link DocumentContent \endlink to send to MarkLogic Server
   * \return A unique_ptr for a \link Response \endlink instance. The caller is responsible for destroying the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \note This function is not limited to the REST API, and can be used for the management REST API or any arbitrary MarkLogic
   * web application URL.
   */
  Response* doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) override;

  /**
   * \brief Performs a HTTP POST Request against MarkLogic Server.
   *
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   *
   * Performs a RESTful HTTP POST request to an arbitrary URL on MarkLogic Server
   *
   * \since 8.0.0
   *
   * \param[in] pathAndQueryString the path and query string for the entire post request. E.g. /v1/search?options=myoptions
   * \param[in] payload The \link DocumentContent \endlink to send to MarkLogic Server
   * \return A unique_ptr for a \link Response \endlink instance. The caller is responsible for destroying the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \note This function is not limited to the REST API, and can be used for the management REST API or any arbitrary MarkLogic
   * web application URL.
   */
  Response* doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) override;

  /**
   * \brief Performs a HTTP DELETE Request against MarkLogic Server.
   *
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   *
   * Performs a HTTP DELETE REST request to an arbitrary URL on MarkLogic Server
   *
   * \since 8.0.0
   *
   * \param[in] pathAndQueryString the path and query string for the entire delete request. E.g. /v1/documents?uri=/my/doc.json
   * \return A unique_ptr for a \link Response \endlink instance. The caller is responsible for destroying the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \note This function is not limited to the REST API, and can be used for the management REST API or any arbitrary MarkLogic
   * web application URL.
   */
  Response* doDelete(const std::string& pathAndQueryString) override;

  // @}


  /// \name wrap_rest Convenience wrapper function calls for common MarkLogic REST API calls.
  // @{

  // Wrapped and supported functions
  /**
   * \brief Retrieves a document from the server, at the given document URI (MarkLogic unique document ID)
   *
   * Performs a GET /v1/documents?uri HTTP call
   *
   * \param[in] uri The URI of the document to fetch from MarkLogic Server
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.0
   */
  Response* getDocument(const std::string& uri) override; // TODO add optional call parameters (E.g. fetch properties also)

  /**
   * \brief Saves a document to MarkLogic (either as new or an update), at the given document URI (MarkLogic unique document ID)
   *
   * Performs a call to PUT /v1/documents?ext in order to save a Document to MarkLogic Server
   *
   * \param[in] uri The URI of the document to save to MarkLogic Server
   * \param[in] payload The \link DocumentContent \endlink to send to MarkLogic Server
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.0
   */
  Response* saveDocument(const std::string& uri,const IDocumentContent& payload) override;

  /**
   * \brief Deletes the specified document by URI
   *
   * \param[in] uri The document URI to delete
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.0
   */
  Response* deleteDocument(const std::string& uri) override;

  /**
   * \brief Performs a search against the MarkLogic database given the provided search query, text and options
   *
   * Uses a \link SearchDescription \endlink value object to wrap complex search parameters for MarkLogic Server.
   *
   * Performs a POST /v1/search HTTP POST to MarkLogic Server
   *
   * \param[in] desc The SearchDescription defining the search, options, and query string
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.0
   */
  Response* search(const SearchDescription& desc) override;

private:
  class Impl; // forward declaration - PIMPL idiom
  Impl * mImpl;
};

} // end namespace internals

} // end namespace mlclient

#endif /* SRC_INTERNALS_FAKECONNECTION_HPP_ */
