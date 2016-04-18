/*
 * A header file to provide a C wrapping of the Connection C++ class
 */

#ifndef CONNECTIONWRAPPER_H
#define CONNECTIONWRAPPER_H

#include "ResponseWrapper.h"

typedef void CConnection;

#ifdef __cplusplus
extern "C" {
#endif

// constructor
CConnection * connection_new();
// destructor
void connection_delete(CConnection *t);

// member functions

void connection_configure(const CConnection *conn,const char *hostname, const char *port, const char *username, const char *password, const int usessl);

// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
CResponse * connection_doGet(const CConnection *conn,const char *pathAndQuerystring);
CResponse * connection_doPut(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
CResponse * connection_doPost(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
CResponse * connection_doDelete(const CConnection *conn,const char *path);


// Wrapped and supported functions
CResponse * connection_getDocument(const CConnection *conn,const char *uri);
CResponse * connection_saveDocument(const CConnection *conn,const char *uri,const char *payload);
CResponse * connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,const char *options);



#ifdef __cplusplus
}
#endif





#endif
