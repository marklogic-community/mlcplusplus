/**
 * \file logging.hpp
 *
 * \date 2016-07-28
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Defines implementation-independent logging functionality for mlcplusplus
 */

#ifndef INCLUDE_MLCLIENT_LOGGING_HPP_
#define INCLUDE_MLCLIENT_LOGGING_HPP_

#include <mlclient/mlclient.hpp>

#include <ostream>
#include <sstream>
#include <string>

//#ifndef _WIN32

//#include <mlclient/ext/g3log/g3log.hpp>
//#include <mlclient/ext/g3log/logworker.hpp>
//#include <mlclient/internals/G3OutSink.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/mutable_constant.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/attributes/current_process_name.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/exception.hpp> // enables exception handling
#include <boost/log/support/std_regex.hpp> // C++11 regex support

#include <boost/date_time/posix_time/posix_time_types.hpp>


// BEGIN LOGGING IMPL
// THIS SECTION DEFINES THE ACTUAL LOGGING IMPLEMENTATION AND SETTINGS

// END LOGGING IMPL

// BEGIN IMPL OVERRIDES
// SOMETIMES IMPLEMENTATIONS DONT SUPPORT MLCLIENT LOGGING FEATURES - OVERRIDES EXIST HERE TO WORK AROUND THOSE

// END IMPL OVERRIDES


// BEGIN LOGGING MACROS
// THE ACTUAL HIGH LEVEL LOGGING FUNCTIONALITY
// TODO enact Debug verbose levels too and link to google vlog(0) to vlog(3)
//#undef LOG
//#undef LOG_DEBUG
//#undef LOG_INFO
//#undef LOG_ERROR
//#undef LOG_WARN
//#define LOG_DEBUG COMPACT_GOOGLE_LOG_ ## INFO.stream()
//#define LOG_INFO COMPACT_GOOGLE_LOG_ ## INFO.stream()
//#define LOG_ERROR COMPACT_GOOGLE_LOG_ ## ERROR.stream()
//#define LOG_WARN COMPACT_GOOGLE_LOG_ ## WARN.stream()
//#define LOG(lvl) COMPACT_GOOGLE_LOG_ ## INFO.stream()

//#else
// Windows sucks at supporting Google Log
//template<typename Ch, typename Traits = std::char_traits<Ch> >
//struct basic_nullbuf : std::basic_streambuf<Ch, Traits> {
  //typedef std::basic_streambuf<Ch, Traits> base_type;
  //typedef typename base_type::int_type int_type;
  //typedef typename base_type::traits_type traits_type;

  //virtual int_type overflow(int_type c) {
  //  return traits_type::not_eof(c);
  //}
//};

// convenient typedefs
//MLCLIENT_API typedef basic_nullbuf<char> nullbuf;
//MLCLIENT_API typedef basic_nullbuf<wchar_t> wnullbuf;

//MLCLIENT_API typedef std::ostream MLLOGSTREAM;

// buffers and streams
// in some .h
//MLCLIENT_API extern std::ostream cnull;
//extern std::wostream wcnull;

//#define LOG(lvl) cnull

//#endif

namespace mlclient {
  /*
MLCLIENT_API class LogHolder {
public:
  LogHolder();

  boost::log::sources::severity_logger<boost::log::trivial::severity_level>& getInstance();
  static LogHolder* get();

  static void reset();

protected:
  boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;
  static LogHolder* inst;
};


  boost::log::sources::severity_logger<boost::log::trivial::severity_level>& getLogger();

  */
}

/*
boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;

// New macro that includes severity, filename and line number
#define CUSTOM_LOG \
   BOOST_LOG_STREAM_WITH_PARAMS( \
      (lg), \
         (set_get_attrib("File", path_to_filename(__FILE__))) \
         (set_get_attrib("Line", __LINE__)) \
         (set_get_attrib("Function", __func__)) \
         (::boost::log::keywords::severity = (boost::log::trivial::debug)) \
   )

// Set attribute and return the new value
template<typename ValueType>
ValueType set_get_attrib(const char* name, ValueType value) {
   auto attr = boost::log::attribute_cast<boost::log::attributes::mutable_constant<ValueType>>(boost::log::core::get()->get_thread_attributes()[name]);
   attr.set(value);
   return attr.get();
}
*/
// Convert file path to only the filename

