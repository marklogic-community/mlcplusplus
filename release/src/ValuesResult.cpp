/*
 * ValuesResult.cpp
 *
 *  Created on: 15 Aug 2016
 *      Author: adamfowler
 */

#include <mlclient/ValuesResult.hpp>
#include <mlclient/logging.hpp>
#include <memory>

namespace mlclient {

class ValuesResult::Impl {
public:
  Impl(const std::string& optionsName,const std::string& valuesName)
    : optionsName(optionsName), valuesName(valuesName) , type(mlclient::RangeIndexType::STRING), valuesResults(),
      aggregateResults(), start(1), total(0), valuesResolutionTime(), aggregateResolutionTime(), totalTime() {
    ;
  }

  std::string optionsName;
  std::string valuesName;
  mlclient::RangeIndexType type;

  std::vector<ValuesResultValue> valuesResults;
  std::vector<ValuesResultAggregate> aggregateResults;

  long start;
  long total;

  std::string valuesResolutionTime;
  std::string aggregateResolutionTime;
  std::string totalTime;
};




ValuesResult::ValuesResult(const std::string& optionsName,const std::string& valuesName)
  : mImpl(mlclient::make_unique<Impl>(optionsName,valuesName)) {
  LOG(DEBUG) << "ValuesResult::ValuesResult ctor @" << &*this << " : optionsName: " << optionsName << ", valuesName: " << valuesName;
  ;
}
ValuesResult::ValuesResult(ValuesResult&& other) : mImpl(std::move(other.mImpl)) {
  LOG(DEBUG) << "ValuesResult::ValuesResult move ctor @" << &*this << " : optionsName: " << mImpl->optionsName << ", valuesName: " << mImpl->valuesName;
  other.mImpl = nullptr;
}
ValuesResult::ValuesResult(const ValuesResult& other) : mImpl(mlclient::make_unique<Impl>(other.mImpl->optionsName,other.mImpl->valuesName)) {
  mImpl->type = other.mImpl->type;
  mImpl->valuesResults = other.mImpl->valuesResults;
  mImpl->aggregateResults = other.mImpl->aggregateResults;
  mImpl->start = other.mImpl->start;
  mImpl->total = other.mImpl->total;
  mImpl->valuesResolutionTime = other.mImpl->valuesResolutionTime;
  mImpl->aggregateResolutionTime = other.mImpl->aggregateResolutionTime;
  mImpl->totalTime = other.mImpl->totalTime;
  LOG(DEBUG) << "ValuesResult::ValuesResult copy ctor @" << &*this << " : optionsName: " << mImpl->optionsName << ", valuesName: " << mImpl->valuesName;
  //other.mImpl = nullptr;
}
ValuesResult::~ValuesResult() {
  LOG(DEBUG) << "ValuesResult::~ValuesResult dtor @" << &*this;
  //delete(mImpl);
  //mImpl = NULL;
}

void ValuesResult::addValue(const ValuesResultValue& value) {
  mImpl->valuesResults.push_back(std::move(value));
}
const std::vector<ValuesResultValue> ValuesResult::getValues() const {
  return mImpl->valuesResults;
}

void ValuesResult::addAggregate(const ValuesResultAggregate& aggregate) {
  mImpl->aggregateResults.push_back(std::move(aggregate));
}
/*
const std::vector<ValuesResultAggregate> ValuesResult::getAggregates() const {
  return mImpl->aggregateResults;
}*/
const bool ValuesResult::hasAggregates() const {
  return 0 != mImpl->aggregateResults.size();
}
const long ValuesResult::getAggregateCount() const {
  return mImpl->aggregateResults.size();
}
const std::vector<ValuesResultAggregate>::const_iterator ValuesResult::aggregateBegin() const {
  return mImpl->aggregateResults.begin();
}
const std::vector<ValuesResultAggregate>::const_iterator ValuesResult::aggregateEnd() const {
  return mImpl->aggregateResults.end();
}

void ValuesResult::setTimes(const std::string& valuesResolutionTime,const std::string& aggregateResolutionTime,const std::string& totalTime) {
  mImpl->valuesResolutionTime = valuesResolutionTime;
  mImpl->aggregateResolutionTime = aggregateResolutionTime;
  mImpl->totalTime = totalTime;
}

void ValuesResult::setType(const mlclient::RangeIndexType& type) {
  mImpl->type = type;
}
const mlclient::RangeIndexType& ValuesResult::getType() const {
  return mImpl->type;
}

const long ValuesResult::getStart() {
  return mImpl->start;
}

const long ValuesResult::getTotal() {
  return mImpl->total;
}

const std::string& ValuesResult::getValuesResolutionTime() const {
  return mImpl->valuesResolutionTime;
}

const std::string& ValuesResult::getAggregateResolutionTime() const {
  return mImpl->aggregateResolutionTime;
}

const std::string& ValuesResult::getTotalTime() const {
  return mImpl->totalTime;
}

const std::string& ValuesResult::getOptionsName() const {
  return mImpl->optionsName;
}

const std::string& ValuesResult::getValuesName() const {
  return mImpl->valuesName;
}

} // end namespace mlclient

