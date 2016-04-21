/*

 */



#include "ResponseCodes.hpp"

#include "MLCPlusPlus.hpp"

namespace mlclient {

std::ostream& operator << (std::ostream& os, const ResponseType& rt) {
  switch(rt) {
  case ResponseType::BINARY:
    os << "ResponseType::BINARY";
    break;
  case ResponseType::JSON:
    os << "ResponseType::JSON";
    break;
  case ResponseType::TEXT:
    os << "ResponseType::TEXT";
    break;
  case ResponseType::XML:
    os << "ResponseType::XML";
    break;
  case ResponseType::UNKNOWN:
    os << "ResponseType::UNKNOWN";
    break;
  }
  return os;
}

std::string& operator +(std::string& s, const ResponseType& rt) {
  static std::string allStr = "";
  static std::string& all = allStr;
  all.append(s);
  switch(rt) {
  case ResponseType::BINARY:
    all.append("ResponseType::BINARY");
    break;
  case ResponseType::JSON:
    all.append("ResponseType::JSON");
    break;
  case ResponseType::TEXT:
    all.append("ResponseType::TEXT");
    break;
  case ResponseType::XML:
    all.append("ResponseType::XML");
    break;
  default:
    all.append("ResponseType::UNKNOWN");
  }
  return all;
}

std::string& operator+(const char* orig,const ResponseType& rt) {
  static std::string oStr = std::string(orig);
  static std::string& o = oStr;
  static std::string& response = o + rt;
  return response;
}

}
