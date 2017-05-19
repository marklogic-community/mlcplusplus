# 2.8.2 and above can handle openssl letter versions (E.g. 1.0.1h), which is required to get fixed version of openssl
# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file
cmake_minimum_required (VERSION 3.5.0)

set (CMAKE_CXX_STANDARD 11) # C++11...
set (CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set (CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

# Pull in CMake helper projects.
include (CMakeDependentOption)
include (FeatureSummary)

# POLICY SETTING OVERRIDES
set (CMAKE_MACOSX_RPATH 1)
# SYSTEM DETECTION
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

# Allow versions to be in project command.
cmake_policy (SET CMP0048 NEW)

# Create a CMake option for logging.
option (WITH_LOGGING "True if logging enabled, false otherwise." ON)
# Add the feature information for the feature summary.
add_feature_info (Logging WITH_LOGGING "Logging")

# Create a CMake option for SWIG.
option (WITH_SWIG "True if SWIG enabled, false otherwise." ON)
# Add the feature information for the feature summary.
add_feature_info (SWIG WITH_SWIG "SWIG")

# Create a CMake option for SWIG/Python.
# Make the option dependent on SWIG.
cmake_dependent_option (WITH_PYTHON "True if SWIG/Python enabled, false otherwise." OFF "WITH_SWIG" OFF)
# Add the feature information for the feature summary.
add_feature_info (SWIG_Python WITH_PYTHON "SWIG/Python")

# Create a CMake option for SWIG/C#.
# Make the option dependent on SWIG.
cmake_dependent_option (WITH_CSHARP "True if SWIG/C# enabled, false otherwise." OFF "WITH_SWIG" OFF)
# Add the feature information for the feature summary.
add_feature_info (SWIG_CSharp WITH_CSHARP "SWIG/C#")

# Create a CMake option for tests.
option (WITH_TESTS "True if tests enabled, false otherwise." ON)
# Add the feature information for the feature summary.
add_feature_info (Tests WITH_TESTS "Tests")

# Create a CMake option for documentation.
option (WITH_DOCUMENTATION "True if documentation enabled, false otherwise." ON)
# Add the feature information for the feature summary.
add_feature_info (Documentation WITH_DOCUMENTATION "Documentation")

# Create a CMake option for samples.
option (WITH_SAMPLES "True if samples enabled, false otherwise." ON)
# Add the feature information for the feature summary.
add_feature_info (Samples WITH_SAMPLES "Samples")

# Create a CMake option for the usage of shared libraries vs. static.
option (BUILD_SHARED_LIBS "Build shared Libraries." ${BUILD_SHARED_LIBS})
# Add the feature information for the feature summary.
add_feature_info (SharedLibraries BUILD_SHARED_LIBS "Shared libraries")

# Create the project, setting the version and the language (code is composed of C++ and C files).
project (mlclient VERSION 8.0.3 LANGUAGES CXX C)

# Provide the overall package information.
set_package_properties (mlclient PROPERTIES
	URL "https://github.com/marklogic/mlcplusplus" 
	DESCRIPTION "C++ native connection to MarkLogic Server"
)

# DEPENDENCY DETECTION
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(samples)
add_subdirectory(doxygen)

# List all of the features built into this.
feature_summary(WHAT ALL)
