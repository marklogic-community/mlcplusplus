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
    std::string UserRealmPassNonceCnonce(const std::string& username,
        const std::string& realm, const std::string& password, 
        const std::string& nonce, const std::string& cnonce);
    std::string MethodAndURL(const std::string& method, const std::string& url);
    std::string MethodURLAndBodyHash(const std::string& method, 
        const std::string& url, const std::string& bodyHash);
    std::string Response(const std::string& hash1, 
        const std::string& nonce, 
        const std::string& nonceCount, 
        const std::string& clientNonce, 
        const std::string& qop,
        const std::string& hash2);
    std::string Response(const std::string& hash1, const std::string& nonce,
        const std::string& hash2);
private:
    
};

#endif	/* AUTHORIZATIONBUILDER_HPP */

