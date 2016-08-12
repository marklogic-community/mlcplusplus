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

#include "mlclient/utilities/SearchOptionsBuilder.hpp"
#include "mlclient/utilities/SearchBuilder.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/InvalidFormatException.hpp"
#include "mlclient/logging.hpp"
#include <cpprest/http_client.h>
#include <iostream>
#include <string>
#include <sstream>
#include <list>

namespace mlclient {

namespace utilities {


std::ostream& operator << (std::ostream& os, const RangeIndexType& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const RangeIndexType& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const RangeIndexType& rt) {
  switch (rt) {
  case RangeIndexType::ANY_URI:
    return "xs:anyURI";
  case RangeIndexType::DATE:
    return "xs:date";
  case RangeIndexType::DATE_TIME:
    return "xs:dateTime";
  case RangeIndexType::DAY_TIME_DURATION:
    return "xs:dayTimeDuration";
  case RangeIndexType::DECIMAL:
    return "xs:decimal";
  case RangeIndexType::DOUBLE:
    return "xs:double";
  case RangeIndexType::FLOAT:
    return "xs:float";
  case RangeIndexType::G_DAY:
    return "xs:gDay";
  case RangeIndexType::G_MONTH:
    return "xs:gMonth";
  case RangeIndexType::G_YEAR:
    return "xs:gYear";
  case RangeIndexType::G_YEAR_MONTH:
    return "xs:gYearMonth";
  case RangeIndexType::INT:
    return "xs:int";
  case RangeIndexType::LONG:
    return "xs:long";
  case RangeIndexType::STRING:
    return "xs:string";
  case RangeIndexType::TIME:
    return "xs:time";
  case RangeIndexType::UNSIGNED_INT:
    return "xs:unsignedInt";
  case RangeIndexType::UNSIGNED_LONG:
    return "xs:unsignedLong";
  case RangeIndexType::YEAR_MONTH_DURATION:
    return "xs:yearMonthDuration";
  }
}



std::ostream& operator << (std::ostream& os, const AggregateBuiltIn& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const AggregateBuiltIn& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const AggregateBuiltIn& rt) {
  switch (rt) {
  case AggregateBuiltIn::AVG:
    return "avg";
  case AggregateBuiltIn::COUNT:
    return "count";
  case AggregateBuiltIn::MAX:
    return "max";
  case AggregateBuiltIn::MIN:
    return "min";
  case AggregateBuiltIn::STDDEV:
    return "stddev";
  case AggregateBuiltIn::STDDEV_POPULATION:
    return "stddevp";
  case AggregateBuiltIn::SUM:
    return "sum";
  case AggregateBuiltIn::VARIANCE:
    return "variance";
  case AggregateBuiltIn::VARIANCE_POPULATION:
    return "variancep";
  }
}



std::ostream& operator << (std::ostream& os, const FragmentScope& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const FragmentScope& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const FragmentScope& rt) {
  switch (rt) {
  case FragmentScope::CONTENT:
    return "documents";
  case FragmentScope::PROPERTIES:
    return "properties";
  }
}



std::ostream& operator << (std::ostream& os, const FacetOption& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const FacetOption& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const FacetOption& rt) {
  switch (rt) {
  case FacetOption::ANY:
    return "any";
  case FacetOption::ASCENDING:
    return "ascending";
  case FacetOption::CHECKED:
    return "checked";
  case FacetOption::CONCURRENT:
    return "concurrent";
  case FacetOption::DESCENDING:
    return "descending";
  case FacetOption::DOCUMENT:
    return "document";
  case FacetOption::PROPERTIES:
    return "properties";
  case FacetOption::EMPTIES:
    return "empties";
  case FacetOption::FRAGMENT_FREQUENCY:
    return "fragment-frequency";
  case FacetOption::FREQUENCY_ORDER:
    return "frequency-order";
  case FacetOption::ITEM_FREQUENCY:
    return "item-frequency";
  case FacetOption::ITEM_ORDER:
    return "item-order";
  case FacetOption::LIMIT:
    return "limit=";
  case FacetOption::LOCKS:
    return "locks";
  case FacetOption::MAP:
    return "map";
  case FacetOption::SAMPLE:
    return "sample=";
  case FacetOption::SCORE_LOGTF:
    return "score-logtf";
  case FacetOption::SCORE_LOGTFIDF:
    return "score-logtfidf";
  case FacetOption::SCORE_RANDOM:
    return "score-random";
  case FacetOption::SCORE_SIMPLE:
    return "score-simple";
  case FacetOption::SKIP:
    return "skip=";
  case FacetOption::TIMEZONE:
    return "timezone=";
  case FacetOption::TRUNCATE:
    return "truncate=";
  case FacetOption::TYPE:
    return "type=";
  case FacetOption::UNCHECKED:
    return "unchecked";
  }
}


std::ostream& operator << (std::ostream& os, const RangeOption& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const RangeOption& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const RangeOption& rt) {
  switch (rt) {
  case RangeOption::CACHED:
    return "cached";
  case RangeOption::MAX_OCCURS:
    return "max-occurs=";
  case RangeOption::MIN_OCCURS:
    return "min-occurs=";
  case RangeOption::SCORE_FUNCTION_LINEAR:
    return "score-function=linear";
  case RangeOption::SCORE_FUNCTION_RECIPROCAL:
    return "score-function=reciprocal";
  case RangeOption::SCORE_FUNCTION_ZERO:
    return "score-function=zero";
  case RangeOption::SLOPE_FACTOR:
    return "slope-factor=";
  case RangeOption::SYNONYM:
    return "synonym";
  case RangeOption::UNCACHED:
    return "uncached";
  }
}


std::ostream& operator << (std::ostream& os, const ValuesOption& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const ValuesOption& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const ValuesOption& rt) {
  switch (rt) {
  case ValuesOption::ORDERED:
    return "ordered";
  case ValuesOption::SCORE_ZERO:
    return "score-zero";

  case ValuesOption::ASCENDING:
    return "ascending";
  case ValuesOption::DESCENDING:
    return "descending";
  case ValuesOption::ANY:
    return "any";
  case ValuesOption::DOCUMENT:
    return "document";
  case ValuesOption::PROPERTIES:
    return "properties";

  case ValuesOption::LOCKS:
    return "locks";
  case ValuesOption::FREQUENCY_ORDER:
    return "grequency-order";
  case ValuesOption::ITEM_ORDER:
    return "item-order";
  case ValuesOption::FRAGMENT_FREQUENCY:
    return "fragment-frequency";

  case ValuesOption::ITEM_FREQUENCY:
    return "item-frequency";
  case ValuesOption::SCORE_LOGTFIDF:
    return "score-logtfidf";
  case ValuesOption::SCORE_LOGTF:
    return "score-logtf";
  case ValuesOption::SCORE_SIMPLE:
    return "score-simple";

  case ValuesOption::SCORE_RANDOM:
    return "score-random";
  case ValuesOption::CHECKED:
    return "checked";
  case ValuesOption::UNCHECKED:
    return "unchecked";
  case ValuesOption::CONCURRENT:
    return "concurrent";
  case ValuesOption::MAP:
    return "map";

  case ValuesOption::PROXIMITY:
    return "proximity=";
  case ValuesOption::TIMEZONE:
    return "timezone=";
  case ValuesOption::LIMIT:
    return "limit=";
  case ValuesOption::SAMPLE:
    return "sample=";
  case ValuesOption::TRUNCATE:
    return "truncate=";
  case ValuesOption::SKIP:
    return "skip=";
  }
}

RangeOptions::RangeOptions() : type(RangeIndexType::STRING), facet(false), container(nullptr), fragmentScope(FragmentScope::CONTENT),
    facetOptions(), rangeOptions() {
  ;
}
RangeOptions::~RangeOptions() {
  container = NULL; // Do not delete - may be used elsewhere
}

void RangeOptions::setType(const RangeIndexType type) {
  this->type = type;
}
const RangeIndexType RangeOptions::getType() const {
  return type;
}

void RangeOptions::setFacet(const bool facet) {
  this->facet = facet;
}
const bool RangeOptions::getFacet() const {
  return facet;
}

void RangeOptions::setContainer(IContainerRef* container) {
  this->container = container;
}
const bool RangeOptions::hasContainer() const {
  return nullptr != container;
}
const IContainerRef* RangeOptions::getContainer() const {
  return container;
}

void RangeOptions::setFragmentScope(const FragmentScope& scope) {
  fragmentScope = scope;
}
const FragmentScope RangeOptions::getFragmentScope() const {
  return fragmentScope;
}

void RangeOptions::clearFacetOptions() {
  facetOptions.clear();
}
void RangeOptions::addFacetOptionWithValue(const FacetOption& option,const std::string& value) {
  // TODO add sanity checks here too, and catch any invalid values trying to slip in
  facetOptions.insert(std::pair<FacetOption,std::string>(option,value));
}
void RangeOptions::addFacetOption(const FacetOption& option) {
  if (FacetOption::CHECKED == option) {
    facetOptions.erase(FacetOption::UNCHECKED);
  }
  if (FacetOption::UNCHECKED == option) {
    facetOptions.erase(FacetOption::CHECKED);
  }
  if (FacetOption::ASCENDING == option) {
    facetOptions.erase(FacetOption::DESCENDING);
  }
  if (FacetOption::DESCENDING == option) {
    facetOptions.erase(FacetOption::ASCENDING);
  }
  if (FacetOption::DOCUMENT == option) {
    facetOptions.erase(FacetOption::PROPERTIES);
  }
  if (FacetOption::PROPERTIES == option) {
    facetOptions.erase(FacetOption::DOCUMENT);
  }
  if (FacetOption::FREQUENCY_ORDER == option) {
    facetOptions.erase(FacetOption::ITEM_ORDER);
  }
  if (FacetOption::ITEM_ORDER == option) {
    facetOptions.erase(FacetOption::FREQUENCY_ORDER);
  }
  facetOptions.insert(std::pair<FacetOption,std::string>(option,"true"));
}
const bool RangeOptions::hasFacetOptions() const {
  return 0 != facetOptions.size();
}
const std::map<FacetOption,std::string> RangeOptions::getFacetOptions() const {
  return facetOptions;
}

void RangeOptions::clearRangeOptions() {
  rangeOptions.clear();
}
void RangeOptions::addRangeOptionWithValue(const RangeOption& option,const std::string& value) {
  // TODO add checks here, including checks for invalid values
  rangeOptions.insert(std::pair<RangeOption,std::string>(option,value));
}
void RangeOptions::addRangeOption(const RangeOption& option) {
  if (RangeOption::CACHED == option) {
    rangeOptions.erase(RangeOption::UNCACHED);
  }
  if (RangeOption::UNCACHED == option) {
    rangeOptions.erase(RangeOption::CACHED);
  }
  if (RangeOption::SCORE_FUNCTION_LINEAR == option) {
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_RECIPROCAL);
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_ZERO);
  }
  if (RangeOption::SCORE_FUNCTION_RECIPROCAL == option) {
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_LINEAR);
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_ZERO);
  }
  if (RangeOption::SCORE_FUNCTION_ZERO == option) {
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_RECIPROCAL);
    rangeOptions.erase(RangeOption::SCORE_FUNCTION_LINEAR);
  }
  rangeOptions.insert(std::pair<RangeOption,std::string>(option,"true"));
}
const bool RangeOptions::hasRangeOptions() const {
  return 0 != rangeOptions.size();
}
const std::map<RangeOption,std::string> RangeOptions::getRangeOptions() const {
  return rangeOptions;
}



