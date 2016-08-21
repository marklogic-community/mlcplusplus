/**
 * \file DocumentBatchHelper.cpp
 *
 * \date 20 Aug 2016
 * \author adamfowler
 */


#include <mlclient/utilities/DocumentBatchHelper.hpp>
#include <mlclient/DocumentContent.hpp>
#include <mlclient/Document.hpp>
#include <mlclient/DocumentSet.hpp>
#include <mlclient/Permission.hpp>
#include <mlclient/logging.hpp>

#include <dirent.h>
#include <vector>
#include <cstring>
#include <string>

namespace mlclient {

namespace utilities {

void DocumentBatchHelper::addFilesToDocumentSet(const std::string& folder,const std::string& baseFolder,const bool stripBase,const std::string& appendBase,
    const std::vector<std::string>& collections,const std::vector<Permission>& permissions,IDocumentContent* properties,DocumentSet& addTo,
    const bool showHiddenDirs) {
  DIR *dpdf;
  struct dirent *epdf;
  dpdf = opendir(folder.c_str());
  LOG(DEBUG) << "Reading: " << folder;
  if (dpdf != NULL) {
    while ((epdf = readdir(dpdf)) != NULL) {
      if(showHiddenDirs
          ? (epdf->d_type==DT_DIR && std::string(epdf->d_name) != ".." && std::string(epdf->d_name) != "." )
          : (epdf->d_type==DT_DIR && strstr(epdf->d_name,"..") == NULL && strstr(epdf->d_name,".") == NULL ) ) {
        addFilesToDocumentSet(std::string(folder + "/" + epdf->d_name),baseFolder,stripBase,
            appendBase,collections,permissions,properties, addTo, showHiddenDirs);
      }
      if(epdf->d_type==DT_REG) {
        // create Document and addTo set
        Document doc;
        doc.setCollections(collections);
        doc.setPermissions(permissions);
        doc.setProperties(properties);
        std::string fname = std::string(folder + "/" + epdf->d_name);
        if (stripBase) {
          fname = fname.substr(0,baseFolder.length());
        }
        doc.setUri(std::string(appendBase + fname));
        LOG(DEBUG) << "Found document: " << doc.getUri();
        FileDocumentContent* fdc = new FileDocumentContent(folder + "/" + epdf->d_name);

        // TODO make filedc set mime type correctly based on extension

        doc.setContent(fdc);
        addTo.push_back(std::move(doc)); // moved by called function
        //files.push_back(folder + epdf->d_name);
      } else {
        LOG(DEBUG) << "Unhandled file type: " << epdf->d_type;
      }
    }
    closedir(dpdf);
  } else {
    LOG(DEBUG) << "Folder is null! Cannot read: " << folder;
  }
}

} // end namespace utilities
} // end namespace mlclient


