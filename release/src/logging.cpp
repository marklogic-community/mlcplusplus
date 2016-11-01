/**
 * \file logging.cpp
 *
 * \date 2016-08-11
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <mlclient/logging.hpp>

#ifndef _WIN32
//#include <glog/logging.h>
#endif

#include <ostream>
#include <cstring>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/attributes/current_process_name.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

//#include <mlclient/internals/G3OutSink.hpp>
//#include <mlclient/ext/g3log/filesink.hpp>

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
//nullbuf null_obj;
//wnullbuf wnull_obj;
//std::ostream cnull(&null_obj);
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
//#ifndef _WIN32
  //if (true == config.toerr) {
  //  FLAGS_logtostderr = 1;
  //} else {
  //  FLAGS_logtostderr = 0;
  //}
  // reconfigure logger with the new settings
  //FLAGS_log_dir = config.folder;

  // TODO handle log level

  if (!configured) {
    //google::InitGoogleLogging("mlclient"); // BUG CANNOT CALL THIS MORE THAN ONCE! - no need, just redefine globals
    //google::InstallFailureSignalHandler();

/*
    //using namespace g3;
    std::cout << "Configuring logging" << std::endl;


    std::unique_ptr<g3::LogWorker> worker{ g3::LogWorker::createLogWorker() };
    std::cout << "Got worker" << std::endl;
    //auto defaultHandler = worker->addDefaultLogger("mlclient", config.folder); // <-- sits there forever
    std::cout << "added default logger" << std::endl;

    // logger is initialized
    g3::initializeLogging(worker.get());
    std::cout << "initialized logging" << std::endl;

    //auto defHandle = worker->addSink(std2::make_unique<g3::FileSink>("mlclient", config.folder, "g3log"), &g3::FileSink::fileWrite);
    //std::cout << "Added file sink" << std::endl;
    auto sinkHandle = worker->addSink(std2::make_unique<G3OutSink>(), &G3OutSink::ReceiveLogMessage);
    std::cout << "Added cout sink" << std::endl;

    g3::only_change_at_initialization::setLogLevel(DEBUG, true);
    std::cout << "Set Debug" << std::endl;
    */


    
    boost::log::add_common_attributes();
    /*
        boost::shared_ptr< logging::core > core = boost::log::core::get();
        core->add_global_attribute("LineID", attrs::counter< unsigned int >(1));
        core->add_global_attribute("TimeStamp", attrs::local_clock());
        core->add_global_attribute("Scope", attrs::named_scope());
        */
        //boost::log::core::get()->add_global_attribute("Scope", boost::log::attributes::named_scope()); // Causes segfault
        boost::log::core::get()->add_global_attribute("Process",boost::log::attributes::current_process_name());

      boost::log::add_file_log(
        boost::log::keywords::target = config.folder,
        boost::log::keywords::file_name = "mlclient_%N.log",                     /*< file name pattern >*/
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        boost::log::keywords::format = "[%TimeStamp%] %Process% %ProcessID% %ThreadID% %Message%"                                 /*< log record format >*/
      );

      // Use this to also log to console: boost::log::add_console_log(std::cout);

      /*if (config.level == "INFO") {
        boost::log::core::get()->set_filter
        (
            boost::log::trivial::severity >= boost::log::trivial::info
        );
      } else {*/
      // TODO fix the detection of _DEBUG as its currently ignored
        boost::log::core::get()->set_filter
        (
            boost::log::trivial::severity >= boost::log::trivial::debug
        );
      //}




    configured = true;
  }
//#endif
}

} // end namespace mlclient