MLCLIENT_API std::string path_to_filename(std::string path);




  typedef boost::posix_time::ptime time_type;
  //! Current time source
#if defined(BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK)
  typedef boost::posix_time::microsec_clock clock_source;
#else
  typedef boost::posix_time::second_clock clock_source;
#endif // defined(BOOST_DATE_TIME_HAS_HIGH_PRECISION_CLOCK)

class ScopeLogger {
public:
  MLCLIENT_API ScopeLogger(std::string name,boost::log::sources::severity_logger<boost::log::trivial::severity_level> logger);
  MLCLIENT_API ~ScopeLogger();
protected:
  clock_source clock;
  time_type started;
  boost::log::sources::severity_logger<boost::log::trivial::severity_level> logger;
  std::string name;


};


#define DEBUG debug
#define INFO info

#define LOG_LOCATION                            \
  boost::log::attribute_cast<boost::log::attributes::mutable_constant<int>>(boost::log::core::get()->get_global_attributes()["Line"]).set(__LINE__); \
  boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(boost::log::core::get()->get_global_attributes()["File"]).set(path_to_filename(__FILE__)); \
  boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(boost::log::core::get()->get_global_attributes()["Function"]).set(__func__);


//#define LOG(DEBUG) BOOST_LOG_TRIVIAL(debug)
#define LOG(lvl) LOG_LOCATION; BOOST_LOG_SEV(boost::log::trivial::logger::get(), boost::log::trivial::severity_level::lvl)


// The following redefined a low-level non formatted log function, as per easylogging++.h
#define CLOG(lvl) LOG(lvl)

#define TIMED_FUNC(id) BOOST_LOG_NAMED_SCOPE(#id)
#define TIMED_SCOPE(id,scopename) BOOST_LOG_NAMED_SCOPE(scopename)
//#define ENTRANCE_LOG(a,b,c,d) LOG(info) << "Entered " + a + b + c + d;
//#define DEBUG_ENTRANCE_LOG(a,b,c,d) LOG(debug) << "Debug Entered" + a + b + c + d;


/*
#define LOG(DEBUG) LOG_LOCATION;                                               \
  BOOST_LOG_SEV(_log, boost::log::trivial::severity_level::debug)

#define LOG_LOCATION                            \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<int>>(boost::log::core::get()->get_global_attributes()["Line"]).set(__LINE__); \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(boost::log::core::get()->get_global_attributes()["File"]).set(__FILE__); \
    boost::log::attribute_cast<boost::log::attributes::mutable_constant<std::string>>(boost::log::core::get()->get_global_attributes()["Function"]).set(__func__);
*/

//#define LOG(INFO) BOOST_LOG_TRIVIAL(info)

// END LOGGING MACROS

// BEGIN LOGGING INIT
// DEFINED THE INITIALISATION OF THE LOGGING

// END LOGGING INIT

namespace mlclient {

/**
 * \brief LoggingConfiguration to use
 *
 * Use alongside \link reconfigureLogging() \endlink .
 */
struct LoggingConfiguration {
  /** \brief The folder to log to **/
  std::string folder = "";

  /** \brief The level. INFO or DEBUG strings **/
  std::string level = "INFO";

  /** Log to stdout too? */
  bool toerr = false;
};

/*
 * \brief Initialises logging, once, globally, for this library only.
 *
 * \note Normally called once via a global function in mlclient.cpp.
 *
 * \since 8.0.2
 */
MLCLIENT_API void libraryLoggingInit();

/**
 * \brief Reconfigure logging from command line args
 *
 * --log-folder "/some/folder/location" Specifies the folder within which logging is done (and enables file logging), disabled by default
 * --log-level INFO|DEBUG Specify either INFO or DEBUG log level. Defaults to INFO in Release builds, or DEBUG in Debug builds.
 * --log-stdout true Specify log messages should also be copied to stdout (the terminal, typically). Defaults to false
 *
 * \since 8.0.2
 */
MLCLIENT_API void reconfigureLogging(int argc,const char * argv[]);

/**
 * \brief Reconfigures logging from a LoggingConfiguration struct
 *
 * \param[in] config The LoggingConfiguration to use
 */
MLCLIENT_API void reconfigureLoggingSettings(const LoggingConfiguration& config);

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_LOGGING_HPP_ */
