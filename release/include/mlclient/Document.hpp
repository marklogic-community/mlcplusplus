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
 * \brief Typedef for a Collection as a string
 *
 * \since 8.0.2
 */
typedef std::string Collection;

/**
 * \brief Represents a set of Collection object instances.
 *
 * \since 8.0.2
 */
typedef std::vector<Collection> CollectionSet;

/**
 * \brief Provides an Iterator over a set of Collection instances.
 *
 * \since 8.0.2
 */
typedef std::vector<Collection>::const_iterator CollectionIterator;


/**
 * \brief Typedef for a Document URI as a string
 *
 * \since 8.0.2
 */
typedef std::string DocumentUri;

/**
 * \brief Represents a set of DocumentUri object instances.
 *
 * \since 8.0.2
 */
typedef std::vector<DocumentUri> DocumentUriSet;

/**
 * \brief Provides an Iterator over a set of DocumentUri instances.
 *
 * \since 8.0.2
 */
typedef std::vector<DocumentUri>::const_iterator DocumentUriIterator;



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
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties,PermissionSet own_permissions);
  MLCLIENT_API virtual ~Document() = default;

  MLCLIENT_API const std::string& getUri() const;
  MLCLIENT_API void setUri(const std::string& uri);
  MLCLIENT_API const bool hasUri() const;

  MLCLIENT_API const CollectionSet getCollections() const;
  MLCLIENT_API void setCollections(const CollectionSet& collections);
  MLCLIENT_API const bool hasCollections() const;

  MLCLIENT_API const IDocumentContent* getContent() const;
  MLCLIENT_API const bool hasContent() const;
  MLCLIENT_API void setContent(IDocumentContent* own_content);

  MLCLIENT_API const IDocumentContent* getProperties() const;
  MLCLIENT_API const bool hasProperties() const;
  MLCLIENT_API void setProperties(IDocumentContent* own_properties);

  MLCLIENT_API const PermissionSet getPermissions() const;
  MLCLIENT_API const bool hasPermissions() const;
  MLCLIENT_API void setPermissions(PermissionSet own_permissions);

  MLCLIENT_API bool operator==(const Document& other);
  MLCLIENT_API bool operator!=(const Document& other);

private:
  std::string uri;
  IDocumentContent* content;
  IDocumentContent* properties;
  PermissionSet permissions;
  CollectionSet collections;
};

} // end namespace mlclient


#endif /* INCLUDE_MLCLIENT_DOCUMENT_HPP_ */
