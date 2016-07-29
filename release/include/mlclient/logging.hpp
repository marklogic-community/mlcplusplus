/**
 * \file logging.hpp
 *
 * \date 2016-07-28
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \brief Defines implementation-independent logging functionality for mlcplusplus
 */

#ifndef INCLUDE_MLCLIENT_LOGGING_HPP_
#define INCLUDE_MLCLIENT_LOGGING_HPP_

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
#define LOG_DEBUG COMPACT_GOOGLE_LOG_ ## INFO.stream()
#define LOG_INFO COMPACT_GOOGLE_LOG_ ## INFO.stream()
#define LOG_ERROR COMPACT_GOOGLE_LOG_ ## ERROR.stream()
#define LOG_WARN COMPACT_GOOGLE_LOG_ ## WARN.stream()
#define LOG(lvl) COMPACT_GOOGLE_LOG_ ## INFO.stream()


// The following redefined a low-level non formatted log function, as per easylogging++.h
#define CLOG(lvl) LOG(lvl)

#define TIMED_FUNC(id) //
#define TIMED_SCOPE(id,scopename) //

// END LOGGING MACROS

// BEGIN LOGGING INIT
// DEFINED THE INITIALISATION OF THE LOGGING

// END LOGGING INIT

namespace mlclient {
} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_LOGGING_HPP_ */
