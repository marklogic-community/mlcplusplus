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
 * \file MarkLogicTypes.hpp
 *
 * \date 2016-12-06
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */


#ifndef SRC_MARKLOGICTYPES_HPP_
#define SRC_MARKLOGICTYPES_HPP_

#include <mlclient/mlclient.hpp>
#include <iostream>
#include <string>
#include <sstream>

namespace mlclient {

enum class RangeIndexType {
  INT, UNSIGNED_INT,LONG,UNSIGNED_LONG,FLOAT,DOUBLE,
  DECIMAL,DATE_TIME,TIME,DATE,G_YEAR_MONTH,G_YEAR,
  G_MONTH,G_DAY,YEAR_MONTH_DURATION,
  DAY_TIME_DURATION,STRING,ANY_URI,BOOLEAN
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

  MLCLIENT_API friend std::ostream& operator<<(std::ostream& os, const IQuery& query);

protected:
  MLCLIENT_API virtual std::ostream& write(std::ostream& os) const = 0;
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const IQuery& rt);
MLCLIENT_API std::string& operator +(std::string& s, const IQuery& rt);






// CONTAINER REFERENCES

/**
 * \brief Represents a named container in the MarkLogic structured query API
 *
 * A container could be a JSON property or XML element. These containers are used at the top level of
 * many structure query object configuration.
 *
 * This class is an abstract class, designed to be subclassed, not used directly
 */
class IContainerRef {
public:
  MLCLIENT_API IContainerRef() = default;
  MLCLIENT_API virtual ~IContainerRef() = default;

  friend std::ostream& operator<<(std::ostream& os, const IContainerRef& ref);

protected:
  virtual std::ostream& write(std::ostream& os) const = 0;
};
std::ostream& operator << (std::ostream& os, const IContainerRef& rt);
std::string& operator +(std::string& s, const IContainerRef& rt);

/**
 * \brief A specialisation of IContainerRef to represent a JSON property container
 *
 * \since 8.0.2
 */
class JsonPropertyRef : public IContainerRef {
public:
  MLCLIENT_API JsonPropertyRef();
  MLCLIENT_API ~JsonPropertyRef() = default;

  /**
   * \brief Sets the property this class is referring to
   * \param property The JSON property name
   */
  MLCLIENT_API void setProperty(const std::string& property);
  /**
   * \brief Returns the structured query JSON string representation of this container ref instance
   *
   * \return The structured query JSON string
   */
  MLCLIENT_API const std::string getRef();

protected:
  std::ostream& write(std::ostream& os) const override;

private:
  std::string value;
};



} // end namespace mlclient

#endif /* defines SRC_MARKLOGICTYPES_HPP_ */
