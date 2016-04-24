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
CConnection * ml_connection_new();
// destructor
void ml_connection_delete(CConnection *t);

// member functions

void ml_connection_configure(const CConnection *conn,const char *hostname, const char *port, const char *username, const char *password, const int usessl);

// BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
CResponse * ml_connection_doGet(const CConnection *conn,const char *pathAndQuerystring);
CResponse * ml_connection_doPut(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
CResponse * ml_connection_doPost(const CConnection *conn,const char *pathAndQuerystring,const char *payload);
CResponse * ml_connection_doDelete(const CConnection *conn,const char *path);


// Wrapped and supported functions
CResponse * ml_connection_getDocument(const CConnection *conn,const char *uri);
CResponse * ml_connection_saveDocument(const CConnection *conn,const char *uri,const char *payload);
CResponse * ml_connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,const char *options);



#ifdef __cplusplus
}
#endif





#endif
