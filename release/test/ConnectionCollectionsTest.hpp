
#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include <string>

#ifndef __Scratch__ConnectionCollectionsTest__
#define __Scratch__ConnectionCollectionsTest__

using namespace mlclient;

class ConnectionCollectionsTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionCollectionsTest);
    CPPUNIT_TEST(testListTopLevelCollections);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testListTopLevelCollections(void);
private:
  IConnection* ml;
};

#endif /* defined(__Scratch__ConnectionCollectionsTest__) */
