/**
 * \file SearchDescription.hpp
 * \since 8.0.0
 * \date 2016-04-25
 *
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_SEARCHDESCRIPTION_HPP_
#define SRC_SEARCHDESCRIPTION_HPP_

#include "DocumentContent.hpp"

namespace mlclient {

/**
 * \class SearchDescription
 * \since 8.0.0
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \date 2016-04-25
 *
 * \brief A POD class representing input to the POST of /v1/search - i.e. all search configuration
 *
 * May contain just query text, a complex query, options, or a mix thereof.
 *
 * Used to simplify calls to Connection::search
 *
 * Defaults to a blank text query (i.e. return all results) and default (server side configured) options.
 */
class SearchDescription {
public:
  /**
   * \brief Default Constructor
   */
  SearchDescription();
  /**
   * \brief Default destructor
   *
   * \note Virtual so allows subclassing
   */
  virtual ~SearchDescription(); // allows subclassing

  /**
   * \brief Set the search options content
   *
   * Could be either an XML or JSON description of search options.
   *
   * See CppRestJsonHelper or PugiXmlHelper to create a TextDocumentContent that wraps raw JSON or XML strings.
   *
   * \param[inout] options The search options as an XML or JSON DocumentContent instance
   */
  void setOptions(TextDocumentContent& options);

  /**
   * \brief Returns the options as a document
   * \return A non-editable reference to the underlying search options.
   */
  const TextDocumentContent& getOptions() const;

  /**
   * \brief Sets the complex query using an XML or JSON DocumentContent instance
   *
   * See CppRestJsonHelper or PugiXmlHelper to create a TextDocumentContent that wraps raw JSON or XML strings.
   *
   * \param[inout] query The TextDocumentContent instance wrapping the XML or JSON query.
   */
  void setQuery(TextDocumentContent& query);

  /**
   * \brief Returns the complex query as a document
   *
   * \note Does not return a representation of the query text as a cts:query - use ::getQueryText for that
   *
   * \return A non editable reference to the underlying complex query TextDocumentContent
   */
  const TextDocumentContent& getQuery() const;

  /**
   * \brief Sets the plain text query text.
   *
   * This can be used at the same time as a complex query in POST /v1/search (i.e. in Connection::search )
   *
   * \param[inout] qtext The plain text query
   */
  void setQueryText(std::string qtext);

  /**
   * \brief Returns the plain text query
   *
   * \return A non-editable reference to the underlying string query text.
   */
  const std::string& getQueryText() const;

  /**
   * \brief Returns a string representation of the total payload for this search, as passed to MarkLogic Server
   *
   * Includes search complex query, query text, and options document, if supplied.
   *
   * Used as the raw input to POST /v1/search, and encompasses all search configuration
   *
   * \return A TextDocumentContent (Which may be XML or JSON) wrapping the entire search request. Caller is responsible for deleting this object.
   */
  TextDocumentContent* getPayload() const;
private:
  class Impl;
  Impl* mImpl;
};

} // end mlclient namespace


#endif /* SRC_SEARCHDESCRIPTION_HPP_ */
