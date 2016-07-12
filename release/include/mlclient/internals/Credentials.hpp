/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Credentials.h
 * Created by Paul Hoehne on 29 May 2014.
 */

#ifndef __MLCLIENT__Credentials__
#define __MLCLIENT__Credentials__

#include <cpprest/http_client.h>

#include <string>
#include <map>
#include <cstdint>

namespace mlclient {

namespace internals {

///
/// Used to manage the credentials for digest authentication.  Normally the
/// username and password are initially known.  As part of the Digest challenge,
/// the server will return a qop value, nonce, and relam.  The client is 
/// responsible for generating a client side nonce and for managing the 
/// nonce count.
///
class Credentials {
  friend class AuthenticatingProxy;

  std::wstring user;
  std::wstring pass;

  std::string nonce;
  std::string qop;
  std::string opaque;
  std::string realm;
  std::string uri;
  std::string cnonce;
  uint32_t nonce_count;

protected:
  ///
  /// Generate the authentication header contents.  This is what goes into
  /// the Authorize header.  Parses the incoming authenticate header
  /// to produce the response header.
  ///
  /// \param method The HTTP method used.
  /// \param uri The path portion of the URI
  /// \param auth_header The contents of the WWW Authenticate header
  /// \return The contents of the Authorization header
  ///
  std::string authenticate(const std::string& method, const std::string& uri,
      const std::string& auth_header);

  ///
  /// Generate the authentication header contents.  This is what goes into
  /// the Authorize header.  Requires that the credentials are set up to
  /// perform authentication and have a qop and nonce.
  ///
  /// \param method The HTTP method used.
  /// \param uri The path portion of the URI
  /// \return The contents of the Authorization header
  ///
  std::string authenticate(const std::string& method, const std::string& uri);


  ///
  /// Generate a random client nonce.
  ///
  /// \return A random nonce value
  ///
  std::string generateRandomCnonce(void) const; // TODO hide me in Impl

public:

  ///
  /// Constructor
  ///
  Credentials();

  ///
  /// Constructor
  ///
  /// \param username The username
  /// \param password The user's (plaintext) password
  ///
  Credentials(const std::string& username, const std::string& password);

  ///
  /// Constructor
  ///
  /// \param username The username
  /// \param password The user's (plaintext) password
  /// \param cnonce The client side nonce
  /// \param nc The nonce count
  ///
  Credentials(const std::string& username, const std::string& password,
      const std::string& cnonce, const uint32_t& nc);

  ///
  /// Constructor
  ///
  /// \param username The username
  /// \param password The user's (plaintext) password
  ///
  Credentials(const std::wstring& username, const std::wstring& password);

  ~Credentials(void);

  ///
  /// Returns the if the credentials are capable of generating a response
  /// to the digest challenge.
  ///
  /// \return Weather or not it can generate a challenge response
  ///
  bool canAuthenticate(void) const;

  ///
  /// Parses the Authenticate header to extract the nonce, the qop and the
  /// realm.  Once the credentials have been provided the authenticate
  /// header, the credentials will be capable of formulating a response
  /// to the digest challenge.
  ///
  /// \param _raw The raw WWW Authenticate header
  ///
  void parseWWWAuthenticateHeader(const std::string& _raw);

  ///
  /// Returns the server provided nonce
  ///
  /// \return The nonce
  ///
  std::string getNonce(void) const;

  ///
  /// Returns the server provided qop
  ///
  /// \return The qop
  ///
  std::string getQop(void) const;

  ///
  /// Returns the server provided opaque value
  ///
  /// \return The opaque
  ///
  std::string getOpaque(void) const;

  ///
  /// Returns the server provided realm
  ///
  /// \return The realm
  ///
  std::string getRealm(void) const;

};

}

}

#endif /* defined(__MLCLIENT__Credentials__) */
