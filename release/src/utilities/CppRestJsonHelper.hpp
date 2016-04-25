/*
 * CppRestJsonHelper.hpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_CPPRESTJSONHELPER_HPP_
#define SRC_UTILITIES_CPPRESTJSONHELPER_HPP_

// I don't mind exposing these in an optional helper class
#include <cpprest/http_client.h>
#include "../DocumentContent.hpp"

namespace mlclient {

namespace utilities {

/**
 * This class provides utility functions to handle JSON data
 */
class CppRestJsonHelper {
public:
  CppRestJsonHelper() = delete;
  ~CppRestJsonHelper() = delete;

  // DocumentContent conversion
  static DocumentContent& toDocument(const web::json::value json);
  static web::json::value fromDocument(const DocumentContent& doc);

  // Response conversion
  static web::json::value fromResponse(const Response& resp);

};

} // end utilities namespace

} // end mlclient namespace

#endif /* SRC_UTILITIES_CPPRESTJSONHELPER_HPP_ */
