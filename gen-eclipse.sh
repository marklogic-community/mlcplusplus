#!/bin/sh

. settings.sh
cd $BINDIR

cmake -G "Eclipse CDT4 - Unix Makefiles" $SRCDIR

echo "Completed Build Generation for Eclipse - Now open Eclipse CDT and execute a build."
exit 0
