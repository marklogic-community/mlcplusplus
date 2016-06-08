/*
 * SearchResult.cpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#include "SearchResult.hpp"

namespace mlclient {

const std::string SearchResult::JSON = "json";
const std::string SearchResult::XML = "xml";

SearchResult::SearchResult() : index(0),uri(""),path(""),score(0),confidence(0.0),fitness(0.0),detail(DETAIL::NONE),detailContent("") {
  ;
}

SearchResult::SearchResult(const long index, const std::string& uri, const std::string& path,const long score,
    const double confidence,const double fitness,const DETAIL& detail,const std::string& detailContent,
    const std::string& mimeType,const std::string& format) {
  this->index = index;
  this->uri = uri;
  this->path = path;
  this->score = score;
  this->confidence = confidence;
  this->fitness = fitness;
  this->detail = detail;
  this->detailContent = detailContent;
  this->mimeType = mimeType;
  this->format = format;
}

long SearchResult::getIndex() {
  return index;
}
const std::string& SearchResult::getUri() const {
  return uri;
}
const std::string& SearchResult::getPath() const {
  return path;
}
long SearchResult::getScore() {
  return score;
}
double SearchResult::getConfidence() {
  return confidence;
}
double SearchResult::getFitness() {
  return fitness;
}
const SearchResult::DETAIL& SearchResult::getDetail() const {
  return detail;
}
const std::string& SearchResult::getDetailContent() const {
  return detailContent;
}
const std::string& SearchResult::getMimeType() const {
  return mimeType;
}
const std::string& SearchResult::getFormat() const {
  return format;
}

} // end namespace mlclient
