/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//
//  ConnectionDocumentCrudTest.hpp
//  Scratch
//
//  Created by Adam Fowler on 27/Nov/2015.
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

    CPPUNIT_TEST(testSaveText);
    CPPUNIT_TEST(testGetText);
    CPPUNIT_TEST(testDeleteText);
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

  void testSaveText(void);
  void testGetText(void);
  void testDeleteText(void);
private:
  IConnection* ml;
  std::string json;
  std::string xml;
  std::string text;
  std::string jsonUri;
  std::string xmlUri;
  std::string textUri;
};

#endif /* defined(__Scratch__ConnectionDocumentCrudTest__) */
