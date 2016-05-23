#!/bin/sh

mkdir -p ./bin/api
cd release

doxygen Doxyfile
cd ..

echo "Done generating docs."

rm -rf ../mlcplusplus-pages/developapi
cp -R ./bin/api/html ../mlcplusplus-pages/developapi
cd ../mlcplusplus-pages
git add .
git commit -a -m "Regenerated API docs"
cd ../mlcplusplus

echo "Done committing API docs"

exit 0
