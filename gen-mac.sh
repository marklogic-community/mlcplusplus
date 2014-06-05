#!/bin/sh

. settings.sh
cd $BINDIR
cmake -G Xcode $SRCDIR

echo "Completed Build Generation for Mac - Now open Xcode, e.g. type 'open bin/MLCPlusPlus.xcodeproj' and hit <enter>."
exit 0
