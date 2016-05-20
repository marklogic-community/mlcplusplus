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

#include "utilities/CppRestJsonHelper.hpp"
#include "utilities/PugiXmlHelper.hpp"
#include <iostream>

#include "Connection.hpp"
#include "Response.hpp"
#include "ConnectionFactory.hpp"

int main(int argc, const char * argv[])
{
  using namespace mlclient;
  using namespace mlclient::utilities;

  std::cout << "Running getdoc..." << std::endl;

  Connection* ml = ConnectionFactory::getConnection();

  std::string uri = "/some/doc.json";
  if (argc > 1) {
    uri = std::string(argv[1]);
  }

  const Response* rp = ml->getDocument(uri); // MUST keep local reference to unique_ptr for this to work!!!

  ResponseType rt = rp->getResponseType();
  std::cout << "Response type: " << rt << std::endl;
  if (ResponseType::JSON == rt) { std::cout << "This is JSON doc " << uri << ": " << std::endl << CppRestJsonHelper::fromResponse(*rp) << std::endl; }
  if (ResponseType::XML == rt) { std::cout << "This is XML doc " << uri << ": " << std::endl;PugiXmlHelper::fromResponse(*rp)->save(std::cout); std::cout << std::endl; }

  std::cout << "getdoc complete" << std::endl;
  return 0;
}

