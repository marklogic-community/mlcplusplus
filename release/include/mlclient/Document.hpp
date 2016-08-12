/*
 * \file Document.hpp
 *
 * \date 2016-08-04
 * \author adamfowler
 * \since 8.0.2
 *
 */

#ifndef INCLUDE_MLCLIENT_DOCUMENT_HPP_
#define INCLUDE_MLCLIENT_DOCUMENT_HPP_

#include <mlclient/DocumentContent.hpp>
#include <mlclient/Permission.hpp>
#include <vector>

namespace mlclient {

/**
 * \brief Provides a representation of a MarkLogic Document.
 * \since 8.0.2
 * \date 2016-08-04
 *
 * \note The top level Document object is implementation independent and so is a concrete class.
 */
class Document {
public:
  Document();
  Document(const std::string& uri);
  Document(const std::string& uri,IDocumentContent* own_content);
  Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties);
  Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties,std::vector<Permission> own_permissions);
  virtual ~Document() = default;

  const std::string& getUri() const;
  void setUri(const std::string& uri);
  const bool hasUri() const;

  const std::vector<std::string> getCollections() const;
  void setCollections(const std::vector<std::string>& collections);
  const bool hasCollections() const;

  const IDocumentContent* getContent() const;
  const bool hasContent() const;
  void setContent(IDocumentContent* own_content);

  const IDocumentContent* getProperties() const;
  const bool hasProperties() const;
  void setProperties(IDocumentContent* own_properties);

  const std::vector<Permission> getPermissions() const;
  const bool hasPermissions() const;
  void setPermissions(std::vector<Permission> own_permissions);

private:
  std::string uri;
  IDocumentContent* content;
  IDocumentContent* properties;
  std::vector<Permission> permissions;
  std::vector<std::string> collections;
};

} // end namespace mlclient


#endif /* INCLUDE_MLCLIENT_DOCUMENT_HPP_ */
