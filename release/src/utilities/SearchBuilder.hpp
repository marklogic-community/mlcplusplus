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
 * \file SearchBuilder.hpp
 *
 * \date 2016-06-08
 * \author Adam Fowler <adam.fowler@marklogic.com>
 */

#include "../SearchDescription.hpp"
#include <list>
#include <string>

namespace mlclient {

namespace utilities {

class IQuery {
  // TODO define IQuery
};

class IContainerRef {
  // TODO define IContainerRef
};

class ITypedValue {
  // TODO define ITypedValue
};

/**
 * \class SearchBuilder
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.2
 * \date 2016-06-08
 *
 * \brief This class helps create a MarkLogic complex search JSON object for use with SearchDescription
 *
 * \note This class deals only with a complex search, NOT search options or text grammar.
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class SearchBuilder {
public:
  enum RangeOperation {
    Equal,NotEqual,LessThan,LessThanOrEqual,MoreThan,MoreThanOrEqual
  };

  SearchBuilder() = default;
  ~SearchBuilder() = default;

  // public static methods that create query terms and option constraints
  static IQuery& createCollectionQuery(const std::string& collection);
  static IQuery& createWordQuery(const IContainerRef& container,const std::string& value);
  static IQuery& createValueQuery(const IContainerRef& container,const ITypedValue& value);
  static IQuery& createRangeQuery(const IContainerRef& container,const SearchBuilder::RangeOperation operation,const ITypedValue& value);
  static IQuery& createConstraintQuery(const std::string& constraintName,const ITypedValue& value);
  static IQuery& createUriQuery(const std::list<std::string> uris);

  // public class methods that control the create of a search or query
  SearchBuilder* andQuery(const std::list<IQuery&> queries);
  SearchBuilder* orQuery(const std::list<IQuery&> queries);
  SearchBuilder* notQuery(const std::list<IQuery&> queries);

private:

}; // end SearchBuilder class

} // end namespace utilities

} // end namespace mlclient

