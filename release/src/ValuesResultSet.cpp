/**
 * \file ValuesResultSet.cpp
 *
 * \date 16 Aug 2016
 * \author adamfowler
 */

#include <mlclient/ValuesResultSet.hpp>
#include <mlclient/Connection.hpp>
#include <mlclient/utilities/ResponseHelper.hpp>

#include <mlclient/logging.hpp>
#include <cpprest/http_client.h>

#include <map>
#include <vector>

namespace mlclient {

class ValuesResultSet::Impl {
public:
  Impl(IConnection* conn) : mConn(conn), exception(), values(), mIter(nullptr), mCachedEnd(nullptr), tasks() {
    LOG(DEBUG) << "ValuesResultSet::Impl ctor @" << &*this;
  }
  Impl(const Impl& other) = delete;
  Impl(Impl&& other) = delete;
  ~Impl() {
    mConn = NULL;
    delete(mIter);
    mIter = NULL;
    delete(mCachedEnd);
    mCachedEnd = NULL;
  }

  IConnection* mConn;
  std::exception exception;
  std::vector<ValuesResult> values;

  ValuesIterator* mIter;
  ValuesIterator* mCachedEnd;

  std::map<long,pplx::task<void>*> tasks;
};





ValuesResultSet::ValuesResultSet(IConnection* conn) : mImpl(mlclient::make_unique<Impl>(conn)) {
  LOG(DEBUG) << "ValuesResultSet::ValuesResultSet ctor @" << &*this;
}
ValuesResultSet::~ValuesResultSet() {
  LOG(DEBUG) << "ValuesResultSet::~ValuesResultSet dtor @" << &*this;
}

void ValuesResultSet::addLookup(const std::string& optionsName,const std::string& valuesName) {
  //ValuesResult vra(optionsName,valuesName);
  //mImpl->values.push_back(std::move(vra));
  //ValuesResult* vra = new ValuesResult(optionsName,valuesName);
  //mImpl->values.push_back(vra);
  LOG(DEBUG) << "Creating new ValuesResult and emplacing in vector: optionsName: " << optionsName << ", valuesName: " << valuesName;
  mImpl->values.emplace_back(optionsName,valuesName);
}

void ValuesResultSet::wait() const {
  for (auto taskIter = mImpl->tasks.begin(); taskIter != mImpl->tasks.end();++taskIter) {
    taskIter->second->wait();
  }
}

ValuesIterator* ValuesResultSet::begin() {
  // TODO wait for all to return - later we can just wait for the ones we need answers from...
  wait();
  mImpl->mIter = new ValuesIterator(this);

  ValuesIterator* beginIter = mImpl->mIter->begin();
  mImpl->mCachedEnd = mImpl->mIter->end(); // cache end iterator to prevent poorly written code from instantiating many iterator instances
  return beginIter;
}
ValuesIterator* ValuesResultSet::end() {
  // cache and return iterator for end
  //TIMED_FUNC(ValuesResultSet_end);
  return mImpl->mCachedEnd;
}

bool ValuesResultSet::fetch() {
  // fire off parallel tasks to go fetch the results

  Impl& refImpl(*mImpl);

  long i = 0;
  pplx::task<void>* fetchTask;
  for (auto iter = mImpl->values.begin(); iter != mImpl->values.end();++iter) {
    fetchTask = new pplx::task<void>([&refImpl,iter] () {
      LOG(DEBUG) << "Began values fetch task...";
      LOG(DEBUG) << "Got iter reference";

      try {
        LOG(DEBUG) << "In try";
        LOG(DEBUG) << "valuesName: " << iter->getValuesName() << ", optionsName: " << iter->getOptionsName();
        Response* resp = refImpl.mConn->values(iter->getValuesName(),iter->getOptionsName());
        LOG(DEBUG) << "Got response";

        mlclient::utilities::ResponseHelper::getAggregateResults(*resp,*iter);
/*
        if (iter->hasAggregates()) { // implement function
          LOG(DEBUG) << "Has aggregates";
          //std::vector<ValuesResultAggregate> vars = result.getAggregates(); // normally only one result...
          for (auto varIter = iter->aggregateBegin(); varIter != iter->aggregateEnd();++varIter) { // TODO MAKE ITER VALUE NON CONST
            LOG(DEBUG) << "In aggregate loop";
            ValuesResultAggregate var = *varIter;
            LOG(DEBUG) << "Got aggregate reference";
            var.value = mlclient::utilities::ResponseHelper::getAggregateResult(*resp,var.name); // double
            LOG(DEBUG) << " set aggregate value";
          }
        }
        */

        LOG(DEBUG) << "Deleting response";
        delete(resp);
        LOG(DEBUG) << "Response deleted";
      } catch (std::exception& ref) {
        LOG(DEBUG) << "Exception in initial fetch task: " << ref.what();
        refImpl.exception = ref;
      }
      LOG(DEBUG) << "End values fetch task";

    });
    LOG(DEBUG) << "Inserting task";
    mImpl->tasks.insert(std::pair<long,pplx::task<void>*>(i++,fetchTask)); // end task initialisation


  } // end loop
  LOG(DEBUG) << "Returning true";
  return true;
}

std::exception ValuesResultSet::getFetchException() {
  // any exceptions are retuned here.
  return mImpl->exception;
}

const long ValuesResultSet::getTotal() const {
  return mImpl->values.size();
}








ValuesIterator::ValuesIterator() : mResultSet(nullptr), position(0) {
  ;
}
ValuesIterator::ValuesIterator(ValuesResultSet* set) : mResultSet(set), position(0) {
  ;
}
ValuesIterator::ValuesIterator(ValuesResultSet* set,long pos) : mResultSet(set), position(pos) {
  ;
}

ValuesIterator* ValuesIterator::begin() {
  //TIMED_FUNC(ValuesIterator_begin);
  long st = 1; // assume at least one result

  if (mResultSet->getTotal() == 0) {
    st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  }
  ValuesIterator* iter = new ValuesIterator(mResultSet, st);
  return iter;
}

ValuesIterator* ValuesIterator::end() {
  //TIMED_FUNC(ValuesIterator_end);
  long st = mResultSet->getTotal();
  if (0 == st) {
    //st = 0; // stops vector overflow where end = 0 (no results) and start = 1 (because of being 1 based in MarkLogic Server)
  } else {
    st++; // past end of vector, if at least one result
  }
  ValuesIterator* iter = new ValuesIterator(mResultSet, st); // ensure end is PAST last result
  return iter;
}

bool ValuesIterator::operator==(const ValuesIterator& other) {
  return position == other.position;
}
bool ValuesIterator::operator!=(const ValuesIterator& other) {
  return position != other.position;
}
void ValuesIterator::operator++() {
  LOG(DEBUG) << " ValuesResultIterator @" << &*this << " operator++() position: " << position;
  mResultSet->wait();
  // Wait for completion - No need, done within begin()
  position++;
  if (position > mResultSet->getTotal() + 1) {
    position = mResultSet->getTotal() + 1; // past end of results
  //} else {
    // wait for task to complete
  //  mResultSet->mImpl->tasks.at(position)->wait(); // should always be complete anyway...
  }
  LOG(DEBUG) << " ValuesResultIterator @" << &*this << " operator++() position now: " << position;
}
const ValuesResult ValuesIterator::operator*() {
  mResultSet->wait();
  return mResultSet->mImpl->values.at(position - 1); // position is 1 based
}

ValuesIterator ValuesIterator::operator=(const ValuesIterator& other) {
  mResultSet = other.mResultSet;
  position = other.position;
  return other;
}

const ValuesResult& ValuesIterator::first() const {
  mResultSet->wait();
  return mResultSet->mImpl->values.at(position - 1);
}

} // end namespace mlclient

