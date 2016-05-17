/*
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
  //std::map<std::string,std::string>::iterator& iterator();
  const std::string& getHeader(const std::string& header) const;
  const std::map<std::string,std::string>& getHeaders() const;
  void clear();

private:
  std::map<std::string,std::string> mHeaders; // no point hiding - we have a compile time dependency on std::map from setHeaders()
};

} // end namespace mlclient

#endif /* defined SRC_INTERNALS_HTTPHEADERS_HPP_ */
