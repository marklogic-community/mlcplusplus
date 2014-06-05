#!/bin/sh
#cmake clean

. settings.sh

#echo "Removing general CMake files"
#rm -rf CMakeFiles CMakeScripts cmake_install.cmake CMakeCache.txt CPackConfig.cmake CPackSourceConfig.cmake MLCPlusPlusConfig.h
#echo "Removing Mac build files"
#rm -rf MLCPlusPlus.build MLCPlusPlus.xcodeproj
#echo "Removing UNIX build files"
#rm -rf Makefile *.a *.so Debug *.dylib
#echo "Removing KDevelop build files"
#rm -rf MLCPlusPlus.kdevelop MLCPlusPlus.kdevelop.filelist MLCPlusPlus.kdevses
#echo "Removing Eclipse build files"
#rm -rf .cproject .project
echo "Removing binary build files"
rm -rf $BINDIR/*

echo "Completed clean"
exit 0
