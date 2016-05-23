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
 * HttpHeaders.hpp
 *
 *  Created on: 17 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_INTERNALS_HTTPHEADERS_HPP_
#define SRC_INTERNALS_HTTPHEADERS_HPP_

#include <string>
#include <map>

namespace mlclient {

class HttpHeaders {
public:
  HttpHeaders();
  ~HttpHeaders() = default;
  void setHeaders(const std::map<std::string,std::string>& headers);
  void setHeader(const std::string& header,const std::string& value);
  const std::string& getHeader(const std::string& header) const;
  const std::map<std::string,std::string>& getHeaders() const;
  void clear();

private:
  std::map<std::string,std::string> mHeaders; // no point hiding via PIMPL idiom - we have a compile time dependency on std::map from setHeaders()
};

} // end namespace mlclient

#endif /* defined SRC_INTERNALS_HTTPHEADERS_HPP_ */
