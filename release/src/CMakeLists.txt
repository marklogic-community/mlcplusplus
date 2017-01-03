# Set the list of features needed by this project.
# cxx_auto_type																		 Automatic type deduction, as defined in N1984.
# cxx_extern_templates								Extern templates, as defined in N1987.
# cxx_lambdas: 										Lambda functions, as defined in N2927.
# cxx_nullptr: 										Null pointer, as defined in N2431.
# cxx_override:										Override control override keyword, as defined in N2928, N3206 and N3272.
# cxx_rvalue_references: 							R-value references, as defined in N2118.
# cxx_template_template_parameters: 				Template template parameters, as defined in ISO/IEC 14882:1998.
# cxx_deleted_functions								Deleted functions, as defined in N2346.
# cxx_static_assert									Static assert, as defined in N1720.
#set(mandatory_features cxx_extern_templates cxx_rvalue_references cxx_template_template_parameters cxx_auto_type)
#set(all_features ${mandatory_features} cxx_nullptr cxx_override cxx_lambdas cxx_deleted_functions cxx_static_assert)
# Create the compatibility filepath.
#set(compatibility_filepath "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Compatibility.hpp")
# Write the compatibility header.
#write_compiler_detection_header(
#	FILE ${compatibility_filepath}
#	PREFIX ${PROJECT_NAME}
#	COMPILERS MSVC GNU Clang AppleClang
#	FEATURES ${all_features})

# Create the configuration filepath.
set(config_filepath "${PROJECT_BINARY_DIR}/mlclientConfig.h")
# Have CMake do a search and replace on the version numbers in our config.h file
configure_file(
	"${PROJECT_SOURCE_DIR}/mlclientConfig.h.in"
	${config_filepath}
)

# Create an installation for the header files.
#install(FILES ${compatibility_filepath} DESTINATION ${INSTALL_INCLUDE_DIR} COMPONENT headers)
#install(FILES ${config_filepath} DESTINATION ${INSTALL_INCLUDE_DIR} COMPONENT headers)

# Store the header directory(so that I don't have to type it over and over again).
set(hdr_dir ${PROJECT_SOURCE_DIR}/include/mlclient)

# Select all of the exported header files.
set(exported_hdr_filepaths
	${hdr_dir}/CWrapper.hpp
	${hdr_dir}/Connection.hpp
	${hdr_dir}/Document.hpp
	${hdr_dir}/DocumentContent.hpp
	${hdr_dir}/DocumentSet.hpp
	${hdr_dir}/HttpHeaders.hpp
	${hdr_dir}/InvalidFormatException.hpp
	${hdr_dir}/MarkLogicTypes.hpp
	${hdr_dir}/NoCredentialsException.hpp
	${hdr_dir}/Permission.hpp
	${hdr_dir}/Response.hpp
	${hdr_dir}/SearchDescription.hpp
	${hdr_dir}/SearchResult.hpp
	${hdr_dir}/SearchResultSet.hpp
	${hdr_dir}/ValuesResult.hpp
	${hdr_dir}/ValuesResultSet.hpp
	${hdr_dir}/logging.hpp
	${hdr_dir}/mlclient.hpp
)

# Select all of the utilities header files.
set(utilities_hdr_filepaths
	${hdr_dir}/utilities/CppRestJsonDocumentContent.hpp
	${hdr_dir}/utilities/CppRestJsonHelper.hpp
	${hdr_dir}/utilities/DocumentBatchHelper.hpp
	${hdr_dir}/utilities/DocumentBatchWriter.hpp
	${hdr_dir}/utilities/DocumentHelper.hpp
	${hdr_dir}/utilities/PathNavigator.hpp
	${hdr_dir}/utilities/PugiXmlDocumentContent.hpp
	${hdr_dir}/utilities/PugiXmlHelper.hpp
	${hdr_dir}/utilities/ResponseHelper.hpp
	${hdr_dir}/utilities/SearchBuilder.hpp
	${hdr_dir}/utilities/SearchOptionsBuilder.hpp
)

# Select all of the internal header files.
set(internals_hdr_filepaths
	${hdr_dir}/internals/AuthenticatingProxy.hpp
	${hdr_dir}/internals/AuthorizationBuilder.hpp
	${hdr_dir}/internals/Conversions.hpp
	${hdr_dir}/internals/Credentials.hpp
	${hdr_dir}/internals/FakeConnection.hpp
	${hdr_dir}/internals/MLCrypto.hpp
	${hdr_dir}/internals/memory.hpp
)

