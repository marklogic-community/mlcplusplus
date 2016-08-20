#!/bin/sh

# Make tar ball of code (Assumes build is complete and successful)
VER=`echo ../../version.txt`

echo "Building mlclient libraries RPM - mlclient-$VER"

rm -rf folder
mldir -p folder
mkdir -p rpmbuild/{RPMS,SRPMS,BUILD,SOURCES,SPECS,tmp}

FOLDER=folder/mlclient-$VER

mkdir -p $FOLDER/usr/local/lib
install -m 755 ../../bin/src/libmlclient.so $FOLDER/usr/local/lib/

tar -zvcf rpmbuild/SOURCES/mlclient-$VER.tar.gz $FOLDER

cd rpmbuild
rpmbuild -ba SPECS/mlclient.spec
