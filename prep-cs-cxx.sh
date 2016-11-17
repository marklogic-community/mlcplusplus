#!/bin/sh

sed -i '.bak' 's/enum mlclient::/mlclient::/g' bin/src/CSharpSources/mlclient-csCSHARP_wrap.cxx
sed -i '.bak' 's/"mlclientcs", EntryPoint/"mlclientcs.dll", EntryPoint/g' bin/src/CSharpSources/mlclientcsPINVOKE.cs

echo "Done"
exit 0

