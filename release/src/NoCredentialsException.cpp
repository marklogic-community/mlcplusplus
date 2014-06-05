//
//  NoCredentialsException.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include "NoCredentialsException.hpp"

const char* NoCredentialsException::what(void) const throw() {
    return "No credentials found";
}