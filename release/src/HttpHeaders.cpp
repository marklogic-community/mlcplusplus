/*
 * HttpHeaders.cpp
 *
 *  Created on: 17 May 2016
 *      Author: adamfowler
 */

#include "HttpHeaders.hpp"

#include <map>
#include <string>

namespace mlclient {



HttpHeaders::HttpHeaders() : mHeaders() {
  ;
}

// default destructor

void HttpHeaders::setHeaders(const std::map<std::string,std::string>& headers) {
  mHeaders = headers;
}
void HttpHeaders::setHeader(const std::string& header,const std::string& value) {
  mHeaders.insert(std::pair<std::string,std::string>(header,value));
}
//std::map<std::string,std::string>::iterator& iterator();
const std::string& empty = "";
const std::string& HttpHeaders::getHeader(const std::string& header) const {
  std::map<std::string,std::string>::const_iterator iter = mHeaders.find(header);
  if (mHeaders.end() == iter) {
    return empty;
  }
  return iter->second;
}
const std::map<std::string,std::string>& HttpHeaders::getHeaders() const {
  return mHeaders;
}
void HttpHeaders::clear() {
  mHeaders.clear();
}

} // end namespace mlclient


