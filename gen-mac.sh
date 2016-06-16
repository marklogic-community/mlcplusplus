#!/bin/sh

. settings.sh
. ./bin/build-deps-settings.sh

cd $BINDIR
cmake $CMAKE_OPTIONS -G Xcode $SRCDIR

echo "Completed Build Generation for Mac. To build, type './build.sh' and hit <enter>."
exit 0
