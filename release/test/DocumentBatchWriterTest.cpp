/**
 * \file DocumentBatchWriter.cpp
 *
 * \date 21 Aug 2016
 * \author adamfowler
 */


#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "DocumentBatchWriterTest.hpp"
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/DocumentSet.hpp"
#include "mlclient/Permission.hpp"
#include "mlclient/utilities/DocumentBatchWriter.hpp"
#include "mlclient/utilities/DocumentBatchHelper.hpp"
#include "mlclient/NoCredentialsException.hpp"
#include "mlclient/utilities/ResponseHelper.hpp"

#include <string>

#include "mlclient/logging.hpp"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(DocumentBatchWriterTest);

class UploadObserver : public mlclient::utilities::IBatchNotifiable {
public:
  UploadObserver() : ex() {
    ;
  }
  ~UploadObserver() {
    ;
  }

  void batchOperationComplete(const DocumentUriSet uris,bool success,std::exception exc) override {
    LOG(DEBUG) << "Written files in a batch (OK?: " << success << ") :-";
    for (auto& it : uris) {
      LOG(DEBUG) << "  " << it;
    }
      ex = exc;
      LOG(DEBUG) << "  Exception: " << exc.what();
  }

  std::exception ex;
};


void DocumentBatchWriterTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE DocumentBatchWriterTest::setUp";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void DocumentBatchWriterTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE DocumentBatchWriterTest::tearDown";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = nullptr;
}

void DocumentBatchWriterTest::testFolder(void) {
  TIMED_FUNC(testValues);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering DocumentBatchWriterTest::testFolder";

  UploadObserver obs;

  DocumentBatchWriter writer(ml);
  writer.addBatchListener(&obs);
  CollectionSet collections;
  collections.emplace_back("mlcpptest");
  PermissionSet perms;
  perms.emplace_back("admin",Capability::EXECUTE); // good test as this isn't normally default assigned

  DocumentSet set;

  DocumentBatchHelper::addFilesToDocumentSet("testdata/documents/recursive","testdata/documents/recursive",true,"/mlcpptest/",
      collections,perms,nullptr,set);

  LOG(DEBUG) << "DocumentBatchWriterTest: set size: " << set.size();

  long setSize = set.size(); // set is reassigned by the next line, move!

  writer.assignDocuments(std::move(set));

  writer.send();

  // now just wait for it to finish...

  writer.wait();

  LOG(DEBUG) << "Exception is blank?: " << (0 == strcmp("std::exception",obs.ex.what()));
  CPPUNIT_ASSERT_MESSAGE("Exception returned during batch write",(0 == strcmp("std::exception",obs.ex.what())));

  Progress p = writer.getProgress();
  LOG(DEBUG) << "Document set size: " << setSize << ", complete size: " << p.completed;
  LOG(DEBUG) << "Progress: Complete: " << p.completed << ", total: " << p.total << ", pct: " << p.percentageComplete;
  LOG(DEBUG) << "Progress: duration: " << p.duration << ", est remaining duration: " << p.durationEstimateRemaining;
  CPPUNIT_ASSERT_MESSAGE("Document set size not equal to completed size",(setSize == p.completed));

  CPPUNIT_ASSERT_MESSAGE("Writer not set to finished",writer.isFinished());
  CPPUNIT_ASSERT_MESSAGE("Writer set to cancelled",!writer.isCancelled());
  CPPUNIT_ASSERT_MESSAGE("Writer not set to complete",writer.isComplete());
}


