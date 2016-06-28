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


// QUERY TYPES

/**
 * \brief A high level abstract class representing a MarkLogic Structured Query
 * \since 8.0.2
 * \date 2016-06-08
 */
class MLCLIENT_API IQuery {
public:
  /**
   * \brief Default Constructor
   */
  IQuery() = default;

  /**
   * \brief Default Destructor
   */
  virtual ~IQuery() = default;

  friend std::ostream& operator<<(std::ostream& os, const IQuery& query);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};


std::ostream& operator << (std::ostream& os, const IQuery& rt);
std::string& operator +(std::string& s, const IQuery& rt);



class MLCLIENT_API GenericQuery: public IQuery {
public:
  GenericQuery();
  ~GenericQuery() = default;

  void setQuery(const std::string& value);
  const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};

class MLCLIENT_API JsonPropertyQuery: public IQuery {
public:
  JsonPropertyQuery();
  ~JsonPropertyQuery() = default;

  void setQuery(const std::string& property,const std::string& value);
  const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};

// CONTAINER REFERENCES

class MLCLIENT_API IContainerRef {
public:
  // TODO define IContainerRef
  IContainerRef() = default;
  virtual ~IContainerRef() = default;

  friend std::ostream& operator<<(std::ostream& os, const IContainerRef& ref);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};
std::ostream& operator << (std::ostream& os, const IContainerRef& rt);
std::string& operator +(std::string& s, const IContainerRef& rt);

class MLCLIENT_API JsonPropertyRef : public IContainerRef {
public:
  JsonPropertyRef();
  ~JsonPropertyRef() = default;

  void setProperty(const std::string& property);
  const std::string getRef();

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};


// MARKLOGIC SUPPORTED TYPES

class MLCLIENT_API ITypedValue {
public:
  ITypedValue() = default;
  virtual ~ITypedValue() = default;
};









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
class MLCLIENT_API SearchBuilder {
public:
  MLCLIENT_API enum RangeOperation {
    Equal,NotEqual,LessThan,LessThanOrEqual,MoreThan,MoreThanOrEqual
  };

  SearchBuilder();
  ~SearchBuilder() = default;

  // public static methods that create query terms and option constraints
  static IQuery* collectionQuery(const std::vector<std::string>& collections);
  //static IQuery& createWordQuery(const IContainerRef& container,const std::string& value);
  //static IQuery& createValueQuery(const IContainerRef& container,const ITypedValue& value);
  //static IQuery& createRangeQuery(const IContainerRef& container,const SearchBuilder::RangeOperation operation,const ITypedValue& value);
  //static IQuery& createConstraintQuery(const std::string& constraintName,const ITypedValue& value);
  static IQuery* documentQuery(const std::vector<std::string>& uris);

  // public class methods that control the create of a search or query
  static IQuery* andQuery(const std::vector<IQuery>& queries);
  static IQuery* orQuery(const std::vector<IQuery>& queries);
  static IQuery* notQuery(const std::vector<IQuery>& queries);

  // instance methods that control the base search definition
  SearchBuilder* setQuery(IQuery* query); // top level root query

  ITextDocumentContent* toDocument();

private:
  class Impl; // forward declaration
  Impl* mImpl;

}; // end SearchBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif
