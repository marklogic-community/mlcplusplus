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
//  main.cpp
//  Created by Paul Hoehne on 5/27/14.
//

#include <iostream>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>

#ifndef ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_PERFORMANCE_MICROSECONDS 1
#endif

#include "easylogging++.h"


INITIALIZE_EASYLOGGINGPP


int main(int argc, const char * argv[])
{
  START_EASYLOGGINGPP(argc, argv);

  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line %msg");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);

  el::Configurations performanceConf;
  performanceConf.setToDefault();
  performanceConf.set(el::Level::Info, el::ConfigurationType::Format, "%msg");
  performanceConf.set(el::Level::Info,el::ConfigurationType::Filename,"../performance.log"); /// TODO make output file include version number of this upcoming release
  //performanceConf.set(el::Level::Info,el::ConfigurationType::MillisecondsWidth,"6");
  el::Loggers::reconfigureLogger("performance", performanceConf);
  el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat); // ensures performance numbers are always quoted as seconds, never formatted

  LOG(INFO) << "In tests main";

  /// TODO delete performance.csv before running tests

  //CppUnit::TestResult controller;

  //CppUnit::TestResultCollector collector;
  //controller.addListener(&collector);

  //CppUnit::BriefTestProgressListener progress;
  //controller.addListener(&progress);

  CppUnit::TextUi::TestRunner runner;
  runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
  bool wasSuccessful = runner.run( "", false );
  return wasSuccessful;
}

