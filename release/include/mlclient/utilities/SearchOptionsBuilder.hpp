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
 * \file SearchOptionsBuilder.hpp
 *
 * \date 2016-06-08
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_UTILITIES_SEARCHOPTIONSBUILDER_HPP_
#define SRC_UTILITIES_SEARCHOPTIONSBUILDER_HPP_

#include <mlclient/mlclient.hpp>
#include <mlclient/utilities/SearchBuilder.hpp>

#include <mlclient/SearchDescription.hpp>
#include <mlclient/DocumentContent.hpp>

#include <list>
#include <string>
#include <map>

namespace mlclient {

namespace utilities {

enum class RangeIndexType {
  INT, UNSIGNED_INT,LONG,UNSIGNED_LONG,FLOAT,DOUBLE,
  DECIMAL,DATE_TIME,TIME,DATE,G_YEAR_MONTH,G_YEAR,
  G_MONTH,G_DAY,YEAR_MONTH_DURATION,
  DAY_TIME_DURATION,STRING,ANY_URI
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeIndexType& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeIndexType& rt);

MLCLIENT_API const std::string translate_rangeindextype(const RangeIndexType& rt);

/*
namespace RangeIndexType {
  static const std::string INT = "xs:int";
  static const std::string UNSIGNED_INT = "xs:unsignedInt";
  static const std::string LONG = "xs:long";
  static const std::string UNSIGNED_LONG = "xs:unsignedLong";
  static const std::string FLOAT = "xs:float";
  static const std::string DOUBLE = "xs:double";
  static const std::string DECIMAL = "xs:decimal";
  static const std::string DATE_TIME = "xs:dateTime";
  static const std::string TIME = "xs:time";
  static const std::string DATE = "xs:date";
  static const std::string G_YEAR_MONTH = "xs:gYearMonth";
  static const std::string G_YEAR = "xs:gYear";
  static const std::string G_MONTH = "xs:gMonth";
  static const std::string G_DAY = "xs:gDay";
  static const std::string YEAR_MONTH_DURATION = "xs:yearMonthDuration";
  static const std::string DAY_TIME_DURATION = "xs:dayTimeDuration";
  static const std::string STRING = "xs:string";
  static const std::string ANY_URI = "xs:anyURI";
}*/

enum class AggregateBuiltIn {
  SUM,AVG,MAX,MIN,COUNT,STDDEV,STDDEV_POPULATION,VARIANCE,VARIANCE_POPULATION
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const AggregateBuiltIn& rt);
MLCLIENT_API std::string& operator +(std::string& s, const AggregateBuiltIn& rt);
MLCLIENT_API const std::string translate_aggregatebuiltin(const AggregateBuiltIn& rt);

// TODO string output and streaming definitions for IndexType


enum class FragmentScope {
  CONTENT,PROPERTIES
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const FragmentScope& rt);
MLCLIENT_API std::string& operator +(std::string& s, const FragmentScope& rt);
MLCLIENT_API const std::string translate_fragmentscope(const FragmentScope& rt);

enum class FacetOption {
  // These ones do NOT require a value
  ASCENDING,DESCENDING,EMPTIES,ANY,DOCUMENT,PROPERTIES,
  LOCKS,FREQUENCY_ORDER,ITEM_ORDER,FRAGMENT_FREQUENCY,
  ITEM_FREQUENCY,SCORE_LOGTFIDF,SCORE_LOGTF,SCORE_SIMPLE,
  SCORE_RANDOM,CHECKED,UNCHECKED,CONCURRENT,MAP,

  // These following ones all need a value
  TYPE,TIMEZONE,LIMIT,SAMPLE,TRUNCATE,SKIP
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const FacetOption& rt);
MLCLIENT_API std::string& operator +(std::string& s, const FacetOption& rt);
MLCLIENT_API const std::string translate_facetoption(const FacetOption& rt);

enum class RangeOption {
  // The following options have no values
  CACHED,UNCACHED,SYNONYM,

  // The following options contradict each other and have hard coded values
  SCORE_FUNCTION_ZERO,SCORE_FUNCTION_RECIPROCAL,SCORE_FUNCTION_LINEAR,

