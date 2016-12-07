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
 * \file MarkLogicTypes.cpp
 *
 * \date 2016-12-06
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <mlclient/MarkLogicTypes.hpp>
#include <mlclient/logging.hpp>
#include <iostream>
#include <string>
#include <sstream>

namespace mlclient {

std::ostream& operator << (std::ostream& os, const RangeIndexType& rt) {
  os << translate_rangeindextype(rt);
  return os;
}
std::string& operator +(std::string& s, const RangeIndexType& rt) {
  s.append(translate_rangeindextype(rt));
  return s;
}
const std::string translate_rangeindextype(const RangeIndexType& rt) {
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
  case RangeIndexType::BOOLEAN:
    return "xs:boolean";
  }
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
const std::string JsonPropertyRef::getRef() {
  std::ostringstream oss;
  write(oss);
  return oss.str();
}


} // end namespace mlclient
