# How to Contribute to the MLCPlusPlus project

## GitFlow

TODO full intro to GitFlow (feature-branch-workflow)

## Architectural standards

- Hide all underlying dependency API (E.g. JSON and XML implementations) - don't use web::json::value in public APIs
- Allow introspection of Response objects to determine type (via method call, not class name)
- Build for high speed use with respect to I/O to and from MarkLogic Server

## Code conventions and standards

The below generally apply:-

- Apply all lessons of Effective C++, and API design recommendations of C++ API Design.
- Target C++ 11
- Perform safe equality comparisons. E.g. if (0 == someVariable)... thus preventing accidentally doing someVariable = 0

Specifically:-
- use const address parameters to all public API calls where we will not modify the data (E.g. saveDocument()) - i.e. IN/OUT parameters
- Use virtual destructors in classes - WHY?
- Return full objects, not references, when we are done with the objects. E.g. Response object from getDocument()
- Use Smart Pointers for any and all resources (TODO example)

## Hiding implementation details

To prevent clients of the mlclient API having to recompile if we change the header files, we should hide as many
implementation details as possible. This includes all private members and private functions.

Use the PIMPL (Private Implementation) idiom with a forward declared Impl class in the header files. All private members
and private functions of the main class now become public members and public methods of the Impl class.

This also ensures speedy compilation times, and allows us to shield our API users from any future changes to the
libraries we use to implement the API. (E.g. HTTP REST, JSON and XML libraries).

## Subclass, enum, and constant declarations

Subclasses or Realizations, enums, and constants should be defined in the header file for their main types. E.g.
all DocumentContent subclasses are defined in DocumentContent.hpp. Subclasses are realized in the main CPP files.
E.g. TextDocumentContent is fleshed out in DocumentContent.cpp.

All enum's should have their type explicitly included in their definitions - do not rely on the compiler.

## External dependencies

These should be entirely hidden from all .hpp header files in the Public API. For instances where an external API
type is used, a Helper class should be defined in the utility package - do not introduce dependencies within the public API.

The pugi XML library is used to handle XML documents, for example, but this functionality is handled in the PugiXmlHelper
class. This allows you to in future create, for instance, a Libxml2Helper class.

This also means we are free to switch out underlying APIs without disrupting our public API.

The internals namespace includes classes whose CPP files have direct dependencies on the cpprest (aka Microsoft Casablanca)
HTTP REST and JSON API. This is fine as it is unavoidable without a further layer of indirection. As this class is
neer used directly (it's part of the private API), this direct dependency is fine for our uses.

## Large, complex, or optional function parameters

Use a value object class to hold parameters where there are many combinations rather than implement many overloaded
functions. This makes the API easier to remember, and allows us to set sensible defaults.

A classic example of this is in the SearchDefinition class which could comprise of a search (in JSON or XML),
search options (in JSON or XML), and query text (string) - or any combination thereof.

Again, prefer utility classes to help build these in complex circumstances. E.g. complex multi query search using a
search builder class. (which doesn't exist yet).

## C Wrapper API

The CWrapper class provides a template to wrap any C++ class in our API. This is used in just the places where a C API
would reasonably want to call. i.e. the Connection and Response classes.

These functions are prefixed with ml_, followed hy a lowercase version of the classname E.g. connection_, followed
by the function name in camel case. E.g. getConnection.

The first parameter is a pointer to the CWrapper of the concrete class (CConnection in the above example).

The CConnection class is a typedef allowing direct casting of a C CConnection pointer to a C++ Connection pointer by
the wrapper C++ API.

## Documentation comments

Doxygen is used to generate API documentation. Please use the /** and \*\*/ characters to start and end a Doxygen
comment.
