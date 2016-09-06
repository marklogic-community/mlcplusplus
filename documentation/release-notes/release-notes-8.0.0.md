# Release notes for MLCPlusPlus version 8.0.0

This release is the first major release with working functionality, documentation, and tests.

Major features in this release:-
 - Compilation works with Eclipse CDT (gen-eclipse.sh)
 - Compilation works with Unix Makefiles (gen-unix.sh)
 - Full API, install, and design documentation
 - Full test suite for all Connection functions, using cpprest
 - Logging, including performance logging, using easylogging++.h
 - Connection generic HTTP functions: getSync, postSync, putSync, deleteSync
 - Connection REST API functions: saveDocument, getDocument, deleteDocument, search
 - TextDocument and SearchDescription classes introduced to wrap REST API concepts
 - C wrapper API for C++ Connection functionality
 - Samples in C and C++
 - Generated Python wrapper via SWIG (initial test work towards future C#.NET wrapper via SWIG)

Bug fixes:-
 - Not applicable - first major release

Known issues:-
 - C and C++ test apps receive HTTP Unauthorised exception when running - https://github.com/adamfowleruk/mlcplusplus/issues/118
