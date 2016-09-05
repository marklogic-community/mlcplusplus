/**
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
 * \file DocumentBatchHelper.hpp
 *
 * \date 20 Aug 2016
 * \author adamfowler
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHHELPER_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHHELPER_HPP_

#include <mlclient/Document.hpp>
#include <mlclient/DocumentContent.hpp>
#include <mlclient/DocumentSet.hpp>
#include <mlclient/mlclient.hpp>

namespace mlclient {

namespace utilities {

/**
 * \brief Helper functions for common batch document operations.
 *
 * \since 8.0.2
 */
class DocumentBatchHelper {
public:
  DocumentBatchHelper() = delete;
  ~DocumentBatchHelper() = delete;

  /**
   * \brief Takes all files in a folder and subfolders and adds them to a DocumentSet
   *
   * Works cross platform on Windows and Mac. Can also be used via the C# wrapper.
   *
   * See the cppbatchupload and csbatchupload samples for example usage.
   *
   * \since 8.0.2
   */
  MLCLIENT_API static void addFilesToDocumentSet(const std::string& folder,const std::string& baseFolder,const bool stripBase,const std::string& appendBase,
      const CollectionSet& collections,const PermissionSet& permissions,IDocumentContent* properties,DocumentSet& addTo,
      bool showHiddenDirs = false);

};

} // end namespace utilities

} // end namespace mlclient



#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHHELPER_HPP_ */
