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
/**
 * \file Connection.hpp
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2015-11-29
 *
 * \brief Provides the definition of the Connection class. No enums or constants are defined
 *
 */
#ifndef __MLCLIENT_CONNECTION__
#define __MLCLIENT_CONNECTION__

#include "mlclient/mlclient.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/SearchDescription.hpp"
#include <mlclient/Document.hpp>

/**
 * \brief the namespace which wraps all Core Public C++ API classes.
 */
namespace mlclient {
/**
 * \author Adam Fowler <adam.fower@marklogic.com>
 * \since 8.0.0
 * \date 2016-05-15
 *
 * \brief Provides a virtual only interface for a connection. Allows the creation of a FakeConnection subclass, or a real Connection subclass.
 */
class IConnection {
public:

  /**
   * \brief Creates a Connection instance.
   *
   * Defaults connection to admin/admin, localhost, nossl, port 8002, and the Documents database.
   *
   * \since 8.0.0
   */
  MLCLIENT_API IConnection() = default;

  /**
   * Destroys a Connection instance.
   */
  virtual ~IConnection() = default;

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
  MLCLIENT_API virtual void configure(const std::string& hostname, const std::string& port, const std::string& username,
      const std::string& password, const bool usessl = false) = 0;

  /**
   * \brief Connects or tests the authentication in the connection. May not actually connect.
   * \note Should be called prior to any use of functions. Is not called for the developer
   */
  MLCLIENT_API virtual bool connect() = 0;

  /**
   * \brief Frees up resources held by the connection, until the next call to connect.
   * \note Should be called by a class' destructor
   */
  MLCLIENT_API virtual void disconnect() = 0;

  /**
   * \brief Sets the name of the database to query/update. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \param[in] The string name (not internal MarkLogic numeric ID) of the database to query.
   */
  MLCLIENT_API virtual void setDatabaseName(const std::string& db) = 0;

  /**
   * \brief Returns the database name we're querying/updating. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \return A string representation of the database name (not internal MarkLogic database numeric ID)
   */
  MLCLIENT_API virtual std::string getDatabaseName() = 0;

  // @}

