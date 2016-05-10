//
//  MLCPlusPlus.cpp
//  MLCPlusPlus
//
//  Created by Adam Fowler on 04/Jun/2014.
//  Copyright (c) 2014 __MARKLOGIC__. All rights reserved.
//

#include "mlclient.hpp"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

namespace mlclient {
int runOnce() {
    LOG(INFO) << "Registering logger [mlclient]";
    el::Loggers::getLogger("mlclient");

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
    el::Loggers::reconfigureLogger("performance", performanceConf);
    el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat); // ensures performance numbers are always quoted as seconds, never formatted

    return 0;
}

int runOnceHelper = runOnce();


} // end namespace mlclient
