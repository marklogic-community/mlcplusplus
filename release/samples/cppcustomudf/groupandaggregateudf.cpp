/**
 * \file groupandaggregate.cpp
 *
 * \date 17 Aug 2016
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <MarkLogic.h>
#include <string>
#include <map>
#include <functional>

#ifdef _MSC_VER
#define PLUGIN_DLL __declspec(dllexport)
#else // !_MSC_VER
#define PLUGIN_DLL
#endif

using namespace marklogic;


class IInterimResult {
public:

  static IInterimResult* create() {
    return nullptr;
  }

  IInterimResult() : groupByValue("") {
    ;
  }

  virtual ~IInterimResult() {
    ;
  }

  // Virtual functions must be PURE virtual (= 0) else MarkLogic complains that Symbol for IInterimResult is not in compiled library
  virtual void add(const TupleIterator& from) = 0;
  virtual void merge(const IInterimResult* other) = 0;
  virtual const void writeToMap(OutputSequence& os) const = 0;

  virtual const void encode(Encoder& e, Reporter& reporter) const = 0;
  virtual void decode(Decoder& d, Reporter& reporter) = 0;

  std::string groupByValue;
};

class MeanInterimResult : public IInterimResult {
public:
  MeanInterimResult() : total(0.0), count(0) {
    groupByValue = "";
  }

  void add(const TupleIterator& from) override {
    if (from.width() > 1) {
      double newTotal;
      uint64_t freq = from.frequency();
      from.value(1,newTotal); // we only use the second (value) column
      total += (newTotal * freq);
      count += freq;
    }
    // else silently fail to add anything if no second range index configured (means we've been invoked from values() rather than tuples() )
  }
  const void writeToMap(OutputSequence& os) const override {
    os.startMap();
    os.writeMapKey("groupBy");
    String groupStr(groupByValue.c_str());
    os.writeValue(groupStr);
    os.writeMapKey("total");
    os.writeValue(total);
    os.writeMapKey("count");
    os.writeValue(count);
    os.writeMapKey("mean");
    os.writeValue(total / count);
    os.endMap();
  }
  void merge(const IInterimResult* other) override {
    MeanInterimResult* otherMean = (MeanInterimResult*)other;
    total += otherMean->total;
    count += otherMean->count;
  }
  const void encode(Encoder& e, Reporter& reporter) const override {
    String groupStr(groupByValue.c_str());
    e.encode(groupStr);
    e.encode(total);
    e.encode(count);
  }
  void decode(Decoder& d, Reporter& reporter) override {
    String groupStr;
    d.decode(groupStr);
    groupByValue = std::string(groupStr);
    d.decode(total);
    d.decode(count);
  }

  static IInterimResult* create() {
    MeanInterimResult* res = new MeanInterimResult;
    return res;
  }

  double total;
  int count; // decode/encode don't support long!
};

class SumInterimResult : public IInterimResult {
public:
  SumInterimResult() : total(0.0), count(0) {
    groupByValue = "";
  }

  void add(const TupleIterator& from) override {
    if (from.width() > 1) {
      double newTotal;
      uint64_t freq = from.frequency();
      from.value(1,newTotal); // we only use the second (value) column
      total += (newTotal * freq);
      count += freq;
    }
    // else silently fail to add anything if no second range index configured (means we've been invoked from values() rather than tuples() )
  }
  const void writeToMap(OutputSequence& os) const override {
    os.startMap();
    os.writeMapKey("groupBy");
    String groupStr(groupByValue.c_str());
    os.writeValue(groupStr);
    os.writeMapKey("sum");
    os.writeValue(total);
    os.writeMapKey("count");
    os.writeValue(count);
    os.endMap();
  }
  void merge(const IInterimResult* other) override {
    MeanInterimResult* otherMean = (MeanInterimResult*)other;
    total += otherMean->total;
    count += otherMean->count;
  }
  const void encode(Encoder& e, Reporter& reporter) const override {
    String groupStr(groupByValue.c_str());
    e.encode(groupStr);
    e.encode(total);
    e.encode(count);
  }
  void decode(Decoder& d, Reporter& reporter) override {
    String groupStr;
    d.decode(groupStr);
    groupByValue = std::string(groupStr);
    d.decode(total);
    d.decode(count);
  }

  static IInterimResult* create() {
    SumInterimResult* res = new SumInterimResult;
    return res;
  }

  double total;
  int count; // decode/encode don't support long!
};





/**
 * \brief This UDF calculates the mean of a specified value given a value to group by.
 *
 * \note We assume for performance reasons that the group-by column (the first, index 0, column)
 * has LOW CARDINALITY, usually a boolean (1 or 0) value, and that the field is indexed as a string in the codepoint collation (fastest)
 *
 * \note We further assume the second column (1) is a double field which is the field the mean is being calculated over (for Mean aggregate only)
 *
 * Currently this aggregate UDF only supports a Mean average, but the pattern is very easy to extend for other group-by and aggregate functions
 *
 * \note In future this UDF should be expanded to calculate different aggregations over each of the fields at index 1 and above, by configuration.
 * This will allow a single hit against a set of data to have multiple field aggregations calculated in a single hit, using the same group-by settings.
 *
 * \note Due to how MarkLogic UDFs are implemented, this mechanism requires range indexes for all columns you need to query or return.
 *
 * This is the foundation of a lot of work around propensity score matching (PSM) ATT estimation and matching algorithms.
 */
