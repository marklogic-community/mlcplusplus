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
 * PathNavigator.hpp
 *
 * \date 2016-12-06
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.3
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_PATHNAVIGATOR_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_PATHNAVIGATOR_HPP_

#include <mlclient/Document.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/DocumentContent.hpp>

namespace mlclient {

namespace utilities {

class PathNavigator {
public:
    PathNavigator() = delete;
    ~PathNavigator() = delete;

    MLCLIENT_API static IDocumentNode* navigate(const IDocumentNavigator* nav,const std::string& path);

    MLCLIENT_API static IDocumentNode* at(const IDocumentNode* node,const std::string& subpath);
};

} // end namespace utilities

} // end namespace mlclient

#endif /* define INCLUDE_MLCLIENT_UTILITIES_PATHNAVIGATOR_HPP_ */

