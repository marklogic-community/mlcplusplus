//
//  ConnectionDocumentCrudTest.hpp
//  Scratch
//
//  Created by Adam Fowler on 27/Nov/2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "Connection.hpp"
#include "Response.hpp"
#include "DocumentContent.hpp"
#include "NoCredentialsException.hpp"

#include <string>

#ifndef __Scratch__ConnectionDocumentCrudTest__
#define __Scratch__ConnectionDocumentCrudTest__

using namespace mlclient;

class ConnectionDocumentCrudTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionDocumentCrudTest);
    CPPUNIT_TEST(testSaveJson);
    CPPUNIT_TEST(testGetJson);
    CPPUNIT_TEST(testDeleteJson);
    CPPUNIT_TEST(testSaveXml);
    CPPUNIT_TEST(testGetXml);
    CPPUNIT_TEST(testDeleteXml);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testSaveJson(void);
  void testGetJson(void);
  void testDeleteJson(void);
  void testSaveXml(void);
  void testGetXml(void);
  void testDeleteXml(void);
private:
  Connection* ml;
  std::string json;
  std::string xml;
  std::string jsonUri;
  std::string xmlUri;
};

#endif /* defined(__Scratch__ConnectionDocumentCrudTest__) */
