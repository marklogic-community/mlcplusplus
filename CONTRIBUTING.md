# How to Contribute to the MLCPlusPlus project

## GitFlow

TODO full intro to GitFlow (feature-branch-workflow)

## Architectural standards

- Hide all underlying dependency API (E.g. JSON and XML implementations) - don't use web::json::value in public APIs
- Allow introspection of Response objects to determine type (via method call, not class name)
- Build for high speed use with respect to I/O to and from MarkLogic Server
- Support both Synchronous and Asynchronous API calls, and do this fairly transparently
 - no drastic function parameter differences
 - If there is a 3 parameter version of Synchronous search(), then there should be a 3 parameter version of Asynchronous search()
  - Does not include the call back or return value, obviously

## Code conventions and standards

The below generally apply:-

- Apply all lessons of Effective C++
- Target C++ 98 at the moment (some customers may not use C++11 or C++14 yet)
- Perform safe equality comparisons. E.g. if (0 == someVariable)... thus preventing accidentally doing someVariable = 0

Specifically:-
- use const address parameters to all public API calls where we will not modify the data (E.g. saveDocument())
- Use virtual destructors in classes
- Return full objects, not references, when we are done with the objects. E.g. Response object from getDocument()
- Use Smart Pointers for any and all resources (TODO example)
