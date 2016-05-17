#!/usr/bin/python

import mlclientpython

connection = mlclient.Connection();
connection.configure("192.168.123.4","9797","admin","admin",false);

response = connection.getDocument("/some/100_0.xml")

print "Document content: ", response.getContent()
