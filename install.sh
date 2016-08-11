#!/bin/sh
. settings.sh
cd bin
. build-deps-settings.sh
echo "-- Installing mlclient on system - will prompt for sudo password"
sudo cmake --build . --target install 
cd ..
sudo mkdir -p /usr/local/include/mlclient
sudo cp -R release/include/mlclient/* /usr/local/include/mlclient/
echo "-- Completed installation"
exit 0

