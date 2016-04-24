#include "ConnectionWrapper.h"
#include "ConnectionFactoryWrapper.h"
#include "ConnectionFactory.hpp"

extern "C" {

CConnection* ml_samples_connectionfactory_getConnection() {
  return (CConnection*)ConnectionFactory::getConnection();
}

}