# Select all of the external header files.
set(external_hdr_filepaths
	${hdr_dir}/ext/pugixml/pugiconfig.hpp
	${hdr_dir}/ext/pugixml/pugixml.hpp
)

# Select all of the exported source files.
set(exported_src_filepaths 
	Connection.cpp
	ConnectionWrapper.cpp
	Document.cpp
	DocumentContent.cpp
	HttpHeaders.cpp
	InvalidFormatException.cpp
	MarkLogicTypes.cpp
	NoCredentialsException.cpp
	Permission.cpp
	Response.cpp
	ResponseWrapper.cpp
	SearchDescription.cpp
	SearchResult.cpp
	SearchResultSet.cpp
	ValuesResult.cpp
	ValuesResultSet.cpp
	logging.cpp
	mlclient.cpp
)

# Select all of the internals source files.
set(internals_src_filepaths
	internals/AuthenticatingProxy.cpp
	internals/AuthorizationBuilder.cpp
	internals/Conversions.cpp
	internals/Credentials.cpp
	internals/FakeConnection.cpp
	internals/MLCrypto.cpp
)

# Select all of the utilities source files.
set(utilities_src_filepaths
	utilities/CppRestJsonDocumentContent.cpp
	utilities/CppRestJsonHelper.cpp
	utilities/DocumentBatchHelper.cpp
	utilities/DocumentBatchWriter.cpp
	utilities/DocumentHelper.cpp
	utilities/PathNavigator.cpp
	utilities/PugiXmlDocumentContent.cpp
	utilities/PugiXmlHelper.cpp
	utilities/ResponseHelper.cpp
	utilities/SearchBuilder.cpp
	utilities/SearchOptionsBuilder.cpp
)

# Select all of the external source files.
set(external_src_filepaths 
	ext/pugixml/pugixml.cpp
)

# Create the library target(and associate it with all of the source code.
add_library(mlclient SHARED
	${config_filepath}
	${exported_hdr_filepaths}
	${utilities_hdr_filepaths}
	${internals_hdr_filepaths}
	${external_hdr_filepaths}
	${exported_src_filepaths}
	${utilities_src_filepaths}
	${internals_src_filepaths}
	${external_src_filepaths}
)

# Compile under C++11
set_property(TARGET mlclient PROPERTY CXX_STANDARD 11)
# Tie in the include directories.
target_include_directories(mlclient 
		PUBLIC ${PROJECT_SOURCE_DIR}/include
		PUBLIC ${PROJECT_BINARY_DIR}
		PUBLIC ${OPENSSL_INCLUDE_DIR}
		PUBLIC ${Boost_INCLUDE_DIRS}
)
# Need to indicate project requires features...
#target_compile_features(mlclient PUBLIC ${mandatory_features})

# Group the source files for clarity in the MS Visual Studio solution.
source_group("include\\\\mlclient" FILES ${exported_hdr_filepaths})
source_group("include\\\\mlclient\\\\utilities" FILES ${utilities_hdr_filepaths})
source_group("include\\\\mlclient\\\\internals" FILES ${internals_hdr_filepaths})
source_group("include\\\\mlclient\\\\ext\\\\pugixml" FILES ${external_hdr_filepaths})
source_group("src" FILES ${exported_src_filepaths})
source_group("src\\\\utilities" FILES ${utilities_src_filepaths})
source_group("src\\\\internals" FILES ${internals_src_filepaths})
source_group("src\\\\ext\\\\pugixml" FILES ${external_src_filepaths})

# Set up the link libraries.
target_link_libraries(mlclient
	${LIB}cpprest
	${OPENSSL_LIBRARIES}
	${CPPREST_LIB}
	${Boost_FILESYSTEM_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
	${Boost_THREAD_LIBRARY}
	${Boost_ATOMIC_LIBRARY}
	${Boost_CHRONO_LIBRARY}
	${Boost_RANDOM_LIBRARY}
	${Boost_REGEX_LIBRARY}
	${Boost_LOG_LIBRARY}
	${Boost_LOG_SETUP_LIBRARY}
	${Boost_UNIT_TEST_FRAMEWORK}
)

# Set up the compile definitions.
# TODO Evaluate if this should also be defined on Cygwin/MinGW - I suspect not.
target_compile_definitions(mlclient
	PUBLIC $<$<CXX_COMPILER_ID:MSVC>:UNICODE>
	PUBLIC $<$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GCC>>:_GLIBCXX_USE_NANOSLEEP>
)

# Set up the compiler options.
target_compile_options(mlclient
	# The cxx_flags must be set here, because the ios-cmake toolchain file unfortunately sets "-headerpad_max_install_names" which is not a valid clang flag.
	PUBLIC $<$<PLATFORM_ID:IOS>:"-fvisibility=hidden -fvisibility-inlines-hidden">
	PUBLIC $<$<OR:$<CXX_COMPILER_ID:Clang>,$<PLATFORM_ID:IOS>>:"-fno-strict-aliasing -Wno-error=unused-local-typedefs -Wall -Wextra -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls -Wno-overloaded-virtual -Wno-sign-conversion -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-char-subscripts -Wno-switch -Wno-unused-parameter -Wno-unused-variable -Wno-deprecated -Wno-unused-value -Wno-unknown-warning-option -Wno-return-type-c-linkage -Wno-unused-function -Wno-sign-compare -Wno-shorten-64-to-32 -Wno-reorder -stdlib=libc++ -Wno-return-type-c-linkage -Wno-unneeded-internal-declaration">
	PUBLIC $<$<CXX_COMPILER_ID:GCC>:"-fno-strict-aliasing -Wall -Wextra -Wunused-parameter -Wcast-align -Wcast-qual -Wconversion -Wformat=2 -Winit-self -Winvalid-pch -Wmissing-format-attribute -Wmissing-include-dirs -Wpacked -Wredundant-decls -Wunreachable-code -Wno-deprecated -Wno-unknown-pragmas -Wno-reorder -Wno-unused-function -Wno-char-subscripts -Wno-switch -Wno-unused-but-set-parameter -Wno-deprecated -Wno-unused-value -Wno-unused-local-typedefs">
)

# Now build SWIG bindings

IF(WITH_SWIG)
	
FIND_PACKAGE( SWIG )

IF( SWIG_FOUND )

INCLUDE(${SWIG_USE_FILE})

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")




# SWIG Python

IF(WITH_PYTHON)
message( "-- Building SWIG Python bindings" )

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${PYTHON_INCLUDE_PATH} ${mlclient_INCLUDE_DIR} )

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
#	libpugixml.a
	mlclient
	${Casablanca_LIBRARIES}
	${PYTHON_LIBRARIES}
)
SET(CMAKE_SWIG_FLAGS "")

else()
	message("-- NOT building SWIG Python wrapper(edit ./bin/build-deps-settings.sh|bat with WITH_PYTHON=1 to enable)")
endif()
# endif for python with check






# SWIG C#.NET

IF(WITH_CSHARP)
message( "-- Building SWIG CSharp bindings" )

# Find C#

find_package( CSharp REQUIRED )
include( ${CSHARP_USE_FILE} )

set(SWIG_MODULE_mlclientCSharp_TARGET_NAME "mlclientcs")

set_source_files_properties( mlclient-cs.i PROPERTIES CPLUSPLUS ON )

	# Make sure the nested directory structure exists
	set(CSHARP_SOURCE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CSharpSources CACHE INTERNAL "")
	set(CSHARP_BINARY_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CSharpBinaries CACHE INTERNAL "")
	file(MAKE_DIRECTORY ${CSHARP_SOURCE_DIRECTORY})
	file(MAKE_DIRECTORY ${CSHARP_BINARY_DIRECTORY})

		# Create swig target
		set(CMAKE_SWIG_OUTDIR ${CSHARP_SOURCE_DIRECTORY})
		if( UNIX )
			#set(CMAKE_SWIG_FLAGS -dllimport \"mlclientcs\")
		else(WIN32 )
			#set(CMAKE_SWIG_FLAGS -dllimport \"mlclientcs\")
		endif( UNIX )
		set(CMAKE_SWIG_FLAGS -I${CMAKE_CURRENT_SOURCE_DIR} -namespace \"mlclient\" ${CMAKE_SWIG_GLOBAL_FLAGS} ${CMAKE_SWIG_FLAGS})
		set(SWIG_MODULE_mlclientCSharp_EXTRA_DEPS ${SWIG_EXTRA_DEPS}
			${CMAKE_CURRENT_SOURCE_DIR}/mlclient-cs.i
		) #	${CMAKE_CURRENT_SOURCE_DIR}/CSharpTypemapHelper.i

		swig_add_module(mlclientcs csharp mlclient-cs.i)

		target_link_libraries(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} mlclient ${mlclient_LIBRARIES})
		set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CSHARP_BINARY_DIRECTORY})
		if( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
			set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "lib")
			set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".dylib")
		else(Other)
			if( UNIX )
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "lib")
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".so")
			else( WIN32 )
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES PREFIX "")
				set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME} PROPERTIES SUFFIX ".dll")
				foreach( CMAKE_CONFIGURATION_TYPE ${CMAKE_CONFIGURATION_TYPES} )
					string(TOUPPER ${CMAKE_CONFIGURATION_TYPE} CMAKE_CONFIGURATION_TYPE)
					set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME}
						PROPERTIES LIBRARY_OUTPUT_DIRECTORY_${CMAKE_CONFIGURATION_TYPE} "${CSHARP_BINARY_DIRECTORY}")
					set_target_properties(${SWIG_MODULE_mlclientCSharp_TARGET_NAME}
						PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${CMAKE_CONFIGURATION_TYPE} "${CSHARP_BINARY_DIRECTORY}")
				endforeach( )
			endif( UNIX )
		endif( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )

		# The below needs to be /usr/lib, along with all depdendencies, as C# apps suck at following env variables
		install(TARGETS mlclientcs LIBRARY DESTINATION lib
																ARCHIVE DESTINATION "lib"
																RUNTIME DESTINATION "bin"
																COMPONENT library )


