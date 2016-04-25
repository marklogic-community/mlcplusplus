
#ifndef __MLCLIENT_CONNECTION__
#define __MLCLIENT_CONNECTION__

#include "mlclient.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"

namespace mlclient {

class Connection {

public:
  Connection();
  ~Connection();

  void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password, const bool usessl);
  void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password);
  // TODO anonymous connection support
  // TODO Kerberos connection support
  // TODO test BASIC and DIGEST and BASIC+DIGEST authentication methods

  // BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
  std::unique_ptr<Response> doGet(const std::string& pathAndQuerystring);
  std::unique_ptr<Response> doPut(const std::string& pathAndQuerystring,const DocumentContent& payload);
  std::unique_ptr<Response> doPost(const std::string& pathAndQuerystring,const DocumentContent& payload);
  // TODO XML payload
  // TODO multipart payload
  std::unique_ptr<Response> doDelete(const std::string& path);


  // Wrapped and supported functions
  std::unique_ptr<Response> getDocument(const std::string& uri);
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
