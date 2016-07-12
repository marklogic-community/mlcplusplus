#!/bin/sh

. settings.sh
. ./bin/build-deps-settings.sh

cd $BINDIR

cmake $CMAKE_OPTIONS -G "Visual Studio 9 2008 Win64" $SRCDIR

echo "Completed Build Generation for Visual Studio 64 bit - Now open Visual Studio"
exit 0
