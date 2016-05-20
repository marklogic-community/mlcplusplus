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
//
//  NoCredentialsException.h
//  Created by Paul Hoehne on 5/29/14.
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
