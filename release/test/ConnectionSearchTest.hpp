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
 *
 * ConnectionSearchTest.hpp
 *
 *  Created on: 10 May 2016
 *      Author: adamfowler
 */

#ifndef TEST_CONNECTIONSEARCHTEST_HPP_
#define TEST_CONNECTIONSEARCHTEST_HPP_

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"


using namespace mlclient;

class ConnectionSearchTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionSearchTest);
    CPPUNIT_TEST(testEmptySearch);
    CPPUNIT_TEST(testQueryText);
    CPPUNIT_TEST(testWordQuery);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testEmptySearch(void);
  void testQueryText(void);
  void testWordQuery(void);
private:
  IConnection* ml;
  std::string json;
  std::string xml;
  std::string jsonUri;
  std::string xmlUri;
};


#endif /* TEST_CONNECTIONSEARCHTEST_HPP_ */
