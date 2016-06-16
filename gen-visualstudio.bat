echo off

rem call bin/build-deps-settings.bat

cd bin


set BOOST_ROOT_DIR=..\..\casablanca\packages\boost.1.58.0.0
set BOOST_INCLUDEDIR=..\..\casablanca\packages\boost.1.58.0.0\lib\native\include
set BOOST_LIBRARYDIR=..\..\casablanca\packages\boost_system-vc140.1.58.0-vs140rc\
set OPENSSL_ROOT_DIR=..\..\casablanca\packages\openssl.v140.windesktop.msvcstl.static.rt-dyn.x86.1.0.2.1
set OPENSSL_INCLUDE_DIR=%OPENSSL_ROOT_DIR%\build\native\include
set OPENSSL_LIBRARIES_DIR=%OPENSSL_ROOT_DIR%\lib\native\v140\windesktop\msvcstl\static\rt-dyn\x86\debug
set OPENSSL_LIBRARIES=%OPENSSL_LIBRARIES_DIR%\libeay32.lib;%OPENSSL_LIBRARIES_DIR%\ssleay32.lib

call "%VS140COMNTOOLS%\vsvars32.bat"

echo -- Detected Visual Studio Version: %VisualStudioVersion%

rem VS 2010 = Visual Studio 10 2010 Win64
rem VS 2012 = Visual Studio 11 2012 Win64
rem VS 2013 = Visual Studio 12 2013 Win64
rem VS 2015 = Visual Studio 14 2015 Win64

cmake.exe %CMAKE_OPTIONS% -DOPENSSL_LIBRARIES=%OPENSSL_LIBRARIES% -DOPENSSL_INCLUDE_DIR=%OPENSSL_INCLUDE_DIR% -DOPENSSL_ROOT_DIR=%OPENSSL_ROOT_DIR% -DBOOST_LIBRARYDIR=%BOOST_LIBRARYDIR% -DBOOST_INCLUDEDIR=%BOOST_INCLUDEDIR% -G "Visual Studio 14 2015 Win64" ../release


cd ..

echo -- Done.
echo on
