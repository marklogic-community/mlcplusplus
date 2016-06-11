cmake_minimum_required (VERSION 2.8)
project (mlclient)

# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file

# EDITABLE SETTINGS BEGIN

set (mlclient_VERSION_MAJOR 8)
set (mlclient_VERSION_MINOR 0)
set (mlclient_VERSION_REVISION 2)

# EDITABLE SETTINGS END

# SYSTEM DETECTION

# Boost (Includes system, thread, locale, regex and filesystem components by default)
find_package (Boost REQUIRED COMPONENTS filesystem system thread atomic chrono random regex)


  if(APPLE AND NOT OPENSSL_ROOT_DIR)
    # Prefer a homebrew version of OpenSSL over the one in /usr/lib
    file(GLOB OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/*)
    # Prefer the latest (make the latest one first)
    list(REVERSE OPENSSL_ROOT_DIR)
  endif()
  # This should prevent linking against the system provided 0.9.8y
  set(_OPENSSL_VERSION "")
  find_package(OpenSSL 1.0.0 REQUIRED)

include_directories (AFTER
  ${OPENSSL_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
  /usr/local/opt/openssl/include
  )

set(Casablanca_LIBRARY ${LIB}cpprest)
set(Casablanca_LIBRARIES ${Casablanca_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Boost_ATOMIC_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
  ${Boost_RANDOM_LIBRARY}
  ${Boost_REGEX_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK}
)

link_directories(/usr/lib /usr/local/lib /usr/local/opt/openssl/lib )

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)
add_subdirectory(doxygen)
