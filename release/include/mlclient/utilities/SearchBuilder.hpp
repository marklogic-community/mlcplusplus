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

#include <mlclient/mlclient.hpp>
#include <mlclient/MarkLogicTypes.hpp>
#include <mlclient/SearchDescription.hpp>
#include <mlclient/Document.hpp>

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

MLCLIENT_API const std::string translate_rangeoperation(const RangeOperation& rt);


/**
 * \brief A Generic Query concrete class for an IQuery
 *
 * This class is useful when you want to provide the low-level text (JSON representation of structure query configuration)
 * rather than create a subclass for every potential IQuery instance.
 *
 * \since 8.0.2
 */
class GenericQuery: public IQuery {
public:
  /**
   * \brief Creates a blank GenericQuery instance
   */
  MLCLIENT_API GenericQuery();
  MLCLIENT_API ~GenericQuery() = default;

  /**
   * \brief Sets the query from a (JSON) string value
   *
   * \param value The string JSON structured query value for this query
   */
  MLCLIENT_API void setQuery(const std::string& value);
  /**
   * \brief Returns the underlying query as text from this query instance
   *
   * \return The string query content
   */
  MLCLIENT_API const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};

/**
 * \brief A JSON property value query instance implementation of an IQuery
 *
 * \since 8.0.2
 *
 * See IQuery for details
 */
class JsonPropertyQuery: public IQuery {
public:
  /**
   * \brief Creates a blank JSON property value query
   */
  MLCLIENT_API JsonPropertyQuery();
  MLCLIENT_API ~JsonPropertyQuery() = default;

  /**
   * \brief Sets the property query given the named property and string query value
   *
   * \param property The full property name
   * \param value the exact string value to match
   */
  MLCLIENT_API void setQuery(const std::string& property,const std::string& value);
  /**
   * \brief Returns the underlying string query (structured query) as a string
   *
   * \return The JSON structured query string
   */
  MLCLIENT_API const std::string& getQuery() const;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string m_value;
};



// MARKLOGIC SUPPORTED TYPES

/**
 * \brief A Tagging interface to represent a typed value within the structure query API
 * \since 8.0.2
 */
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

