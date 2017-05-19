# Use the multithreaded version of Boost.
set(Boost_USE_MULTITHREADED ON)
# Use the static version of Boost.
set(Boost_USE_STATIC_LIBS ON)
# Boost (Includes system, thread, locale, regex and filesystem components by default - we need thread only)
find_package (Boost REQUIRED COMPONENTS thread log log_setup filesystem)
# Note the properties of the package.
set_package_properties (Boost PROPERTIES
	TYPE REQUIRED
	URL "https://github.com/boostorg/boost"
	PURPOSE "Infrastructure for underlying C++")

# Special instructions for Apple to prefer homebrew version...
if (APPLE AND NOT OPENSSL_ROOT_DIR)
	# Prefer a homebrew version of OpenSSL over the one in /usr/lib
	file (GLOB OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/*)
	# Prefer the latest (make the latest one first)
	list (REVERSE OPENSSL_ROOT_DIR)
endif (APPLE AND NOT OPENSSL_ROOT_DIR)

# This should prevent linking against the system provided 0.9.8
set (_OPENSSL_VERSION "")
# Find OpenSSL for usage in this project.
find_package (OpenSSL 1.0.0 REQUIRED)
# Note the properties of the package.
set_package_properties (OpenSSL PROPERTIES
	TYPE REQUIRED
	URL "https://github.com/openssl/openssl"
	PURPOSE "Provides C++ TLS/SSL API")

# Find Casablanca/C++ REST SDK for usage in this project.
find_package (Casablanca)
# Note the properties of the package.
set_package_properties (Casablanca PROPERTIES
	TYPE REQUIRED
	URL "https://github.com/Microsoft/cpprestsdk"
	PURPOSE "Provides C++ REST API")

# Have CMake do a search and replace on the version numbers in our config.h file
configure_file (
	"${PROJECT_SOURCE_DIR}/mlclientConfig.h.in"
	"${PROJECT_BINARY_DIR}/mlclientConfig.h"
)

# Now build SWIG bindings
if (WITH_SWIG)
	# Find SWIG for usage in this project.
	find_package (SWIG)
	# Note the properties of the package.
	set_package_properties (SWIG PROPERTIES
		TYPE OPTIONAL
		URL "https://github.com/swig/swig"
		PURPOSE "Provides C++ interface to other high level languages")
endif (WITH_SWIG)

# ML C++ own libraries
add_library (mlclient SHARED

	"${PROJECT_SOURCE_DIR}/include/mlclient/CWrapper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/Connection.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/ConnectionWrapper.h"
	"${PROJECT_SOURCE_DIR}/include/mlclient/Document.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/DocumentContent.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/DocumentSet.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/HttpHeaders.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/InvalidFormatException.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/MarkLogicTypes.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/NoCredentialsException.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/Permission.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/Response.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/ResponseWrapper.h"
	"${PROJECT_SOURCE_DIR}/include/mlclient/SearchDescription.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/SearchResult.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/SearchResultSet.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/ValuesResult.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/ValuesResultSet.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/logging.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/mlclient.h"
	"${PROJECT_SOURCE_DIR}/include/mlclient/mlclient.hpp"

	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/AuthenticatingProxy.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/AuthorizationBuilder.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/Conversions.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/Credentials.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/FakeConnection.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/MLCrypto.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/internals/memory.hpp"

	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/CppRestJsonDocumentContent.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/CppRestJsonHelper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/DocumentBatchHelper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/DocumentBatchWriter.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/DocumentHelper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/PathNavigator.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/PugiXmlDocumentContent.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/PugiXmlHelper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/ResponseHelper.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/SearchBuilder.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/utilities/SearchOptionsBuilder.hpp"

	"${PROJECT_SOURCE_DIR}/include/mlclient/ext/pugixml/pugiconfig.hpp"
	"${PROJECT_SOURCE_DIR}/include/mlclient/ext/pugixml/pugixml.hpp"
	
	"${PROJECT_BINARY_DIR}/mlclientConfig.h"

	Connection.cpp
	mlclient.cpp
	logging.cpp
	NoCredentialsException.cpp
	HttpHeaders.cpp
	Response.cpp
	MarkLogicTypes.cpp

	DocumentContent.cpp
	InvalidFormatException.cpp
	SearchDescription.cpp
	SearchResult.cpp
	SearchResultSet.cpp
	ValuesResult.cpp
	ValuesResultSet.cpp

	Permission.cpp
	Document.cpp

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
	utilities/PugiXmlDocumentContent.cpp
	utilities/DocumentHelper.cpp
	utilities/DocumentBatchHelper.cpp
	utilities/DocumentBatchWriter.cpp
	utilities/ResponseHelper.cpp
	utilities/SearchBuilder.cpp
	utilities/SearchOptionsBuilder.cpp
	utilities/PathNavigator.cpp

	ext/pugixml/pugixml.cpp
)

# Pull in the parent libraries.
target_link_libraries (mlclient
	PUBLIC ${CASABLANCA_LIBRARIES}
	PRIVATE ${Boost_FILESYSTEM_LIBRARIES}
	PRIVATE ${Boost_SYSTEM_LIBRARIES}
	PRIVATE ${Boost_THREAD_LIBRARIES}
	PRIVATE ${Boost_ATOMIC_LIBRARIES}
	PRIVATE ${Boost_CHRONO_LIBRARIES}
	PRIVATE ${Boost_RANDOM_LIBRARIES}
	PRIVATE ${Boost_REGEX_LIBRARIES}
	PRIVATE ${Boost_LOG_LIBRARIES}
	PRIVATE ${Boost_LOG_SETUP_LIBRARIES}
	PUBLIC ${OPENSSL_LIBRARIES}
)

# Pull in the include directories.
target_include_directories (mlclient
	PUBLIC "${PROJECT_BINARY_DIR}"
	PUBLIC "${PROJECT_SOURCE_DIR}/include"
	PUBLIC "${OPENSSL_INCLUDE_DIR}"
	PUBLIC "${Boost_INCLUDE_DIRS}"
)

# Pull in the compiler definitions.
target_compile_definitions (mlclient
	# Not sure if this should be based on platform or compiler (MinGW?)
	PUBLIC "$<$<PLATFORM_ID:Windows>:UNICODE;_UNICODE>"
	PUBLIC "$<$<C_COMPILER_ID:MSVC>:>"
	PUBLIC "$<$<CXX_COMPILER_ID:MSVC>:>"
	PUBLIC "$<$<C_COMPILER_ID:Clang>:_GLIBCXX_USE_NANOSLEEP>"
	PUBLIC "$<$<CXX_COMPILER_ID:Clang>:_GLIBCXX_USE_NANOSLEEP>"
	PUBLIC "$<$<C_COMPILER_ID:GNU>:_GLIBCXX_USE_NANOSLEEP>"
	PUBLIC "$<$<CXX_COMPILER_ID:GNU>:_GLIBCXX_USE_NANOSLEEP>"
)

# Pull in the compiler options.
target_compile_options (mlclient
	PUBLIC "$<$<C_COMPILER_ID:MSVC>:>"
	PUBLIC "$<$<CXX_COMPILER_ID:MSVC>:>"
	PUBLIC "$<$<C_COMPILER_ID:Clang>:>"
	PUBLIC "$<$<CXX_COMPILER_ID:Clang>:>"
	PUBLIC "$<$<C_COMPILER_ID:GNU>:>"
	PUBLIC "$<$<CXX_COMPILER_ID:GNU>:>"
)

IF (SWIG_FOUND)
	INCLUDE(${SWIG_USE_FILE})
	#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
	SET(CMAKE_SWIG_FLAGS "")
	# SWIG Python
	IF (WITH_PYTHON)
		message( "-- Building SWIG Python bindings" )
		FIND_PACKAGE(PythonLibs)
		INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${PYTHON_INCLUDE_PATH} ${PROJECT_SOURCE_DIR}/include )
		SET_SOURCE_FILES_PROPERTIES(mlclient-python.i PROPERTIES CPLUSPLUS ON)
		#SET_SOURCE_FILES_PROPERTIES(mlclient-python.i PROPERTIES SWIG_FLAGS "-includeall")

		swig_add_library(mlclientpython
			LANGUAGE python
			SOURCES
				mlclient-python.i
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
			mlclient
			${PYTHON_LIBRARIES}
		)
		SET(CMAKE_SWIG_FLAGS "")
	else()
		message("-- NOT building SWIG Python wrapper (edit ./bin/build-deps-settings.sh|bat with WITH_PYTHON=1 to enable)")
	endif()
	# SWIG C#.NET
	IF (WITH_CSHARP)
		message( "-- Building SWIG CSharp bindings" )
		# Find C#
		find_package( CSharp REQUIRED )
		include( ${CSHARP_USE_FILE} )
		set(SWIG_MODULE_mlclientCSharp_TARGET_NAME "mlclientcs")

		set_source_files_properties ( mlclient-cs.i PROPERTIES CPLUSPLUS ON )
	
		# Make sure the nested directory structure exists
		set(CSHARP_SOURCE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CSharpSources CACHE INTERNAL "")
		set(CSHARP_BINARY_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CSharpBinaries CACHE INTERNAL "")
		file(MAKE_DIRECTORY ${CSHARP_SOURCE_DIRECTORY})
		file(MAKE_DIRECTORY ${CSHARP_BINARY_DIRECTORY})

		# Create swig target
		set(CMAKE_SWIG_OUTDIR ${CSHARP_SOURCE_DIRECTORY})
		set(CMAKE_SWIG_FLAGS -I${CMAKE_CURRENT_SOURCE_DIR} -namespace \"mlclient\" ${CMAKE_SWIG_GLOBAL_FLAGS} ${CMAKE_SWIG_FLAGS})
		set(SWIG_MODULE_mlclientCSharp_EXTRA_DEPS ${SWIG_EXTRA_DEPS}
			${CMAKE_CURRENT_SOURCE_DIR}/mlclient-cs.i
		) #	${CMAKE_CURRENT_SOURCE_DIR}/CSharpTypemapHelper.i

		swig_add_library(mlclientcs
			LANGUAGE csharp
			SOURCES
				mlclient-cs.i
		)

		target_link_libraries(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} mlclient ${mlclient_LIBRARIES})
		set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CSHARP_BINARY_DIRECTORY})
		if ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
			set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "lib")
			set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".dylib")
		else (Other)
			if ( UNIX )
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "lib")
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".so")
			else ( WIN32 )
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "")
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".dll")
				foreach ( CMAKE_CONFIGURATION_TYPE ${CMAKE_CONFIGURATION_TYPES} )
					string(TOUPPER ${CMAKE_CONFIGURATION_TYPE} CMAKE_CONFIGURATION_TYPE)
					set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME}
						PROPERTIES LIBRARY_OUTPUT_DIRECTORY_${CMAKE_CONFIGURATION_TYPE} "${CSHARP_BINARY_DIRECTORY}")
					set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME}
						PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${CMAKE_CONFIGURATION_TYPE} "${CSHARP_BINARY_DIRECTORY}")
				endforeach( )
			endif( UNIX )
		endif ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
		# The below needs to be /usr/lib, along with all depdendencies, as C# apps suck at following env variables
		install (TARGETS mlclientcs LIBRARY DESTINATION lib
			ARCHIVE DESTINATION "lib"
			RUNTIME DESTINATION "bin"
			COMPONENT library )
		SET(CMAKE_SWIG_FLAGS "")
	else()
		message("-- NOT building SWIG C# wrapper (edit ./bin/build-deps-settings.sh|bat with WITH_CSHARP=1 to enable)")
	endif()

# SWIG -Go
#SET_SOURCE_FILES_PROPERTIES(mlclient-go.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(mlclient-go.i PROPERTIES SWIG_FLAGS "-includeall -cgo -intgosize 64")
#SWIG_ADD_MODULE(mlclient-go go mlclient-go.i
#		Connection.cpp
#		mlclient.cpp
#		NoCredentialsException.cpp
#		Response.cpp

#		DocumentContent.cpp
#		InvalidFormatException.cpp
#		SearchDescription.cpp
#)
#SWIG_LINK_LIBRARIES(mlclient-go
#		libcpprest.dylib
#		libcommon_utilities.dylib
#		libssl.dylib
#		libcrypto.dylib
#		libpugixml.a
#)

# SWIG -Ruby
#SET_SOURCE_FILES_PROPERTIES(mlclient-ruby.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(mlclient-ruby.i PROPERTIES SWIG_FLAGS "-I/usr/local/include/ruby-2.2.0/ruby.h")
#SWIG_ADD_MODULE(mlclient-ruby ruby mlclient-ruby.i
#		Connection.cpp
#		mlclient.cpp
#		NoCredentialsException.cpp
#		Response.cpp
#
#		DocumentContent.cpp
#		InvalidFormatException.cpp
#		SearchDescription.cpp
#)
#set_source_files_properties( ${swig_generated_file_fullname}
#	PROPERTIES COMPILE_FLAGS "-I/usr/local/include/ruby-2.2.0/ruby.h")
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
#	 OUTPUT	${SWIG_OUTPUT}
#	 COMMAND ${CMAKE_COMMAND} -E echo_append "Creating wrapper code for ruby..."
#	 COMMAND ${SWIG_EXECUTABLE} -c++ -ruby -autorename -o ${SWIG_OUTPUT} -I${LIBMLCLIENT_INCLUDE_DIR} ${SWIG_INPUT}
#	 COMMAND ${CMAKE_COMMAND} -E echo "Done."
#	 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#	 DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.i
#)

#ADD_LIBRARY( mlclient-ruby SHARED ${SWIG_OUTPUT} )
#INCLUDE_DIRECTORIES( ${RUBY_INCLUDE_PATH} ${LIBMLCLIENT_INCLUDE_DIR} )

#SET_TARGET_PROPERTIES( mlclient-ruby PROPERTIES PREFIX "" OUTPUT_NAME "mlclient-ruby")

#TARGET_LINK_LIBRARIES( mlclient-ruby mlclient )
#TARGET_LINK_LIBRARIES( mlclient-ruby ${RUBY_LIBRARY} )

#INSTALL(TARGETS mlclient-ruby LIBRARY DESTINATION ${RUBY_VENDOR_ARCH_DIR})


else(SWIG_FOUND)
	message("-- NOT building SWIG modules (edit ./bin/build-deps-settings.sh|bat with WITH_SWIG=1 to enable)")
endif(SWIG_FOUND)
# end if with_swig set (off by default)

# INSTALLATION
install (TARGETS mlclient LIBRARY DESTINATION lib
	ARCHIVE DESTINATION "lib"
	RUNTIME DESTINATION "bin"
	COMPONENT library )
#install (FILES mlclient.h mlclient.hpp Response.hpp ResponseWrapper.h NoCredentialsException.hpp InvalidFormatException.hpp ConnectionWrapper.h Connection.hpp CWrapper.hpp SearchDescription.hpp DocumentContent.hpp HttpHeaders.hpp SearchResult.hpp SearchResultSet.hpp DESTINATION include/mlclient)
#install (FILES utilities/CppRestJsonDocumentContent.hpp utilities/SearchBuilder.hpp utilities/SearchOptionsBuilder.hpp utilities/ResponseHelper.hpp utilities/CppRestJsonHelper.hpp utilities/PugiXmlHelper.hpp DESTINATION include/mlclient/utilities)
#install (FILES ${PROJECT_SOURCE_DIR}/include DESTINATION include)

file(GLOB MLCPP_HEADERS_MLCLIENT include/mlclient/*.hpp include/mlclient/*.h )
install(FILES ${MLCPP_HEADERS_MLCLIENT} DESTINATION include/mlclient )
file(GLOB MLCPP_HEADERS_UTILITIES include/mlclient/utilities/*.hpp include/mlclient/utilities/*.h )
install(FILES ${MLCPP_HEADERS_UTILITIES} DESTINATION include/mlclient/utilities )


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
