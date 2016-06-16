call settings.bat
cd bin
call build-deps-settings.bat
cmake --build . --target install
cd ..
