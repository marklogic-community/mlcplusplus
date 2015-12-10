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
  }
  return os;
}

}
