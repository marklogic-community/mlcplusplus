/*
 * SearchDescription.hpp
 *
 *  Created on: 25 Apr 2016
 *      Author: adamfowler
 */

#ifndef SRC_SEARCHDESCRIPTION_HPP_
#define SRC_SEARCHDESCRIPTION_HPP_

#include "DocumentContent.hpp"

namespace mlclient {

class SearchDescription {
public:
  SearchDescription();
  virtual ~SearchDescription(); // allows subclassing

  void setOptions(TextDocumentContent& options);
  const TextDocumentContent& getOptions() const;
  void setQuery(TextDocumentContent& query);
  const TextDocumentContent& getQuery() const;
  void setQueryText(std::string qtext);
  const std::string& getQueryText() const;
  /**
   * Returns a string representation of the total payload for this search, as passed to MarkLogic Server (includes search, qtext, and options)
   */
  const TextDocumentContent& getPayload() const;
private:
  class Impl;
  Impl* mImpl;
};

} // end mlclient namespace


#endif /* SRC_SEARCHDESCRIPTION_HPP_ */
