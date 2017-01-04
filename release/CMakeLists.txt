# 2.8.2 and above can handle openssl letter versions (E.g. 1.0.1h), which is required to get fixed version of openssl
cmake_minimum_required (VERSION 2.8.2)
project (mlclient)


# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file

# EDITABLE SETTINGS BEGIN

set (mlclient_VERSION_MAJOR 8)
set (mlclient_VERSION_MINOR 0)
set (mlclient_VERSION_REVISION 3)

# EDITABLE SETTINGS END

# POLICY SETTING OVERRIDES
set(CMAKE_MACOSX_RPATH 1)

# SYSTEM DETECTION


# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules )


# SYSTEM DETECTION

# Platform (not compiler) specific settings
if(IOS)

  # The cxx_flags must be set here, because the ios-cmake toolchain file unfortunately sets "-headerpad_max_install_names" which is not a valid clang flag.
  set(CMAKE_CXX_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

  set(BUILD_SHARED_LIBS OFF)
elseif(UNIX) # This includes OSX
  #find_package(Boost COMPONENTS system thread locale regex filesystem REQUIRED)
  #find_package(Threads REQUIRED)
  #find_package(OpenSSL REQUIRED)

  option(BUILD_SHARED_LIBS "Build shared Libraries." ON)
  #SET(GLOG_LIB libglog.so)
  SET(CPPREST_LIB libcpprest.so)
  SET(LIBSSL_LIB /usr/lib/x86_64-linux-gnu/libssl.so)
  SET(LIBCRYPTO_LIB /usr/lib/x86_64-linux-gnu/libcrypto.so)
elseif(WIN32)
  option(BUILD_SHARED_LIBS "Build shared Libraries." ON)

  add_definitions(-DUNICODE)

  if(NOT BUILD_SHARED_LIBS)
    # This causes cmake to not link the test libraries separately, but instead hold onto their object files.
    set(TEST_LIBRARY_TARGET_TYPE OBJECT)
  endif()

  set(LIB lib)
else()
  message("-- Unsupported Build Platform.")
endif()

# Universal binary only makes sense on OSX
IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    OPTION (OSX_UNIVERSAL "Build an OSX universal binary" OFF)
    IF (OSX_UNIVERSAL)
        message("-- Building Mac OS X Universal Binary")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch i386 -arch x86_64")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -arch i386 -arch x86_64")
    ENDIF ()
    #SET(GLOG_LIB "libglog.dylib")
    SET(CPPREST_LIB libcpprest.dylib)
    SET(LIBSSL_LIB libssl.dylib)
    SET(LIBCRYPTO_LIB libcrypto.dylib)
ENDIF ()



message ("-- Checking compiler ID: ${CMAKE_CXX_COMPILER_ID}" )

# Compiler (not platform) specific settings
if(( ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") OR IOS)
  message("-- Setting clang options")

  # Casablanca fix for versions before 2.7.0 (CLang issue)
  add_definitions("-Wno-error=unused-local-typedefs")
  # NOT IN CLang - add_definitions("-Wnounused-local-typedefs")

  set(WARNINGS "-Wall -Wextra -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls")
  set(OSX_SUPPRESSIONS "-Wno-overloaded-virtual -Wno-sign-conversion -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-char-subscripts -Wno-switch -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-unused-value -Wno-unknown-warning-option -Wno-return-type-c-linkage -Wno-unused-function -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-reorder")
  set(WARNINGS "${WARNINGS} ${OSX_SUPPRESSIONS}")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wno-return-type-c-linkage -Wno-unneeded-internal-declaration -D_GLIBCXX_USE_NANOSLEEP")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
elseif( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
  message("-- Setting gcc options")

  set(WARNINGS "-Wall -Wextra -Wunused-parameter -Wcast-align -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls -Wunreachable-code")
  set(LINUX_SUPPRESSIONS "-Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-function -Wno-char-subscripts -Wno-switch -Wno-unused-but-set-parameter -Wno-deprecated -Wno-unused-value -Wno-unused-local-typedefs")

  set(WARNINGS "${WARNINGS} ${LINUX_SUPPRESSIONS}")
  set(LD_FLAGS "${LD_FLAGS} -Wl,-z,defs")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing -D_GLIBCXX_USE_NANOSLEEP")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  message("-- Setting msvc options")
  set(WARNINGS)
else()
  message("-- Unknown compiler, success is doubtful.")
  message("CMAKE_CXX_COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")
endif()

message("-- Build Type: " ${CMAKE_BUILD_TYPE} )
if( ${CMAKE_BUILD_TYPE} MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  add_definitions(-D_DEBUG)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()


set(mlclient_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)



# DEPENDENCY DETECTION

# Boost (Includes system, thread, locale, regex and filesystem components by default - we need thread only)
set(Boost_USE_STATIC_LIBS   ON)
find_package (Boost REQUIRED COMPONENTS thread log-mt log_setup-mt filesystem )


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
  ${mlclient_INCLUDE_DIR}
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
  ${Boost_LOG-MT_LIBRARY}
  ${Boost_LOG_SETUP-MT_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK}
  #${GLOG_LIB}
  ${LIBSSL_LIB}
  ${LIBCRYPTO_LIB}
  ${CPPREST_LIB}
)

link_directories(/usr/lib /usr/local/lib /usr/local/opt/openssl/lib )


IF (WITH_LOGGING)
  message("-- Enabling logging")
else()
  message("-- NOT enabling logging")
endif()


add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)
add_subdirectory(doxygen)
