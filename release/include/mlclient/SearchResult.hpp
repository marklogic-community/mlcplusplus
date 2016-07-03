/*
 * SearchResult.hpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_SEARCHRESULT_HPP_
#define SRC_UTILITIES_SEARCHRESULT_HPP_

#include "mlclient/mlclient.hpp"
#include "mlclient/DocumentContent.hpp"
#include <string>

namespace mlclient {

/**
 * \brief Represents a single search result. Wraps all REST API search result metadata and content.
 *
 * \since 8.0.2
 *
 * \date 2016-06-08
 *
 * A SearchResult in MarkLogic Server consistent of not just the result itself, but also its metadata.
 * Indeed, using the "none" snippet option means no content is returned, leaving just the metadata.
 */
class SearchResult {
public:
  /**
   * Represents one of the snippetting options in use by the search result
   */
  MLCLIENT_API enum DETAIL {
    SNIPPETS, CONTENT, NONE, CUSTOM
  };
  /**
   * Used to tag the search result content format as JSON
   */
  MLCLIENT_API static const std::string JSON;
  /**
   * Used to tag the search result content format as XML
   */
  MLCLIENT_API static const std::string XML;
  /**
   * Used to tag the search result content format as Binary
   */
  MLCLIENT_API static const std::string BINARY;

  /**
   * Empty constructor
   */
  MLCLIENT_API SearchResult();
  /**
   * Copy constructor
   * \param other The SearchResult to copy (shallow copy)
   */
  MLCLIENT_API SearchResult(const SearchResult& other) = default;
  /**
   * Detail constructor. Used by SearchResultSet and other search result wrapping functions and classes.
   * \param index The index (position, 1 based) of this result in the total search result list, across all pages
   * \param uri The document URI this search result represents
   * \param path The XPath representing this document (more accurately, MarkLogic Fragment)
   * \param score The search score calculated for this result
   * \param confidence The search confidence calculated for this result
   * \param fitness The search fitness calculated for this result
   * \param detail The level of snippet detail returned from the result
   * \param detailContent The raw text content of the search result
   * \param mimeType The MIME type of the result content
   * \param format The REST API format of the result (can be "json" or "xml" or "binary" or "text" or "none")
   */
  MLCLIENT_API SearchResult(const long index, const std::string& uri, const std::string& path,const long score,
      const double confidence,const double fitness,const DETAIL& detail,IDocumentContent* detailContent = nullptr,
      const std::string& mimeType = "",const std::string& format = JSON);
  MLCLIENT_API virtual ~SearchResult() = default;

  /**
   * \brief Returns the (1 based) index of this result in the total search results, across all pages
   * \return The (1 based) index
   */
  MLCLIENT_API long getIndex();
  /**
   * \brief Returns the document uri of the result
   * \return The document uri of the result
   */
  MLCLIENT_API const std::string& getUri() const;
  /**
   * \brief Returns the document (more accurately, fragment) XPath of the result
   * \return The document (fragment) XPath of the result
   */
  MLCLIENT_API const std::string& getPath() const;
  /**
   * \brief Returns the calculated search score for this result
   * \return The search score
   */
  MLCLIENT_API long getScore();
  /**
   * \brief Returns the calculated search confidence for this result
   * \return The search confidence
   */
  MLCLIENT_API double getConfidence();
  /**
   * \brief Returns the calculated search fitness for this result
   * \return The search fitness
   */
  MLCLIENT_API double getFitness();
  /**
   * \brief Returns the level of detail of this result
   * \return The level of detail returned for this result
   */
  MLCLIENT_API const DETAIL& getDetail() const;
  /**
   * \brief Returns the raw text content of this result
   * \return The raw text content of this result
   */
  MLCLIENT_API const IDocumentContent* getDetailContent() const;
  /**
   * \brief Returns the MIME type of the result
   * \return The MIME type. Could be application/json, application/xml, or any other stored MIME type
   */
  MLCLIENT_API const std::string& getMimeType() const;
  /**
   * \brief Returns the short text format of this result
   * \return The short text format of this result. Could be "text" or "json" or "xml" or "none"
   */
  MLCLIENT_API const std::string& getFormat() const;

private:
  long index;
  std::string uri;
  std::string path;
  long score;
  double confidence;
  double fitness;
  DETAIL detail;
  IDocumentContent* detailContent;
  std::string mimeType;
  std::string format;

};

} // end namespace mlclient

#endif /* SRC_UTILITIES_SEARCHRESULT_HPP_ */