std::ostream& operator << (std::ostream& os, const RangeOptions& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const RangeOptions& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const RangeOptions& rt) {
  std::ostringstream os;
  os << "\"range\":{";
  os << "\"type\":\"" << rt.getType() << "\",";
  // TODO collation if string
  os << "\"facet\":";
  if (rt.getFacet()) {
    os << "true";
  } else {
    os << "false";
  }
  os << ",";
  if (rt.hasContainer()) {
    os << *(rt.getContainer()); // calls it's stream << function
    os << ",";
  }
  os << "\"fragment-scope\":\"" << rt.getFragmentScope() << "\"";
  if (rt.hasFacetOptions() || rt.hasRangeOptions()) {
    os << ",";
  }
  // TODO bucket and computed bucket
  if (rt.hasFacetOptions()) {
    os << "\"facet-option\":[";
    std::map<FacetOption,std::string> fo = rt.getFacetOptions();
    bool first = true;
    for (auto iter = fo.begin();iter != fo.end();++iter) {
      if (first) {
        first = false;
      } else {
        os << ",";
      }
      os << "\"" << iter->first;
      if (0 != strcmp("true",iter->second.c_str())) {
        os << iter->second; // some non boolean value (all boolean values MUST be true, if used)
      }
      os << "\"";
    }
    os << "]";
  }
  if (rt.hasFacetOptions() && rt.hasRangeOptions()) {
    os << ",";
  }
  if (rt.hasRangeOptions()) {
    os << "\"range-options\":[";
    std::map<RangeOption,std::string> fo = rt.getRangeOptions();
    bool first = true;
    for (auto iter = fo.begin();iter != fo.end();++iter) {
      if (first) {
        first = false;
      } else {
        os << ",";
      }
      os << "\"" << iter->first;
      if (0 != strcmp("true",iter->second.c_str())) {
        os << iter->second; // some non boolean value (all boolean values MUST be true, if used)
      }
      os << "\"";
    }
    os << "]";
  }
  os << "}";
  return os.str();
}




