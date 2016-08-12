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
 * \file SearchBuilder.hpp
 *
 * \date 2016-06-08
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_UTILITIES_SEARCHBUILDER_HPP_
#define SRC_UTILITIES_SEARCHBUILDER_HPP_

#include "mlclient/mlclient.hpp"
#include "mlclient/SearchDescription.hpp"

#include <cpprest/http_client.h> // deliberate compile time dependency

#include <vector>
#include <string>
#include <ostream>

namespace mlclient {

namespace utilities {


// ENUMS
/**
 * The MarkLogic Search Range Query Operation - Unknown (means the API hasn't been told by your own function calls!).
 */
enum class RangeOperation : int { UNKNOWN_TYPE = 0, GE = 1, GT = 2, LT = 3, LE = 4, EQ = 5, NE = 6 };

MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeOperation& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeOperation& rt);

MLCLIENT_API const std::string translate(const RangeOperation& rt);

// QUERY TYPES

/**
 * \brief A high level abstract class representing a MarkLogic Structured Query
 * \since 8.0.2
 * \date 2016-06-08
 */
class IQuery {
public:
  /**
   * \brief Default Constructor
   */
  MLCLIENT_API IQuery() = default;

  /**
   * \brief Default Destructor
   */
  MLCLIENT_API virtual ~IQuery() = default;

  friend std::ostream& operator<<(std::ostream& os, const IQuery& query);

protected:
  MLCLIENT_API virtual std::ostream& write(std::ostream& os) const = 0;
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const IQuery& rt);
MLCLIENT_API std::string& operator +(std::string& s, const IQuery& rt);



class GenericQuery: public IQuery {
public:
  MLCLIENT_API GenericQuery();
  MLCLIENT_API ~GenericQuery() = default;

  MLCLIENT_API void setQuery(const std::string& value);
  MLCLIENT_API const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};

class JsonPropertyQuery: public IQuery {
public:
  MLCLIENT_API JsonPropertyQuery();
  MLCLIENT_API ~JsonPropertyQuery() = default;

  MLCLIENT_API void setQuery(const std::string& property,const std::string& value);
  MLCLIENT_API const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string m_value;
};

// CONTAINER REFERENCES

class IContainerRef {
public:
  // TODO define IContainerRef
  MLCLIENT_API IContainerRef() = default;
  MLCLIENT_API virtual ~IContainerRef() = default;

  friend std::ostream& operator<<(std::ostream& os, const IContainerRef& ref);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};
std::ostream& operator << (std::ostream& os, const IContainerRef& rt);
std::string& operator +(std::string& s, const IContainerRef& rt);

class JsonPropertyRef : public IContainerRef {
public:
  MLCLIENT_API JsonPropertyRef();
  MLCLIENT_API ~JsonPropertyRef() = default;

  MLCLIENT_API void setProperty(const std::string& property);
  MLCLIENT_API const std::string getRef();

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};


// MARKLOGIC SUPPORTED TYPES

class ITypedValue {
public:
  MLCLIENT_API ITypedValue() = default;
  MLCLIENT_API virtual ~ITypedValue() = default;
};





/**
 * \brief The mode determines whether the QueryBuilder will generate JSON based queries, xml based queries, or an or query of all types (DEFAULT).
 * \note Useful when you have a mix of documents of both types. See also setDefaultXmlNamespace().
 */
enum class QueryBuilderMode {ALL,XML,JSON};


/**
 * \class SearchBuilder
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-06-08
 *
 * \brief This class helps create a MarkLogic complex search JSON object for use with SearchDescription
 *
 * \note This class deals only with a complex search, NOT search options or text grammar.
 *
 * \note This class only ever generates JSON output, never XML. This enables the class to be more efficient,
 * using the same internal structures as required by a JSON stream.
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class SearchBuilder {
public:
  MLCLIENT_API SearchBuilder();
  MLCLIENT_API ~SearchBuilder() = default;

  // public static methods that create query terms and option constraints
  MLCLIENT_API static IQuery* collectionQuery(const std::vector<std::string>& collections);
  //static IQuery& createWordQuery(const IContainerRef& container,const std::string& value);
  //static IQuery& createValueQuery(const IContainerRef& container,const ITypedValue& value);
  //static IQuery& createRangeQuery(const IContainerRef& container,const SearchBuilder::RangeOperation operation,const ITypedValue& value);
  //static IQuery& createConstraintQuery(const std::string& constraintName,const ITypedValue& value);
  MLCLIENT_API static IQuery* documentQuery(const std::vector<std::string>& uris);

  // public class methods that control the create of a search or query
  MLCLIENT_API static IQuery* andQuery(const std::vector<IQuery*>& queries);
  MLCLIENT_API static IQuery* orQuery(const std::vector<IQuery*>& queries);
  MLCLIENT_API static IQuery* notQuery(const IQuery* query);

  MLCLIENT_API IQuery* valueQuery(const std::string ref,const std::string value);
  MLCLIENT_API IQuery* jsonValueQuery(const std::string ref,const std::string value);
  MLCLIENT_API IQuery* xmlValueQuery(const std::string ref,const std::string value);
  MLCLIENT_API IQuery* rangeQuery(const std::string ref,const RangeOperation op,const std::string value);
  MLCLIENT_API IQuery* jsonRangeQuery(const std::string ref,const RangeOperation op,const std::string value);
  MLCLIENT_API IQuery* xmlRangeQuery(const std::string ref,const RangeOperation op,const std::string value);

  // instance methods that control the base search definition
  MLCLIENT_API SearchBuilder* setQuery(IQuery* query); // top level root query

  MLCLIENT_API void setDefaultXmlNamespace(const std::string& ns);
  MLCLIENT_API const std::string& getDefaultXmlNamespace() const;
  MLCLIENT_API void setMode(const QueryBuilderMode mode);
  MLCLIENT_API const QueryBuilderMode getMode() const;

  MLCLIENT_API ITextDocumentContent* toDocument();

private:
  class Impl; // forward declaration
  Impl* mImpl;

}; // end SearchBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif
