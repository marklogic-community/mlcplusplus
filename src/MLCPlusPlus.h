
#ifndef __MLCPlusPlus__
#define __MLCPlusPlus__

#include "cpprest/http_client.h"

#include <string>

class Connection {
    static Connection* _instance;

    Connection();
public:
    static Connection* Instance(void);
    void configure(const std::string& hostname, const std::string& port, const std::string& username, const std::string& password);
};

#endif /* defined(__MLCPlusPlus__) */
