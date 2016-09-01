/*
 * ValuesResultSet.hpp
 *
 *  Created on: 12 Aug 2016
 *      Author: adamfowler
 */

#ifndef INCLUDE_MLCLIENT_VALUESRESULTSET_HPP_
#define INCLUDE_MLCLIENT_VALUESRESULTSET_HPP_

#include <mlclient/mlclient.hpp>
#include <mlclient/ValuesResult.hpp>
#include <mlclient/Connection.hpp>

namespace mlclient {

class ValuesIterator; // forward declaration - see end of file

class ValuesResultSet {
public:
  /**
   * A public typedef for the values iterator. This prevents recoding if we change the implementation in future.
   */
  typedef ValuesIterator const_iterator;

  MLCLIENT_API ValuesResultSet(IConnection* conn);

  MLCLIENT_API ValuesResultSet(const ValuesResultSet& other) = delete;

  MLCLIENT_API ~ValuesResultSet();

  MLCLIENT_API void addLookup(const std::string& optionsName,const std::string& valuesName);

  /**
   * \brief Returns the total number of lookups we have results for
   * \return total The total number of lookups we have results for
   */
  MLCLIENT_API const long getTotal() const;

  // iterator methods around each values result
  /**
   * \brief Returns the iterator for this values result set
   * \return The iterator for this values result set
   */
  MLCLIENT_API ValuesIterator* begin();
  /**
   * \brief Returns a reference to the end of the iterator for this values result set
   * \return A reference to the end of the iterator for this values result set
   */
  MLCLIENT_API ValuesIterator* end();

  /**
   * \brief Uses the provided Connection to perform a request, and initialise this object and the list of values results.
   *
   * \note You can call the functions begin() and end() immediately after fetch() returns (they will block)
   *
   * \note This function actually sends one request out per aggregate or lexicon lookup request
   *
   * \return true if no errors were raised, false otherwise
   */
  MLCLIENT_API bool fetch();

  /**
   * \brief Returns the exception, if any, encountered by fetch(). nullptr is returned if no exception raised.
   * \return The exception instance pointer
   */
  MLCLIENT_API std::exception* getFetchException();

  friend class ValuesIterator;

private:
  class Impl; // forward declaration
  std::unique_ptr<Impl> mImpl;

  void wait() const;
};


class ValuesIterator {
public:
  MLCLIENT_API ValuesIterator();
  MLCLIENT_API ValuesIterator(ValuesResultSet* set);
  MLCLIENT_API ValuesIterator(ValuesResultSet* set,long pos);

  MLCLIENT_API ValuesIterator* begin();
  MLCLIENT_API ValuesIterator* end();

  MLCLIENT_API bool operator==(const ValuesIterator& other);
  MLCLIENT_API bool operator!=(const ValuesIterator& other);
  MLCLIENT_API void operator++();
  MLCLIENT_API const ValuesResult operator*();
  MLCLIENT_API ValuesIterator operator=(const ValuesIterator& other);

  MLCLIENT_API const ValuesResult& first() const;

private:
  ValuesResultSet* mResultSet;
  long position;
};

}


#endif /* INCLUDE_MLCLIENT_VALUESRESULTSET_HPP_ */
