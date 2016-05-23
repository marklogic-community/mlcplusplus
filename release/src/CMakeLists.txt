# 2.8.2 and above can handle openssl letter versions (E.g. 1.0.1h), which is required to get fixed version of openssl
cmake_minimum_required (VERSION 2.8.2)
project (mlclient)

# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file


#set (CMAKE_MODULE_PATH "../cmake/modules")


# SYSTEM DETECTION

# Platform (not compiler) specific settings
if(IOS)

  # The cxx_flags must be set here, because the ios-cmake toolchain file unfortunately sets "-headerpad_max_install_names" which is not a valid clang flag.
  set(CMAKE_CXX_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

  set(BUILD_SHARED_LIBS OFF)
elseif(UNIX) # This includes OSX
  find_package(Boost COMPONENTS system thread locale regex filesystem REQUIRED)
  find_package(Threads REQUIRED)
  #find_package(OpenSSL REQUIRED)

  option(BUILD_SHARED_LIBS "Build shared Libraries." ON)
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

# Casablanca fix for versions before 2.7.0 (CLang issue)
add_definitions("-Wno-error=unused-local-typedefs")
add_definitions("-Wnounused-local-typedefs")

# Compiler (not platform) specific settings
if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang") OR IOS)
  message("-- Setting clang options")

  set(WARNINGS "-Wall -Wextra -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls")
  set(OSX_SUPPRESSIONS "-Wno-overloaded-virtual -Wno-sign-conversion -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-char-subscripts -Wno-switch -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-unused-value -Wno-unknown-warning-option -Wno-return-type-c-linkage -Wno-unused-function -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-reorder")
  set(WARNINGS "${WARNINGS} ${OSX_SUPPRESSIONS}")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wno-return-type-c-linkage -Wno-unneeded-internal-declaration")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
  message("-- Setting gcc options")

  set(WARNINGS "-Wall -Wextra -Wunused-parameter -Wcast-align -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls -Wunreachable-code")
  set(LINUX_SUPPRESSIONS "-Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-function -Wno-char-subscripts -Wno-switch -Wno-unused-but-set-parameter -Wno-deprecated -Wno-unused-value -Wno-unused-local-typedefs")

  set(WARNINGS "${WARNINGS} ${LINUX_SUPPRESSIONS}")
  set(LD_FLAGS "${LD_FLAGS} -Wl,-z,defs")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(STRICT_CXX_FLAGS ${WARNINGS} "-Werror -pedantic")
else()
  message("-- Unknown compiler, success is doubtful.")
endif()



# Have CMake do a search and replace on the version numbers in our config.h file
configure_file (
  "${PROJECT_SOURCE_DIR}/mlclientConfig.h.in"
  "${PROJECT_BINARY_DIR}/mlclientConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find mlclientConfig.h
include_directories("${PROJECT_BINARY_DIR}")



# ML C++ own libraries
add_library (mlclient SHARED
    Connection.cpp
    mlclient.cpp
    NoCredentialsException.cpp
    HttpHeaders.cpp
    Response.cpp

    DocumentContent.cpp
    InvalidFormatException.cpp
    SearchDescription.cpp

    internals/AuthenticatingProxy.cpp
    internals/AuthorizationBuilder.cpp
    internals/Credentials.cpp
    internals/FakeConnection.cpp
    internals/MLCrypto.cpp

    ConnectionWrapper.cpp
    ResponseWrapper.cpp

    utilities/CppRestJsonHelper.cpp
    utilities/CppRestJsonDocumentContent.cpp
    utilities/PugiXmlHelper.cpp
)



# ML C++ dependencies

include_directories (BEFORE ../include )

# Casablanca
# Assume source in same directory as mlclient
#include_directories (AFTER
#  ${PROJECT_BINARY_DIR}/../../casablanca/Release/include
#  ${PROJECT_BINARY_DIR}/../../casablanca/Release/src/pch
#  )

# Open SSL - to find the cmake commands - TODO do we need this anymore?
set (OPENSSL_DIR "/usr/local/opt/openssl")

# Search OpenSSL
#find_package(PkgConfig REQUIRED)
#pkg_search_module(OPENSSL REQUIRED openssl)

#if( OPENSSL_FOUND )
#    include_directories(${OPENSSL_INCLUDE_DIRS})
#    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
#else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
#endif()

# TODO Use 1.0.1h explicitly to prevent MITM and other zero day attacks
#find_package (OpenSSL REQUIRED
# Following line seems REQUIRED on Mac OS X
#  PATHS /usr/local/opt/openssl
#  )
# NB That OpenSSL on the mac is very very old. Here is the 1.0.1h openssl info:-
#     LDFLAGS:  -L/usr/local/opt/openssl/lib
#     CPPFLAGS: -I/usr/local/opt/openssl/include

set (OPENSSL_INCLUDE_DIR "/usr/local/opt/openssl/include")
#set (OPENSSL_LIBRARIES "/usr/local/opt/openssl/lib/libssl.dylib")


# Now link our library to its dependencies
#target_link_libraries (mlclient
#  ${PROJECT_BINARY_DIR}/../../casablanca/build.release/Binaries/libcasablanca.dylib
#  ${OPENSSL_LIBRARIES}
#  ${Boost_LIBRARIES}
#  )

target_link_libraries (mlclient
    libcpprest.dylib
#    libcommon_utilities.dylib
    libssl.dylib
    libcrypto.dylib
    libpugixml.a
    ${Casablanca_LIBRARIES}
)




# Now build SWIG bindings

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

# SWIG Python

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${PYTHON_INCLUDE_PATH})

SET_SOURCE_FILES_PROPERTIES(mlclient-python.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(mlclient-python.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(mlclientpython python mlclient-python.i
    Connection.cpp
    mlclient.cpp
    NoCredentialsException.cpp
    HttpHeaders.cpp
    Response.cpp

    DocumentContent.cpp
    InvalidFormatException.cpp
    SearchDescription.cpp
)
SWIG_LINK_LIBRARIES(mlclientpython
    libcpprest.dylib
    libssl.dylib
    libcrypto.dylib
    libpugixml.a
    mlclient
    ${Casablanca_LIBRARIES}
    ${PYTHON_LIBRARIES}
)

# SWIG C#.NET

# Find C#
#find_package( CSharp REQUIRED )
#include( ${CSHARP_USE_FILE} )

#set(_build 0)
#set(_revision 0)




# SWIG -Go

#SET_SOURCE_FILES_PROPERTIES(mlclient-go.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(mlclient-go.i PROPERTIES SWIG_FLAGS "-includeall -cgo -intgosize 64")
#SWIG_ADD_MODULE(mlclient-go go mlclient-go.i
#    Connection.cpp
#    mlclient.cpp
#    NoCredentialsException.cpp
#    Response.cpp

#    DocumentContent.cpp
#    InvalidFormatException.cpp
#    SearchDescription.cpp
#)
#SWIG_LINK_LIBRARIES(mlclient-go
#    libcpprest.dylib
#    libcommon_utilities.dylib
#    libssl.dylib
#    libcrypto.dylib
#    libpugixml.a
#    ${Casablanca_LIBRARIES}
#)

# SWIG -Ruby

#SET_SOURCE_FILES_PROPERTIES(mlclient-ruby.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(mlclient-ruby.i PROPERTIES SWIG_FLAGS "-I/usr/local/include/ruby-2.2.0/ruby.h")
#SWIG_ADD_MODULE(mlclient-ruby ruby mlclient-ruby.i
#    Connection.cpp
#    mlclient.cpp
#    NoCredentialsException.cpp
#    Response.cpp
#
#    DocumentContent.cpp
#    InvalidFormatException.cpp
#    SearchDescription.cpp
#)
#set_source_files_properties( ${swig_generated_file_fullname}
#                             PROPERTIES COMPILE_FLAGS "-I/usr/local/include/ruby-2.2.0/ruby.h")
#SWIG_LINK_LIBRARIES(mlclient-ruby mlclient)



#SET( LIBMLCLIENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
#SET( RUBY_EXECUTABLE "ruby" )
#SET( RUBY_INCLUDE_PATH "/usr/local/include/ruby-2.2.0/ruby.h" )


#EXECUTE_PROCESS(COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print Config::CONFIG['vendorarchdir']" OUTPUT_VARIABLE RUBY_VENDOR_ARCH_DIR)

#MESSAGE(STATUS "Ruby executable: ${RUBY_EXECUTABLE}")
#MESSAGE(STATUS "Ruby vendor arch dir: ${RUBY_VENDOR_ARCH_DIR}")
#MESSAGE(STATUS "Ruby include path: ${RUBY_INCLUDE_PATH}")

#SET( SWIG_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/mlclient_ruby.cxx" )

#ADD_CUSTOM_COMMAND (
#   OUTPUT  ${SWIG_OUTPUT}
#   COMMAND ${CMAKE_COMMAND} -E echo_append "Creating wrapper code for ruby..."
#   COMMAND ${SWIG_EXECUTABLE} -c++ -ruby -autorename -o ${SWIG_OUTPUT} -I${LIBMLCLIENT_INCLUDE_DIR} ${SWIG_INPUT}
#   COMMAND ${CMAKE_COMMAND} -E echo "Done."
#   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.i
#)

#ADD_LIBRARY( mlclient-ruby SHARED ${SWIG_OUTPUT} )
#INCLUDE_DIRECTORIES( ${RUBY_INCLUDE_PATH} ${LIBMLCLIENT_INCLUDE_DIR} )

#SET_TARGET_PROPERTIES( mlclient-ruby PROPERTIES PREFIX "" OUTPUT_NAME "mlclient-ruby")

#TARGET_LINK_LIBRARIES( mlclient-ruby mlclient )
#TARGET_LINK_LIBRARIES( mlclient-ruby ${RUBY_LIBRARY} )

#INSTALL(TARGETS mlclient-ruby LIBRARY DESTINATION ${RUBY_VENDOR_ARCH_DIR})








# INSTALLATION
install (TARGETS mlclient LIBRARY DESTINATION lib)
install (FILES mlclient.h mlclient.hpp Response.hpp ResponseWrapper.h NoCredentialsException.hpp InvalidFormatException.hpp ConnectionWrapper.h Connection.hpp CWrapper.hpp CppRestJsonHelper.hpp PugiXmlHelper.hpp SearchDescription.hpp DocumentContent.hpp DESTINATION include)



# CPack installer

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MarkLogic C++ Client Library")
SET(CPACK_PACKAGE_VENDOR "MarkLogic Inc.")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${mlclient_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${mlclient_VERSION_MINOR}")
include (CPack)
