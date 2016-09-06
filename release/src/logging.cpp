/**
 * \file logging.cpp
 *
 * \date 2016-08-11
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <mlclient/logging.hpp>

#ifndef _WIN32
#include <glog/logging.h>
#endif

#include <ostream>
#include <cstring>

 // For sharing easyloggingpp configuration
 /*
 el::base::type::StoragePointer sharedLoggingRepository() {
 return el::Helpers::storage();
 }*/

 /*
 #ifndef WITH_LOGGING
 #ifndef ELPP_DISABLE_LOGS
 #define ELPP_DISABLE_LOGS 1
 #endif
 #ifndef ELPP_NO_DEFAULT_LOG_FILE
 #define ELPP_NO_DEFAULT_LOG_FILE 1
 #endif
 #endif



 #ifdef _WIN32
 #undef ELPP_DISABLE_LOGS
 #undef ELPP_NO_DEFAULT_LOG_FILE
 #endif
 */

 /*
 #ifndef ELPP_PERFORMANCE_MICROSECONDS
 #define ELPP_PERFORMANCE_MICROSECONDS 1
 #endif

 */
 /*
 #ifndef ELPP_STACKTRACE_ON_CRASH
 #define ELPP_STACKTRACE_ON_CRASH 1
 #endif
 */
 /*
 #ifndef ELPP_THREAD_SAFE
 #define ELPP_THREAD_SAFE 1
 #endif

 #define ELPP_AS_DLL // Tells Easylogging++ that it's used for DLL
 #define ELPP_EXPORT_SYMBOLS // Tells Easylogging++ to export symbols
 */

 /*
 #ifndef ELPP_FORCE_USE_STD_THREAD
 #define ELPP_FORCE_USE_STD_THREAD 1
 #endif
 */

 /*
 #ifndef ELPP_EXPERIMENTAL_ASYNC
 #define ELPP_EXPERIMENTAL_ASYNC 1
 #endif
 */

 /*
 #include "mlclient/logging.hpp"

 INITIALIZE_EASYLOGGINGPP

 #undef TIMED_FUNC
 #undef TIMED_SCOPE
 #undef LOG
 #undef CLOG
 #define TIMED_FUNC //
 #define TIMED_SCOPE //
 #define LOG //
 #define CLOG //
 */

 // in a concrete .cpp
#ifdef _WIN32
nullbuf null_obj;
//wnullbuf wnull_obj;
std::ostream cnull(&null_obj);
//std::wostream wcnull(&wnull_obj);
#endif


namespace mlclient {


void libraryLoggingInit() {
  LoggingConfiguration config;
  config.level = "INFO";
  config.toerr = false;

#ifdef _WIN32
  config.folder = "z:\\Documents\\marklogic\\git\\mlodbc\\logs\\";
#else
  config.folder = "/Users/adamfowler/Documents/marklogic/git/mlcplusplus/logs";
#endif
  reconfigureLoggingSettings(config);

/*
#ifndef _WIN32
  FLAGS_logtostderr = 0;
#ifdef _WIN32
  FLAGS_log_dir = "z:\\Documents\\marklogic\\git\\mlodbc\\logs\\";
#else
  FLAGS_log_dir = "/Users/adamfowler/Documents/marklogic/git/mlcplusplus/logs";
#endif
  google::InitGoogleLogging("mlclient");
  google::InstallFailureSignalHandler();
#endif
  */

    //LOG(INFO) << "Registering logger [mlclient]";
  //std::cout << "in mlclient::runOnce()" << std::endl;
    //el::Logger* logger = el::Loggers::getLogger("mlclient"); // TODO use this and configure it
  /*
    el::Configurations defaultConf;
    defaultConf.setToDefault();
//#ifndef WITH_LOGGING
//    defaultConf.setGlobally(el::ConfigurationType::Enabled,"false");
//#endif
    // Values are always std::string
    defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line %msg");
    defaultConf.setGlobally(el::ConfigurationType::Filename, "z:\\Documents\\marklogic\\git\\mlodbc\\logs\\windows.log");
    defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "false");
    // default logger uses default configurations
    el::Loggers::reconfigureLogger("default", defaultConf);

    el::Configurations performanceConf;
    performanceConf.setToDefault();
//#ifndef WITH_LOGGING
//    performanceConf.set(el::Level::Info, el::ConfigurationType::Enabled,"false");
//#endif
    performanceConf.set(el::Level::Info, el::ConfigurationType::Format, "%msg");
    performanceConf.set(el::Level::Info, el::ConfigurationType::ToStandardOutput, "false");
    performanceConf.set(el::Level::Info, el::ConfigurationType::Filename,"z:\\Documents\\marklogic\\git\\mlodbc\\logs\\performance.log"); /// TODO make output file include version number of this upcoming release
    el::Loggers::reconfigureLogger("performance", performanceConf);
    el::Loggers::addFlag(el::LoggingFlag::FixedTimeFormat); // ensures performance numbers are always quoted as seconds, never formatted
    */
}

void reconfigureLogging(int argc,const char * argv[]) {
  LoggingConfiguration config;
  config.folder = "./logs";
#ifdef _DEBUG
  config.level = "DEBUG";
#else
  config.level = "INFO";
#endif

  for (int i = 0;i < argc;i++) {
    if (0 == strcmp("--log-folder",argv[i]) && i < (argc - 1)) {
      config.folder = argv[i + 1];
      ++i; // skip value
    }
    if (0 == strcmp("--log-level",argv[i]) && i < (argc - 1)) {
      config.level = argv[i + 1];
      ++i; // skip value
    }
    if (0 == strcmp("--log-stderr",argv[i]) && i < (argc - 1) && 0==strcmp("true",argv[i + 1])) {
      config.toerr = true;
      ++i; // skip value
    }
  }

  reconfigureLoggingSettings(config);
}

void reconfigureLoggingSettings(const LoggingConfiguration& config) {
  static bool configured = false;
  // The following is a hack as google logging hates Win32 currently
#ifndef _WIN32
  //if (true == config.toerr) {
  //  FLAGS_logtostderr = 1;
  //} else {
    FLAGS_logtostderr = 0;
  //}
  // reconfigure logger with the new settings
  FLAGS_log_dir = config.folder;

  // TODO handle log level

  if (!configured) {
    google::InitGoogleLogging("mlclient"); // BUG CANNOT CALL THIS MORE THAN ONCE! - no need, just redefine globals
    google::InstallFailureSignalHandler();
    configured = true;
  }
#endif
}

} // end namespace mlclient
