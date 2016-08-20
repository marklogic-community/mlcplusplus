/**
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

namespace mlclient {

namespace utilities {

/**
 * \brief Helper functions for common batch document operations.
 *
 * \since 8.0.2
 */
class DocumentBatchHelper {
public:
  /**
   * \brief Takes all files in a folder and subfolders and adds them to a DocumentSet
   *
   * \since 8.0.2
   */
  static void addFilesToDocumentSet(const std::string& folder,const bool stripBase,const std::string& appendBase,
      const std::vector<std::string>& collections,const std::vector<Permission>& permissions,IDocumentContent* properties,DocumentSet& addTo,
      bool showHiddenDirs = false);

};

} // end namespace utilities

} // end namespace mlclient



#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTBATCHHELPER_HPP_ */
