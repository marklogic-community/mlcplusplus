/*
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
 */
//
//  main.cpp
//  Created by Paul Hoehne on 5/27/14.
//

#include <mlclient/logging.hpp>



#include <iostream>
#include "ConnectionFactory.hpp"
#include "mlclient/Document.hpp"
#include "mlclient/DocumentSet.hpp"
#include "mlclient/Permission.hpp"
#include "mlclient/utilities/DocumentBatchWriter.hpp"
#include "mlclient/utilities/DocumentBatchHelper.hpp"
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>



using namespace mlclient;
using namespace mlclient::utilities;

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



int main(int argc, const char * argv[])
{

  //mlclient::reconfigureLogging(argc,argv);

  std::cout << "in main" << std::endl;

  bool wasSuccessful = false;

  /*
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line %msg");
  //defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "false");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);

  el::Configurations performanceConf;
  performanceConf.setToDefault();
  performanceConf.set(el::Level::Info, el::ConfigurationType::Format, "%msg");
  performanceConf.set(el::Level::Info,el::ConfigurationType::Filename,"../performance.log"); /// TODO make output file include version number of this upcoming release
  //performanceConf.set(el::Level::Info,el::ConfigurationType::MillisecondsWidth,"6");
  el::Loggers::reconfigureLogger("performance", performanceConf);
  el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat); // ensures performance numbers are always quoted as seconds, never formatted
*/

  LOG(INFO) << "In tests main";

  /// TODO delete performance.csv before running tests

  //CppUnit::TestResult controller;

  //CppUnit::TestResultCollector collector;
  //controller.addListener(&collector);

  //CppUnit::BriefTestProgressListener progress;
  //controller.addListener(&progress);

  LOG(INFO) << "Performing out of cppunit test content set up";


  IConnection* ml = ConnectionFactory::getConnection();

  // load test content from folders

  UploadObserver obs;

  DocumentBatchWriter writer(ml);
  writer.addBatchListener(&obs);
  CollectionSet collections;
  collections.emplace_back("zoo");
  collections.emplace_back("mlcpptest");
  PermissionSet perms;
  //perms.emplace_back("admin",Capability::READ); // good test as this isn't normally default assigned

  DocumentSet set;

  DocumentBatchHelper::addFilesToDocumentSet(
    "data/zoojson","data/zoojson",true,"/zoo/",
      collections,perms,nullptr,set);

  LOG(DEBUG) << "Load zoo: set size: " << set.size();

  long setSize = set.size(); // set is reassigned by the next line, move!

  writer.assignDocuments(std::move(set));

  writer.send();

  // now just wait for it to finish...

  writer.wait();

  LOG(DEBUG) << "Exception is blank?: " << (0 == strcmp("std::exception",obs.ex.what()));
  Progress p = writer.getProgress();
  LOG(DEBUG) << "Document set size: " << setSize << ", complete size: " << p.completed;
  LOG(DEBUG) << "Progress: Complete: " << p.completed << ", total: " << p.total << ", pct: " << p.percentageComplete;
  LOG(DEBUG) << "Progress: duration: " << p.duration << ", est remaining duration: " << p.durationEstimateRemaining;




  LOG(INFO) << "Performing tests";

  try {
    CppUnit::TestResult controller;

    CppUnit::TestResultCollector result;
    controller.addListener( &result );

    CppUnit::BriefTestProgressListener progressListener;
    controller.addListener( &progressListener );

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    runner.run( controller );
  } catch (std::exception& e) {
    LOG(DEBUG) << "EXCEPTION RUNNING TESTS: " << e.what();
  }
  return true;
}
