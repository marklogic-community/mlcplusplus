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
#include <mlclient/mlclient.hpp>
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
  MLCLIENT_API Document();
  MLCLIENT_API Document(const std::string& uri);
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content);
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties);
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties,std::vector<Permission> own_permissions);
  MLCLIENT_API virtual ~Document() = default;

  MLCLIENT_API const std::string& getUri() const;
  MLCLIENT_API void setUri(const std::string& uri);
  MLCLIENT_API const bool hasUri() const;

  MLCLIENT_API const std::vector<std::string> getCollections() const;
  MLCLIENT_API void setCollections(const std::vector<std::string>& collections);
  MLCLIENT_API const bool hasCollections() const;

  MLCLIENT_API const IDocumentContent* getContent() const;
  MLCLIENT_API const bool hasContent() const;
  MLCLIENT_API void setContent(IDocumentContent* own_content);

  MLCLIENT_API const IDocumentContent* getProperties() const;
  MLCLIENT_API const bool hasProperties() const;
  MLCLIENT_API void setProperties(IDocumentContent* own_properties);

  MLCLIENT_API const std::vector<Permission> getPermissions() const;
  MLCLIENT_API const bool hasPermissions() const;
  MLCLIENT_API void setPermissions(std::vector<Permission> own_permissions);

  MLCLIENT_API bool operator==(const Document& other);
  MLCLIENT_API bool operator!=(const Document& other);

private:
  std::string uri;
  IDocumentContent* content;
  IDocumentContent* properties;
  std::vector<Permission> permissions;
  std::vector<std::string> collections;
};

} // end namespace mlclient


#endif /* INCLUDE_MLCLIENT_DOCUMENT_HPP_ */
