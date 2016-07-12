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
 *
 * HttpHeaders.cpp
 *
 *  Created on: 17 May 2016
 *      Author: adamfowler
 */

#include "mlclient/HttpHeaders.hpp"

#include "mlclient/ext/easylogging++.h"

#include <map>
#include <string>


namespace mlclient {

HttpHeaders::HttpHeaders() : mHeaders() {
  //TIMED_FUNC(HttpHeaders_defaultConstructor); // DO NOT LOG AS THIS CLASS IS STATICALLY INITIALISED!!! CAUSES SEG FAULT!!!
}

void HttpHeaders::setHeaders(const std::map<std::string,std::string>& headers) {
  TIMED_FUNC(HttpHeaders_setHeaders);
  mHeaders = headers;
}
void HttpHeaders::setHeader(const std::string& header,const std::string& value) {
  TIMED_FUNC(HttpHeaders_setHeader);
  mHeaders.insert(std::pair<std::string,std::string>(header,value));
}

const std::string& empty = "";

const std::string& HttpHeaders::getHeader(const std::string& header) const {
  TIMED_FUNC(HttpHeaders_getHeader);
  std::map<std::string,std::string>::const_iterator iter = mHeaders.find(header);
  if (mHeaders.end() == iter) {
    return empty;
  }
  return iter->second;
}

const std::map<std::string,std::string>& HttpHeaders::getHeaders() const {
  TIMED_FUNC(HttpHeaders_getHeaders);
  return mHeaders;
}

void HttpHeaders::clear() {
  TIMED_FUNC(HttpHeaders_clear);
  mHeaders.clear();
}

} // end namespace mlclient

