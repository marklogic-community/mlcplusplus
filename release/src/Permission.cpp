/**
 * \file Permission.cpp
 *
 * \date 2016-08-09
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include <mlclient/Permission.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <string>
#include <sstream>

namespace mlclient {



/*
 * Capability Type operators - allows string output of code in human readable form
 */

/**
 * \brief Adds the textual representation of a capability type to a stream. E.g. Capability::EXECUTE => execute
 * \param os Output Stream (E.g. std::cout)
 * \param rt Capability Type const reference
 * \return
 */
std::ostream& operator << (std::ostream& os, const Capability& rt) {
  os << translate(rt);
  return os;
}

/**
 * \brief Adds the textual representation of a Capability type to a string. E.g. Capability::EXECUTE => execute
 * \param s String to concatenate to
 * \param rt The Capability type const reference
 * \return The string representation
 */
std::string& operator +(std::string& s, const Capability& rt) {
  s.append(translate(rt));
  return s;
}

const std::string translate(const Capability& rt) {
  std::ostringstream os;
  os << "Unknown Capability Type: "  << (int)rt;
  std::string result = os.str();
  switch(rt) {
  case Capability::EXECUTE:
    result = "execute";
    break;
  case Capability::READ:
    result = "read";
    break;
  case Capability::UPDATE:
    result = "update";
    break;
  case Capability::INSERT:
    result = "insert";
    break;
  }
  return result;
}

Capability toCapability(const std::string& capString) {
  const char* cs = capString.c_str();
  if (0 == strcmp(cs,"read")) {
    return Capability::READ;
  } else if (0 == strcmp(cs,"update")) {
    return Capability::UPDATE;
  } else if (0 == strcmp(cs,"insert")) {
    return Capability::INSERT;
  } else if (0 == strcmp(cs,"execute")) {
    return Capability::EXECUTE;
  } else {
    throw new InvalidFormatException("Capability type unknown: " + capString);
  }
}




Permission::Permission(const std::string& role,const Capability& capability) : role(role), capability(capability) {
  ;
}

Permission::Permission(Permission&& other) {
  role = std::move(other.role); // moves
  capability = other.capability; // copies
}

const std::string& Permission::getRole() const {
  return role;
}
void Permission::setRole(const std::string& role) {
  this->role = role;
}
const Capability& Permission::getCapability() const {
  return capability;
}
void Permission::setCapability(const Capability& capability) {
  this->capability = capability;
}









/*
 * Permission operators - allows string output of code in human readable form
 */

/**
 * \brief Adds the textual representation of a Permission type to a stream. E.g. role 'seniorstaff', Capability::EXECUTE => perm:seniorstaff=execute
 * \param os Output Stream (E.g. std::cout)
 * \param rt Permission Type reference
 * \return
 */
std::ostream& operator << (std::ostream& os, const Permission& rt) {
  os << translate(rt);
  return os;
}

/**
 * \brief Adds the textual representation of a Permission type to a string. E.g. role 'seniorstaff', Capability::EXECUTE => perm:seniorstaff=execute
 * \param s String to concatenate to
 * \param rt The Permission type reference
 * \return The string representation
 */
std::string& operator +(std::string& s, const Permission& rt) {
  s.append(translate(rt));
  return s;
}

const std::string translate(const Permission& rt) {
  std::ostringstream os;
  os << "perm:" << rt.getRole() << "=" << rt.getCapability();
  return os.str();
}

}

