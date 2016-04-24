//
//  AsyncWrapper.hpp
//
//  Created by Adam Fowler on 24/Jul/14
//  Copyright (c) 2014 Adam Fowler. All rights reserved.
//

#include <mlclient.hpp>
#include <functional>
#include <cstdint>

#include "AuthenticatingProxy.hpp"
#include "Response.hpp"
#include "ResponseCodes.hpp"


namespace mlclient {

namespace internals {

class AsyncWrapper {
  AuthenticatingProxy _proxy;

public:
  AsyncWrapper(AuthenticatingProxy& p);

  // generic functions
  do(json::value& options,json::value& content,std::function<void(const Response&)> callback);

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

private:
  // HIGH
  void applyTransformProperties();
  void applySearchProperties();

};

}

}
