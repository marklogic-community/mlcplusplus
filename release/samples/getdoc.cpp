//
//  main.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/27/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <iostream>

#include "MLCPlusPlus.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "ResponseCodes.hpp"
#include "ConnectionFactory.hpp"

int main(int argc, const char * argv[])
{
  using namespace mlclient;

  std::cout << "Running getdoc..." << std::endl;

  Connection* ml = ConnectionFactory::getConnection();

  std::string uri = "/some/doc.json";
  if (argc > 1) {
    uri = std::string(argv[1]);
  }

  const std::unique_ptr<Response> rp = ml->getDocument(uri); // MUST keep local reference to unique_ptr for this to work!!!
  Response* response = rp.get();

  ResponseType rt = response->getResponseType();
  std::cout << "Response type: " << rt << std::endl;
  if (ResponseType::JSON == rt) { std::cout << "This is JSON doc " << uri << ": " << std::endl << response->asJson() << std::endl; }
  if (ResponseType::XML == rt) { std::cout << "This is XML doc " << uri << ": " << std::endl;response->asXml().save(std::cout); std::cout << std::endl; }

  std::cout << "getdoc complete" << std::endl;
  return 0;
}

