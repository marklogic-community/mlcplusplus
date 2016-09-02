/*
 * Document.cpp
 *
 *  Created on: 9 Aug 2016
 *      Author: adamfowler
 */

#include <mlclient/Document.hpp>

#include <string>

namespace mlclient {

Document::Document() : uri(""), content(nullptr), properties(nullptr), permissions(), collections() {
  ;
}
Document::Document(const std::string& uri) : uri(uri), content(nullptr), properties(nullptr), permissions(), collections() {
  ;
}
Document::Document(const std::string& uri,IDocumentContent* own_content)
  : uri(uri), content(own_content), properties(nullptr), permissions(), collections() {
  ;
}
Document::Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties)
  : uri(uri), content(own_content), properties(own_properties), permissions(), collections() {
  ;
}
Document::Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties,std::vector<Permission> own_permissions)
  : uri(uri), content(own_content), properties(own_properties), permissions(own_permissions), collections() {
  ;
}

const std::string& Document::getUri() const {
  return uri;
}
void Document::setUri(const std::string& uri) {
  this->uri = uri;
}
const bool Document::hasUri() const {
  return 0 != strcmp("",uri.c_str());
}


const std::vector<std::string> Document::getCollections() const {
  return collections;
}
void Document::setCollections(const std::vector<std::string>& collections) {
  this->collections = collections;
}
const bool Document::hasCollections() const {
  return 0 != collections.size();
}

const IDocumentContent* Document::getContent() const {
  return content;
}
void Document::setContent(IDocumentContent* own_content) {
  content = own_content;
}
const bool Document::hasContent() const {
  return nullptr != content;
}

const IDocumentContent* Document::getProperties() const {
  return properties;
}
const bool Document::hasProperties() const {
  return nullptr != properties;
}
void Document::setProperties(IDocumentContent* own_properties) {
  properties = own_properties;
}

const std::vector<Permission> Document::getPermissions() const {
  return permissions;
}
const bool Document::hasPermissions() const {
  return 0 != permissions.size();
}
void Document::setPermissions(std::vector<Permission> own_permissions) {
  permissions = own_permissions;
}

bool Document::operator==(const Document& other) {
  return uri == other.uri;
}
bool Document::operator!=(const Document& other) {
  return uri != other.uri;
}

} // end namespace mlclient
