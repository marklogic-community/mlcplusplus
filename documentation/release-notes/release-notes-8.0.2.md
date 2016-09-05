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
 - batch upload - C++, C#
 - query text search - C++, C#
 - getdoc document fetch by URI - C++, C#, Python
 - C++ Custom UDF invocation (See known issues, below)
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
 - 235 Tests don't build on Windows - https://github.com/adamfowleruk/mlcplusplus/issues/235
 - SWIG generation bug for C# - csharp/std_vector.i has a but in it. You may see a (uint) conversion error. Use the provided CS and built libraries to work around this until a SWIG fix can be created by their team.

## Known incompatibilities with previous versions

### Factories return IConnection pointer, not Connection pointer

In order to allow future replacement of HTTP for other protocols, and allow a FakeConnection for automated testing
where no MarkLogic instance was available, I've created an abstract class called IConnection. This should be used
instead of Connection wherever possible in order to allow the switch out from one Connection implementation to
another transparently from your code.

Thus the ConnectionFactory classes in samples and tests both return an IConnection pointer now. You will need
to recode your apps where you use a ConnectionFactory so that they return an IConnection pointer.

## Future planned incompatibilities / deprecations

Below are future changes that will mean an alteration to client code is needed.

### Unicode string

It is highly likely in the 8.0.3 release that all instances of std::string will be replaced by std::wstring. The
same goes for char being replaced by wchar.

Developers should plan for this extra code modification overhead in future releases.

https://github.com/adamfowleruk/mlcplusplus/issues/63

### Pointers vs. references

Pointers are used in a lot of places in the API. In future many of these will be replaced with references. In
future all classes will support Move Semantics where this makes sense. Currently this is only true for Document
and ValuesResult classes. This change is happening to make a less buggy and more performant API. It will also
ease creation of SWIG based wrappers for other languages.

https://github.com/adamfowleruk/mlcplusplus/issues/255

### Package changes

Certain REST API configuration is common to general core API functionality, and utilities classes. At the moment
they live in utilities classes, but in future they may be broken out in to their own REST API namespace. This is
particularly the case for index types, data types, and mime types.

https://github.com/adamfowleruk/mlcplusplus/issues/256
