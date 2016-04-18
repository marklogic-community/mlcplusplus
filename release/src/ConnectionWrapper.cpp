#include "ConnectionWrapper.h"
#include "Connection.hpp"
#include <cpprest/json.h>
#include <stdbool.h>

extern "C" {

// constructor and destructor
    CConnection * connection_new() {
    	using namespace mlclient;
        Connection *t = new Connection();

        return (CConnection *)t;
    }
    void connection_delete(CConnection *conn) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;

        delete t;
    }

    void connection_configure(const CConnection *conn,const char *hostname, const char *port,
    		const char *username, const char *password, const int usessl) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        t->configure(std::string(hostname),std::string(port),std::string(username),std::string(password),
        		(0==usessl?false:true));
    }

    // BASIC commands allowing re-use of this connection, perhaps for URLs we don't yet wrap
    CResponse * connection_doGet(const CConnection *conn,const char *pathAndQuerystring) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        const Response& resp = t->doGet(std::string(pathAndQuerystring));
        return (CResponse*)(&resp);
    }
    CResponse * connection_doPut(const CConnection *conn,const char *pathAndQuerystring,
    		const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        const Response& resp = t->doPut(std::string(pathAndQuerystring),json::value(std::string(payload)));
        return (CResponse*)(&resp);
    }
    CResponse * connection_doPost(const CConnection *conn,const char *pathAndQuerystring,
    		const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        const Response& resp = t->doPost(std::string(pathAndQuerystring),json::value(std::string(payload)));
        return (CResponse*)(&resp);
    }
    CResponse * connection_doDelete(const CConnection *conn,const char *path) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        const Response& resp = t->doDelete(std::string(path));
        return (CResponse*)(&resp);
    }


    // Wrapped and supported functions
    CResponse * connection_getDocument(const CConnection *conn,const char *uri) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        const Response& resp = t->getDocument(std::string(uri));
        return (CResponse*)(&resp);
    }
    CResponse * connection_saveDocument(const CConnection *conn,const char *uri,const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        const Response& resp = t->saveDocument(std::string(uri),json::value(std::string(payload)));
        return (CResponse*)(&resp);
    }
    CResponse * connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,
    		const char *options) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        const Response& resp = t->search(json::value(std::string(searchQuery)),std::string(qtext),json::value(std::string(options)));
        return (CResponse*)(&resp);
    }


// member functions
/*
    void test_testfunc(const CConnection *test) {
        Connection *t = (Connection *)test;
        t->testfunc();
    }
    */

}
