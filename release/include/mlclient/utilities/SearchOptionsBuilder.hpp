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

#include "mlclient/mlclient.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"

#include "mlclient/SearchDescription.hpp"
#include "mlclient/DocumentContent.hpp"

#include <list>
#include <string>
#include <map>

namespace mlclient {

namespace utilities {

namespace RangeIndexType {
enum t {
  INT, UNSIGNED_INT,LONG,UNSIGNED_LONG,FLOAT,DOUBLE,DECIMAL,DATE_TIME,TIME,DATE,G_YEAR_MONTH,G_YEAR,G_MONTH,G_DAY,YEAR_MONTH_DURATION,
  DAY_TIME_DURATION,STRING,ANY_URI
};
} // end namespace RangeIndexType

MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeIndexType::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeIndexType::t& rt);

MLCLIENT_API const std::string translate(const RangeIndexType::t& rt);

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

namespace AggregateBuiltIn {
MLCLIENT_API enum t {
  SUM,AVG,MAX,MIN,COUNT,STDDEV,STDDEV_POPULATION,VARIANCE,VARIANCE_POPULATION
};
} // end namespace AggregateBuiltIn

MLCLIENT_API std::ostream& operator << (std::ostream& os, const AggregateBuiltIn::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const AggregateBuiltIn::t& rt);
MLCLIENT_API const std::string translate(const AggregateBuiltIn::t& rt);

// TODO string output and streaming definitions for IndexType


namespace FragmentScope {
MLCLIENT_API enum t {
  CONTENT,PROPERTIES
};
} // end namespace FragmentScope

MLCLIENT_API std::ostream& operator << (std::ostream& os, const FragmentScope::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const FragmentScope::t& rt);
MLCLIENT_API const std::string translate(const FragmentScope::t& rt);

namespace FacetOption {
MLCLIENT_API enum t {
  // These ones do NOT require a value
  ASCENDING,DESCENDING,EMPTIES,ANY,DOCUMENT,PROPERTIES,
  LOCKS,FREQUENCY_ORDER,ITEM_ORDER,FRAGMENT_FREQUENCY,
  ITEM_FREQUENCY,SCORE_LOGTFIDF,SCORE_LOGTF,SCORE_SIMPLE,
  SCORE_RANDOM,CHECKED,UNCHECKED,CONCURRENT,MAP,

  // These following ones all need a value
  TYPE,TIMEZONE,LIMIT,SAMPLE,TRUNCATE,SKIP
};
} // end namespace FacetOption

MLCLIENT_API std::ostream& operator << (std::ostream& os, const FacetOption::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const FacetOption::t& rt);
MLCLIENT_API const std::string translate(const FacetOption::t& rt);

namespace RangeOption {
MLCLIENT_API enum t {
  // The following options have no values
  CACHED,UNCACHED,SYNONYM,

  // The following options contradict each other and have hard coded values
  SCORE_FUNCTION_ZERO,SCORE_FUNCTION_RECIPROCAL,SCORE_FUNCTION_LINEAR,

  // The following options require number values
  SLOPE_FACTOR,MAX_OCCURS,MIN_OCCURS
};
} // end namespace RangeOption


MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeOption::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeOption::t& rt);
MLCLIENT_API const std::string translate(const RangeOption::t& rt);

namespace ValuesOption {
MLCLIENT_API enum t {
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
} // end namespace ValuesOption

MLCLIENT_API std::ostream& operator << (std::ostream& os, const ValuesOption::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const ValuesOption::t& rt);
MLCLIENT_API const std::string translate(const ValuesOption::t& rt);

MLCLIENT_API class RangeOptions {
public:
  RangeOptions();
  virtual ~RangeOptions();

  void setType(const RangeIndexType::t type);
  const RangeIndexType::t getType() const;

  void setFacet(const bool facet);
  const bool getFacet() const;

  void setContainer(IContainerRef* container);
  const bool hasContainer() const;
  const IContainerRef* getContainer() const;

  void setFragmentScope(const FragmentScope::t& scope);
  const FragmentScope::t getFragmentScope() const;

  void clearFacetOptions();
  void addFacetOptionWithValue(const FacetOption::t& option,const std::string& value);
  // TODO sensible sanity checking for contradictory option values (checked, unchecked, etc.)
  void addFacetOption(const FacetOption::t& option);
  const bool hasFacetOptions() const;
  const std::map<FacetOption::t,std::string> getFacetOptions() const;

  void clearRangeOptions();
  void addRangeOptionWithValue(const RangeOption::t& option,const std::string& value);
  // TODO sensible sanity checking for contradictory option values (different score functions, etc.)
  void addRangeOption(const RangeOption::t& option);
  const bool hasRangeOptions() const;
  const std::map<RangeOption::t,std::string> getRangeOptions() const;

  // TODO buckets and computed bucket configuration

private:
  RangeIndexType::t type;
  bool facet;
  IContainerRef* container;

  FragmentScope::t fragmentScope;
  std::map<FacetOption::t,std::string> facetOptions;
  std::map<RangeOption::t,std::string> rangeOptions;
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeOptions& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeOptions& rt);
MLCLIENT_API const std::string translate(const RangeOptions& rt);


MLCLIENT_API class AggregateInfo {
public:
  AggregateInfo();
  virtual ~AggregateInfo() = default;

  // Other member functions
  void setAggregate(const AggregateBuiltIn::t aggregate);
  void setAggregate(const std::string& udfName,const std::string& udfPath);
  const bool isAggregateBuiltin() const;
  const AggregateBuiltIn::t getAggregate() const;
  const bool isCustomAggregate() const;
  const std::string getUdfName() const;
  const std::string getUdfPath() const;

private:
  bool bAggregateBuiltIn;
  AggregateBuiltIn::t aggregate;
  bool bCustomAggregate;
  std::string udfName;
  std::string udfPath;

};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const AggregateInfo& rt);
MLCLIENT_API std::string& operator +(std::string& s, const AggregateInfo& rt);
MLCLIENT_API const std::string translate(const AggregateInfo& rt);

