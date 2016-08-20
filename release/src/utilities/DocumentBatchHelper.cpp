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

#include <dirent.h>
#include <vector>
#include <cstring>

namespace mlclient {

namespace utilities {

void DocumentBatchHelper::addFilesToDocumentSet(const std::string& folder,const bool stripBase,const std::string& appendBase,
    const std::vector<std::string>& collections,const std::vector<Permission>& permissions,IDocumentContent* properties,DocumentSet& addTo,
    const bool showHiddenDirs) {
  DIR *dpdf;
  struct dirent *epdf;
  dpdf = opendir(folder.c_str());
  if (dpdf != NULL) {
    while ((epdf = readdir(dpdf)) != NULL) {
      if(showHiddenDirs
          ? (epdf->d_type==DT_DIR && std::string(epdf->d_name) != ".." && std::string(epdf->d_name) != "." )
          : (epdf->d_type==DT_DIR && strstr(epdf->d_name,"..") == NULL && strstr(epdf->d_name,".") == NULL ) ) {
        addFilesToDocumentSet(std::string((stripBase ? "" : folder) + epdf->d_name+"/"),stripBase,
            appendBase,collections,permissions,properties, addTo, showHiddenDirs);
      }
      if(epdf->d_type==DT_REG) {
        // create Document and addTo set
        Document doc;
        doc.setCollections(collections);
        doc.setPermissions(permissions);
        doc.setProperties(properties);
        doc.setUri(std::string(appendBase + (stripBase ? (epdf->d_name) : (folder + epdf->d_name))));
        FileDocumentContent* fdc = new FileDocumentContent(folder + epdf->d_name);
        doc.setContent(fdc);
        addTo.push_back(std::move(doc)); // moved by called function
        //files.push_back(folder + epdf->d_name);
      }
    }
  }
  closedir(dpdf);
}

}
}


