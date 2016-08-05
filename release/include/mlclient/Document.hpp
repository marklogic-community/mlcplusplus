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
  virtual ~Document();

  const std::string& getUri() const;
  void setUri(const std::string& uri);

  const IDocumentContent* getContent() const;
  void setContent(IDocumentContent* own_content);

  const IDocumentContent* getProperties() const;
  void setProperties(IDocumentContent* own_properties);

  const std::vector<Permission> getPermissions() const;
  void setPermissions(std::vector<Permission> own_permissions);

private:

};

} // end namespace mlclient


#endif /* INCLUDE_MLCLIENT_DOCUMENT_HPP_ */
