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
//  ConnectionRawHttpTest.hpp
//  Scratch
//
//  Created by Adam Fowler on 15/Nov/2016.
//

#include <cppunit/Test.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include <string>

#ifndef __Scratch__ConnectionRawHttpTest__
#define __Scratch__ConnectionRawHttpTest__

using namespace mlclient;

class ConnectionRawHttpTest : public CppUnit::TestCase {
  CPPUNIT_TEST_SUITE(ConnectionRawHttpTest);
    CPPUNIT_TEST(testDoPost);
  CPPUNIT_TEST_SUITE_END();
public:
  void setUp();
  void tearDown();

  void testDoPost(void);
private:
  IConnection* ml;
};

#endif /* defined(__Scratch__ConnectionRawHttpTest__) */
