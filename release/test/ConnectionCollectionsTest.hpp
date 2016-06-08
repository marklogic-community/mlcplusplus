
#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "NoCredentialsException.hpp"

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
