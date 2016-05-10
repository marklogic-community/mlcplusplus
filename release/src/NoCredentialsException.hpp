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
 * \class NoCredentialsException
 * \since 8.0.0
 * \date 2016-04-24
 *
 * \brief Indicates that you have not provided the Connection with any credentials, or the credentials are invalid.
 */
class NoCredentialsException : public std::exception {
public:
  /**
   * \brief An override of the what() function to provide a better description of the issue.
   */
  virtual const char* what() const throw() override;
};

}

#endif /* defined(NOCREDENTIALSEXCEPTION_H) */
