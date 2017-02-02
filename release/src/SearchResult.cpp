/*
 * SearchResult.cpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#include "mlclient/SearchResult.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/logging.hpp"

namespace mlclient {

class SearchResult::Impl {
public:
  Impl() {
    ;
  }
};

SearchResult::SearchResult() : mImpl(new Impl), index(0),uri(""),path(""),score(0),confidence(0.0),fitness(0.0),detail(Detail::NONE),detailContent(nullptr), format(Format::JSON) {
  //TIMED_FUNC(SearchResult_defaultConstructor);
  //LOG(DEBUG) << "    SearchResult::defaultConstructor @" << &*this;
}

SearchResult::~SearchResult() {
  //TIMED_FUNC(SearchResult_destructor);
  //LOG(DEBUG) << "    SearchResult::destructor @" << &*this;
  //delete this->detailContent;
  //detailContent = nullptr;
}

SearchResult::SearchResult(const long index, const std::string& uri, const std::string& path,const long score,
    const double confidence,const double fitness,const Detail& detail,std::shared_ptr<IDocumentNode>& own_detailContent,
    const std::string& mimeType,const Format& format) : mImpl(new Impl) {
  //TIMED_FUNC(SearchResult_detailConstructor);
  //LOG(DEBUG) << "    SearchResult::detailedConstructor @" << &*this;
  this->index = index;
  this->uri = uri;
  this->path = path;
  this->score = score;
  this->confidence = confidence;
  this->fitness = fitness;
  this->detail = detail;
  this->detailContent = own_detailContent;
  this->mimeType = mimeType;
  this->format = format;
}

SearchResult::SearchResult(SearchResult&& other) {
  //TIMED_FUNC(SearchResult_moveConstructor);
  //LOG(DEBUG) << "    SearchResult::moveConstructor @" << &*this;
  mImpl = other.mImpl;
  other.mImpl = nullptr;
  this->index = std::move(other.index);
  this->uri = std::move(other.uri);
  this->path = std::move(other.path);
  this->score = std::move(other.score);
  this->fitness = std::move(other.fitness);
  this->detail = std::move(other.detail);
  this->detailContent = other.detailContent;
  //other.detailContent = nullptr;
  this->mimeType = std::move(other.mimeType);
  this->format = std::move(other.format);
  this->confidence = std::move(other.confidence);
}

SearchResult& SearchResult::operator= (const SearchResult&& other) {
  //LOG(DEBUG) << "    SearchResult::copy assignment operator @" << &*this;

  this->index = other.index;
  this->uri = other.uri;
  this->path = other.path;
  this->score = other.score;
  this->fitness = other.fitness;
  this->detail = other.detail;
  this->detailContent = other.detailContent;
  this->mimeType = other.mimeType;
  this->format = other.format;
  this->confidence = other.confidence;
  return *this;
}

SearchResult& SearchResult::operator= (SearchResult&& other) {
  //LOG(DEBUG) << "    SearchResult::move assignment operator @" << &*this;
  mImpl = other.mImpl;
  other.mImpl = nullptr;
  this->index = std::move(other.index);
  this->uri = std::move(other.uri);
  this->path = std::move(other.path);
  this->score = std::move(other.score);
  this->fitness = std::move(other.fitness);
  this->detail = std::move(other.detail);
  this->detailContent = other.detailContent;
  other.detailContent = nullptr;
  this->mimeType = std::move(other.mimeType);
  this->format = std::move(other.format);
  this->confidence = std::move(other.confidence);
  return *this;
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
const SearchResult::Detail& SearchResult::getDetail() const {
  return detail;
}
std::shared_ptr<IDocumentNode> SearchResult::getDetailContent() const {
  //TIMED_FUNC(SearchResult_getDetailContent);
  return detailContent;
}
void SearchResult::releaseContent() {
  detailContent.reset();
}
const std::string& SearchResult::getMimeType() const {
  return mimeType;
}
const Format& SearchResult::getFormat() const {
  return format;
}

} // end namespace mlclient
