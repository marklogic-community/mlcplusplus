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

    const Response& response = ml->getDocument(uri);

    ResponseType rt = response.GetResponseType();
    std::cout << "Response type: " << rt << std::endl;
    if (ResponseType::JSON == rt) { std::cout << "This is JSON doc " << uri << ": " << std::endl << response.Json() << std::endl; }
    if (ResponseType::XML == rt) { std::cout << "This is XML doc " << uri << ": " << std::endl;response.Xml().save(std::cout); std::cout << std::endl; }

    std::cout << "getdoc complete" << std::endl;
    return 0;
}

