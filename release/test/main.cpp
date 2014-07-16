//
//  main.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/27/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <iostream>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>

int main(int argc, const char * argv[])
{
    CppUnit::TestResult controller;
    
    CppUnit::TestResultCollector collector;
    controller.addListener(&collector);
    
    CppUnit::BriefTestProgressListener progress;
    controller.addListener(&progress);
    
    CppUnit::TestRunner::TestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);
    return 0;
}

