/**
 * \file BatchDocumentWriter.hpp
 *
 * \date 20 Aug 2016
 * \author adamfowler
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHWRITER_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHWRITER_HPP_

#include <mlclient/DocumentSet.hpp>
#include <mlclient/Document.hpp>
#include <mlclient/Connection.hpp>

#include <mlclient/mlclient.hpp>

namespace mlclient {

namespace utilities {

enum class TransactionMode {
  PER_RECORD,PER_BATCH,ALL
};

struct Progress {
  long completed;
  long total;
  double percentageComplete;
  long duration;
  long durationEstimateRemaining;
  double rate;
};

/**
 * \brief An abstract class that supports notification when a Document (batch) action is completed
 *
 * \since 8.0.2
 */
class IBatchNotifiable {
public:
  MLCLIENT_API virtual ~IBatchNotifiable();

  MLCLIENT_API virtual void batchOperationComplete(const DocumentUriSet out_uris,bool success,std::exception* problem) = 0;
};

/**
 * \brief Manages a batched document upload/write operation
 *
 * \since 8.0.2
 */
class DocumentBatchWriter {
public:
  MLCLIENT_API DocumentBatchWriter(IConnection* conn);
  MLCLIENT_API DocumentBatchWriter(const DocumentBatchWriter& other) = delete;
  MLCLIENT_API ~DocumentBatchWriter();

  MLCLIENT_API void assignDocuments(DocumentSet&& set);

  MLCLIENT_API void setBatchParameters(const int parallelTasks,const int batchSize,const TransactionMode& mode);
  MLCLIENT_API const int getParallelTasks() const;
  MLCLIENT_API const int getBatchSize() const;
  MLCLIENT_API const TransactionMode getMode() const;

  MLCLIENT_API void addBatchListener(IBatchNotifiable* notifiable);
  MLCLIENT_API void removeBatchListener(IBatchNotifiable* notifiable);

  MLCLIENT_API void send();
  MLCLIENT_API void stop();

  MLCLIENT_API void wait() const;

  /**
   * \brief Has this class ran to completion?
   */
  MLCLIENT_API const bool isComplete() const;

  /**
   * \brief Has this class been cancelled?
   */
  MLCLIENT_API const bool isCancelled() const;

  /**
   * \brief Are all asynchronous operations completed?
   *
   * \note This class can still be working after stop() has been called. E.g. if a batch upload request is in progress
   */
  MLCLIENT_API const bool isFinished() const;

  MLCLIENT_API const Progress getProgress() const;
private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};

} // end namespace utilities

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHWRITER_HPP_ */
