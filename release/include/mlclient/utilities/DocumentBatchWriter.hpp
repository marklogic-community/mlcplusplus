/**
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

/**
 * \brief Represents the Batch upload transaction mode used by DocumentBatchWriter. Defaults to PER_BATCH
 * \since 8.0.2
 */
enum class TransactionMode {
  PER_RECORD,PER_BATCH,ALL
};

/**
 * \brief The progress of the upload within DocumentBatchWriter
 * \since 8.0.2
 */
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
 * \note Can be subclassed directly in other wrappers (E.g. C#)
 *
 * \since 8.0.2
 */
class IBatchNotifiable {
public:
  MLCLIENT_API virtual ~IBatchNotifiable();

  /**
   * \brief Receives a complete event from the DocumentBatchWriter class
   *
   * \since 8.0.2
   *
   * \param out_uris The set of DocumentUris that have been processed (not necessarily succeeded in uploading)
   * \param success Whether all files were uploaded
   * \param problem The exception thrown by one of the batch upload attempts, if success is false
   */
  MLCLIENT_API virtual void batchOperationComplete(const DocumentUriSet out_uris,bool success,std::exception problem) = 0;
};

/**
 * \brief Manages a batched document upload/write operation
 *
 * \since 8.0.2
 */
class DocumentBatchWriter {
public:
  /**
   * \brief Constructs a DocumentBatchWriter that wraps the provided IConnection instance
   * \since 8.0.2
   * \param conn The pointer to an IConnection subclass instance. In, but not OWNS. (This class never delete's this pointer)
   */
  MLCLIENT_API DocumentBatchWriter(IConnection* conn);
  /**
   * \brief The DELETED copy constructor
   */
  MLCLIENT_API DocumentBatchWriter(const DocumentBatchWriter& other) = delete;
  /**
   * \brief The destructor
   */
  MLCLIENT_API ~DocumentBatchWriter();

  /**
   * \brief Assigns a set of documents ready for upload.
   *
   * \note These can hold FileDocumentContent instances, and thus are only loaded during batch request creation (efficient)
   *
   * \since 8.0.2
   *
   * \param set The DocumentSet to upload to MarkLogic
   */
  MLCLIENT_API void assignDocuments(DocumentSet&& set);

  /**
   * \brief Sets the parameters for this batch
   *
   * \note Defaults to 5 parallel tasks, each holding 10 documents, with mode of PER_BATCH transactions.
   *
   * \note parallelTasks performs a lot of work before the (thin) call to perform a REST request. Each Connection instance
   * only ever executes one REST request at a time - never in parallel - so be aware of that when loading content. This
   * restriction may be removed in future versions.
   *
   * \since 8.0.2
   *
   * \param parallelTasks The number of paralleltasks to use
   * \param batchSize The number of documents to submit in each batch (also submits their metadata)
   * \param mode The batch mode to use
   */
  MLCLIENT_API void setBatchParameters(const int parallelTasks,const int batchSize,const TransactionMode& mode);
  /**
   * \brief Returns the number of parallel tasks being used
   *
   * \return The number of parallel tasks
   */
  MLCLIENT_API const int getParallelTasks() const;
  /**
   * \brief Returns the number of documents sent per batch
   *
   * \return Documents per batch
   */
  MLCLIENT_API const int getBatchSize() const;
  /**
   * \brief Returns the transaction mode used
   *
   * \return The TransactionMode in use
   */
  MLCLIENT_API const TransactionMode getMode() const;

  /**
   * \brief Adds a listener for batch events
   *
   * \param notifiable the IBatchNotifiable listener to add
   */
  MLCLIENT_API void addBatchListener(IBatchNotifiable* notifiable);
  /**
   * \brief Removes a listener for batch events
   *
   * \param notifiable the IBatchNotifiable listener to remove
   */
  MLCLIENT_API void removeBatchListener(IBatchNotifiable* notifiable);

  /**
   * \brief Begins the batch operation
   *
   * \note This is where the underlying tasks are created and allocated to threads
   */
  MLCLIENT_API void send();
  /**
   * \brief Cancels the batch operation
   *
   * \note Some tasks may be in flight still when this is called. They still run to completion.
   */
  MLCLIENT_API void stop();

  /**
   * \brief Causes the calling thread to wait for the completion of all batches assigned to all parallel tasks
   *
   * Useful for simple synchronous batch updates
   */
  MLCLIENT_API void wait() const;

  /**
   * \brief Has this class ran to completion?
   *
   * \return A boolean as to whether we ran to completion (true) or not
   */
  MLCLIENT_API const bool isComplete() const;

  /**
   * \brief Has this class been cancelled?
   * \return A boolean as to whether we were cancelled (true) or not
   */
  MLCLIENT_API const bool isCancelled() const;

  /**
   * \brief Are all asynchronous operations completed?
   *
   * \note This class can still be working after stop() has been called. E.g. if a batch upload request is in progress
   *
   * \return A boolean as to whether this class is now finished
   */
  MLCLIENT_API const bool isFinished() const;

  /**
   * \brief Returns the current progress data for this class
   *
   * \note This is currently an Overall progress, not for the last X seconds.
   *
   * \return The current Progress of the batch upload.
   */
  MLCLIENT_API const Progress getProgress() const;
private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};

} // end namespace utilities

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHWRITER_HPP_ */
