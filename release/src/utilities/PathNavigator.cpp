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
 * PathNavigator.cpp
 *
 * \date 2016-12-06
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.3
 */

#include <mlclient/utilities/PathNavigator.hpp>
#include <mlclient/InvalidFormatException.hpp>
#include <mlclient/DocumentContent.hpp>

// TODO replace the below with templates and the at() pattern

namespace mlclient {
namespace utilities {

IDocumentNode* PathNavigator::navigate(const IDocumentNavigator* nav,const std::string& path) {
  size_t location = path.find('/');
  size_t start = 0;
  if (std::string::npos == location) {
      throw mlclient::InvalidFormatException("No element or property at top level of path");
  }
  if (0 == location) {
      start = 1;
      location = path.find('/',start);
  }
  std::string curLevel = path.substr(start,location);
  std::string lower = "";
  if (location != path.size()) {
    lower = path.substr(location + 1);
  }

  IDocumentNode* child = nav->at(curLevel);
  if (lower.size() == 0) {
      // at end of path
      return child;
  } else {
      return at(child,lower);
  }
}

IDocumentNode* PathNavigator::at(const IDocumentNode* node,const std::string& subpath) {
  size_t location = subpath.find('/');
  size_t start = 0;
  if (std::string::npos == location) {
    if (subpath.size() == 0) {
      throw mlclient::InvalidFormatException("No element or property at lower level of path");
    }
    location = subpath.size();
  } else {
    if (0 == location) { // should never happen, but could be double slash - TODO support double slash not absolute paths
      start = 1;
      location = subpath.find('/',start);
    }
  }
  std::string curLevel = subpath.substr(start,location);
  std::string lower = "";
  if (location != subpath.size()) {
    lower = subpath.substr(location + 1);
  }

  IDocumentNode* child = node->at(curLevel);
  if (lower.size() == 0) {
      // at end of path
      return child;
  } else {
      return at(child,lower);
  }
}

} // end namespace utilities
} // end namespace mlclient