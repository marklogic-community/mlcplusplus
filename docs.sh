#!/bin/sh

mkdir -p ./bin/api
cd release

doxygen Doxyfile

echo "Done."

exit 0
