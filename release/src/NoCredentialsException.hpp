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

/**
 * \brief Indicates that you have not provided the Connection with any credentials, or the credentials are invalid.
 */
class NoCredentialsException : public std::exception {
public:
  virtual const char* what() const throw() override;
};

}

#endif /* defined(NOCREDENTIALSEXCEPTION_H) */
