/*
 * XmlHelper.hpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_PUGIXMLHELPER_HPP_
#define SRC_UTILITIES_PUGIXMLHELPER_HPP_

#include <pugixml.hpp>
#include "../Response.hpp"

namespace mlclient {

namespace utilities {

class PugiXmlHelper {
public:
  XmlHelper() = delete;
  ~XmlHelper() = delete;

  // DocumentContent conversion
  static DocumentContent& toDocument(const pugi::xml_document& dc);
  static pugi::xml_document fromDocument(const DocumentContent& dc);

  // Response conversion
  static pugi::xml_document& fromResponse(const Response& resp);

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_PUGIXMLHELPER_HPP_ */
