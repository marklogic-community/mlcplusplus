#!/bin/sh

. settings.sh
cd $BINDIR

cmake -DOSX_UNIVERSAL="1" -G "Unix Makefiles" $SRCDIR


echo "Completed build file generation for Unix Makefiles. Now type 'cd bin; make' and hit <enter>."
exit 0
