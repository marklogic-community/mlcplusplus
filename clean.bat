echo off
echo "Removing binary build files"

cd bin
del /Q *
cd ..

echo "Completed clean"
echo on
