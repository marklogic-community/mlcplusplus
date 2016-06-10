/**
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
 * \file SearchBuilder.cpp
 * \since 8.0.2
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Provides convenience functions to parse MarkLogic response objects
 * \date 2016-06-09
 */

#include <cpprest/http_client.h>
#include "SearchBuilder.hpp"
#include "CppRestJsonHelper.hpp"
#include "CppRestJsonDocumentContent.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace mlclient {

namespace utilities {

// IQuery global operators

std::ostream& operator<<(std::ostream& os,const IQuery& query) {
  return query.write(os);
}

std::string& operator +(std::string& s, const IQuery& query) {
  std::ostringstream oss;
  oss << query;
  s.append(oss.str());
  return s;
}





GenericQuery::GenericQuery() : value() {
}

std::ostream& GenericQuery::write(std::ostream& os) const {
  os << value;
  return os;
}

/*
std::ostream& operator<<(std::ostream& str,GenericQuery& query) {
  str << query.getQuery();
  return str;
}

std::string& operator +(std::string& s, const GenericQuery& query) {
  std::ostringstream oss;
  oss << query.getQuery();
  s.append(oss.str());
  return s;
}
*/

void GenericQuery::setQuery(const web::json::value& value) {
  this->value = value;
}

const web::json::value& GenericQuery::getQuery() const {
  return value;
}





JsonPropertyQuery::JsonPropertyQuery() : value() {
}

std::ostream& JsonPropertyQuery::write(std::ostream& os) const {
  os << value;
  return os;
}
/*
std::ostream& operator<<(std::ostream& str,JsonPropertyQuery& query) {
  str << query.getQuery();
  return str;
}

std::string& operator +(std::string& s, const JsonPropertyQuery& query) {
  std::ostringstream oss;
  oss << query.getQuery();
  s.append(oss.str());
  return s;
}*/

void JsonPropertyQuery::setQuery(const std::string& property,const web::json::value& value) {
  std::ostringstream str;
  str << "{\"container-query\": {\"property\": \"" << property << "\", \"value\": " << value << "}}"; // TODO validate value returns quotes around string and not around numbers, etc.
  GenericQuery query;
  query.setQuery(web::json::value(str.str()));
}

const web::json::value& JsonPropertyQuery::getQuery() const {
  return value;
}




// Container references


std::ostream& operator<<(std::ostream& os,const IContainerRef& ref) {
  return ref.write(os);
}

std::string& operator +(std::string& s, const IContainerRef& ref) {
  std::ostringstream oss;
  oss << ref;
  s.append(oss.str());
  return s;
}




JsonPropertyRef::JsonPropertyRef() : value() {
}

std::ostream& JsonPropertyRef::write(std::ostream& os) const {
  os << value;
  return os;
}
/*
std::ostream& operator<<(std::ostream& str,JsonPropertyRef& ref) {
  str << ref.getRef();
  return str;
}

std::string& operator +(std::string& s, const JsonPropertyRef& rt) {
  std::ostringstream oss;
  oss << rt;
  s.append(oss.str());
  return s;
}*/

void JsonPropertyRef::setProperty(const std::string& property) {
  // TODO set the property json
}






class SearchBuilder::Impl {
public:
  static IQuery* multiQuery(const std::vector<IQuery>& queries,const std::string& queryType) {
    GenericQuery* query = new GenericQuery;
    std::ostringstream oss;
    oss << "{\"" << queryType << "-query\": [";
    for (auto& iter: queries) {
      oss << iter; // TODO ensure comma between queries, and no trailing comma
    }
    oss << "]}";
    query->setQuery(web::json::value(oss.str()));
    return query;
  };

  static std::ostringstream& multiStringProperty(const std::vector<std::string> strings,const std::string& property,std::ostringstream& oss) {
    oss << "\"" << property << "\": [";
    for (auto& iter: strings) {
      oss << iter; // TODO ensure comma between queries, and no trailing comma
    }
    oss << "]";
    return oss;
  }

  IQuery* rootQuery;
}; // end Impl class





SearchBuilder::SearchBuilder(): mImpl(new SearchBuilder::Impl) {
  ;
}





IQuery* SearchBuilder::collectionQuery(const std::vector<std::string>& collections) {
  std::ostringstream oss;
  oss << "{\"collection-query\": {";
  Impl::multiStringProperty(collections,"collection",oss);
  oss << "}}";
  GenericQuery* query = new GenericQuery;
  query->setQuery(web::json::value(oss.str()));
  return query;
}



IQuery* SearchBuilder::documentQuery(const std::vector<std::string>& uris) {
  std::ostringstream oss;
  oss << "{\"document-query\": {";
  Impl::multiStringProperty(uris,"uri",oss);
  oss << "}}";
  GenericQuery* query = new GenericQuery;
  query->setQuery(web::json::value(oss.str()));
  return query;
}





// public class methods that control the create of a search or query
IQuery* SearchBuilder::andQuery(const std::vector<IQuery>& queries) {
  return Impl::multiQuery(queries,"and");
}

IQuery* SearchBuilder::orQuery(const std::vector<IQuery>& queries) {
  return Impl::multiQuery(queries,"or");
}

IQuery* SearchBuilder::notQuery(const std::vector<IQuery>& queries) {
  return Impl::multiQuery(queries,"not");
}


SearchBuilder* SearchBuilder::setQuery(IQuery* query) {
  mImpl->rootQuery = query;
  return this;
}

ITextDocumentContent& SearchBuilder::toDocument() {
  std::ostringstream oss;
  oss << mImpl->rootQuery;
  return *CppRestJsonHelper::toDocument(web::json::value(oss.str()));
}


} // end namespace utilities

} // end namespace mlclient
