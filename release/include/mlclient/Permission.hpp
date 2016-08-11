/*
 * \file Permission.hpp
 *
 * \date 2016-08-09
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 */

#ifndef INCLUDE_MLCLIENT_PERMISSION_HPP_
#define INCLUDE_MLCLIENT_PERMISSION_HPP_

#include "mlclient/mlclient.hpp"
#include <string>
#include <iosfwd>

namespace mlclient {

/**
 * \brief A capability associated with a (Document) permission in MarkLogic Server.
 */
enum Capability {
  EXECUTE, INSERT, READ, UPDATE
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const Capability& rt);
MLCLIENT_API std::string& operator +(std::string& s, const Capability& rt);

MLCLIENT_API const std::string translate(const Capability& rt);

MLCLIENT_API Capability toCapability(const std::string& capString);

/**
 * \brief Represents a single MarkLogic Permission
 */
class Permission {
public:
  Permission(const std::string& role,const Capability& capability);
  Permission(Permission&& other); // move ctor
  Permission(const Permission& other) = default; // copy ctor
  virtual ~Permission() = default;

  Permission& operator=(const Permission& other) = default; // default copy assignment operator

  const std::string& getRole() const;
  void setRole(const std::string& role);
  const Capability& getCapability() const;
  void setCapability(const Capability& capability);

private:
  std::string role;
  Capability capability;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const Permission& rt);
MLCLIENT_API std::string& operator +(std::string& s, const Permission& rt);

MLCLIENT_API const std::string translate(const Permission& rt);


} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_PERMISSION_HPP_ */