  // The following options require number values
  SLOPE_FACTOR,MAX_OCCURS,MIN_OCCURS
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeOption& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeOption& rt);
MLCLIENT_API const std::string translate_rangeoption(const RangeOption& rt);

enum class ValuesOption {
  /* These ones do NOT require a value */
  ASCENDING,DESCENDING,ANY,DOCUMENT,PROPERTIES,
  LOCKS,FREQUENCY_ORDER,ITEM_ORDER,FRAGMENT_FREQUENCY,
  ITEM_FREQUENCY,SCORE_LOGTFIDF,SCORE_LOGTF,SCORE_SIMPLE,
  SCORE_RANDOM,SCORE_ZERO,CHECKED,UNCHECKED,CONCURRENT,
  /* Following are for values only, no value */
  MAP,
  /* Following are for tuples only, no value */
  ORDERED,
  /* Following are for tuples only, with value */
  PROXIMITY,
  /* These following ones all need a value */
  TIMEZONE,LIMIT,SAMPLE,TRUNCATE,SKIP
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const ValuesOption& rt);
MLCLIENT_API std::string& operator +(std::string& s, const ValuesOption& rt);
MLCLIENT_API const std::string translate_valuesoption(const ValuesOption& rt);

class RangeOptions {
public:
  MLCLIENT_API RangeOptions();
  MLCLIENT_API virtual ~RangeOptions();

  MLCLIENT_API void setType(const RangeIndexType type);
  MLCLIENT_API const RangeIndexType getType() const;

  MLCLIENT_API void setCollation(const std::string& collation = "http://marklogic.com/collation/codepoint"); // TODO correct value.
  MLCLIENT_API const std::string getCollation() const;

  MLCLIENT_API void setFacet(const bool facet);
  MLCLIENT_API const bool getFacet() const;

  MLCLIENT_API void setContainer(IContainerRef* container);
  MLCLIENT_API const bool hasContainer() const;
  MLCLIENT_API const IContainerRef* getContainer() const;

  MLCLIENT_API void setFragmentScope(const FragmentScope& scope);
  MLCLIENT_API const FragmentScope getFragmentScope() const;

  MLCLIENT_API void clearFacetOptions();
  MLCLIENT_API void addFacetOptionWithValue(const FacetOption& option,const std::string& value);
  // TODO sensible sanity checking for contradictory option values (checked, unchecked, etc.)
  MLCLIENT_API void addFacetOption(const FacetOption& option);
  MLCLIENT_API const bool hasFacetOptions() const;
  MLCLIENT_API const std::map<FacetOption,std::string> getFacetOptions() const;

  MLCLIENT_API void clearRangeOptions();
  MLCLIENT_API void addRangeOptionWithValue(const RangeOption& option,const std::string& value);
  // TODO sensible sanity checking for contradictory option values (different score functions, etc.)
  MLCLIENT_API void addRangeOption(const RangeOption& option);
  MLCLIENT_API const bool hasRangeOptions() const;
  MLCLIENT_API const std::map<RangeOption,std::string> getRangeOptions() const;

  // TODO buckets and computed bucket configuration

private:
  RangeIndexType type;
  std::string collation;
  bool facet;
  IContainerRef* container;

  FragmentScope fragmentScope;
  std::map<FacetOption,std::string> facetOptions;
  std::map<RangeOption,std::string> rangeOptions;
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeOptions& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeOptions& rt);
MLCLIENT_API const std::string translate_rangeoptions(const RangeOptions& rt);


class AggregateInfo {
public:
  MLCLIENT_API AggregateInfo();
  MLCLIENT_API virtual ~AggregateInfo() = default;

  // Other member functions
  MLCLIENT_API void setAggregate(const AggregateBuiltIn aggregate);
  MLCLIENT_API void setAggregate(const std::string& udfName,const std::string& udfPath);
  MLCLIENT_API const bool isAggregateBuiltin() const;
  MLCLIENT_API const AggregateBuiltIn getAggregate() const;
  MLCLIENT_API const bool isCustomAggregate() const;
  MLCLIENT_API const std::string getUdfName() const;
  MLCLIENT_API const std::string getUdfPath() const;

private:
  bool bAggregateBuiltIn;
  AggregateBuiltIn aggregate;
  bool bCustomAggregate;
  std::string udfName;
  std::string udfPath;

};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const AggregateInfo& rt);
MLCLIENT_API std::string& operator +(std::string& s, const AggregateInfo& rt);
MLCLIENT_API const std::string translate_aggregateinfo(const AggregateInfo& rt);

enum class LexiconType {
  RANGE,GEO_ELEMENT,GEO_ELEMENT_PAIR,GEO_ATTRIBUTE_PAIR,GEO_JSON_PROPERTY,GEO_JSON_PROPERTY_PAIR,GEO_PATH,COLLECTION,URI
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const LexiconType& rt);
MLCLIENT_API std::string& operator +(std::string& s, const LexiconType& rt);
MLCLIENT_API const std::string translate_lexicontype(const LexiconType& rt);

class ILexiconRef {
public:
  MLCLIENT_API ILexiconRef() = default;
  MLCLIENT_API virtual ~ILexiconRef() = default;

  MLCLIENT_API virtual void setLexiconType(LexiconType type) = 0;
  MLCLIENT_API virtual const LexiconType getLexiconType() const = 0;

