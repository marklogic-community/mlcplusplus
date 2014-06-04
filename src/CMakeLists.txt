cmake_minimum_required (VERSION 2.6)
project (MLCPlusPlus)

# See http://www.cmake.org/cmake/help/cmake_tutorial.html for extra help on this file

# EDITABLE SETTINGS BEGIN

set (MLCPlusPlus_VERSION_MAJOR 0)
set (MLCPlusPlus_VERSION_MINOR 1)

# EDITABLE SETTINGS END





configure_file (
  "${PROJECT_SOURCE_DIR}/MLCPlusPlusConfig.h.in"
  "${PROJECT_BINARY_DIR}/MLCPlusPlusConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find MLCPlusPlusConfig.h
include_directories("${PROJECT_BINARY_DIR}")



# ML C++ own libraries
add_library (MLCPlusPlus SHARED MLCPlusPlus.cpp)

# ML C++ dependencies

# TODO Casablanca


# INSTALLATION
install (TARGETS MLCPlusPlus DESTINATION lib)
install (FILES MLCPlusPlus.h DESTINATION include)



# CPack installer

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${MLCPlusPlus_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${MLCPlusPlus_VERSION_MINOR}")
include (CPack)
