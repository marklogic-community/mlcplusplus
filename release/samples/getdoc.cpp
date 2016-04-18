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

    const Response& response = ml->getDocument("/some/doc.json");

    ResponseType rt = response.GetResponseType();
    std::cout << "Response type: " << rt << std::endl;
    if (ResponseType::JSON == rt) { std::cout << "This is /some/doc.json: " << std::endl << response.Json() << std::endl; }
    // TODO XML support

    std::cout << "getdoc complete" << std::endl;
    return 0;
}

