/*
 * SearchResult.hpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#ifndef SRC_UTILITIES_SEARCHRESULT_HPP_
#define SRC_UTILITIES_SEARCHRESULT_HPP_

#include <string>

namespace mlclient {


class SearchResult {
public:
  enum DETAIL {
    SNIPPETS, CONTENT, NONE
  };
  static const std::string JSON;
  static const std::string XML;

  SearchResult();
  SearchResult(const SearchResult& other) = default;
  SearchResult(const long index, const std::string& uri, const std::string& path,const long score,
      const double confidence,const double fitness,const DETAIL& detail,const std::string& detailContent = "",
      const std::string& mimeType = "",const std::string& format = JSON);
  virtual ~SearchResult() = default;

  long getIndex();
  const std::string& getUri() const;
  const std::string& getPath() const;
  long getScore();
  double getConfidence();
  double getFitness();
  const DETAIL& getDetail() const;
  const std::string& getDetailContent() const;
  const std::string& getMimeType() const;
  const std::string& getFormat() const;

private:
  long index;
  std::string uri;
  std::string path;
  long score;
  double confidence;
  double fitness;
  DETAIL detail;
  std::string detailContent;
  std::string mimeType;
  std::string format;

};

} // end namespace mlclient

#endif /* SRC_UTILITIES_SEARCHRESULT_HPP_ */
