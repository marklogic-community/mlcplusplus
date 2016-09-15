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
  MLCLIENT_API bool operator==(const ValuesResultValue& other) {
    return value == other.value;
  };

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
  MLCLIENT_API bool operator==(const ValuesResultAggregate& other) {
    return name == other.name;
  };

  std::string name; //< The name of this aggregate in the search options
  ValuesResultAggregateType type; //< The aggregate type - single double, or complex value map
  double value; //< The simple aggregate result value, if applicable
  StringMap complexValue; //< The complex aggregate result value, if applicable
};

typedef std::vector<ValuesResultValue> ValuesResultValueSet;
typedef std::vector<ValuesResultAggregate> ValuesResultAggregateSet;

/**
 * \brief Contains details of the overarching /v1/values (i.e. Connection::values) call results.
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 *
 * \date 2016-08-12
 * \since 8.0.2
 */
class ValuesResult {
public:
  /**
   * \brief Creates a values result with the specified options name and values name (from submitted search options)
   *
   * \param optionsName The string name of the options node for this values result
   * \param valuesName The string name for this particular values result
   */
  MLCLIENT_API ValuesResult(const std::string& optionsName,const std::string& valuesName);
  /**
   * \brief Move constructor
   * \param other The ValuesResult object to steal the resources from
   */
  MLCLIENT_API ValuesResult(ValuesResult&& other);
  /**
   * \brief Copy constructor
   * \param other The ValuesResult to copy
   */
  MLCLIENT_API ValuesResult(const ValuesResult& other);
  /**
   * \brief Destructor
   */
  MLCLIENT_API ~ValuesResult();

  /**
   * \brief Adds a values result value to this instance
   * \param value the result value to add
   */
  MLCLIENT_API void addValue(const ValuesResultValue& value);
  /**
   * \brief Returns the underlying set of Values from this instance
   * \return The result set
   */
  MLCLIENT_API const ValuesResultValueSet getValues() const;

  // Is there only ever one of these??? I hope an RFE will get resolved to add more in one request!
  /**
   * \param Adds an aggregate configuration to the set to lookup by this class
   *
   * \note The current REST API only supports submitting one aggregate request per call. This may
   * be resolved in future versions. That change will be fully abstracted by this class' internals.
   *
   * \param aggregate The aggregate configuration to lookup
   */
  MLCLIENT_API void addAggregate(const ValuesResultAggregate& aggregate);
  //MLCLIENT_API const std::vector<ValuesResultAggregate> getAggregates() const;
  /**
   * \brief Whether any aggregate lookups are configured
   * \return True if one or more aggregate lookups are configured
   */
  MLCLIENT_API const bool hasAggregates() const;
  /**
   * \brief Returns the number of aggregates configured for lookup
   * \return The number of aggregate lookups configured
   */
  MLCLIENT_API const long getAggregateCount() const;
  /**
   * \brief Returns an iterator over the underlying aggregate lookups
   * \return The iterator over the list of aggregate lookups
   */
  MLCLIENT_API const ValuesResultAggregateSet::const_iterator aggregateBegin() const;
  /**
   * \brief Returns an iterator end marker for the underlying set of aggregate lookups
   * \return The iterator end marker
   */
  MLCLIENT_API const ValuesResultAggregateSet::const_iterator aggregateEnd() const;

  /**
   * \brief Used to set the total response times by the code actually performing the values lookups
   * \param valuesResolutionTime The xs:duration string
   * \param aggregateResolutionTime The xs:duration string
   * \param totalTime The xs:duration string
   */
  MLCLIENT_API void setTimes(const std::string& valuesResolutionTime,const std::string& aggregateResolutionTime,const std::string& totalTime);

  /**
   * \brief Sets the underlying range index lexicon type (A MarkLogic XML type)
   * \param type The lexicon type for lookup
   */
  MLCLIENT_API void setType(const mlclient::utilities::RangeIndexType& type);
  /**
   * \brief Returns the lexicon type
   * \return The lexicon type
   */
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
