echo off
rem get BASE_DIR from environment variable, or default to .. (parent folder)
set BASE_DIR=..
set PLATFORM=Win32

echo "-- Checking for this script's pre-requisites"
echo " - git?"
rem could fall back to simple http fetch of zip file of master instead of using git
echo " - Microsoft Visual Studio?"
echo " - Nuget?"
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