AggregateInfo::AggregateInfo() : bAggregateBuiltIn(false), aggregate(AggregateBuiltIn::COUNT), bCustomAggregate(false),
    udfName(""),udfPath("") {
  ;
}

// Other member functions
void AggregateInfo::setAggregate(const AggregateBuiltIn aggregate) {
  this->aggregate = aggregate;
  bAggregateBuiltIn = true;
  bCustomAggregate = false;
}
void AggregateInfo::setAggregate(const std::string& udfName,const std::string& udfPath) {
  this->udfName = udfName;
  this->udfPath = udfPath;
  bAggregateBuiltIn = false;
  bCustomAggregate = true;
}
const bool AggregateInfo::isAggregateBuiltin() const {
  return bAggregateBuiltIn;
}
const AggregateBuiltIn AggregateInfo::getAggregate() const {
  if (!bAggregateBuiltIn) {
    throw InvalidFormatException("Aggregate is not a built in. Use getUdfName and getUdfPath instead");
  }
  return aggregate;
}
const bool AggregateInfo::isCustomAggregate() const {
  return bCustomAggregate;
}
const std::string AggregateInfo::getUdfName() const {
  if (!bCustomAggregate) {
    throw InvalidFormatException("Aggregate is not custom. Use getAggregate instead");
  }
  return udfName;
}
const std::string AggregateInfo::getUdfPath() const {
  if (!bCustomAggregate) {
    throw InvalidFormatException("Aggregate is not custom. Use getAggregate instead");
  }
  return udfPath;
}


