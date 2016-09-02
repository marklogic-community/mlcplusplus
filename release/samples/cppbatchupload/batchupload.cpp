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
 *
 *  main.cpp
 *  Created by Adam Fowler on 02 Sep 2016.
 */

#include "ConnectionFactory.hpp"

#include <mlclient/utilities/DocumentBatchWriter.hpp>
#include <mlclient/utilities/DocumentBatchHelper.hpp>

#include <mlclient/Connection.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/logging.hpp>

#include <iostream>

class UploadObserver : public mlclient::utilities::IBatchNotifiable {
public:
  UploadObserver() : ex(nullptr) {
    ;
  }
  ~UploadObserver() {
    ;
  }

  void batchOperationComplete(const std::vector<std::string> uris,bool success,std::exception* exc) override {
    std::cout << "Written files in a batch (OK?: " << success << ") :-" << std::endl;
    for (auto& it : uris) {
      std::cout << "  " << it << std::endl;
    }
    if (exc) {
      ex = exc;
      std::cout << "  Exception: " << exc->what() << std::endl;
    }
  }

  std::exception* ex;
};

int main(int argc, const char * argv[])
{
  using namespace mlclient;
  using namespace mlclient::utilities;

  mlclient::reconfigureLogging(argc,argv);

  LOG(DEBUG) << "Running batchupload...";
  if (argc < 3) {
    std::cout << "Must specify the root load folder as first parameter" << std::endl;
    std::cout << "Must specify the collection as second parameter" << std::endl;
    std::cout << "Usage: " << argv[0] << ": <folder> <collection>" << std::endl;
    std::cout << "Example Usage: " << argv[0] << ": ./some/folder mydocs" << std::endl;
    return 1;
  }

  Connection* ml = ConnectionFactory::getConnection();



  UploadObserver obs;

  DocumentBatchWriter writer(ml);
  writer.addBatchListener(&obs);
  std::vector<std::string> collections;
  collections.emplace_back(argv[2]);
  std::vector<Permission> perms;
  perms.emplace_back("admin",Capability::EXECUTE); // good test as this isn't normally default assigned

  DocumentSet set;

  DocumentBatchHelper::addFilesToDocumentSet(argv[1],argv[1],true,"/cppbatchupload/",
      collections,perms,nullptr,set);

  LOG(DEBUG) << "DocumentBatchWriterTest: set size: " << set.size();

  long setSize = set.size(); // set is reassigned by the next line, move!

  writer.assignDocuments(std::move(set));

  writer.send();

  // now just wait for it to finish...

  writer.wait();

  std::cout << "Exception is nullptr?: " << (nullptr == obs.ex) << std::endl;

  Progress p = writer.getProgress();
  std::cout << "Document set size: " << setSize << ", complete size: " << p.completed << std::endl;
  std::cout << "Progress: Complete: " << p.completed << ", total: " << p.total << ", pct: " << p.percentageComplete << std::endl;
  std::cout << "Progress: duration: " << p.duration << ", est remaining duration: " << p.durationEstimateRemaining << std::endl;

  std::cout << "batch upload complete" << std::endl;
  return 0;
}

