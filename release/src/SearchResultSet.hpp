/*
 * SearchResultSet.hpp
 *
 *  Created on: 25 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_SEARCHRESULTSET_HPP_
#define SRC_UTILITIES_SEARCHRESULTSET_HPP_

#include "SearchResult.hpp"
#include "Connection.hpp"
#include "SearchDescription.hpp"
#include <list>

namespace mlclient {

/**
 * \brief A self-advancing result set class
 *
 * Sometimes it is useful to advance beyond 1 page of search results in MarkLogic.
 * This class allows this to happen whilst carrying out any additional page requests
 * to the underlying Connection when needed.
 */
class SearchResultSet {
public:
  typedef std::list<SearchResult>::const_iterator const_iterator ;

  /**
   * \brief Creates a self-advancing result set given the specified search description
   */
  SearchResultSet(const IConnection& conn,const SearchDescription& desc);

  /**
   * \brief Destroys a SearchResultSet and all of its owned resources
   */
  virtual ~SearchResultSet() = default;

  // iterator methods around each search result
  const_iterator begin() const;
  const_iterator end() const;

  // TODO initially, no request
  // TODO then just make a request at end of a collection
  // TODO in future though, specify how many pages we pre-fetch asynchronously between page processing operations (provide subclass of iterator)

  /**
   * \brief Uses the provided Connection and SearchDescription to perform a request, and initial this object and the list of results.
   *
   * \note You can call the functions begin() and end() immediately after fetch() returns (fetch() uses synchronous request functions in Connection)
   * \return true if no errors were raised, false otherwise
   */
  bool fetch();

  /**
   * \brief Returns the exception, if any, encountered by fetch(). nullptr is returned if no exception raised.
   */
  std::exception* getFetchException();

private:
  IConnection& mConn;
  SearchDescription& mInitialDescription;
  std::list<SearchResult> mResults;
  std::exception* mFetchException;
};

} // end namespace mlclient

#endif /* SRC_UTILITIES_SEARCHRESULTSET_HPP_ */
