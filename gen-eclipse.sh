#!/bin/sh

. settings.sh
cd $BINDIR

cmake -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -G "Eclipse CDT4 - Unix Makefiles" $SRCDIR

echo "Completed Build Generation for Eclipse - Now open Eclipse CDT and execute a build."
exit 0
