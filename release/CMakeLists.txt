cmake_minimum_required (VERSION 2.8)
project (mlclient)

# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file

# SYSTEM DETECTION

# Boost (Includes system, thread, locale, regex and filesystem components by default)
find_package (Boost REQUIRED COMPONENTS filesystem system thread atomic chrono random regex)

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
  /usr/local/lib/libpugixml.a
)

link_directories(/usr/lib /usr/local/lib /usr/local/opt/openssl/lib )

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)