std::ostream& operator << (std::ostream& os, const AggregateInfo& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const AggregateInfo& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const AggregateInfo& rt) {
  std::ostringstream os;
  if (rt.isAggregateBuiltin() || rt.isCustomAggregate()) {
    os << "\"aggregate\":{";
    if (rt.isAggregateBuiltin()) {
      os << "\"apply\":\"" << rt.getAggregate() << "\"";
    } else {
      // sanity 'else' check in case boolean logic in class is flawed - don't want invalid options
      if (rt.isCustomAggregate()) {
        os << "\"apply\":\"" << rt.getUdfName() << "\",";
        os << "\"udf\":\"" << rt.getUdfPath() << "\"";
      }
    }
    os << "}";
  }
  return os.str();
}



std::ostream& operator << (std::ostream& os, const LexiconType& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const LexiconType& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const LexiconType& rt) {
  switch (rt) {
  case LexiconType::COLLECTION:
    return "collection";
  case LexiconType::GEO_ATTRIBUTE_PAIR:
    return "geo-attr-pair";
  case LexiconType::GEO_ELEMENT:
    return "geo-elem";
  case LexiconType::GEO_ELEMENT_PAIR:
    return "geo-elem-pair";
  case LexiconType::GEO_JSON_PROPERTY:
    return "geo-json-property";
  case LexiconType::GEO_JSON_PROPERTY_PAIR:
    return "geo-json-property-pair";
  case LexiconType::GEO_PATH:
    return "geo-path";
  case LexiconType::RANGE:
    return "range";
  case LexiconType::URI:
    return "uri";
  }
}


