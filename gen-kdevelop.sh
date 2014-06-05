#!/bin/sh

. settings.sh
cd $BINDIR

cmake -G KDevelop3 $SRCDIR

echo "Completed Build Generation for KDevelop - Now open KDevelop"
exit 0
