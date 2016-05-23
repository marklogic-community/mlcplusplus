/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * \file InvalidFormatException.h
 *
 * \author Adam Fowler
 * \date 2016-04-18
 * \since 8.0.0
 */

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

} // end namespace mlclient

#endif /* defined(INVALIDFORMATEXCEPTION_H) */
