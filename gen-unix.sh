#!/bin/sh

. settings.sh
. ./bin/build-deps-settings.sh

cd $BINDIR

cmake $CMAKE_OPTIONS -G "Unix Makefiles" $SRCDIR


echo "Completed build file generation for Unix Makefiles. Now type 'cd bin; make' and hit <enter>."
exit 0
