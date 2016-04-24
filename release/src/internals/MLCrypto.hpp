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

#include "../mlclient.hpp"
#include <string>


namespace mlclient {

namespace internals {

/// Crypto support classs
///
/// This class provides some basic wrappers around crypto hashing functions.
/// It's expected that the implementation will be conditionally compiled to
/// include the libraries appropriate to the platform.
///
class MLCrypto {
public:
  ///
  /// Constructor
  ///
  MLCrypto();

  ///
  /// Copy constructor
  ///
  MLCrypto(const MLCrypto& orig);
  virtual ~MLCrypto();

  ///
  /// Returns the MD5 hash of the given string
  ///
  /// \param raw The raw string to hash
  /// \return The MD5 hash as a hex string
  ///
  std::string md5(const std::string& raw) const;

  ///
  /// Convert a set of bytes to a hex encoded string.
  ///
  /// \param bytes The raw bytes
  /// \param length The length of the byte string
  /// \return The hex representaiton of the bytes
  std::string toHex(const uint8_t* bytes, const size_t& length) const;
private:

};

}

}

#endif	/* MLCRYPTO_HPP */

