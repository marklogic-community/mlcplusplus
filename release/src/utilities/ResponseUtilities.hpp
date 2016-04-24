/*
 * ResponseUtilities.hpp
 *
 *  Created on: 24 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_RESPONSEUTILITIES_HPP_
#define SRC_UTILITIES_RESPONSEUTILITIES_HPP_

#include "../Response.hpp"

#include <pugixml.hpp>
#include <cpprest/json.h>

namespace mlclient {

namespace utilities {

class ResponseUtilities {
public:
  ResponseUtilities() = delete;
  ~ResponseUtilities() = delete;

  ///
  /// For XML responses, returns a document using the libxml2 library.
  ///
  /// \return The response document
  ///
  static const pugi::xml_document& asXml(const Response& resp);
  //void SetXml(const pugi::xml_document& doc);

  ///
  /// For JSON  responses, returns the document using the Casablanca JSON
  /// object represenation.
  ///
  /// \return The JSON object
  ///
  static const web::json::value asJson(const Response& resp); // uses copy semantics, not reference - peculiarity of the cpprest library

private:

};

}
}

#endif /* SRC_UTILITIES_RESPONSEUTILITIES_HPP_ */
