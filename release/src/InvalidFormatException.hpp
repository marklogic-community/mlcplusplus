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


namespace mlclient {

/**
 * \class InvalidFormatException
 * \since 8.0.0
 * \date 2016-04-24
 *
 * \brief Indicates an issue with parsing content
 *
 * Indicates that the given content type specific operation failed or could not proceed as the underlying content
 * is not of the correct type, or is corrupted. E.g. you've use an XML function on a JSON document.
 */
class InvalidFormatException : public std::exception {
public:
  /**
   * \brief An override of the what() function to provide a better description of the issue.
   */
  virtual const char* what() const throw() override;
};

}

#endif /* defined(INVALIDFORMATEXCEPTION_H) */
