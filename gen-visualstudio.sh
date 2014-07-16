#!/bin/sh

. settings.sh
cd $BINDIR

cmake -G "Visual Studio 9 2008 Win64" $SRCDIR

echo "Completed Build Generation for Visual Studio 64 bit - Now open Visual Studio"
exit 0
