#!/bin/sh

. settings.sh
. ./bin/build-deps-settings.sh

cd $BINDIR

cmake $CMAKE_OPTIONS -G KDevelop3 $SRCDIR

echo "Completed Build Generation for KDevelop - Now open KDevelop"
exit 0
