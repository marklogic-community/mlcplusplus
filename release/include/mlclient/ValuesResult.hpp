/*
 * ValuesResult.hpp
 *
 *  Created on: 12 Aug 2016
 *      Author: adamfowler
 */

#ifndef INCLUDE_MLCLIENT_VALUESRESULT_HPP_
#define INCLUDE_MLCLIENT_VALUESRESULT_HPP_

#include <mlclient/mlclient.hpp>
#include <mlclient/utilities/SearchOptionsBuilder.hpp>

namespace mlclient {


/**
 * \brief Represents a single values lexicon result from a values lookup
 *
 * \note POD type
 *
 * \since 8.0.2
 */
struct ValuesResultValue {
  long frequency;
  std::string value;
};

/**
 * \brief Represents the type of response received from the aggregate
 *
 * There are multiple formats returned from the MarkLogic REST API's aggregate calls.
 * The OOTB aggregates return a simple vlaue element, which is a double encoded as a string.
 * The REST API can also return full map:map() results from UDFs that use this capability.
 * This is either a single map of string keys to typed values, or an array of maps.
 *
 * \note Currently there is a bug in the REST API that causes it only to return the first
 * numeric value from the first element in the map array. This also has side effects for very
 * large numbers. https://bugtrack.marklogic.com/41650
 *
 * This implementation is therefore necessarily flexible at the cost of programmatic precision and ease.
 *
 * The SIMPLE_DOUBLE response will be used for all OOTB aggregates from MarkLogic, and any UDF
 * aggregate that returns a single double value. COMPLEX_MAP_ARRAY will be used where a single map instance
 * is returned, or an array is returned. This is because this tier cannot detect from the response whether
 * the UDF only returns one map by design, or just happened to return a single map instance on this one occasion.
 *
 * \since 8.0.2
 */
enum class ValuesResultAggregateType {
  SIMPLE_DOUBLE,COMPLEX_MAP_ARRAY
};

/**
 * \brief Represents a single aggregate result from a values lookup
 *
 * \note POD type
 *
 * \since 8.0.2
 */
struct ValuesResultAggregate {
  std::string name;
  ValuesResultAggregateType type;
  double value;
  std::map<std::string,std::string> complexValue;
};

/**
 * \brief Contains details of the overarching /v1/values / Connection::values call results.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 *
 * \date 2016-08-12
 * \since 8.0.2
 */
class ValuesResult {
public:
  MLCLIENT_API ValuesResult(const std::string& optionsName,const std::string& valuesName);
  MLCLIENT_API ValuesResult(ValuesResult&& other);
  MLCLIENT_API ValuesResult(const ValuesResult& other);
  MLCLIENT_API ~ValuesResult();

  MLCLIENT_API void addValue(const ValuesResultValue& value);
  MLCLIENT_API const std::vector<ValuesResultValue> getValues() const;

  // Is there only ever one of these??? I hope an RFE will get resolved to add more in one request!
  MLCLIENT_API void addAggregate(const ValuesResultAggregate& aggregate);
  //MLCLIENT_API const std::vector<ValuesResultAggregate> getAggregates() const;
  MLCLIENT_API const bool hasAggregates() const;
  MLCLIENT_API const long getAggregateCount() const;
  MLCLIENT_API const std::vector<ValuesResultAggregate>::const_iterator aggregateBegin() const;
  MLCLIENT_API const std::vector<ValuesResultAggregate>::const_iterator aggregateEnd() const;

  MLCLIENT_API void setTimes(const std::string& valuesResolutionTime,const std::string& aggregateResolutionTime,const std::string& totalTime);

  MLCLIENT_API void setType(const mlclient::utilities::RangeIndexType& type);
  MLCLIENT_API const mlclient::utilities::RangeIndexType& getType() const;

  /**
   * \brief Returns the sequence number of the first values result
   *
   * \note Only relevant if skip=N is used in options configuration. MarkLogic uses 1 based numbers. Thus the first record is at position 1, not position 0
   * \return The first result's sequence number (lowest is 1)
   */
  MLCLIENT_API const long getStart();

  /**
   * \brief Returns the total count of values results
   *
   * \return The total number of values results returned.
   */
  MLCLIENT_API const long getTotal();

  /**
   * \brief Returns the values resolution time for the last values requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the time to resolve the values
   */
  MLCLIENT_API const std::string& getValuesResolutionTime() const;

  /**
   * \brief Returns the aggregate resolution time for the last values requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the time to resolve the aggregate
   */
  MLCLIENT_API const std::string& getAggregateResolutionTime() const;

  /**
   * \brief Returns the total time taken for the last values requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the total time taken (includes both values and aggregate times)
   */
  MLCLIENT_API const std::string& getTotalTime() const;

  /**
   * \brief Return the name of the REST API search options used to derive the result.
   *
   * \return The options name string
   */
  MLCLIENT_API const std::string& getOptionsName() const;

  /**
   * \brief Return the name of the values, configured within the search options specified, used to derive the result.
   *
   * \return The values name string, as configured within the specified search options
   */
  MLCLIENT_API const std::string& getValuesName() const;

private:
  class Impl; // forward declaration
  //Impl* mImpl;
  std::unique_ptr<Impl> mImpl;
};

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_VALUESRESULT_HPP_ */
