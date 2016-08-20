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
  virtual ~IBatchNotifiable();

  virtual void batchOperationComplete(const std::vector<std::string> out_uris,bool success,std::exception* problem) = 0;
};

/**
 * \brief Manages a batched document upload/write operation
 *
 * \since 8.0.2
 */
class DocumentBatchWriter {
public:
  DocumentBatchWriter(IConnection* conn);
  DocumentBatchWriter(const DocumentBatchWriter& other) = delete;
  ~DocumentBatchWriter();

  void assignDocuments(DocumentSet&& set);

  void setBatchParameters(const int parallelTasks,const int batchSize,const TransactionMode& mode);
  const int getParallelTasks() const;
  const int getBatchSize() const;
  const TransactionMode getMode() const;

  void addBatchListener(IBatchNotifiable* notifiable);
  void removeBatchListener(IBatchNotifiable* notifiable);

  void send();
  void stop();

  void wait() const;

  /**
   * \brief Has this class ran to completion?
   */
  const bool isComplete() const;

  /**
   * \brief Has this class been cancelled?
   */
  const bool isCancelled() const;

  /**
   * \brief Are all asynchronous operations completed?
   *
   * \note This class can still be working after stop() has been called. E.g. if a batch upload request is in progress
   */
  const bool isFinished() const;

  const Progress getProgress() const;
private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};

} // end namespace utilities

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHWRITER_HPP_ */
