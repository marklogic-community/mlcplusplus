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

/**
 * \brief Provides support for multiple values result lookups in a single hit
 */
class ValuesResultSet {
public:
  /**
   * A public typedef for the values iterator. This prevents recoding if we change the implementation in future.
   */
  typedef ValuesIterator const_iterator;

  /**
   * \brief Creates a ValuesResultSet linked to the provided connection instance
   *
   * \param conn The connection instance. This class does NOT delete this connection upon destruction.
   */
  MLCLIENT_API ValuesResultSet(IConnection* conn);

  /**
   * \brief Delete copy constructor to prevent concurrent updates of same underlying data
   */
  MLCLIENT_API ValuesResultSet(const ValuesResultSet& other) = delete;

  MLCLIENT_API ~ValuesResultSet();

  /**
   * \brief Adds a values lexicon lookup to this batch process
   * \param optionsName The search options to perform the lookup against
   * \param valuesName The values configuration named within the specified search options
   */
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

/**
 * \brief Provides an STL compliant iterator implementation over a ValuesResultSet
 *
 * \warning Not quite STL compliant - it returns pointers rather than references. This
 * should be fixed in 8.0.3. In particular in your loop you need to have this as your comparison:
 * (*iter) != (*(myresultset::end())) and for the increment operator: ++(*iter)
 *
 * See the ValuesResultSetTest class for a sample use under release/test
 *
 * \since 8.0.2
 */
class ValuesIterator {
public:
  /**
   * \brief Default Constructor
   */
  MLCLIENT_API ValuesIterator();
  /**
   * \brief Creates a ValuesIterator that wraps a result set, starting from the first result
   * \param set The result set to wrap
   */
  MLCLIENT_API ValuesIterator(ValuesResultSet* set);
  /**
   * \brief Creates a ValuesIterator that wraps a result set, starting from the specified position
   * \param set The result set to wrap
   * \param pos The position to start iterating from
   */
  MLCLIENT_API ValuesIterator(ValuesResultSet* set,long pos);

  /**
   * \brief Returns the start iterator
   * \return The starting point iterator
   */
  MLCLIENT_API ValuesIterator* begin();
  /**
   * \brief Returns the iterator end marker
   * \return The iterator end marker
   */
  MLCLIENT_API ValuesIterator* end();

  /**
   * \brief Whether this instance is the 'same' (same position value) as the other instance
   * \param other The ValuesIterator to compare this instance against
   * \return True if the iterators have the same position
   */
  MLCLIENT_API bool operator==(const ValuesIterator& other);
  /**
   * \brief Whether this instance is NOT the 'same' (same position value) as the other instance
   * \param other The ValuesIterator to compare this instance against
   * \return True if the iterators do not have the same position
   */
  MLCLIENT_API bool operator!=(const ValuesIterator& other);
  /**
   * \brief increments this iterator instance's position
   */
  MLCLIENT_API void operator++();
  /**
   * \brief Returns a pointer to the ValuesResult at the current position in the set
   * \return The ValuesResult at this position
   */
  MLCLIENT_API const ValuesResult operator*();
  /**
   * \brief copy assignment operator
   * \param other The ValuesIterator to copy
   * \return The current ValuesIterator instance
   */
  MLCLIENT_API ValuesIterator operator=(const ValuesIterator& other);

  /**
   * \brief Returns the first ValuesResult in the result set
   * \return The first values result in the result set
   */
  MLCLIENT_API const ValuesResult& first() const;

private:
  ValuesResultSet* mResultSet;
  long position;
};

}


#endif /* INCLUDE_MLCLIENT_VALUESRESULTSET_HPP_ */
