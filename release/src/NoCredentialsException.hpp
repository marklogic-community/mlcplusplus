//
//  NoCredentialsException.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef __Scratch__NoCredentialsException__
#define __Scratch__NoCredentialsException__

#include <exception>
#include <stdexcept>

#include "MLCPlusPlus.hpp"

namespace mlclient {

class NoCredentialsException : public std::exception {
public:
    virtual const char* what() const throw() override;
};

}

#endif /* defined(__Scratch__NoCredentialsException__) */
