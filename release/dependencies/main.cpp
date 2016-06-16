/*
 * \brief This file tests our dependencies (cpprest, openssl, etc.) are installed correctly, by exercising the compiler
 * and linker on this machine.
 * \since 8.0.2
 * \date 2016-06-15
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <cpprest/json.h>
#include <openssl/md5.h>
#include <boost/uuid/uuid.hpp>

int main(int argc, const char * argv[]) {
  web::json::value value;
  MD5_CTX _context;
  boost::uuids::uuid random_uuid = boost::uuids::random_generator()();
  return 0;
}