class GroupAndAggregateUDF : public AggregateUDF {
public:





  // Default constructor
  //GroupAndAggregateUDF() = default;

  // Copy constructor
  //GroupAndAggregateUDF(const GroupAndAggregateUDF& other) {
  //  interimValues = std::map<std::string,IInterimResult*>();
  //  resultTypeRef = other.resultTypeRef; // always the same across use
  //}

  AggregateUDF* clone() const {
    return (new GroupAndAggregateUDF(*this));  // calls copy constructor
  }

  void start(Sequence& args, Reporter& reporter) {
    try {
      // default to mean average
      resultTypeRef = &MeanInterimResult::create; // refer to function, not call it, so no ()
      for (; !args.done(); args.next()) {
        String argValue;
        args.value(argValue);
        std::string arg = std::string(argValue);

        if ("aggregate=sum" == arg) {
          resultTypeRef = &SumInterimResult::create;
        }
        // TODO other parameters
        // TODO check for a "compression=gzip" setting, and set our configuration accordingly

      } // end for
    } catch (std::exception& ex) {
      reporter.error(("Exception in start(): " + std::string(ex.what())).c_str());
    }
  }



  /**
   * \brief Get the values we need for the aggregate and cache them
   *
   * Assume the first column (index 0) is the group by field (with LOW cardinality)
   */
  void map(TupleIterator& values, Reporter& reporter) {
    try {
      for (; !values.done(); values.next()) {
        std::string groupBy;
        String tempString;
        values.value(0,tempString);
        groupBy = std::string(tempString);

        auto it = interimValues.find(groupBy);
        if (it == interimValues.end()) {
          // new
          IInterimResult* newInterim = resultTypeRef();
          newInterim->groupByValue = groupBy;
          newInterim->add(values);
          interimValues.insert(std::pair<std::string,IInterimResult*>(groupBy,newInterim));
        } else {
          IInterimResult* interim = interimValues.at(groupBy);
          // merge
          interim->add(values);
        }
      }
    } catch (std::exception& ex) {
      reporter.error(("Exception in map(): " + std::string(ex.what())).c_str());
    }
  }

  /**
   * \brief Reduce down the values from another aggregate UDF instance, and copy in to this aggregate instance
   */
  void reduce(const AggregateUDF* otherAgg, Reporter& reporter) {
    try {
      // loop through other's values and add to our equivalent value (if exists)
      // if doesn't exist in our values, add to our values
      const GroupAndAggregateUDF* other = (const GroupAndAggregateUDF*)otherAgg;
      for(auto ivi=other->interimValues.begin(); ivi!=other->interimValues.end(); ++ivi) {
        std::string groupBy(ivi->first);

        auto it = interimValues.find(groupBy);
        if (it == interimValues.end()) {
          // new
          IInterimResult* newInterim = resultTypeRef();
          newInterim->groupByValue = groupBy;
          newInterim->merge(ivi->second);
          interimValues.insert(std::pair<std::string,IInterimResult*>(groupBy,newInterim));
        } else {
          IInterimResult* interim = interimValues.at(groupBy);
          // merge
          interim->merge(ivi->second);
        }
      } // end for
    } catch (std::exception& ex) {
      reporter.error(("Exception in reduce(): " + std::string(ex.what())).c_str());
    }
  } // end reduce



  /**
   * \brief Encode to XDQP stream
   */
  void encode(Encoder& e, Reporter& reporter) {
    try {
      // TODO consider gzip compression at this top level, and using a std::ostringstream to collate values (optional setting at aggregate level)

      // no need to encode resultTypeRef as that's handled in the start() or clone() function
      // do need to encode count though
      e.encode((int)interimValues.size());
      for (auto ivi = interimValues.begin();ivi != interimValues.end();++ivi) {
        ivi->second->encode(e,reporter);
      }
    } catch (std::exception& ex) {
      reporter.error(("Exception in encode(): " + std::string(ex.what())).c_str());
    }
  }

  /**
   * \brief Decode from XDQP stream
   */
  void decode(Decoder& d, Reporter& reporter) {
    try {
      int size;
      d.decode(size);
      IInterimResult* interim;
      for (long i = 0;i < size;i++) {
        // decode all interim results
        interim = resultTypeRef();
        interim->decode(d,reporter);
      }
    } catch (std::exception& ex) {
      reporter.error(("Exception in decode(): " + std::string(ex.what())).c_str());
    }
  }

  /**
   * \brief Return the final result from the remaining aggregate UDF instance
   */
  void finish(OutputSequence& os, Reporter& reporter) {
    try {
      // Take Interim Values and merge results
      for (auto ivi = interimValues.begin();ivi != interimValues.end();++ivi) {
        ivi->second->writeToMap(os);
      }
    } catch (std::exception& ex) {
      reporter.error(("Exception in finish(): " + std::string(ex.what())).c_str());
    }
  }

  /**
   * \brief Clear up resources from this aggregate UDF
   */
  void close() {
    // NOT SAFE TO DELETE ANYTHING - called multiple times
    interimValues.clear();
  }

private:
  std::map<std::string,IInterimResult*> interimValues; // holds the values collected by this aggregate
  std::function<IInterimResult*(void)> resultTypeRef; // factory static function reference
};

extern "C" PLUGIN_DLL void marklogicPlugin(Registry& r) {
  r.version(1);
  r.registerAggregate<GroupAndAggregateUDF>("groupandaggregate");
}

