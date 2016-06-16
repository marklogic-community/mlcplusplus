#!/bin/sh
. settings.sh
cd bin
echo "-- Cleaning away compiled binaries"
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

echo "-- Completed clean"
exit 0