  // TODO anonymous connection support
  // TODO Kerberos connection support
  // TODO test BASIC and DIGEST and BASIC+DIGEST authentication methods

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
  MLCLIENT_API virtual Response* doGet(const std::string& pathAndQuerystring) = 0;

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
  MLCLIENT_API virtual Response* doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) = 0;

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
  MLCLIENT_API virtual Response* doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) = 0;

  /// TODO multipart payload
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
  MLCLIENT_API virtual Response* doDelete(const std::string& pathAndQueryString) = 0;

  /// TODO PATCH and other HTTP synonyms

  // @}


  /// \name wrap_rest Convenience wrapper function calls for common MarkLogic REST API calls.
  // @{

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
  MLCLIENT_API virtual Response* getDocument(const std::string& uri) = 0; /// TODO add optional call parameters (E.g. fetch properties also)

  /**
   *
   * \brief Retrieves a document from the server, at the given document URI (MarkLogic unique document ID, within the Document object)
   *
   * \note This method differs from getDocument(const std::string& uri) in that it populates the document specified, rather than returning
   * a document from the method (or within the response). This method fetches ALL of document content AND properties AND collections AND permissions
   *
   * Performs a GET /v1/documents?uri HTTP call, fetching all document information.
   *
   * \param[inout] inout_document The document to fetch from MarkLogic Server. MUST have a URI.
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* getDocument(Document& inout_document) = 0;

  /**
   * \brief Populates the content of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentContent(Document& inout_document) = 0;

  /**
   * \brief Populates the properties of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentProperties(Document& inout_document) = 0;

  /**
   * \brief Populates the permissions of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentPermissions(Document& inout_document) = 0;

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
  MLCLIENT_API virtual Response* saveDocument(const std::string& uri,const IDocumentContent& payload) = 0;

  /**
   * \brief Saves a document to MarkLogic (either as new or an update), at the given document URI (MarkLogic unique document ID)
   *
   * Performs a call to PUT /v1/documents?ext in order to save a Document to MarkLogic Server
   *
   * \param[in] Document The \link Document \endlink to send to MarkLogic Server. Must have a URI and Content DocumentContent instance.
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* saveDocument(const Document& doc) = 0;

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
  MLCLIENT_API virtual Response* deleteDocument(const std::string& uri) = 0;

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
  MLCLIENT_API virtual Response* search(const SearchDescription& desc) = 0;

  /**
   * \brief Performs a search against a REST extension that is compatible with POST /v1/search (i.e. Connection::search)
   *
   * \note Useful when your extension places extra criteria on the search that the REST API does not support.
   *
   * \note This could be used to effectively create 'stored procedures' that took a search to restrict the documents
   * the work occurs over, returning a result set just like Connection::search (i.e. POST /v1/search)
   *
   * See also \link Connection::valuesExtension \endlink for similar functionality for aggregate/values extensions
   *
   * \param[in] extensionName The REST API extension name (file name without .xqy or .sjs) to invoke
   * \param[in] desc The SearchDescription defining the search, options, and query string
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* searchExtension(const std::string& extensionName,const SearchDescription& desc) = 0;

  /**
   * \brief Saves search options to the server.
   *
   * \param[in] optionsName The name of the options on the server
   * \param[in] optionsDoc The document containing the options
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* saveSearchOptions(const std::string& optionsName,const IDocumentContent* optionsDoc) = 0;

  /**
   * \brief Performs a values lookup in MarkLogic Server, returning the top values from the lexicon as per the search options configuration used.
   *
   * \note What is returned from the call is entirely dependent upon the search options configuration used.
   *
   * \note Invokes GET /v1/values/VALUESNAME?options=OPTIONSNAME
   *
   * \param[in] valuesName The name of the values Configuration within the search options to use
   * \param[in] optionsName The name of the installed search options to specify (no default)
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* values(const std::string& valuesName,const std::string& optionsName) = 0;


  /**
   * \brief Performs a values against a REST extension that is compatible with POST /v1/search (i.e. Connection::search)
   *
   * \note Useful when your extension places extra criteria on the search that the REST API does not support.
   *
   * \note This could be used to effectively create 'stored procedures' that took a search to restrict the documents
   * the work occurs over, returning a result set just like Connection::search (i.e. POST /v1/search)
   *
   * See also \link Connection::searchExtension \endlink for similar functionality for aggregate/values extensions
   *
   * Invokes POST /v1/values/VALUESNAME?options=OPTIONSNAME and not GET
   *
   * \note Because the values endpoint takes a name in the URL and REST extensions do not support this, the valuesName
   * variable is passed to the 'values' parameter on the querystring of the request.
   *
   * \param[in] extensionName The REST API extension name (file name without .xqy or .sjs) to invoke
   * \param[in] valuesName The name of the values Configuration within the search options to use
   * \param[in] optionsName The name of the installed search options to specify (no default)
   * \param[in] desc The SearchDescription defining the search, options, and query string
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* valuesExtension(const std::string& extensionName,const std::string& valuesName,
      const std::string& optionsName,const SearchDescription& desc) = 0;

  /**
   * \brief Lists the top level collections. I.e. ones starting without a / or ones starting with a / but not containing a / character
   * \note Requires the Collection Lexicon to be enabled on the MarkLogic Database
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* listRootCollections() = 0;

  /**
   * \brief Lists the immediate child collections of the specified parent Collections.
   * \note Parent collection must start with a /
   * \note Requires the Collection Lexicon to be enabled on the MarkLogic Database
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* listCollections(const std::string& parentCollection) = 0;


  /*

  // search functions
  // HIGH PRIORITY
  void search(json::value& query,json::value& options,int start,json::value& searchproperties,std::function<void(const Response&)> callback);
  void structuredSearch(json::value& query,json::value& options,json::value& searchproperties,std::function<void(const Response&)> callback);
  void combined(json::value& structuredQuery,std::string& textQuery,json::value& options,json::value& searchproperties,std::function<void(const Response&)> callback);
  void saveSearchOptions(std::string& name,json::value& options,std::function<void(const Response&)> callback);
  void searchOptions(std::string& name,std::function<void(const Response&)> callback); // gets them
  // MEDIUM PRIORITY
  void values();
  void valuesCombined();
  void saveSearchOptionsCheck();
  // LOW PRIORITY
  void collect();
  void list();
  void keyvalue();
  void searchCollection();
  void suggest();

  // lexicon functions
  // LOW
  void collections();

  // semantic functions
  // LOW
  void saveGraph();
  void mergeGraph();
  void graph();
  void deleteGraph();
  void sparql();

  // configuration functions
  // MEDIUM
  void saveTransform();
  void deleteTransform();
  void getTransform();
  // LOW
  void listTransforms();
  void indexes();

  // transactions
  // MEDIUM
  void begin();
  void commit();
  void rollback();

  // rest extensions from MLJS
  // HIGH
  void version();
  int getVersion(); // returns cached/default version value - no rest request
  // LOW
  void whoami();
  */



};















