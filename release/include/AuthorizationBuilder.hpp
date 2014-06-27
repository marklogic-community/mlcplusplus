/* 
 * File:   AuthorizationBuilder.hpp
 * Author: phoehne
 *
 * Created on June 26, 2014, 6:00 PM
 */

#ifndef AUTHORIZATIONBUILDER_HPP
#define	AUTHORIZATIONBUILDER_HPP

#include <string>

class AuthorizationBuilder {
public:
    AuthorizationBuilder();
    AuthorizationBuilder(const AuthorizationBuilder& orig);
    ~AuthorizationBuilder();
    
    std::string UsernameRealmAndPassword(const std::string& username, 
        const std::string& realm, const std::string& password);
private:
    
};

#endif	/* AUTHORIZATIONBUILDER_HPP */

