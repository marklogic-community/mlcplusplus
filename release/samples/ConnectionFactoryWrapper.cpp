#include "ConnectionWrapper.h"
#include "ConnectionFactoryWrapper.h"
#include "ConnectionFactory.hpp"

extern "C" {

CConnection* connectionfactory_getConnection() {
  return (CConnection*)ConnectionFactory::getConnection();
}

}
