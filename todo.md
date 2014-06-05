Before initial checkin of 0.1 (June 2014):-
- DONE Fix code
 - DONE MLCPlusPlus empty files and header
- DONE Test unix makefile build
 - DONE make runs successfully (tested on mac)
 - DONE get using shared libraries not static
- DONE Test XCode
- TEST KDevelop IDE project files and builds
- TEST Add Eclipse Support
- TEST Add visual studio support (Available on Windows CMake only)
- IN PROGRESS Update clean for build files on each platform
 - DONE Unix, mac
 - IN PROGRESS KDevelop
 - IN PROGRESS Eclipse
 - VS
- IN PROGRESS Update .gitignore for build files on each platform
 - DONE Unix, Mac
 - IN PROGRESS KDevelop
 - IN PROGRESS Eclipse
 - VS
- DONE Use bin directory for binaries (unless platform has own build folder)
 - DONE intermediate files (generated h files)
 - DONE Makefile distribution built code (dylib, so targets)
- DONE Update README file for quick start
- DONE Add next step echo line for each gen file. E.g. 'execute <open MLCPlusPlus.xcodeproj> now'
- DONE Add Casablanca dependency
 - NA (Need to download and build separately on different platforms) - Include files in distribution (Or auto via NuGet?)
 - NA Check include file CXX macro and CheckLibraryExists
 - NA Use find_library for Casablanca library (libcasablanca)
 - DONE add_include for libs/* folders' header files
 - NA must be present for build to work - Install Casablanca if not present when installing MLCPlusPlus
 - DONE Add link libraries command
 - DONE Add include in MLCPlusPlus.h and cpp and recheck build works

0.2 release (June 2014):-
- Abstraction for authentication
- Basic Connection configure function
- Test Authentication
 – DIGEST Auth support – may not be part of Casablanca REST stack (released Dec 2013/Apr 2014)
  – If not included, Ask AF for JavaScript and .NET examples of Digest auth on client side
 - OPTIONAL BASIC auth support
 - OPTIONAL none (passthrough) auth support
 - OPTIONAL BASIC+DIGEST auth support
 - Support SSL/TLS
 - OPTIONAL Support certificates for securing comms (if supported by REST API?)
- Abstract out calls to REST functions
 - Basic abstraction (see __doreq_node in MLJS)
 - Handle request/response special cases (see __doreq_node in MLJS.js and xhr2.js in MLJS)
- Create generic Response object (See MLJS for example)
- Decide on JSON (in Casablanca) or XML (may require libXml2) as default for all REST requests
- Create document – PUT /v1/documents
- Patch document (append – stream data, and alter – document envelope metadata) – PATCH /v1/documents
- Get document - GET /v1/documents?uri=
- do function (Simple to use functions for any REST endpoint. E.g. Custom endpoints)

0.4 release (Completion of Basic MBO features - July 2014):-
- Transaction begin – POST /v1/transactions (HTTP 20x response content is txid)
- Commit – POST /v1/transactions/{txid}
- Abandon – POST /v1/transactions/{txid}

0.6 release (Aug 2014) (Additional features for MWE):-
- List folder (URI lexicon under /my/dir) – GET /v1/values/{name}
- Search – POST /v1/search (combined query)
 - search string query
 - structured query
 - combined query
- Fetch doc/metadata  - GET /v1/documents
- Fetch part of binary content (segment) for HTTP ‘stream’ (chunking) – GET /v1/documents
- Delete – DELETE /v1/documents
- Create – PUT /v1/documents
- Check if file stale (REST version id) – HEAD /v1/documents (Etag)
- Rename/Move – None, use user defined replace library and PATCH /v1/documents
- Change metadata (e.g. to set off publish workflow) – PATCH /v1/documents?category=metadata
- Fetch file related provenance (and related docs) – POST /v1/sparql

0.8 release (Sep 2014):-
- Select test framework
- Command line Tools (with test integration)
 - mlconnect - test connection to a MarkLogic Server
- Tests for basic functionality
 - Also ensure keep-alive on tcp connection is working
- API documentation
 - Select API documentation tool
  - VTK Documentation Framework (See Documentation macro) - requires Doxygen, perl, etc
 - Write documentation for all current functionality

1.0 release (Dec 2014 alongside ML8):-
- Execute simple test that exercises Casablanca and MLCPlusPlus (casablanca version property?)
- CMake settings
 - Ensure 64 bit by default is built
 - Ensure secure openssl version used
 - CFBundle rather than dylib on a mac?
  - If so, also generate plist file - framework or bundle
 - Named targets?
 - Options
  - 64 bit vs 32 bit (some clients may be 32 bit)
  - Optional advanced XML support? (libxml2)
 - clean target? (and update clean script)
 - other macros that may help
  - FindBoost
  - FindCxxTest
  - FindDoxygen, FindPerl, FindPerlLibs, FindVTK
  - FindLibXml2, FindLibXslt
  - FindOpenSSL (OPENSSL_VERSION - This is set to $major.$minor.$revision$path (eg. 0.9.8s) )
  - FindWget, FindCurl
  - FindZLib? (zlib used for compression as option with casablanca? Does ML support it in REST?)
- CPack config
 - Include casablanca library along with MLCPlusPlus (Nuget?)
 - bundle or framework on OS X?
 - exe installer for windows
 - RPM installer for linux (Redhat, Centos)
 - Optional Debian installer for linux
 - store built installers in dist
- Store zip files of source and binaries in dist
- MarkLogic version 8 compatibility testing

1.2 release (Jan 2015):-
- Additional ML 8.0.1 bug fixes if required

1.4 release (Feb 2015):-
- Full REST client endpoint API support
 - Graphstore protocol
 - /v1/values
  - cooccurence
  - lexicons
 - query by example
- Utilities
 - search options builder
 - structured query builder
 - local content cache
- Update API documentation
- Additional tests

1.6 release (Mar 2015)
- R library integration? (Desirable???)
