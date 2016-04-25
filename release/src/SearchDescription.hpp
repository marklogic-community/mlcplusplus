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
  ~SearchDescription();
  void setOptions(TextDocumentContent& options);
  TextDocumentContent getOptions();
  void setQuery(TextDocumentContent& query);
  TextDocumentContent getQuery();
  void setQueryText(std::string qtext);
  std::string getQueryText();
  /**
   * Returns a string representation of the total payload for this search, as passed to MarkLogic Server
   */
  DocumentContent& getPayload();
private:
  class Impl;
  Impl* mImpl;
};

} // end mlclient namespace


#endif /* SRC_SEARCHDESCRIPTION_HPP_ */
