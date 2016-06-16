echo off
echo "Removing binary build files"

cd bin
rem del /Q *
cmake --build . --target clean
cd ..

echo "Completed clean"
echo on
