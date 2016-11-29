/*
 * DocumentTraversalTest.hpp
 *
 *  Created on: 30 Jul 2016
 *      Author: adamfowler
 */

#ifndef TEST_DOCUMENTTRAVERSALTEST_HPP_
#define TEST_DOCUMENTTRAVERSALTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"


using namespace mlclient;

class DocumentTraversalTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(DocumentTraversalTest);
  CPPUNIT_TEST(testJsonTraversal);
  CPPUNIT_TEST(testXmlTraversal);
  CPPUNIT_TEST(testSubDocumentExtraction);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testJsonTraversal(void);
  void testXmlTraversal(void);
  void testSubDocumentExtraction(void);

  void testResult(IDocumentNode* root);
  void testResultN(IDocumentNavigator* root);

private:
  IConnection* ml;
};





#endif /* TEST_DOCUMENTTRAVERSALTEST_HPP_ */
