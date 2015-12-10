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

#ifndef __Scratch__ConnectionDocumentCrudTest__
#define __Scratch__ConnectionDocumentCrudTest__

using namespace mlclient;

class ConnectionDocumentCrudTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(ConnectionDocumentCrudTest);
    CPPUNIT_TEST(TestGetJson);
    //CPPUNIT_TEST(TestSaveJson);
    //CPPUNIT_TEST(TestSaveAllJson);
    CPPUNIT_TEST_SUITE_END();
public:
    void TestGetJson(void);
    //void TestSaveJson(void);
    //void TestSaveAllJson(void);
};

#endif /* defined(__Scratch__ConnectionDocumentCrudTest__) */
