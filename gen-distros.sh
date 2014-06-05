#!/bin/sh
. settings.sh

echo "Building binary distro"
cpack -C CPackConfig.cmake
echo "Building source distro"
cpack -C CPackSourceConfig.cmake

echo "End $0"
exit 0