SET(CMAKE_SWIG_FLAGS "")

else()
	message("-- NOT building SWIG C# wrapper(edit ./bin/build-deps-settings.sh|bat with WITH_CSHARP=1 to enable)")

endif()
# end if c# swig with found





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
#		${Casablanca_LIBRARIES}
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
#														 PROPERTIES COMPILE_FLAGS "-I/usr/local/include/ruby-2.2.0/ruby.h")
#SWIG_LINK_LIBRARIES(mlclient-ruby mlclient)



#SET( LIBMLCLIENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
#SET( RUBY_EXECUTABLE "ruby" )
#SET( RUBY_INCLUDE_PATH "/usr/local/include/ruby-2.2.0/ruby.h" )


#EXECUTE_PROCESS(COMMAND ${RUBY_EXECUTABLE} -r rbconfig -e "print Config::CONFIG['vendorarchdir']" OUTPUT_VARIABLE RUBY_VENDOR_ARCH_DIR)

#MESSAGE(STATUS "Ruby executable: ${RUBY_EXECUTABLE}")
#MESSAGE(STATUS "Ruby vendor arch dir: ${RUBY_VENDOR_ARCH_DIR}")
#MESSAGE(STATUS "Ruby include path: ${RUBY_INCLUDE_PATH}")

#SET( SWIG_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/mlclient_ruby.cxx" )

#ADD_CUSTOM_COMMAND(
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




endif()
# end if swig found
else()
	message("-- NOT building SWIG modules(edit ./bin/build-deps-settings.sh|bat with WITH_SWIG=1 to enable)")
endif()
# end if with_swig set(off by default)




# INSTALLATION
install(TARGETS mlclient LIBRARY DESTINATION lib
	ARCHIVE DESTINATION "lib"
	RUNTIME DESTINATION "bin"
	COMPONENT library)
#install(FILES mlclient.h mlclient.hpp Response.hpp ResponseWrapper.h NoCredentialsException.hpp InvalidFormatException.hpp ConnectionWrapper.h Connection.hpp CWrapper.hpp SearchDescription.hpp DocumentContent.hpp HttpHeaders.hpp SearchResult.hpp SearchResultSet.hpp DESTINATION include/mlclient)
#install(FILES utilities/CppRestJsonDocumentContent.hpp utilities/SearchBuilder.hpp utilities/SearchOptionsBuilder.hpp utilities/ResponseHelper.hpp utilities/CppRestJsonHelper.hpp utilities/PugiXmlHelper.hpp DESTINATION include/mlclient/utilities)
#install(FILES ${mlclient_INCLUDE_DIR} DESTINATION include)

file(GLOB MLCPP_HEADERS_MLCLIENT include/mlclient/*.hpp include/mlclient/*.h )
install(FILES ${MLCPP_HEADERS_MLCLIENT} DESTINATION include/mlclient )
file(GLOB MLCPP_HEADERS_UTILITIES include/mlclient/utilities/*.hpp include/mlclient/utilities/*.h )
install(FILES ${MLCPP_HEADERS_UTILITIES} DESTINATION include/mlclient/utilities )


# CPack installer

# build a CPack driven installer package
include(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MarkLogic C++ Client Library")
SET(CPACK_PACKAGE_VENDOR "MarkLogic Inc.")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${mlclient_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${mlclient_VERSION_MINOR}")
include(CPack)
