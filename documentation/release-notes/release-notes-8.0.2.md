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
 - Tests don't build on Windows -

## Known incompatibilities with previous versions

### Factories return IConnection pointer, not Connection pointer

In order to allow future replacement of HTTP for other protocols, and allow a FakeConnection for automated testing
where no MarkLogic instance was available, I've created an abstract class called IConnection. This should be used
instead of Connection wherever possible in order to allow the switch out from one Connection implementation to
another transparently from your code.

Thus the ConnectionFactory classes in samples and tests both return an IConnection pointer now. You will need
to recode your apps where you use a ConnectionFactory so that they return an IConnection pointer.

## Future planned incompatibilities / deprecations

### Unicode string

It is highly likely in the 8.0.3 release that all instances of std::string will be replaced by std::wstring. The
same goes for char being replaced by wchar.

Developers should plan for this extra conversion overhead in future releases.
