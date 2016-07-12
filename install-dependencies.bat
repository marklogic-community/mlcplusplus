echo off
rem get BASE_DIR from environment variable, or default to .. (parent folder)
set BASE_DIR=..
set PLATFORM=Win32

echo "-- Checking for this script's pre-requisites"
echo " - git?"
rem could fall back to simple http fetch of zip file of master instead of using git
echo " - Microsoft Visual Studio?"
echo " - Nuget?"


$client = new-object System.Net.WebClient
$client.DownloadFile("https://dist.nuget.org/win-x86-commandline/latest/nuget.exe","bin\nuget.exe")

mkdir Packages
cd Packages
..\nuget install OpenSSL

boost
boost_system-vc140
openssl.v140.windesktop.msvcstl.static.rt-dyn
openssl.v140.windesktop.msvcstl.static.rt-dyn.x86
openssl.v140.windesktop.msvcstl.static.rt-dyn.x64


echo " - MSBuild?"

echo "-- Installing dependencies"

set CASABLANCA_HOME=%BASE_DIR%\casablanca
echo " - Downloading Microsoft cpprest (casablanca) to %CASABLANCA_HOME% ..."
git clone http://github.com/Microsoft/cpprest.git %CASABLANCA_HOME%

echo " - Downloading Microsoft's cpprest (casablanca) dependencies..."


echo "-- Building Microsoft's cpprest (casablanca) library for %PLATFORM%"

echo "-- Creating .\bin\build-deps-settings.bat"

echo "-- Testing dependencies by building test programme"

echo "*** Dependency installation complete. Now run gen-visualstudio.bat"

echo on
