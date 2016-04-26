
#ifndef __MLCLIENT_CONNECTION__
#define __MLCLIENT_CONNECTION__

#include "mlclient.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"

namespace mlclient {

class Connection {

public:
  /**
   * Creates a Connection instance. Defaults connection to admin/admin, localhost, nossl, port 8002, and the Documents database.
   */
  Connection();
  /**
   * Destroys a Connection instance.
   */
  ~Connection();

  /**
   * Configures this connection, providing connection override information - host, port, username, password and SSL usage
   */
  void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, const bool usessl);

  /**
   * Configures this connection, providing connection override information - host, port, username, password. Defaults to no SSL.
   */
  void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password);
  /**
   * Sets the name of the database to query/update. Defaults to Documents.
   */
  void setDatabaseName(const std::string& db);
  /**
   * Returns the database name we're querying/updating. Defaults to Documents.
   */
  std::string getDatabaseName();
  // TODO anonymous connection support
  // TODO Kerberos connection support
  // TODO test BASIC and DIGEST and BASIC+DIGEST authentication methods

  // BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
  /**
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   * Performs a HTTP GET Request.
   */
  std::unique_ptr<Response> doGet(const std::string& pathAndQuerystring);
  /**
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   * Performs a HTTP PUT Request.
   */
  std::unique_ptr<Response> doPut(const std::string& pathAndQuerystring,const DocumentContent& payload);
  /**
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   * Performs a HTTP POST Request.
   */
  std::unique_ptr<Response> doPost(const std::string& pathAndQuerystring,const DocumentContent& payload);

  // TODO multipart payload
  /**
   * Allows mlclient based applications to call any arbitrary REST endpoint on MarkLogic. Just in case we don't yet provide
   * a specific convenience method to invoke it.
   * Performs a HTTP DELETE Request.
   */
  std::unique_ptr<Response> doDelete(const std::string& path);


  // Wrapped and supported functions
  /**
   * Retrieves a document from the server, at the given document URI (MarkLogic unique document ID)
   */
  std::unique_ptr<Response> getDocument(const std::string& uri);
  /**
   * Saves a document to MarkLogic (either as new or an update), at the given document URI (MarkLogic unique document ID)
   */
  std::unique_ptr<Response> saveDocument(const std::string& uri,const DocumentContent& payload);
  // TODO save JSON with directory, no uri
  // TODO optional parameters (collection, security, etc.)
  // TODO save XML with and without URI

  // Multi part MIME saveAll function V7+
  //Response saveAllDocuments(const std::string& uris[], const web::json::value& documents[]);
  // TODO XML save all
  // TODO multiple responses when paging in N number of doc transactions

  // CLASHES WITH QTEXT VERSION Response search(const web::json::value& searchQuery,const std::string& options);
  // TODO search with options document (combined query)
  /**
   * Performs a search against the MarkLogic database given the provided search query, text and options
   */
  std::unique_ptr<Response> search(const SearchDescription& desc);
  //std::unique_ptr<Response> search(const web::json::value& searchQuery,const web::json::value& options);
  //std::unique_ptr<Response> search(const web::json::value& searchQuery,const std::string& qtext);
  //std::unique_ptr<Response> search(const web::json::value& searchQuery,const std::string& qtext,const web::json::value& options);
  //std::unique_ptr<Response> search(const SearchDescription& desc);
  // TODO search with XML instead of JSON



/*
  // database functions
  // LOW PRIORITY
  void exists();
  void create();
  void destroy();

  // document functions
  // HIGH PRIORITY
  void get(std::string& uri,json::value& options,std::function<void(const Response&)> callback);
  void save(json::value& content,std::string& uri,json::value& properties,std::function<void(const Response&)> callback);
  void delete(std::string& uri,std::function<void(const Response&)> callback);
  // LOW PRIORITY
  void metadata();
  void properties();
  void saveProperties();
  void merge();
  void replaceProperty();
  void saveAll();

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




private:
  class Impl; // forward declaration - PIMPL idiom
  Impl* mImpl;
};

}

#endif /* defined __MLCLIENT_CONNECTION__ */
