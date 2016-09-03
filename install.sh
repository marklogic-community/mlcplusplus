#!/bin/sh
. settings.sh
cd bin
. build-deps-settings.sh
echo "-- Installing mlclient on system - will prompt for sudo password"
sudo cmake --build . --target install
cd ..
sudo mkdir -p /usr/local/include/mlclient
sudo cp -R release/include/mlclient/* /usr/local/include/mlclient/

echo "-- Generating dist files"
mkdir -p dist/osx-raw
mkdir -p dist/osx-raw/Debug-Universal
mkdir -p dist/windows-raw
mkdir -p dist/windows-raw/Debug-x86
mkdir -p dist/windows-raw/Release-x86
cd release/include
tar czf ../../dist/osx-raw/mlclient-include.tar.gz mlclient
zip -r ../../dist/windows-raw/mlclient-include.zip mlclient -x .DS_Store
cd ../..

cp bin/src/libmlclient.dylib dist/osx-raw/Debug-Universal/
cp bin/src/libcpprest.2.8.dylib dist/osx-raw/Debug-Universal/
cp bin/src/csmlclient.so dist/osx-raw/Debug-Universal/
cp bin/src/_mlclientpython.so dist/osx-raw/Debug-Universal/

cp Build/Debug/csmlclient.dll dist/windows-raw/Debug-x86/
cp Build/Debug/mlclient.dll dist/windows-raw/Debug-x86/
cp Build/Debug/cpprest140d_2_8.dll dist/windows-raw/Debug-x86/
cp Build/Debug/mlclient.lib dist/windows-raw/Debug-x86/
cp Build/Debug/mlclient.exp dist/windows-raw/Debug-x86/
cp Build/Debug/*.exe dist/windows-raw/Debug-x86/

cp Build/Release/csmlclient.dll dist/windows-raw/Release-x86/
cp Build/Release/mlclient.dll dist/windows-raw/Release-x86/
cp Build/Release/cpprest140_2_8.dll dist/windows-raw/Release-x86/
cp Build/Release/mlclient.lib dist/windows-raw/Release-x86/
cp Build/Release/mlclient.exp dist/windows-raw/Release-x86/
cp Build/Release/*.exe dist/windows-raw/Release-x86/

cd dist/windows-raw
zip -r mlclient-Debug-x86.zip Debug-x86 -x .DS_Store
zip -r mlclient-Release-x86.zip Release-x86 -x .DS_Store
rm -rf Debug-x86 Release-x86
cd ../osx-raw
tar czf mlclient-Debug-Universal.tar.gz Debug-Universal
rm -rf Debug-Universal
cd ../..

echo "-- Completed installation"
exit 0
