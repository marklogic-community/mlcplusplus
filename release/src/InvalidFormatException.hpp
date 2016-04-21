//
//  InvalidFormatException.h
//
//  Created by Adam Fowler on 18 Apr 2016
//  Copyright (c) 2016 Adam Fowler. All rights reserved.
//

#ifndef INVALIDFORMATEXCEPTION_H
#define INVALIDFORMATEXCEPTION_H

#include <exception>
#include <stdexcept>

#include "MLCPlusPlus.hpp"

namespace mlclient {

class InvalidFormatException : public std::exception {
public:
  virtual const char* what() const throw() override;
};

}

#endif /* defined(INVALIDFORMATEXCEPTION_H) */
