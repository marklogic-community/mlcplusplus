/*
 * \file Permission.hpp
 *
 * \date 2016-08-09
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 */

#ifndef INCLUDE_MLCLIENT_PERMISSION_HPP_
#define INCLUDE_MLCLIENT_PERMISSION_HPP_

#include <mlclient/mlclient.hpp>
#include <string>
#include <iosfwd>
#include <vector>

namespace mlclient {

/**
 * \brief A capability associated with a (Document) permission in MarkLogic Server.
 */
enum class Capability {
  EXECUTE, INSERT, READ, UPDATE
};


MLCLIENT_API std::ostream& operator << (std::ostream& os, const Capability& rt);
MLCLIENT_API std::string& operator +(std::string& s, const Capability& rt);

MLCLIENT_API const std::string translate_capability(const Capability& rt);

MLCLIENT_API Capability toCapability(const std::string& capString);

/**
 * \brief Represents a single MarkLogic Permission
 */
class Permission {
public:
  MLCLIENT_API Permission(const std::string& role,const Capability& capability);
  MLCLIENT_API Permission(Permission&& other); // move ctor
  MLCLIENT_API Permission(const Permission& other) = default; // copy ctor
  MLCLIENT_API virtual ~Permission() = default;

  MLCLIENT_API Permission& operator=(const Permission& other) = default; // default copy assignment operator

  MLCLIENT_API const std::string& getRole() const;
  MLCLIENT_API void setRole(const std::string& role);
  MLCLIENT_API const Capability& getCapability() const;
  MLCLIENT_API void setCapability(const Capability& capability);

private:
  std::string role;
  Capability capability;
};

MLCLIENT_API std::ostream& operator << (std::ostream& os, const Permission& rt);
MLCLIENT_API std::string& operator +(std::string& s, const Permission& rt);

MLCLIENT_API const std::string translate_permission(const Permission& rt);

/**
 * \brief Represents a set of Permission object instances.
 *
 * \since 8.0.2
 */
typedef std::vector<Permission> PermissionSet;

/**
 * \brief Provides an Iterator over a set of Permission instances.
 *
 * \since 8.0.2
 */
typedef std::vector<Permission>::const_iterator PermissionIterator;




/*

class PermissionListIterator; // fwd declaration

class PermissionList {
public:
  MLCLIENT_API PermissionList();
  MLCLIENT_API ~PermissionList();

  MLCLIENT_API void add(Permission& in_perm);
  MLCLIENT_API PermissionListIterator begin();
  MLCLIENT_API PermissionListIterator end();

  friend class PermissionListIterator;

private:
  std::vector<Permission> list;
};

class PermissionListIterator {
public:
  MLCLIENT_API PermissionListIterator();
  MLCLIENT_API PermissionListIterator(PermissionList* set);
  MLCLIENT_API PermissionListIterator(PermissionList* set,long pos);

  MLCLIENT_API PermissionListIterator begin();
  MLCLIENT_API PermissionListIterator end();

  MLCLIENT_API bool operator==(const PermissionListIterator& other);
  MLCLIENT_API bool operator!=(const PermissionListIterator& other);
  MLCLIENT_API void operator++();
  MLCLIENT_API const Permission& operator*();
  MLCLIENT_API PermissionListIterator operator=(const PermissionListIterator& other);

  MLCLIENT_API const Permission& first() const;

private:
  PermissionList* list;
  long position;
};
*/

} // end namespace mlclient

#endif /* INCLUDE_MLCLIENT_PERMISSION_HPP_ */
