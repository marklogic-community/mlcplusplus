//
//  main.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/27/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

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