  MLCLIENT_API friend std::ostream& operator<<(std::ostream& os, const ILexiconRef& ref);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};
MLCLIENT_API std::ostream& operator<<(std::ostream& os, const ILexiconRef& ref);
MLCLIENT_API std::string& operator +(std::string& s, const ILexiconRef& rt);

class RangeLexiconRef : public ILexiconRef {
public:
  MLCLIENT_API RangeLexiconRef();
  MLCLIENT_API ~RangeLexiconRef() = default;

  MLCLIENT_API void setRange(RangeOptions range);
  MLCLIENT_API const RangeOptions getRange() const;

  MLCLIENT_API void setLexiconType(LexiconType type) override;
  MLCLIENT_API const LexiconType getLexiconType() const override;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  RangeOptions range;
  LexiconType type;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeLexiconRef& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeLexiconRef& rt);
MLCLIENT_API const std::string translate_rangelexiconref(const RangeLexiconRef& rt);

class ValuesInfo {
public:
  MLCLIENT_API ValuesInfo();
  MLCLIENT_API ~ValuesInfo();

  MLCLIENT_API void setName(const std::string& name);
  MLCLIENT_API const std::string getName() const;

  MLCLIENT_API void setLexicon(ILexiconRef* ref);
  MLCLIENT_API const ILexiconRef* getLexicon() const;
  MLCLIENT_API const bool hasLexicon() const;

  MLCLIENT_API const bool hasAggregate() const;
  MLCLIENT_API void setAggregate(const AggregateInfo& agg);
  MLCLIENT_API const AggregateInfo getAggregate() const;

  MLCLIENT_API const bool hasValuesOptions() const;
  MLCLIENT_API void setValuesOptions(std::map<ValuesOption,std::string> options);
  MLCLIENT_API const std::map<ValuesOption,std::string> getValuesOptions() const;

private:
  std::string name;
  ILexiconRef* lexicon;
  bool bAggregate;
  AggregateInfo aggregate;
  std::map<ValuesOption,std::string> valuesOptions;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const ValuesInfo& rt);
MLCLIENT_API std::string& operator +(std::string& s, const ValuesInfo& rt);
MLCLIENT_API const std::string translate_valuesinfo(const ValuesInfo& rt);




/**
 * \class SearchOptionsBuilder
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-06-08
 *
 * \brief This class helps create a MarkLogic search options JSON object for use with SearchDescription
 *
 * \note This class deals only with search options, NOT complex searches or text grammar.
 *
 * \note This class only ever generates JSON output, never XML. This enables the class to be more efficient,
 * using the same internal structures as required by a JSON stream.
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class SearchOptionsBuilder {
public:

  MLCLIENT_API SearchOptionsBuilder();
  MLCLIENT_API ~SearchOptionsBuilder() = default;

  // public class methods that control the create of a search or query
  MLCLIENT_API SearchOptionsBuilder* additionalQuery(const IQuery& query);
  MLCLIENT_API SearchOptionsBuilder* containerConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* fieldRangeConstraint(const IContainerRef& container); // use fieldContainerRef() with containerConstraint()

  //SearchOptionsBuilder* geoAttributePairConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoElementConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoElementPairConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoPathConstraint(const IContainerRef& container);

  MLCLIENT_API SearchOptionsBuilder* emptySnippet();
  MLCLIENT_API SearchOptionsBuilder* rawSnippet();

  //SearchOptionsBuilder* extractAttributeMetadata();
  //SearchOptionsBuilder* extractElementMetadata();
  //SearchOptionsBuilder* extractPropertyMetadata();
  //SearchOptionsBuilder* extractConstraintMetadata();

  //SearchOptionsBuilder* forests(std::list<std::string> forests);
  //SearchOptionsBuilder* fragmentScope(SearchOptionsBuilder::FragmentScope scope);

  // TODO grammar options including - grouping, implicit, implicitAnd, implicitOr, joiner

  // Values and Tuples configurations
  MLCLIENT_API SearchOptionsBuilder* valuesRangeAggregate(const std::string& name,const RangeOptions& range,
      const AggregateInfo& aggregate,const std::map<ValuesOption,std::string>& valuesOption);
  // also support non aggregate, values listing, configuration
  MLCLIENT_API SearchOptionsBuilder* valuesRange(const std::string& name,const RangeOptions& range,
      const std::map<ValuesOption,std::string>& valuesOption);

  MLCLIENT_API void fromDocument(const ITextDocumentContent& doc);
  MLCLIENT_API ITextDocumentContent* toDocument(bool asObject = false);

private:
  class Impl; // forward declaration - hides underlying API dependencies
  Impl* mImpl;

}; // end SearchOptionsBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif

