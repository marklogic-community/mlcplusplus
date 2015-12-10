//
//  main.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/27/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <iostream>

using namespace mlclient;

int main(int argc, const char * argv[])
{
    Connection& ml = ConnectionFactory::getConnection();

    Response response = ml.getDocument("/some/doc.json");

    ResponseType rt = response.GetResponseType();
    if (ResponseType::JSON == rt) { std::cout << "This is /some/doc.json: " << std::endl << response.Json() << std::endl; }
    // TODO XML support

    return 0;
}

