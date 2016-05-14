#!/bin/sh

mkdir -p ./bin/api
cd release

doxygen Doxyfile
cd ..

echo "Done generating docs."

rm -rf ../mlcplusplus-pages/api
cp -R ./bin/api/html ../mlcplusplus-pages/api
cd ../mlcplusplus-pages
git add .
git commit -a -m "Regenerated API docs"
cd ../mlcplusplus

echo "Done committing API docs"

exit 0
