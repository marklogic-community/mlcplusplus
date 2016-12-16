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

#ifndef _WIN32
#include <dirent.h>
#else
#include <Windows.h>
#endif

#include <vector>
#include <cstring>
#include <string>

namespace mlclient {

namespace utilities {

#ifdef _WIN32
  std::string ws2s(const std::wstring& s)
  {
    int len;
    int slength = (int)s.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
    char* buf = new char[len];
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, buf, len, 0, 0);
    std::string r(buf);
    delete[] buf;
    return r;
  }

  std::wstring s2ws(const std::string& s)
  {
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
  }
#endif

void DocumentBatchHelper::addFilesToDocumentSet(const std::string& folder,const std::string& baseFolder,const bool stripBase,const std::string& appendBase,
    const std::vector<std::string>& collections,const std::vector<Permission>& permissions,IDocumentContent* properties,DocumentSet& addTo,
    const bool showHiddenDirs) {
  LOG(DEBUG) << "addFilesToDocumentSet called with folder: " << folder << " and baseFolder: " << baseFolder;

#ifndef _WIN32
  struct dirent *epdf;
  DIR *dpdf;
  dpdf = opendir(folder.c_str());
#else
  LPWIN32_FIND_DATAW epdf;
  HANDLE dpdf;
  LPCWSTR fws = (s2ws(folder).c_str());
  dpdf = FindFirstFileW(fws, epdf);
#endif
  LOG(DEBUG) << "Reading: " << folder;
  if (dpdf != NULL) {

#ifndef _WIN32

    while ((epdf = readdir(dpdf)) != NULL) {
      if(showHiddenDirs
          ? (epdf->d_type==DT_DIR && std::string(epdf->d_name) != ".." && std::string(epdf->d_name) != "." )
          : (epdf->d_type==DT_DIR && strstr(epdf->d_name,"..") == NULL && strstr(epdf->d_name,".") == NULL ) ) {
        addFilesToDocumentSet(std::string(folder + "/" + epdf->d_name),baseFolder,stripBase, // TODO platform independent file separator
            appendBase,collections,permissions,properties, addTo, showHiddenDirs);
      }
      if(epdf->d_type==DT_REG) {
        std::string dname = epdf->d_name;

#else
    while (dpdf != INVALID_HANDLE_VALUE) {
      std::wstring ws(epdf->cFileName);
      std::string dname;
      dname.assign(ws.begin(),ws.end());
      if (FILE_ATTRIBUTE_DIRECTORY == (FILE_ATTRIBUTE_DIRECTORY & epdf->dwFileAttributes)) {
        // directory
        addFilesToDocumentSet(std::string(folder + "/" + dname), baseFolder, stripBase, // TODO platform independent file separator
          appendBase, collections, permissions, properties, addTo, showHiddenDirs);
      } else
      if (FILE_ATTRIBUTE_NORMAL == (FILE_ATTRIBUTE_NORMAL & epdf->dwFileAttributes)) {


#endif
        // create Document and addTo set
        Document doc;
        doc.setCollections(collections);
        doc.setPermissions(permissions);
        doc.setProperties(properties);
        LOG(DEBUG) << "d_name: " << dname;
        std::string fname = std::string(folder);
        if (stripBase) {
          if (fname == baseFolder) {
            fname = "";
          } else { // This if prevents the next line erroring with too long index if folder and fname match exactly
            fname = fname.substr(baseFolder.length() + 1);
          }
        }
        LOG(DEBUG) << "fname: " << fname << " folder: " << folder << " baseFolder: " << baseFolder;
        doc.setUri(std::string(appendBase + fname + "/" + dname)); // TODO platform independent file separator
        LOG(DEBUG) << "Found document: " << doc.getUri();
        FileDocumentContent* fdc = new FileDocumentContent(folder + "/" + dname); // TODO platform independent file separator

        // NB FileDocumentContent's constructor uses the extension to determine the MIME type, or defaults to application/json

        doc.setContent(fdc);
        addTo.push_back(std::move(doc)); // moved by called function
        //files.push_back(folder + epdf->d_name);
      } else {
#ifndef _WIN32
        LOG(DEBUG) << "Unhandled file type: " << epdf->d_type;
#else
        // TODO windows version
#endif
      }
#ifdef _WIN32
      FindClose(dpdf);

      FindNextFileW(dpdf, epdf);
#endif
    }
#ifndef _WIN32
    closedir(dpdf);
#else

#endif
  } else {
    LOG(DEBUG) << "Folder is null! Cannot read: " << folder;
  }
}

} // end namespace utilities
} // end namespace mlclient
