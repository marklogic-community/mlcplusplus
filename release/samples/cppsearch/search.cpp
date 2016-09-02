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
 *  search.cpp
 *  Created by Adam Fowler on 02 Sep 2016.
 */

#include "ConnectionFactory.hpp"

#include <mlclient/utilities/SearchBuilder.hpp>

#include <mlclient/Connection.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/logging.hpp>

#include <iostream>

int main(int argc, const char * argv[])
{
  using namespace mlclient;
  using namespace mlclient::utilities;

  mlclient::reconfigureLogging(argc,argv);

  LOG(DEBUG) << "Running search...";
  if (argc < 2) {
    std::cout << "Must specify a search string text as first parameter" << std::endl;
    std::cout << "Usage: " << argv[0] << " <querytext>" << std::endl;
    std::cout << "Example Usage: " << argv[0] << " wibble" << std::endl;
    return 1;
  }

  Connection* ml = ConnectionFactory::getConnection();
  SearchDescription desc;
  desc.setQueryText(argv[1]);
  Response* response = ml->search(desc);

  LOG(DEBUG) << "  Response Type: " << response->getResponseType();
  LOG(DEBUG) << "  Response Code: " << response->getResponseCode();
  LOG(DEBUG) << "  Response Content: " << response->getContent();

  std::cout << "Search Results:-" << std::endl;
  std::cout << response->getContent() << std::endl;

  std::cout << "search complete" << std::endl;
  delete response;
  delete ml;
  return 0;
}

