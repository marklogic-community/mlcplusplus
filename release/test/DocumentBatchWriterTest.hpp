/**
 * \file DocumentBatchWriterTest.hpp
 *
 * \date 21 Aug 2016
 * \author adamfowler
 */

#ifndef TEST_DOCUMENTBATCHWRITERTEST_HPP_
#define TEST_DOCUMENTBATCHWRITERTEST_HPP_




#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include <string>

using namespace mlclient;

class DocumentBatchWriterTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(DocumentBatchWriterTest);
    CPPUNIT_TEST(testFolder);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testFolder(void);
private:
  IConnection* ml;
};





#endif /* TEST_DOCUMENTBATCHWRITERTEST_HPP_ */
