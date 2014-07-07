/* 
 * File:   MLCrypto.hpp
 * Author: phoehne
 *
 * Created on July 7, 2014, 10:27 AM
 * 
 * ML Crypto is a wrapper library around the platform specific hashing and 
 * digest libraries.  What I expect to see in here is a lot of 
 * #ifdef __WIN32__
 * #elif __OSX__
 * ...
 */

#ifndef MLCRYPTO_HPP
#define	MLCRYPTO_HPP

#include <string>

class MLCrypto {
public:
    MLCrypto();
    MLCrypto(const MLCrypto& orig);
    virtual ~MLCrypto();
    
    std::string Md5(const std::string& raw) const;
    
    std::string ToHex(const uint8_t* bytes, const size_t& length) const;
private:

};

#endif	/* MLCRYPTO_HPP */

