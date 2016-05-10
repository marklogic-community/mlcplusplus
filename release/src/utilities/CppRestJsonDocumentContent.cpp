/**
 * \file CppRestJsonDocumentContent.cpp
 * \since 8.0.0
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Implements a JSON document content instance for use with Microsoft's cpprest API
 * \date 2016-05-01
 */

#include <cpprest/http_client.h>
#include "CppRestJsonDocumentContent.hpp"
#include <iostream>
#include <string>

namespace mlclient {

namespace utilities {

class CppRestJsonDocumentContent::Impl {
public:
  Impl() {
    value = web::json::value();
  };
  ~Impl() {
    ;
  };
  web::json::value value;
};

CppRestJsonDocumentContent::CppRestJsonDocumentContent() : mImpl(new Impl) {
  ;
}

CppRestJsonDocumentContent::~CppRestJsonDocumentContent() {
  delete mImpl;
}

std::ostream* CppRestJsonDocumentContent::getStream() {
  std::ostringstream* os = new std::ostringstream;
  (*os) << mImpl->value;
  return os;
}

web::json::value& CppRestJsonDocumentContent::getJson() {
  return mImpl->value;
}

void CppRestJsonDocumentContent::setContent(const web::json::value& json) {
  mImpl->value = json;
}


} // end utilities namespace

} // end mlclient namespace
