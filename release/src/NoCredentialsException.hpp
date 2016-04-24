//
//  NoCredentialsException.h
//  Scratch
//
//  Created by Paul Hoehne on 5/29/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#ifndef NOCREDENTIALSEXCEPTION_H
#define NOCREDENTIALSEXCEPTION_H

#include "mlclient.hpp"
#include <exception>
#include <stdexcept>


namespace mlclient {

class NoCredentialsException : public std::exception {
public:
  virtual const char* what() const throw() override;
};

}

#endif /* defined(NOCREDENTIALSEXCEPTION_H) */
