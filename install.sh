#!/bin/sh
. settings.sh
cd bin
. build-deps-settings.sh
echo "-- Installing mlclient on system - will prompt for sudo password"
sudo cmake --build . --target install 
cd ..
echo "-- Completed installation"
exit 0