std::ostream& operator<<(std::ostream& os, const ILexiconRef& ref) {
  return ref.write(os);
}
std::string& operator +(std::string& s, const ILexiconRef& ref) {
  std::ostringstream oss;
  oss << ref;
  s.append(oss.str());
  return s;
}


RangeLexiconRef::RangeLexiconRef() : range(), type(LexiconType::RANGE) {
  ;
}

void RangeLexiconRef::setRange(RangeOptions range) {
  this->range = range;
}
const RangeOptions RangeLexiconRef::getRange() const {
  return range;
}

void RangeLexiconRef::setLexiconType(LexiconType type) {
  this->type = type;
}
const LexiconType RangeLexiconRef::getLexiconType() const {
  return type;
}
std::ostream& RangeLexiconRef::write(std::ostream& os) const {
  os << range;
  return os;
}

std::ostream& operator << (std::ostream& os, const RangeLexiconRef& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const RangeLexiconRef& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const RangeLexiconRef& rt) {
  std::ostringstream os;
  os << rt.getRange(); // direct pass through
  return os.str();
}





ValuesInfo::ValuesInfo() : name(""), lexicon(nullptr), bAggregate(false), aggregate(), valuesOptions() {
  ;
}
ValuesInfo::~ValuesInfo() {
  ; // Do not delete lexicon - may be in use elsewhere
}

void ValuesInfo::setName(const std::string& name) {
  this->name = name;
}
const std::string ValuesInfo::getName() const {
  return name;
}

void ValuesInfo::setLexicon(ILexiconRef* ref) {
  this->lexicon = ref;
}
const ILexiconRef* ValuesInfo::getLexicon() const {
  return lexicon;
}
const bool ValuesInfo::hasLexicon() const {
  return nullptr != lexicon;
}

const bool ValuesInfo::hasAggregate() const {
  return bAggregate;
}
void ValuesInfo::setAggregate(const AggregateInfo& agg) {
  aggregate = agg;
  bAggregate = true;
}
const AggregateInfo ValuesInfo::getAggregate() const {
  if (!bAggregate) {
    throw new InvalidFormatException("ValuesInfo instance does not have an aggregate set");
  }
  return aggregate;
}

const bool ValuesInfo::hasValuesOptions() const {
  return 0 != valuesOptions.size();
}
void ValuesInfo::setValuesOptions(std::map<ValuesOption,std::string> options) {
  valuesOptions = options;
}
const std::map<ValuesOption,std::string> ValuesInfo::getValuesOptions() const {
  return valuesOptions;
}


std::ostream& operator << (std::ostream& os, const ValuesInfo& rt) {
  os << translate(rt);
  return os;
}
std::string& operator +(std::string& s, const ValuesInfo& rt) {
  s.append(translate(rt));
  return s;
}
const std::string translate(const ValuesInfo& rt) {
  std::ostringstream os;
  os << "{\"style\":\"consistent\",\"name\":\"" << rt.getName() << "\"";
  if (rt.hasLexicon()) {
    os << "," << *(rt.getLexicon()); // NEED TO IMPLEMENT WRITE VIRTUAL PURE FUNCTION AND FRIEND IT
  }
  if (rt.hasAggregate()) {
    os << "," << rt.getAggregate();
  }
  if (rt.hasValuesOptions()) {
    os << ",\"values-option\":[";
    bool first = true;
    for (auto iter = rt.getValuesOptions().begin();iter != rt.getValuesOptions().end();++iter) {
      if (first) {
        first = false;
      } else {
        os << ",";
      }
      os << "\"" << iter->first;
      if (0 != strcmp("true",iter->second.c_str())) {
        os << iter->second; // some non boolean value (all boolean values MUST be true, if used)
      }
      os << "\"";
    }
    os << "]";
  }
  os << "}";
  return os.str();
}








