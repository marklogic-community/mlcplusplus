#include "ConnectionWrapper.h"
#include "Connection.hpp"
#include <cpprest/json.h>
#include <stdbool.h>
#include "CWrapper.hpp"

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
        return (CResponse*)(new CWrapper<Response>(t->doGet(std::string(pathAndQuerystring))));
    }
    CResponse * connection_doPut(const CConnection *conn,const char *pathAndQuerystring,
    		const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        return (CResponse*)(new CWrapper<Response>(t->doPut(std::string(pathAndQuerystring),json::value(std::string(payload)))));
    }
    CResponse * connection_doPost(const CConnection *conn,const char *pathAndQuerystring,
    		const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        return (CResponse*)(new CWrapper<Response>(t->doPost(std::string(pathAndQuerystring),json::value(std::string(payload)))));
    }
    CResponse * connection_doDelete(const CConnection *conn,const char *path) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        return (CResponse*)(new CWrapper<Response>(t->doDelete(std::string(path))));
    }


    // Wrapped and supported functions
    CResponse * connection_getDocument(const CConnection *conn,const char *uri) {
    	using namespace mlclient;
        Connection *t = (Connection *)conn;
        //CWrapper<Response> raw(t->getDocument(std::string(uri)));
        //CWrapper<Response>* wrapper = ;
        //CWrapper<Response>* cr = new CWrapper<Response>(t->getDocument(std::string(uri)));
        //CSimpleWrapper* cr = new CSimpleWrapper(t->getDocument(std::string(uri)));
        //CResponseWrapper* cr = new CResponseWrapper(t->getDocument(std::string(uri)));
        //return (CResponse*)(cr);
        CWrapper<Response>* resp = new CWrapper<Response>(std::move(t->getDocument(std::string(uri))));
        //const std::unique_ptr<Response> rp = t->getDocument(std::string(uri));
        //const Response* resp = rp.get();
        return (CResponse*)(resp);
    }
    CResponse * connection_saveDocument(const CConnection *conn,const char *uri,const char *payload) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        return (CResponse*)(new CWrapper<Response>(t->saveDocument(std::string(uri),json::value(std::string(payload)))));
    }
    CResponse * connection_search(const CConnection *conn,const char *searchQuery,const char *qtext,
    		const char *options) {
    	using namespace mlclient;
    	using namespace web;
        Connection *t = (Connection *)conn;
        return (CResponse*)(new CWrapper<Response>(t->search(json::value(std::string(searchQuery)),std::string(qtext),json::value(std::string(options)))));
    }


// member functions
/*
    void test_testfunc(const CConnection *test) {
        Connection *t = (Connection *)test;
        t->testfunc();
    }
    */

}
