#!/bin/sh
. ./settings.sh
cd bin
echo "-- Cleaning away compiled binaries - You may need to run this as root to clear everything"
#cmake --build . --target clean

rm -rf $BINDIR/src
rm -rf $BINDIR/CMakeFiles
rm -rf $BINDIR/CMakeCache.txt
rm -rf $BINDIR/CMakeFiles
rm -rf $BINDIR/CMakeScripts
rm -rf $BINDIR/CPackConfig.cmake
rm -rf $BINDIR/CPackSourceConfig.cmake
rm -rf $BINDIR/cmake_install.cmake
rm -rf $BINDIR/doxygen
rm -rf $BINDIR/mlclient.xcodeproj
rm -rf $BINDIR/mlclientConfig.h
rm -rf $BINDIR/samples
rm -rf $BINDIR/src
rm -rf $BINDIR/test
rm -rf $BINDIR/mlclient.build
rm -rf $BINDIR/Makefile
rm -rf $BINDIR/install_manifest.txt

echo "-- Completed clean"
exit 0