namespace LexiconType {
MLCLIENT_API enum t {
  RANGE,GEO_ELEMENT,GEO_ELEMENT_PAIR,GEO_ATTRIBUTE_PAIR,GEO_JSON_PROPERTY,GEO_JSON_PROPERTY_PAIR,GEO_PATH,COLLECTION,URI
};
} // end namespace ValuesType

MLCLIENT_API std::ostream& operator << (std::ostream& os, const LexiconType::t& rt);
MLCLIENT_API std::string& operator +(std::string& s, const LexiconType::t& rt);
MLCLIENT_API const std::string translate(const LexiconType::t& rt);

MLCLIENT_API class ILexiconRef {
public:
  ILexiconRef() = default;
  virtual ~ILexiconRef() = default;

  virtual void setLexiconType(LexiconType::t type) = 0;
  virtual const LexiconType::t getLexiconType() const = 0;

  friend std::ostream& operator<<(std::ostream& os, const ILexiconRef& ref);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};
std::ostream& operator<<(std::ostream& os, const ILexiconRef& ref);
std::string& operator +(std::string& s, const ILexiconRef& rt);

MLCLIENT_API class RangeLexiconRef : public ILexiconRef {
public:
  RangeLexiconRef();
  ~RangeLexiconRef() = default;

  void setRange(RangeOptions range);
  const RangeOptions getRange() const;

  void setLexiconType(LexiconType::t type) override;
  const LexiconType::t getLexiconType() const override;

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  RangeOptions range;
  LexiconType::t type;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const RangeLexiconRef& rt);
MLCLIENT_API std::string& operator +(std::string& s, const RangeLexiconRef& rt);
MLCLIENT_API const std::string translate(const RangeLexiconRef& rt);

MLCLIENT_API class ValuesInfo {
public:
  ValuesInfo();
  ~ValuesInfo();

  void setName(const std::string& name);
  const std::string getName() const;

  void setLexicon(ILexiconRef* ref);
  const ILexiconRef* getLexicon() const;
  const bool hasLexicon() const;

  const bool hasAggregate() const;
  void setAggregate(const AggregateInfo& agg);
  const AggregateInfo getAggregate() const;

  const bool hasValuesOptions() const;
  void setValuesOptions(std::map<ValuesOption::t,std::string> options);
  const std::map<ValuesOption::t,std::string> getValuesOptions() const;

private:
  std::string name;
  ILexiconRef* lexicon;
  bool bAggregate;
  AggregateInfo aggregate;
  std::map<ValuesOption::t,std::string> valuesOptions;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const ValuesInfo& rt);
MLCLIENT_API std::string& operator +(std::string& s, const ValuesInfo& rt);
MLCLIENT_API const std::string translate(const ValuesInfo& rt);




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
MLCLIENT_API class SearchOptionsBuilder {
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
      const AggregateInfo& aggregate,const std::map<ValuesOption::t,std::string>& valuesOption);
  // also support non aggregate, values listing, configuration
  MLCLIENT_API SearchOptionsBuilder* valuesRange(const std::string& name,const RangeOptions& range,
      const std::map<ValuesOption::t,std::string>& valuesOption);

  MLCLIENT_API void fromDocument(const ITextDocumentContent& doc);
  MLCLIENT_API ITextDocumentContent* toDocument();

private:
  class Impl; // forward declaration - hides underlying API dependencies
  Impl* mImpl;

}; // end SearchOptionsBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif

