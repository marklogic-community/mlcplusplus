//
//  MLCPlusPlus.cpp
//  MLCPlusPlus
//
//  Created by Adam Fowler on 04/Jun/2014.
//  Copyright (c) 2014 __MARKLOGIC__. All rights reserved.
//

#include "MLCPlusPlus.h"

Connection* Connection::_instance = nullptr;

Connection::Connection(void) {
    ;
}

Connection* Connection::Instance(void) {
    if (Connection::_instance == nullptr) {
        Connection::_instance = new Connection();
    }
    return Connection::_instance;
}

void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password) {
  // TODO
}