typedef std::vector<IQuery*> IQuerySet;

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
  /**
   * \brief Factory method. Creates a collection query instance.
   *
   * \param collections The set of collections specified for the query (an OR evaluated list)
   * \return An IQuery pointer instance representing this structured query. Caller OWNS the pointer (this class does not delete it).
   */
  MLCLIENT_API static IQuery* collectionQuery(const CollectionSet& collections);
  //static IQuery& createWordQuery(const IContainerRef& container,const std::string& value);
  //static IQuery& createValueQuery(const IContainerRef& container,const ITypedValue& value);
  //static IQuery& createRangeQuery(const IContainerRef& container,const SearchBuilder::RangeOperation operation,const ITypedValue& value);
  //static IQuery& createConstraintQuery(const std::string& constraintName,const ITypedValue& value);
  /**
   * \brief Factory method. Creates a Document Query instance
   *
   * \param uris The DocumentUriSet (a vector<std::string>) listing the collections a document must be a member of (OR query)
   * \return An IQuery pointer instance representing this structured query. Caller OWNS the pointer (this class does not delete it).
   */
  MLCLIENT_API static IQuery* documentQuery(const DocumentUriSet& uris);

  /// \name searchbuilder_factory Public static class factory methods that control the create of a search or query
  /// @{
  /**
   * \brief Factory method. Creates an and-query
   *
   * \param queries A set of IQuery instances to and-together
   * \return An IQuery pointer instance representing this structured query. Caller OWNS the pointer (this class does not delete it).
   */
  MLCLIENT_API static IQuery* andQuery(const IQuerySet& queries);
  /**
   * \brief Factory method. Creates an or-query instance
   *
   * \param queries A set of IQuery instances to or-together
   * \return An IQuery pointer instance representing this structured query. Caller OWNS the pointer (this class does not delete it).
   */
  MLCLIENT_API static IQuery* orQuery(const IQuerySet& queries);
  /**
   * \brief Factory method. Creates a not-query.
   *
   * \param query The single query to not-query (pass it an or query to not anything where one of a set of queries match)
   * \return An IQuery pointer instance representing this structured query. Caller OWNS the pointer (this class does not delete it).
   */
  MLCLIENT_API static IQuery* notQuery(const IQuery* query);
  ///@}

  /// \name searchbuilder_classquery Instance factory methods that require class state in order to generate queries
  /// @{
  /**
   * \brief Creates a value query given the named reference
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* valueQuery(const std::string queryref,const std::string value);
  /**
   * \brief Creates a JSON property value query given the named reference
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* jsonValueQuery(const std::string queryref,const std::string value);
  /**
   * \brief Creates an xml element value query given the named reference
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* xmlValueQuery(const std::string queryref,const std::string value);
  /**
   * \brief Creates a range query given the named reference, and range operation
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param op The RangeOperation to perform
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* rangeQuery(const std::string queryref,const RangeOperation op,const std::string value,
    const RangeIndexType& type = RangeIndexType::INT);
  /**
   * \brief Creates a JSON property range query given the named reference, and range operation
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param op The RangeOperation to perform
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* jsonRangeQuery(const std::string queryref,const RangeOperation op,const std::string value,
    const RangeIndexType& type = RangeIndexType::INT);
  /**
   * \brief Creates an XML element range query given the named reference, and range operation
   *
   * \note This method checks a list of named references, and thus is an instance method.
   *
   * \param queryref The reference to check
   * \param op The RangeOperation to perform
   * \param value The string value to match
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* xmlRangeQuery(const std::string queryref,const RangeOperation op,const std::string value,
    const RangeIndexType& type = RangeIndexType::INT);

  /**
   * \brief A container query, specifying the parent of an element or property
   *
   * \note Contained query matches at any point below this element or property, not just directly below this element/property (not just child)
   *
   * \note If the Search Builder is in 'all' mode, then this function generates an or query of an elementQuery and a propertyQuery.
   * 
   * \param name The name of the element or property
   * \param query The query to match within this element or property
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* containerQuery(const std::string name,const IQuery* query);

  /**
   * \brief An XML Element query, specifying the parent of an element
   *
   * \note Contained query matches at any point below this element, not just directly below this element (not just child)
   *
   * \param name The name of the element
   * \param ns The namespace of the element
   * \param query The query to match within this element
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* elementQuery(const std::string name,const std::string ns,const IQuery* query);

  /**
   * \brief An JSON property query, specifying the parent of a property
   *
   * \note Contained query matches at any point below this property, not just directly below this property (not just child)
   *
   * \param name The name of the property
   * \param query The query to match within this property
   * \return The IQuery instance created. The caller OWNS this pointer. (This class does not delete the pointer.)
   */
  MLCLIENT_API IQuery* propertyQuery(const std::string name,const IQuery* query);
  /// @}

  /// \name searchbuilder_instance Instance methods that control the base search definition
  /// @{
  /**
   * \brief Sets the root query for this search.
   *
   * Use and-query and or-query to join multiple queries together, then pass the result to this function.
   *
   * \param query The root query for this structured query
   * \return A chainable reference to this class instance, allowing for multiple calls and easy function calling.
   */
  MLCLIENT_API SearchBuilder* setQuery(IQuery* query); // top level root query

  /**
   * \brief Convenience method. Sets the default XML namespace for all XML queries.
   *
   * \param ns The XML namespace full URI string
   */
  MLCLIENT_API void setDefaultXmlNamespace(const std::string& ns);
  /**
   * \brief Returns the default namespace
   *
   * \return The default namespace string
   */
  MLCLIENT_API const std::string& getDefaultXmlNamespace() const;
  /**
   * \brief Sets the query builder mode, i.e. the format of the query.
   *
   * \warning This should ALWAYS be JSON for now. XML queries are not yet supported.
   *
   * \param mode The query format mode
   */
  MLCLIENT_API void setMode(const QueryBuilderMode mode);
  /**
   * \brief Returns the current query builder format mode (JSON)
   * \return The QueryBuilderMode in use (JSON)
   */
  MLCLIENT_API const QueryBuilderMode getMode() const;

  /**
   * \brief Generates an ITextDocumentContent instance representing the serialisation of this structured query.
   *
   * \return The ITextDocumentContent instance. Caller OWNS this pointer. (This class never deletes it)
   */
  MLCLIENT_API ITextDocumentContent* toDocument();

  /// @}

private:
  class Impl; // forward declaration
  Impl* mImpl;

}; // end SearchBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif
