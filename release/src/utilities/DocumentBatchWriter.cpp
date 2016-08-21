/**
 * \file DocumentBatchWriter.cpp
 *
 * \date 20 Aug 2016
 * \author adamfowler
 */

#include <mlclient/utilities/DocumentBatchWriter.hpp>
#include <mlclient/utilities/ResponseHelper.hpp>
#include <mlclient/DocumentSet.hpp>
#include <mlclient/Connection.hpp>
#include <mlclient/Document.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/logging.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <mlclient/mlclient.hpp>

// We can use the following, because cpprest is an internal API dependency
#include <cpprest/http_client.h>

#include <chrono>
#include <map>
#include <vector>
#include <cmath>

namespace mlclient {

namespace utilities {

IBatchNotifiable::~IBatchNotifiable() {
  ;
}

static DocumentSet emptyDocumentSet;

class DocumentBatchWriter::Impl {
public:
  Impl(IConnection* conn) : mConn(conn), set(emptyDocumentSet), parallelTasks(5),batchSize(10),
      mode(TransactionMode::PER_BATCH),toNotify(),complete(false),cancelled(false),finished(true),
      overall(),latest(), completeUris(), tasks(), startTime(1) {
    ;
  }

  long now() {
    auto time = std::chrono::system_clock::now();

    auto since_epoch = time.time_since_epoch();

    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch);

    return millis.count();
  }

  void calculateProgress() {
    long n = now();
    latest.completed = completeUris.size();
    latest.percentageComplete = 100.0 * latest.completed / set.size();
    latest.total = set.size();
    latest.duration = n - startTime;
    latest.durationEstimateRemaining = ((latest.total - latest.completed) * latest.duration) / latest.completed;
    latest.rate = latest.completed / (latest.duration);

    // TODO make the above just for the last X seconds, and update overall separately

    overall = latest; // copy
  }

  void checkComplete() {
    complete = true;
    for (auto& iter: tasks) {
      complete = complete && iter.second->is_done();
    }
    finished = (completeUris.size() == set.size());
    calculateProgress();
  }

  void begin() {
    if (complete || !finished) {
      return; // stop starting the work twice
    }
    finished = false;
    startTime = now();

    // TODO start parallelTasks

    Impl& refImpl(*this);

    long maxIterations = ceil(set.size() / parallelTasks);

    LOG(DEBUG) << "Creating tasks to write " << set.size() << " Documents";

    pplx::task<void>* fetchTask;
    for (long i = 0;i < parallelTasks;i++) {
      fetchTask = new pplx::task<void>([&refImpl,i,&maxIterations] () {
        long myi = i;

        LOG(DEBUG) << "Began document batch writer task... " << myi;
        for (long j = 0;j < maxIterations;j++) {
          // calculate segment start and finish
          long startIdx = ((j * refImpl.parallelTasks) + myi) * refImpl.batchSize;
          long endIdx = startIdx + refImpl.batchSize - 1;

          if (startIdx >= refImpl.set.size()) {
            LOG(DEBUG) << "Start index is out of range: " << startIdx;
            j = maxIterations;
          } else {
            if (endIdx >= refImpl.set.size()) {
              LOG(DEBUG) << "End index is out of range: " << endIdx;
              // must be on last part of set
              endIdx = refImpl.set.size() - 1;
              LOG(DEBUG) << "End index now: " << endIdx;
            }
            LOG(DEBUG) << "Batch writer thread " << myi << " writing documents from index " << startIdx << " to " << endIdx;

            try {
              LOG(DEBUG) << "In try";


              // sanity check values for this set

              Response* resp = refImpl.mConn->saveDocuments(refImpl.set,startIdx,endIdx);
              LOG(DEBUG) << "Got response";

              // update complete
              std::vector<std::string> myUris;
              for (long idx = startIdx; idx <= endIdx;idx++) {
                std::string uri = refImpl.set.at(idx).getUri();
                refImpl.completeUris.push_back(uri);
                myUris.push_back(uri);
              }
              refImpl.checkComplete();

              // check ok and notify
              if (ResponseHelper::isInError(*resp)) {
                std::exception* exc = new InvalidFormatException(ResponseHelper::getErrorDetailAsString(*resp)); // TODO better exception wrapper
                for (auto& tell: refImpl.toNotify) {
                  tell->batchOperationComplete(myUris,false,exc);
                }
                delete(exc);
              } else {
                for (auto& tell: refImpl.toNotify) {
                  tell->batchOperationComplete(myUris,true,nullptr);
                }
              }

              LOG(DEBUG) << "Deleting response";
              delete(resp);
              LOG(DEBUG) << "Response deleted";
            } catch (std::exception& ref) {
              LOG(DEBUG) << "Exception in batch document upload task: " << ref.what();

              std::vector<std::string> myUris;
              for (long idx = startIdx; idx <= endIdx;idx++) {
                std::string uri = refImpl.set.at(idx).getUri();
                myUris.push_back(uri);
              }
              for (auto& tell: refImpl.toNotify) {
                tell->batchOperationComplete(myUris,false,&ref);
              }
            }

          } // end if out of bounds

        } // end iteration for

        LOG(DEBUG) << "End document upload batch task: " << myi;
      });
      LOG(DEBUG) << "adding task";
      refImpl.tasks.insert(std::pair<long,pplx::task<void>*>(i,fetchTask)); // end task initialisation


    } // end loop
    LOG(DEBUG) << "Tasks initialised";
  }

