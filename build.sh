#!/bin/sh
. ./settings.sh
cd bin
. ./build-deps-settings.sh
rm -f src/CSharpSources/*_wrap.*
rm -f src/*PYTHON_wrap.*
echo "-- Building mlclient"
# target name not specified as it's called different things on different platforms! Default is the all target.
cmake --build .
cd ..
echo "-- Completed build. To install, type './install.sh' and hit <enter>"
exit 0
