# 2.8.2 and above can handle openssl letter versions (E.g. 1.0.1h), which is required to get fixed version of openssl
# Need modern modern commands (target_compile_features), so need to upgrade.
cmake_minimum_required (VERSION 3.5.0)

# Bring in some additional CMake modules.
include(WriteCompilerDetectionHeader)
include(CMakeDependentOption)

# POLICY SETTING OVERRIDES
set(CMAKE_MACOSX_RPATH 1)
# Indicate that we should organize by folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Expose the modules directories to CMake.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules )

# Declare the version information.
set(mlclient_VERSION_MAJOR 8)
set(mlclient_VERSION_MINOR 0)
set(mlclient_VERSION_REVISION 3)
set(mlclient_VERSION "${mlclient_VERSION_MAJOR}.${mlclient_VERSION_MINOR}.${mlclient_VERSION_REVISION}")

# Create a series of configuration options to tune portion of project that is in use.
option(WITH_LOGGING "Enable logging." OFF)
option(WITH_TESTS "Enable tests." OFF)
option(WITH_SAMPLES "Enable samples." OFF)
option(WITH_DOCS "Enable documentation." OFF)
option(WITH_SWIG "Enable SWIG." OFF)
# SWIG bindings require SWIG.
cmake_dependent_option(WITH_PYTHON "Use Python (with SWIG)" OFF "WITH_SWIG" OFF)
cmake_dependent_option(WITH_CSHARP "Use C# (with SWIG)" OFF "WITH_SWIG" OFF)

# Declare the project (and tag it with a version).
project(mlclient VERSION ${mlclient_VERSION})

# Platform (not compiler) specific settings
if(IOS)
	set(BUILD_SHARED_LIBS OFF)
elseif(UNIX) # This includes OSX

	option(BUILD_SHARED_LIBS "Build shared Libraries." ON)
	#SET(GLOG_LIB libglog.so)
	SET(CPPREST_LIB libcpprest.so)
	SET(LIBSSL_LIB /usr/lib/x86_64-linux-gnu/libssl.so)
	SET(LIBCRYPTO_LIB /usr/lib/x86_64-linux-gnu/libcrypto.so)
elseif(WIN32)
	option(BUILD_SHARED_LIBS "Build shared Libraries." ON)

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
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
elseif( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
	message("-- Setting gcc options")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message("-- Setting msvc options")
endif()

message("-- Build Type: " ${CMAKE_BUILD_TYPE})

# DEPENDENCY DETECTION

# Boost (Includes system, thread, locale, regex and filesystem components by default - we need thread only)
set(Boost_USE_STATIC_LIBS	 ON)
find_package (Boost REQUIRED COMPONENTS thread log log_setup filesystem )


if(APPLE AND NOT OPENSSL_ROOT_DIR)
	# Prefer a homebrew version of OpenSSL over the one in /usr/lib
	file(GLOB OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/*)
	# Prefer the latest (make the latest one first)
	list(REVERSE OPENSSL_ROOT_DIR)
endif()
# This should prevent linking against the system provided 0.9.8y
set(_OPENSSL_VERSION "")

find_package(OpenSSL 1.0.0 REQUIRED)

link_directories(/usr/lib /usr/local/lib /usr/local/opt/openssl/lib )


IF (WITH_LOGGING)
	message("-- Enabling logging")
else()
	message("-- NOT enabling logging")
endif()

# Add in the various source directories (order matters here, of course).
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)
add_subdirectory(doxygen)
