#!/bin/sh
#cmake clean

echo "Removing general CMake files"
rm -rf CMakeFiles CMakeScripts cmake_install.cmake CMakeCache.txt CPackConfig.cmake CPackSourceConfig.cmake MLCPlusPlusConfig.h
echo "Removing Mac build files"
rm -rf MLCPlusPlus.build MLCPlusPlus.xcodeproj
echo "Removing UNIX build files"
rm -rf Makefile *.a *.so Debug *.dylib
echo "Removing KDevelop build files"
rm -rf MLCPlusPlus.kdevelop MLCPlusPlus.kdevelop.filelist MLCPlusPlus.kdevses

echo "Completed clean"
exit 0
