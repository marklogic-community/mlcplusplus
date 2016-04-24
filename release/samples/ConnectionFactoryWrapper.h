/*
 * A header file to provide a C wrapping of the ConnectionFactory C++ class
 */
#include "ConnectionWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

// member/static wrapper functions
CConnection* ml_samples_connectionfactory_getConnection();


#ifdef __cplusplus
}
#endif
