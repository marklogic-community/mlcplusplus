/*
 * Copyright (c) MarkLogic Corporation. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \file SearchOptionsBuilder.hpp
 *
 * \date 2016-06-08
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#ifndef SRC_UTILITIES_SEARCHOPTIONSBUILDER_HPP_
#define SRC_UTILITIES_SEARCHOPTIONSBUILDER_HPP_

#include "../SearchDescription.hpp"
#include "../DocumentContent.hpp"
#include "SearchBuilder.hpp"
#include <list>
#include <string>

namespace mlclient {

namespace utilities {

/**
 * \class SearchOptionsBuilder
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-06-08
 *
 * \brief This class helps create a MarkLogic search options JSON object for use with SearchDescription
 *
 * \note This class deals only with search options, NOT complex searches or text grammar.
 *
 * \note This class only ever generates JSON output, never XML. This enables the class to be more efficient,
 * using the same internal structures as required by a JSON stream.
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class SearchOptionsBuilder {
public:
  enum FragmentScope {
    Content,Properties
  };

  SearchOptionsBuilder();
  ~SearchOptionsBuilder() = default;

  // public class methods that control the create of a search or query
  SearchOptionsBuilder* additionalQuery(const IQuery& query);
  SearchOptionsBuilder* containerConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* fieldRangeConstraint(const IContainerRef& container); // use fieldContainerRef() with containerConstraint()

  //SearchOptionsBuilder* geoAttributePairConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoElementConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoElementPairConstraint(const IContainerRef& container);
  //SearchOptionsBuilder* geoPathConstraint(const IContainerRef& container);

  SearchOptionsBuilder* emptySnippet();
  SearchOptionsBuilder* rawSnippet();

  //SearchOptionsBuilder* extractAttributeMetadata();
  //SearchOptionsBuilder* extractElementMetadata();
  //SearchOptionsBuilder* extractPropertyMetadata();
  //SearchOptionsBuilder* extractConstraintMetadata();

  //SearchOptionsBuilder* forests(std::list<std::string> forests);
  //SearchOptionsBuilder* fragmentScope(SearchOptionsBuilder::FragmentScope scope);

  // TODO grammar options including - grouping, implicit, implicitAnd, implicitOr, joiner

  void fromDocument(const ITextDocumentContent& doc);
  ITextDocumentContent& toDocument();

private:
  class Impl; // forward declaration - hides underlying API dependencies
  Impl* mImpl;

}; // end SearchOptionsBuilder class

} // end namespace utilities

} // end namespace mlclient

#endif

