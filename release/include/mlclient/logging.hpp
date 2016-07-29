/**
 * \file logging.hpp
 *
 * \date 2016-07-28
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Defines implementation-independent logging functionality for mlcplusplus
 */

#ifndef INCLUDE_MLCLIENT_LOGGING_HPP_
#define INCLUDE_MLCLIENT_LOGGING_HPP_

#include "mlclient/mlclient.hpp"

#include <ostream>
#include <sstream>
#include <string>

#ifndef _WIN32

#include <glog/logging.h>

// BEGIN LOGGING IMPL
// THIS SECTION DEFINES THE ACTUAL LOGGING IMPLEMENTATION AND SETTINGS

// END LOGGING IMPL

// BEGIN IMPL OVERRIDES
// SOMETIMES IMPLEMENTATIONS DONT SUPPORT MLCLIENT LOGGING FEATURES - OVERRIDES EXIST HERE TO WORK AROUND THOSE

// END IMPL OVERRIDES


// BEGIN LOGGING MACROS
// THE ACTUAL HIGH LEVEL LOGGING FUNCTIONALITY
// TODO enact Debug verbose levels too and link to google vlog(0) to vlog(3)
#undef LOG
#undef LOG_DEBUG
#undef LOG_INFO
#undef LOG_ERROR
#undef LOG_WARN
#define LOG_DEBUG COMPACT_GOOGLE_LOG_ ## INFO.stream()
#define LOG_INFO COMPACT_GOOGLE_LOG_ ## INFO.stream()
#define LOG_ERROR COMPACT_GOOGLE_LOG_ ## ERROR.stream()
#define LOG_WARN COMPACT_GOOGLE_LOG_ ## WARN.stream()
#define LOG(lvl) COMPACT_GOOGLE_LOG_ ## INFO.stream()

#else
// Windows sucks at supporting Google Log
template<typename Ch, typename Traits = std::char_traits<Ch> >
struct basic_nullbuf : std::basic_streambuf<Ch, Traits> {
  typedef std::basic_streambuf<Ch, Traits> base_type;
  typedef typename base_type::int_type int_type;
  typedef typename base_type::traits_type traits_type;

  virtual int_type overflow(int_type c) {
    return traits_type::not_eof(c);
  }
};

// convenient typedefs
typedef basic_nullbuf<char> nullbuf;
typedef basic_nullbuf<wchar_t> wnullbuf;

// buffers and streams
// in some .h
extern std::ostream cnull;
//extern std::wostream wcnull;

#define LOG(lvl) cnull

#endif


// The following redefined a low-level non formatted log function, as per easylogging++.h
#define CLOG(lvl) LOG(lvl)

#define TIMED_FUNC(id) //
#define TIMED_SCOPE(id,scopename) //
#define ENTRANCE_LOG(a,b,c,d) //
#define DEBUG_ENTRANCE_LOG(a,b,c,d) //

// END LOGGING MACROS

// BEGIN LOGGING INIT
// DEFINED THE INITIALISATION OF THE LOGGING

// END LOGGING INIT

namespace mlclient {
} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_LOGGING_HPP_ */
