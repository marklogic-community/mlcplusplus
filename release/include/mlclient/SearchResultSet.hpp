/*
 * SearchResultSet.hpp
 *
 *  Created on: 25 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_SEARCHRESULTSET_HPP_
#define SRC_UTILITIES_SEARCHRESULTSET_HPP_

#include "mlclient/mlclient.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/SearchDescription.hpp"

#include <vector>

namespace mlclient {

class SearchResultSetIterator; // fwd declaration - see end of file

/**
 * \brief A self-advancing result set class
 *
 * Sometimes it is useful to advance beyond 1 page of search results in MarkLogic.
 * This class allows this to happen whilst carrying out any additional page requests
 * to the underlying Connection when needed.
 */
class SearchResultSet {
public:

  /**
   * A public typedef for the iterator. This prevents recoding if we change the implementation in future.
   */
  typedef SearchResultSetIterator const_iterator ;

  /**
   * \brief Creates a self-advancing result set given the specified search description
   * \param conn The Connection instance pointer
   * \param desc The Search Description to use for requests - will be owned by this class
   */
  MLCLIENT_API SearchResultSet(IConnection* conn,SearchDescription* desc);

  /**
   * \brief Destroys a SearchResultSet and all of its owned resources
   */
  MLCLIENT_API virtual ~SearchResultSet() = default;

  // iterator methods around each search result
  /**
   * \brief Returns the iterator for this result set
   * \return The iterator for this result set
   */
  MLCLIENT_API SearchResultSetIterator* begin() const;
  /**
   * \brief Returns a reference to the end of the iterator for this result set
   * \return A reference to the end of the iterator for this result set
   */
  MLCLIENT_API SearchResultSetIterator* end() const;

  // TODO initially, no request
  // TODO then just make a request at end of a collection
  // TODO in future though, specify how many pages we pre-fetch asynchronously between page processing operations (provide subclass of iterator)

  /**
   * \brief Uses the provided Connection and SearchDescription to perform a request, and initial this object and the list of results.
   *
   * \note You can call the functions begin() and end() immediately after fetch() returns (fetch() uses synchronous request functions in Connection)
   * \return true if no errors were raised, false otherwise
   */
  MLCLIENT_API bool fetch();

  /**
   * \brief Returns the exception, if any, encountered by fetch(). nullptr is returned if no exception raised.
   * \return The exception instance pointer
   */
  MLCLIENT_API std::exception* getFetchException();

  /**
   * \brief Returns the sequence number of the first search result
   *
   * \note MarkLogic uses 1 based numbers. Thus the first record is at position 1, not position 0
   * \return The first result's sequence number (lowest is 1)
   */
  MLCLIENT_API const long getStart();

  /**
   * \brief Returns the total count of all search results, across all pages
   * \note MarkLogic Server uses xdmp:estimate to calculate this. Thus for an accurate number your
   * filtered xdmp estimate should be the same as your unfiltered xdmp estimate. I.e. should be completely
   * calculable from indexes. Otherwise, this total could be higher than the actual number of results (after filtering).
   * \return The total number of search results returned.
   */
  MLCLIENT_API const long getTotal();

  /**
   * \brief Returns the number of results returned on each page
   * \note MarkLogic Server defaults to 10 per page. This may or may not be the most performant option, depending on
   * search options and thus amount of data returned per result. Try a higher number for better throughput for XML/JSON content.
   * \note This class will automatically fetch the next page of results until they are exhausted, so no need to handle this yourself.
   * \return The number of results returned per page.
   */
  MLCLIENT_API const long getPageLength();

  /**
   * \brief Returns the snippet format. Could be raw, none, or snippet.
   * \return The string description as returned by the REST API. Usually "raw","none",or "snippet". Could be "custom" depending on search options.
   */
  MLCLIENT_API const std::string& getSnippetFormat() const;

  /**
   * \brief Returns the query resolution time for the last page requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the time to resolve the query
   */
  MLCLIENT_API const std::string& getQueryResolutionTime() const;

  /**
   * \brief Returns the snippet resolution time for the last page requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the time to resolve the snippet
   */
  MLCLIENT_API const std::string& getSnippetResolutionTime() const;

  /**
   * \brief Returns the total time taken for the last page requested, if available.
   *
   * Defaults to zero. Uses xsd:duration string format as per the REST API
   *
   * \return xsd:duration string description of the total time taken (includes both snippet and query resolution time)
   */
  MLCLIENT_API const std::string& getTotalTime() const;

  /**
   * \brief Utility function to return the total number of pages in the result set
   * \return The total number of pages in the result set
   */
  MLCLIENT_API const long getPageCount() const;

  /**
   * \brief Sets the maximum number of results to return. Useful if the maximum is larger than the page size.
   * \note Limits the iterator return to max results
   */
  MLCLIENT_API void setMaxResults(long maxResults);

  friend class SearchResultSetIterator;

private:
  class Impl; // forward declaration
  Impl* mImpl;
};


class SearchResultSetIterator {
public:
  MLCLIENT_API SearchResultSetIterator();
  MLCLIENT_API SearchResultSetIterator(SearchResultSet* set);
  MLCLIENT_API SearchResultSetIterator(SearchResultSet* set,long pos);

  MLCLIENT_API SearchResultSetIterator* begin();
  MLCLIENT_API SearchResultSetIterator* end();

  MLCLIENT_API bool operator==(const SearchResultSetIterator& other);
  MLCLIENT_API bool operator!=(const SearchResultSetIterator& other);
  MLCLIENT_API void operator++();
  MLCLIENT_API const SearchResult operator*();
  MLCLIENT_API SearchResultSetIterator operator=(const SearchResultSetIterator& other);

  MLCLIENT_API const SearchResult& first() const;

private:
  SearchResultSet* mResultSet;
  long position;
};

} // end namespace mlclient

#endif /* SRC_UTILITIES_SEARCHRESULTSET_HPP_ */
