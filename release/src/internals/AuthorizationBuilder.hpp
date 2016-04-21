/* 
 * File:   AuthorizationBuilder.hpp
 * Author: phoehne
 *
 * Created on June 26, 2014, 6:00 PM
 */

#ifndef AUTHORIZATIONBUILDER_HPP
#define	AUTHORIZATIONBUILDER_HPP

#include <string>

#include "../MLCPlusPlus.hpp"

namespace mlclient {

namespace internals {

/// AuthorizationBuilder class.
/// 
/// Testable helper class to build the parts of the Digest response.  Takes
/// various parts of the response and combines them appropriately, using the
/// MD5 hashing algorithm where necessary.
///
class AuthorizationBuilder {
public:
  AuthorizationBuilder();
  AuthorizationBuilder(const AuthorizationBuilder& orig);
  ~AuthorizationBuilder();

  ///
  /// Constructs the username password realm hash (one of the candidate
  /// HA1 hashes)
  ///
  /// \param username The username
  /// \param realm The authentication realm
  /// \param password The user (plaintext) password
  /// \return The MD5 hash of the values
  ///
  std::string usernameRealmAndPassword(const std::string& username,
      const std::string& realm, const std::string& password);

  ///
  /// Constructs the alternate HA1 construct that includes the nonce
  /// and cnonce.
  ///
  /// \param username The username
  /// \param realm The authentication realm
  /// \param password The user (plaintext) password
  /// \param nonce The server provided nonce
  /// \param cnonce The client provided nonce
  /// \return The MD5 hash of the values
  ///
  std::string userRealmPassNonceCnonce(const std::string& username,
      const std::string& realm, const std::string& password,
      const std::string& nonce, const std::string& cnonce);

  ///
  /// Constructs the HA2 hash from the HTTP method and the document
  /// portion of the URL.
  ///
  /// \param method The HTTP method (GET, POST, etc.)
  /// \param url The document path portion of the url.
  /// \return The MD5 hash of the values
  ///
  std::string methodAndURL(const std::string& method, const std::string& url);

  ///
  /// Constructs the alternate HA2 hash from the HTTP method, the path
  /// portion of the URL, and the hash of the body contents.
  ///
  /// \param method The HTTP method (GET, POST, etc.)
  /// \param url The document path portion of the url.
  /// \param bodyHash The hash of the body contents.
  ///
  std::string methodURLAndBodyHash(const std::string& method,
      const std::string& url, const std::string& bodyHash);

  ///
  /// Construct a digest response.
  ///
  /// \param hash1 The appropriate HA1 hash
  /// \param nonce The server provided nonce
  /// \param nonceCount The client side counter to prevent replay attacks.
  /// \param clientNonce The client generated nonce
  /// \param qop The qop value returned from the server
  /// \param hash2 The approparite HA2 hash
  /// \return The MD5 encoded hash of the values
  ///
  std::string response(const std::string& hash1,
      const std::string& nonce,
      const std::string& nonceCount,
      const std::string& clientNonce,
      const std::string& qop,
      const std::string& hash2);

  ///
  /// Construct a digest response
  ///
  /// \param hash1 The appropriate HA1 hash
  /// \param nonce The server provided nonce
  /// \param hash2 The approparite HA2 hash
  /// \return The MD5 encoded hash of the values
  ///
  std::string response(const std::string& hash1, const std::string& nonce,
      const std::string& hash2);
private:

};

}

}

#endif	/* AUTHORIZATIONBUILDER_HPP */

