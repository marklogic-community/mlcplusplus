/*
 * CppRestJsonDocumentContent.hpp
 *
 * \date 2016-05-01
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \brief Provides a convenience Json DocumentContent wrapper for use with Microsoft's CPP REST API
 */

#ifndef SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_
#define SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_

#include "../DocumentContent.hpp"

namespace mlclient {

namespace utilities {

class CppRestJsonDocumentContent : public TextDocumentContent {
public:
  CppRestJsonDocumentContent();
  virtual ~CppRestJsonDocumentContent();

  // overridden from base class
  void setContent(const web::json::value& json);
  std::ostream* getStream();

  // the below is unique to this class
  web::json::value& getJson();

private:
  class Impl; // forward declaration
  Impl* mImpl;

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_ */
