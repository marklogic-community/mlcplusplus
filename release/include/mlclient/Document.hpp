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
  /**
   * \brief Creates an empty Document object
   */
  MLCLIENT_API Document();
  /**
   * \brief Creates a Document that holds only a URI reference
   *
   * \param[in] uri The URI for the Document within MarkLogic Server
   */
  MLCLIENT_API Document(const std::string& uri);
  /**
   * \brief Creates a document with a URI and document content fragment
   *
   * \param[in] uri The URI for the Document within MarkLogic Server
   * \param[in] own_content The content fragment. The Document class owns this reference, and deletes it upon destruction
   */
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content);
  /**
   * \brief Creates a Document with a URI, document content fragment, and a document properties document fragment
   *
   * \param[in] uri The URI for the Document within MarkLogic Server
   * \param[in] own_content The content fragment. The Document class owns this reference, and deletes it upon destruction
   * \param[in] own_properties The properties fragment. The Document class owns this reference, and deletes it upon destruction
   */
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties);
  /**
   * \brief Creates a Document with a URI, document content fragment, and a document properties document fragment, and a set of permissions
   *
   * \param[in] uri The URI for the Document within MarkLogic Server
   * \param[in] own_content The content fragment. The Document class owns this reference, and deletes it upon destruction
   * \param[in] own_properties The properties fragment. The Document class owns this reference, and deletes it upon destruction
   * \param[in] own_permissions The permission set to apply. The Document class owns this reference, and deletes it upon destruction
   */
  MLCLIENT_API Document(const std::string& uri,IDocumentContent* own_content,IDocumentContent* own_properties,PermissionSet own_permissions);
  /**
   * \brief Default Destructor
   */
  MLCLIENT_API virtual ~Document() = default;

  /**
   * \brief Returns the URI of this document
   *
   * Returns an empty string if not set
   *
   * \return The document URI, or empty string
   */
  MLCLIENT_API const std::string& getUri() const;
  /**
   * \brief Sets the Document URI
   *
   * \param uri The document URI string
   */
  MLCLIENT_API void setUri(const std::string& uri);
  /**
   * \brief Returns true if the Document's URI has been set
   *
   * \return True if the Document URI has been set, false if blank
   */
  MLCLIENT_API const bool hasUri() const;

  /**
   * \brief Returns the set of collections this document belongs to
   *
   * \note A CollectionSet is a typedef for std::vector<std::string>
   *
   * \return The set of collections this document belongs to. An empty Set if not specified.
   */
  MLCLIENT_API const CollectionSet getCollections() const;
  /**
   * \brief Sets the collections this Document is a member of
   *
   * \note A CollectionSet is a typedef for std::vector<std::string>
   *
   * \param collections The collections the document is a member of
   */
  MLCLIENT_API void setCollections(const CollectionSet& collections);
  /**
   * \brief Whether this document has any collections set
   *
   * \return True if this document's collections have been set
   */
  MLCLIENT_API const bool hasCollections() const;

  /**
   * \brief Returns the content fragment of this document
   *
   * \return The content fragment pointer. nullptr if no content is set (use hasContent() to check)
   */
  MLCLIENT_API const IDocumentContent* getContent() const;
  /**
   * \brief Whether this document has it's content fragment set
   *
   * \return True if the content fragment has been set on this document instance
   */
  MLCLIENT_API const bool hasContent() const;
  /**
   * \brief Sets the content fragment of this document instance
   *
   * \param own_content The content fragment. This class OWNS this pointer from this point on, and deletes it upon destruction.
   */
  MLCLIENT_API void setContent(IDocumentContent* own_content);

  /**
   * \brief Retrieves the property fragment of this document instance
   *
   * \return The properties fragment document content. nullptr if not set
   */
  MLCLIENT_API const IDocumentContent* getProperties() const;
  /**
   * \brief Whether this document instance has its properties fragment set
   *
   * \return True if this document instance has its properties fragment set
   */
  MLCLIENT_API const bool hasProperties() const;
  /**
   * \brief Sets this document's properties fragment
   *
   * \param own_properties The properties fragment. This class OWNS this pointer from this point on, and deletes it upon destruction.
   */
  MLCLIENT_API void setProperties(IDocumentContent* own_properties);

  /**
   * \brief Returns the permissions set on this document instance
   *
   * \return The permission set
   */
  MLCLIENT_API const PermissionSet getPermissions() const;
  /**
   * \brief Whether this document instance has any permissions set
   *
   * \return True if this document instance has had its permissions set
   */
  MLCLIENT_API const bool hasPermissions() const;
  /**
   * \brief Sets this document's permissions
   *
   * \param own_permissions The permissions to set. Uses std::move to own the resources of the PermissionSet
   */
  MLCLIENT_API void setPermissions(PermissionSet own_permissions);

  /**
   * \brief Equality operator. Checks equality of URI only.
   */
  MLCLIENT_API bool operator==(const Document& other);
  /**
   * \brief Inequality operator. Checks inequality of URI only.
   */
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
