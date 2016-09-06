/**
 * \file DocumentSet.hpp
 *
 * \date 20 Aug 2016
 * \author adamfowler
 */

#ifndef INCLUDE_MLCLIENT_DOCUMENTSET_HPP_
#define INCLUDE_MLCLIENT_DOCUMENTSET_HPP_

#include <mlclient/Document.hpp>

namespace mlclient {


  /**
   * \brief Represents a set of Document object instances.
   *
   * \since 8.0.2
   */
  typedef std::vector<Document> DocumentSet;

  /**
   * \brief Provides an Iterator over a set of document instances.
   *
   * \since 8.0.2
   */
  typedef std::vector<Document>::const_iterator DocumentIterator;




//class DocumentIterator;

/*
class DocumentSet { // TODO check to see if this can be replaced by a typedef
public:
  MLCLIENT_API DocumentSet();
  MLCLIENT_API DocumentSet(const DocumentSet& other);
  MLCLIENT_API DocumentSet(DocumentSet&& other);
  MLCLIENT_API ~DocumentSet();

  MLCLIENT_API void add(Document& own_other);
  MLCLIENT_API void add(const Document& other);
  MLCLIENT_API void remove(const Document& member);

  MLCLIENT_API Document& at(long idx) &; // return lvalue reference only

  MLCLIENT_API const DocumentIterator begin() const;
  MLCLIENT_API const DocumentIterator end() const;

  MLCLIENT_API const long size() const;
  MLCLIENT_API void clear();

private:
  class Impl;
  std::unique_ptr<Impl> mImpl;
};
*/

} // end namespace mlclient



#endif /* INCLUDE_MLCLIENT_DOCUMENTSET_HPP_ */