class SearchOptionsBuilder::Impl {
public:
  Impl() : additionalQuery(),constraints(),transform("raw") {
    ;
  };

  std::string additionalQuery;
  std::vector<std::string> constraints;
  std::string transform;

  std::vector<ValuesInfo> values;
};



SearchOptionsBuilder::SearchOptionsBuilder() : mImpl(new Impl) {
  ;
}



SearchOptionsBuilder* SearchOptionsBuilder::additionalQuery(const IQuery& query) {
  std::ostringstream oss;
  oss << query;
  mImpl->additionalQuery = oss.str();
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::containerConstraint(const IContainerRef& container) {
  std::ostringstream oss;
  oss << container;
  mImpl->constraints.push_back(oss.str());

  return this;
}


SearchOptionsBuilder* SearchOptionsBuilder::emptySnippet() {
  mImpl->transform = "empty";
  return this;
}

SearchOptionsBuilder* SearchOptionsBuilder::rawSnippet() {
  mImpl->transform = "raw";
  return this;
}


SearchOptionsBuilder* SearchOptionsBuilder::valuesRangeAggregate(const std::string& name,const RangeOptions& range,
    const AggregateInfo& aggregate,const std::map<ValuesOption,std::string>& valuesOptions) {
  ValuesInfo vi;
  vi.setAggregate(aggregate);
  RangeLexiconRef* rr = new RangeLexiconRef;
  rr->setLexiconType(LexiconType::RANGE);
  rr->setRange(range);
  vi.setLexicon(rr);
  vi.setName(name);
  vi.setValuesOptions(valuesOptions);
  mImpl->values.push_back(std::move(vi));
  return this;
}
// also support non aggregate, values listing, configuration
SearchOptionsBuilder* SearchOptionsBuilder::valuesRange(const std::string& name,const RangeOptions& range,
    const std::map<ValuesOption,std::string>& valuesOptions) {
  ValuesInfo vi;
  RangeLexiconRef* rr = new RangeLexiconRef;
  rr->setLexiconType(LexiconType::RANGE);
  rr->setRange(range);
  vi.setLexicon(rr);
  vi.setName(name);
  vi.setValuesOptions(valuesOptions);
  mImpl->values.push_back(std::move(vi));
  return this;
}

void SearchOptionsBuilder::fromDocument(const ITextDocumentContent& doc) {
  // TODO complete this, parse, and extract values
}

ITextDocumentContent* SearchOptionsBuilder::toDocument(bool asObject) {
  TIMED_FUNC(SearchOptionsBuilder_toDocument);
  std::ostringstream oss;
  if (asObject) {
    oss << "{\"options\":{";
  }
  oss << "\"transform-results\": {\"apply\": \"" << mImpl->transform << "\"}";
  // values options, if present
  if (0 != mImpl->values.size()) {
    oss << ",\"values\":[";
    bool first = true;
    for (auto iter = mImpl->values.begin();iter != mImpl->values.end();++iter) {
      if (first) {
        first = false;
      } else {
        oss << ",";
      }
      oss << *(iter); // uses class' << unary operator
    }
    oss << "]";
  }
  // TODO other JSON attributes
  oss << "}";
  if (asObject) {
    oss << "}";
  }

  GenericTextDocumentContent* tdc = new GenericTextDocumentContent;
  tdc->setContent(oss.str());
  tdc->setMimeType(IDocumentContent::MIME_JSON);
  return tdc;
}



} // end namespace utilities

} // end namespace mlclient
