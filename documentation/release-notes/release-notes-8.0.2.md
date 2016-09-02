# Release notes for MLCPlusPlus version 8.0.2

This release is the second major release with working functionality, documentation, and tests.

Major features in this release:-
- Support for reading and writing XML, JSON, text and binary documents
- Document node traversal API - no need to know whether content is XML or JSON
- Search builder helper class
- Search options builder helper class
- Paging Search Result Set class for streaming multiple search result pages
- Support for lexicon lookups and co-occurence calls
- Document wrapper class, including support for metadata, collections, properties, and permissions
- Support for batch writing documents via DocumentSet and DocumentBatchWriter and DocumentBatchHelper
- New samples:-
 - C++ batch upload
 - C++ query text search
 - C# batch upload
 - C# query text search
 - C++ Custom UDF (See known issues, below)
 - C++ parallel task sample (used as basis for pagination and batch upload support) for the underlying cpprest API
- Unit tests for all Connection functionality
- Unit tests for helper utility classes
- Language wrapper updates
 - C# Language wrapper supports all new functionality
 - Python Language wrapper supports all new functionality
- Performance testing and tuning

Bug fixes:-
 - 193 Digest Auth not working - https://github.com/adamfowleruk/mlcplusplus/issues/193
 - 118 C samples don't authenticate - https://github.com/adamfowleruk/mlcplusplus/issues/118
 - 200 declspec warnings when compiling - https://github.com/adamfowleruk/mlcplusplus/issues/200

Known issues:-
 - REST API co-occurence result formatting Bug - test: ConnectionValuesTest::testValuesUDF will fail
 - REST API bug when using UDFs - test: ConnectionValuesTest::testValuesExtension will fail
 - 227 Tests assume content already exists in MarkLogic - https://github.com/adamfowleruk/mlcplusplus/issues/227
 - 226 Iterators do not match STL norms - https://github.com/adamfowleruk/mlcplusplus/issues/226
 - 217 Logging does not work the same cross platform - https://github.com/adamfowleruk/mlcplusplus/issues/217
