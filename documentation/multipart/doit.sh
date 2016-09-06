#!/bin/bash

curl --digest --user admin:admin -X POST -i --data-binary @body -H "Content-Type: multipart/mixed; boundary=BOUNDARY" -v -H "Accept: application/json" 'http://192.168.123.4:8122/v1/documents'

echo "Done."
exit 0

