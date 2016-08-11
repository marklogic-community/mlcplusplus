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
 *  Created by Paul Hoehne on 27 May 2014.
 */

#include "ConnectionFactory.hpp"

#include <mlclient/utilities/CppRestJsonHelper.hpp>
#include <mlclient/utilities/PugiXmlHelper.hpp>

#include <mlclient/Connection.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/logging.hpp>

#include <iostream>

int main(int argc, const char * argv[])
{
  using namespace mlclient;
  using namespace mlclient::utilities;

  mlclient::reconfigureLogging(argc,argv);

  //std::cout << "Running getdoc..." << std::endl;
  LOG(DEBUG) << "Running getdoc...";

  Connection* ml = ConnectionFactory::getConnection();

  std::string uri = "/some/doc.json";
  if (argc > 1) {
    uri = std::string(argv[1]);
  }

  const Response* rp = ml->getDocument(uri); // MUST keep local reference to unique_ptr for this to work!!!

  ResponseType rt = rp->getResponseType();
  //std::cout << "Response type: " << rt << std::endl;
  LOG(DEBUG) << "Response type: " << rt;
  if (ResponseType::JSON == rt) {
    //std::cout << "This is JSON doc " << uri << ": " << std::endl << CppRestJsonHelper::fromResponse(*rp) << std::endl;
    LOG(DEBUG) << "This is JSON doc " << uri << ": " << std::endl << CppRestJsonHelper::fromResponse(*rp);
  }
  if (ResponseType::XML == rt) {
    //std::cout << "This is XML doc " << uri << ": " << std::endl;
    //PugiXmlHelper::fromResponse(*rp)->save(std::cout); std::cout << std::endl;
    LOG(DEBUG) << "This is XML doc " << uri << ": ";
    PugiXmlHelper::fromResponse(*rp)->save(LOG(DEBUG)); // TODO check this works as expected
  }

  //std::cout << "getdoc complete" << std::endl;
  LOG(DEBUG) << "getdoc complete";
  return 0;
}

