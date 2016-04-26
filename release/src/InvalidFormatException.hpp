//
//  InvalidFormatException.h
//
//  Created by Adam Fowler on 18 Apr 2016
//  Copyright (c) 2016 Adam Fowler. All rights reserved.
//

#ifndef INVALIDFORMATEXCEPTION_H
#define INVALIDFORMATEXCEPTION_H

#include "mlclient.hpp"
#include <exception>
#include <stdexcept>


namespace mlclient {

/**
 * Indicates that the given content type specific operation failed or could not proceed as the underlying content
 * is not of the correct type, or is corrupted. E.g. you've use an XML function on a JSON document.
 */
class InvalidFormatException : public std::exception {
public:
  virtual const char* what() const throw() override;
};

}

#endif /* defined(INVALIDFORMATEXCEPTION_H) */