  void stop() {
    cancelled = true;
  }

  IConnection* mConn;
  DocumentSet& set;
  int parallelTasks;
  int batchSize;
  TransactionMode mode;
  std::vector<IBatchNotifiable*> toNotify;

  bool complete;
  bool cancelled;
  bool finished;

  Progress overall;
  Progress latest;

  std::vector<std::string> completeUris; // includes failed URIs

  std::map<long,pplx::task<void>*> tasks;

  long startTime;

};





DocumentBatchWriter::DocumentBatchWriter(IConnection* conn) : mImpl(mlclient::make_unique<Impl>(conn)) {
  ;
}

DocumentBatchWriter::~DocumentBatchWriter() {
  ;
}

void DocumentBatchWriter::assignDocuments(DocumentSet&& set) {
  mImpl->set = std::move(set);
}

void DocumentBatchWriter::setBatchParameters(const int parallelTasks,const int batchSize,const TransactionMode& mode) {
  mImpl->parallelTasks = parallelTasks;
  mImpl->batchSize = batchSize;
  mImpl->mode = mode;
}
const int DocumentBatchWriter::getParallelTasks() const {
  return mImpl->parallelTasks;
}
const int DocumentBatchWriter::getBatchSize() const {
  return mImpl->batchSize;
}
const TransactionMode DocumentBatchWriter::getMode() const {
  return mImpl->mode;
}

void DocumentBatchWriter::addBatchListener(IBatchNotifiable* notifiable) {
  mImpl->toNotify.push_back(notifiable);
}
void DocumentBatchWriter::removeBatchListener(IBatchNotifiable* notifiable) {
  //mImpl->toNotify.erase(notifiable);
}

void DocumentBatchWriter::send() {
  mImpl->begin();
}
void DocumentBatchWriter::stop() {
  mImpl->stop();
}

void DocumentBatchWriter::wait() const {
  for (auto taskIter = mImpl->tasks.begin(); taskIter != mImpl->tasks.end();++taskIter) {
    taskIter->second->wait();
  }
}

const bool DocumentBatchWriter::isComplete() const {
  return mImpl->complete;
}

const bool DocumentBatchWriter::isCancelled() const {
  return mImpl->cancelled;
}

const bool DocumentBatchWriter::isFinished() const {
  return mImpl->finished;
}

const Progress DocumentBatchWriter::getProgress() const {
  return mImpl->overall;
}


} // end namespace utilities

} // end namespace mlclient