/**
 * \class Connection
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2015-11-29
 *
 * \brief Provides a high level logical object representing all access to a single MarkLogic database
 *
 * Wraps all underlying TCP, HTTP and authentication provided by the internal API. Provides convenience
 * methods that map 1:1 with MarkLogic Server's REST API.
 */
class Connection : public IConnection {

public:
  /**
   * \brief Creates a Connection instance.
   *
   * Defaults connection to admin/admin, localhost, nossl, port 8002, and the Documents database.
   *
   * \since 8.0.0
   */
  MLCLIENT_API Connection();

  /**
   * Destroys a Connection instance.
   */
  MLCLIENT_API ~Connection();

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
  MLCLIENT_API void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password,
      const bool usessl = false) override;

  /**
   * \brief Connects or tests the authentication in the connection. May not actually connect.
   * \note Should be called prior to any use of functions. Is not called for the developer
   */
  MLCLIENT_API bool connect() override;

  /**
   * \brief Frees up resources held by the connection, until the next call to connect.
   * \note Should be called by a class' destructor
   */
  MLCLIENT_API void disconnect() override;

  /**
   * \brief Sets the name of the database to query/update. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \param[in] The string name (not internal MarkLogic numeric ID) of the database to query.
   */
  MLCLIENT_API void setDatabaseName(const std::string& db) override;

  /**
   * \brief Returns the database name we're querying/updating. Defaults to Documents.
   *
   * \since 8.0.0
   *
   * \return A string representation of the database name (not internal MarkLogic database numeric ID)
   */
  MLCLIENT_API std::string getDatabaseName() override;

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
  MLCLIENT_API Response* doGet(const std::string& pathAndQuerystring) override;

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
  MLCLIENT_API Response* doPut(const std::string& pathAndQuerystring,const IDocumentContent& payload) override;

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
  MLCLIENT_API Response* doPost(const std::string& pathAndQuerystring,const IDocumentContent& payload) override;

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
  MLCLIENT_API Response* doDelete(const std::string& pathAndQueryString) override;

  // @}

  /// \name wrap_rest Convenience wrapper function calls for common MarkLogic REST API calls.
  // @{

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
  MLCLIENT_API Response* getDocument(const std::string& uri) override;

  /**
   *
   * \brief Retrieves a document from the server, at the given document URI (MarkLogic unique document ID, within the Document object)
   *
   * \note This method differs from getDocument(const std::string& uri) in that it populates the document specified, rather than returning
   * a document from the method (or within the response). This method fetches ALL of document content AND properties AND collections AND permissions
   *
   * Performs a GET /v1/documents?uri HTTP call, fetching all document information.
   *
   * \param[inout] inout_document The document to fetch from MarkLogic Server. MUST have a URI.
   * \return A unique_ptr for the \link Response \endlink object. The caller is repsonsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.2
   */
  MLCLIENT_API virtual Response* getDocument(Document& inout_document) override;

  /**
   * \brief Populates the content of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentContent(Document& inout_document) override;

  /**
   * \brief Populates the properties of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentProperties(Document& inout_document) override;

  /**
   * \brief Populates the permissions of the specified document (MUST have a uri).
   *
   * See getDocument(Document&) for details.
   */
  MLCLIENT_API virtual Response* getDocumentPermissions(Document& inout_document) override;

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
  MLCLIENT_API Response* saveDocument(const std::string& uri,const IDocumentContent& payload) override;

  MLCLIENT_API Response* saveDocument(const Document& doc) override;

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
  MLCLIENT_API Response* deleteDocument(const std::string& uri) override;

  /**
   * \brief Performs a search against the MarkLogic database given the provided search query, text and options
   *
   * Uses a \link SearchDescription \endlink value object to wrap complex search parameters for MarkLogic Server.
   *
   * Performs a POST /v1/search HTTP POST to MarkLogic Server
   *
   * \param[in] desc The SearchDescription defining the search, options, and query string
   * \return A unique_ptr for the \link Response \endlink object. The caller is responsible for deleting the pointer.
   *
   * \exception NoCredentialsException The credentials for the Connection were not accepted by MarkLogic Server,
   * or permission is denied for this request.
   *
   * \since 8.0.0
   */
  MLCLIENT_API Response* search(const SearchDescription& desc) override;

  /**
   * \brief Performs a search against a REST extension that is compatible with POST /v1/search (i.e. Connection::search)
   *
   * \note Useful when your extension places extra criteria on the search that the REST API does not support.
   *
   * \note This could be used to effectively create 'stored procedures' that took a search to restrict the documents
   * the work occurs over, returning a result set just like Connection::search (i.e. POST /v1/search)
   *
   * See also \link Connection::valuesExtension \endlink for similar functionality for aggregate/values extensions
   *
   * \param[in] extensionName The REST API extension name (file name without .xqy or .sjs) to invoke
   * \param[in] desc The SearchDescription defining the search, options, and query string
   *
   * \since 8.0.2
   */
  MLCLIENT_API Response* searchExtension(const std::string& extensionName,const SearchDescription& desc) override;

  /**
   * \brief Saves search options to the server.
   *
   * \param[in] name The name of the options on the server
   * \param[in] optionsDoc The document containing the options
   *
   * \since 8.0.2
   */
  MLCLIENT_API Response* saveSearchOptions(const std::string& name,const IDocumentContent* optionsDoc) override;

  /**
   * \brief Performs a values lookup in MarkLogic Server, returning the top values from the lexicon as per the search options configuration used.
   *
   * \note What is returned from the call is entirely dependent upon the search options configuration used.
   *
   * \param[in] valuesName The name of the values Configuration within the search options to use
   * \param[in] optionsName The name of the installed search options to specify (no default)
   */
  MLCLIENT_API Response* values(const std::string& valuesName,const std::string& optionsName) override;

  /**
   * \brief Performs a values against a REST extension that is compatible with POST /v1/search (i.e. Connection::search)
   *
   * \note Useful when your extension places extra criteria on the search that the REST API does not support.
   *
   * \note This could be used to effectively create 'stored procedures' that took a search to restrict the documents
   * the work occurs over, returning a result set just like Connection::search (i.e. POST /v1/search)
   *
   * See also \link Connection::searchExtension \endlink for similar functionality for aggregate/values extensions
   *
   * \note Because the values endpoint takes a name in the URL and REST extensions do not support this, the valuesName
   * variable is passed to the 'values' parameter on the querystring of the request.
   *
   * Invokes POST /v1/values/VALUESNAME?options=OPTIONSNAME and not GET
   *
   * \param[in] extensionName The REST API extension name (file name without .xqy or .sjs) to invoke
   * \param[in] valuesName The name of the values Configuration within the search options to use
   * \param[in] optionsName The name of the installed search options to specify (no default)
   * \param[in] desc The SearchDescription defining the search, options, and query string
   *
   * \since 8.0.2
   */
  MLCLIENT_API Response* valuesExtension(const std::string& extensionName,const std::string& valuesName,
      const std::string& optionsName,const SearchDescription& desc) override;

  /**
   * \brief Lists the top level collections. I.e. ones starting without a / or ones starting with a / but not containing a / character
   * \note Requires the Collection Lexicon to be enabled on the MarkLogic Database
   */
  MLCLIENT_API Response* listRootCollections() override;

  /**
   * \brief Lists the immediate child collections of the specified parent Collections.
   * \note Parent collection must start with a /
   * \note Requires the Collection Lexicon to be enabled on the MarkLogic Database
   */
  MLCLIENT_API Response* listCollections(const std::string& parentCollection) override;


  // @}

private:
  class Impl; // forward declaration - PIMPL idiom
  Impl* mImpl;
};

}

#endif /* defined __MLCLIENT_CONNECTION__ */
