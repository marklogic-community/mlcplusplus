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
#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "mlclient/logging.hpp"

namespace mlclient {

namespace utilities {

// RANGE OPERATION FUNCTIONS
std::ostream& operator << (std::ostream& os, const RangeOperation& rt) {
  os << translate(rt);
  return os;
}

std::string& operator +(std::string& s, const RangeOperation& rt) {
  s.append(translate(rt));
  return s;
}

const std::string translate(const RangeOperation& rt) {
  std::string result;
  switch(rt) {
  case RangeOperation::LE:
    result = "LE";
    break;
  case RangeOperation::LT:
    result = "LT";
    break;
  case RangeOperation::GE:
    result = "GE";
    break;
  case RangeOperation::GT:
    result = "GT";
    break;
  case RangeOperation::EQ:
    result = "EQ";
    break;
  case RangeOperation::NE:
    result = "NE";
    break;
  case RangeOperation::UNKNOWN_TYPE:
    result = "RangeOperation::UNKNOWN_TYPE";
    break;
  }
  return result;
}

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
  TIMED_FUNC(GenericQuery_defaultConstructor);
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

void GenericQuery::setQuery(const std::string& value) {
  TIMED_FUNC(GenericQuery_setQuery);
  this->value = value;
}

const std::string& GenericQuery::getQuery() const {
  return value;
}





JsonPropertyQuery::JsonPropertyQuery() : m_value() {
  TIMED_FUNC(JsonPropertyQuery_defaultConstructor);
}

std::ostream& JsonPropertyQuery::write(std::ostream& os) const {
  os << m_value;
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

void JsonPropertyQuery::setQuery(const std::string& property,const std::string& value) {
  TIMED_FUNC(JsonPropertyQuery_setQuery);
  std::ostringstream oss;
  oss << "{\"container-query\": {\"property\": \"" << property << "\", \"value\": " << value << "}}"; // TODO validate value returns quotes around string and not around numbers, etc.
  //GenericQuery query;
  //query.setQuery(oss.str());
  m_value = oss.str();
}

const std::string& JsonPropertyQuery::getQuery() const {
  return m_value;
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
  TIMED_FUNC(JsonPropertyRef_defaultConstructor);
}

std::ostream& JsonPropertyRef::write(std::ostream& os) const {
  os << "\"json-property\":\"" << value << "\"";
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
  value = property;
}






class SearchBuilder::Impl {
public:
  Impl() : rootQuery(nullptr), mode(QueryBuilderMode::ALL), defaultXmlNamespace("") {
    TIMED_FUNC(SearchBuilder_Impl_defaultConstructor);
  }

  static IQuery* multiQuery(const std::vector<IQuery*>& queries,const std::string& queryType) {
    TIMED_FUNC(SearchBuilder_Impl_multiQuery);
    GenericQuery* query = new GenericQuery;
    std::ostringstream oss;
    oss << "{\"" << queryType << "-query\": [";
    bool first = true;
    for (auto& iter: queries) {
      if (first) {
        first = false;
      } else {
        oss << ",";
      }

      oss << (*iter);
    }
    oss << "]}";
    query->setQuery(oss.str());
    return query;
  };

  static std::ostringstream& multiStringProperty(const std::vector<std::string> strings,const std::string& property,std::ostringstream& oss) {
    TIMED_FUNC(SearchBuilder_Impl_multiStringProperty);
    oss << "\"" << property << "\": [";
    int count = 0;
    int size = strings.size();
    for (std::vector<std::string>::const_iterator str = strings.begin();str != strings.end();str++) {
      oss << "\"" << *str << "\""; // ensure comma between queries, and no trailing comma
      if (count < size - 1) {
        oss << ",";
      }
      count++;
    }
    oss << "]";
    return oss;
  }

  IQuery* rootQuery;
  QueryBuilderMode mode;
  std::string defaultXmlNamespace;
}; // end Impl class





SearchBuilder::SearchBuilder(): mImpl(new SearchBuilder::Impl) {
  TIMED_FUNC(SearchBuilder_defaultConstructor);
}


void SearchBuilder::setDefaultXmlNamespace(const std::string& ns) {
  mImpl->defaultXmlNamespace = ns;
}
const std::string& SearchBuilder::getDefaultXmlNamespace() const {
  return mImpl->defaultXmlNamespace;
}
void SearchBuilder::setMode(const QueryBuilderMode mode) {
  mImpl->mode = mode;
}
const QueryBuilderMode SearchBuilder::getMode() const {
  return mImpl->mode;
}



IQuery* SearchBuilder::collectionQuery(const std::vector<std::string>& collections) {
  TIMED_FUNC(SearchBuilder_collectionQuery);
  std::ostringstream oss;
  oss << "{\"collection-query\": {";
  Impl::multiStringProperty(collections,"uri",oss);
  oss << "}}";
  LOG(DEBUG) << "SearchBuilder::collectionQuery: raw text: " << oss.str();
  GenericQuery* query = new GenericQuery;
  query->setQuery(oss.str());
  return query;
}



IQuery* SearchBuilder::documentQuery(const std::vector<std::string>& uris) {
  TIMED_FUNC(SearchBuilder_documentQuery);
  std::ostringstream oss;
  oss << "{\"document-query\": {";
  Impl::multiStringProperty(uris,"uri",oss);
  oss << "}}";
  GenericQuery* query = new GenericQuery;
  query->setQuery(oss.str());
  return query;
}





// public class methods that control the create of a search or query
IQuery* SearchBuilder::andQuery(const std::vector<IQuery*>& queries) {
  TIMED_FUNC(SearchBuilder_andQuery);
  return Impl::multiQuery(queries,"and");
}

IQuery* SearchBuilder::orQuery(const std::vector<IQuery*>& queries) {
  TIMED_FUNC(SearchBuilder_orQuery);
  return Impl::multiQuery(queries,"or");
}

IQuery* SearchBuilder::notQuery(const IQuery* query) {
  TIMED_FUNC(SearchBuilder_notQuery);
  std::ostringstream oss;
  oss << "{\"not-query\": {";
  oss << *query;
  oss << "}}";
  GenericQuery* qry = new GenericQuery;
  qry->setQuery(oss.str());
  return qry;
}

IQuery* SearchBuilder::valueQuery(const std::string ref, const std::string value) {
  if (QueryBuilderMode::ALL == mImpl->mode) {
    return SearchBuilder::orQuery(std::vector<IQuery*>{SearchBuilder::jsonValueQuery(ref,value),SearchBuilder::xmlValueQuery(ref,value)});
  } else if (QueryBuilderMode::XML == mImpl->mode) {
    return SearchBuilder::xmlValueQuery(ref,value);
  } else {
    return SearchBuilder::jsonValueQuery(ref,value);
  }
}


IQuery* SearchBuilder::jsonValueQuery(const std::string ref, const std::string value) {
  TIMED_FUNC(SearchBuilder_valueQuery);
  std::ostringstream oss;
  oss << "{\"value-query\":{";
  // TODO WARNING BUG FOR JSON FIELDS: https://bugtrack.marklogic.com/41348 USE RANGE QUERIES INSTEAD (which sucks)
  oss << "\"json-property\": \"" << ref << "\",\"text\": [\"" << value << "\"]";
  oss << "}}";
  GenericQuery* qry = new GenericQuery;
  qry->setQuery(oss.str());
  return qry;
}

IQuery* SearchBuilder::xmlValueQuery(const std::string ref, const std::string value) {
  TIMED_FUNC(SearchBuilder_valueQuery);
  std::ostringstream oss;
  oss << "{\"value-query\":{";
  // TODO WARNING BUG FOR JSON FIELDS: https://bugtrack.marklogic.com/41348 USE RANGE QUERIES INSTEAD (which sucks)
  oss << "\"element\": {\"name\":\"" << ref << "\",\"namespace\":\"" << mImpl->defaultXmlNamespace << "\"},\"text\": [\"" << value << "\"]";
  oss << "}}";
  GenericQuery* qry = new GenericQuery;
  qry->setQuery(oss.str());
  return qry;
}

IQuery* SearchBuilder::rangeQuery(const std::string ref, const RangeOperation op, const std::string value) {
  if (QueryBuilderMode::ALL == mImpl->mode) {
    // TODO WARNING This function in ALL mode will not work due to bug: https://bugtrack.marklogic.com/41350
    return SearchBuilder::orQuery(std::vector<IQuery*>{SearchBuilder::jsonRangeQuery(ref,op,value),SearchBuilder::xmlRangeQuery(ref,op,value)});
  } else if (QueryBuilderMode::XML == mImpl->mode) {
    return SearchBuilder::xmlRangeQuery(ref,op,value);
  } else {
    return SearchBuilder::jsonRangeQuery(ref,op,value);
  }
}

IQuery* SearchBuilder::jsonRangeQuery(const std::string ref, const RangeOperation op, const std::string value) {
  TIMED_FUNC(SearchBuilder_rangeQuery);
  std::ostringstream oss;
  oss << "{\"range-query\":{";
  oss << "\"type\": \"xs:integer\",\"json-property\": \"" << ref << "\",\"value\": " << value << ",\"range-operator\":\"" << op << "\"";
  // TODO support other types here too, multiple values, with options, and so on
  oss << "}}";
  GenericQuery* qry = new GenericQuery;
  qry->setQuery(oss.str());
  return qry;
}

IQuery* SearchBuilder::xmlRangeQuery(const std::string ref, const RangeOperation op, const std::string value) {
  TIMED_FUNC(SearchBuilder_rangeQuery);
  std::ostringstream oss;
  oss << "{\"range-query\":{";
  oss << "\"type\": \"xs:integer\",\"element\": {\"name\":\"" << ref << "\",\"namespace\":\"" << mImpl->defaultXmlNamespace << "\"}";
  oss << ",\"value\": " << value << ",\"range-operator\":\"" << op << "\"";
  // TODO support other types here too, multiple values, with options, and so on
  oss << "}}";
  GenericQuery* qry = new GenericQuery;
  qry->setQuery(oss.str());
  return qry;
}


SearchBuilder* SearchBuilder::setQuery(IQuery* query) {
  TIMED_FUNC(SearchBuilder_setQuery);
  LOG(DEBUG) << "SearchBuilder::setQuery query to stream: " << *query;
  mImpl->rootQuery = query;
  return this;
}

ITextDocumentContent* SearchBuilder::toDocument() {
  TIMED_FUNC(SearchBuilder_toDocument);
  std::ostringstream oss;
  //oss << "{\"query\":";
  if (nullptr != mImpl->rootQuery) {
    oss << *(mImpl->rootQuery);
  } else {
    oss << "{}";
  }
  //oss << "}";
  GenericTextDocumentContent* tdc = new GenericTextDocumentContent;
  tdc->setContent(oss.str());
  tdc->setMimeType(mlclient::IDocumentContent::MIME_JSON);
  return tdc;

  //return CppRestJsonHelper::toDocument(web::json::value(oss.str()));
}


} // end namespace utilities

} // end namespace mlclient
