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
 * \file InvalidFormatException.cpp
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \created 2016-04-18
 * \since 8.0.0
 */

#include "InvalidFormatException.hpp"


namespace mlclient {

const char* InvalidFormatException::what(void) const throw() {
  return "Response is not of the required type for requested function/operation to be carried out";
}

} // end namepace mlclient
