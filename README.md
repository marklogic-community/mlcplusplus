This repository contains a C++ cross platform wrapper for the MarkLogic Server REST API.

## Quick Start

You can build from source then use in your projects.

### Get Casablanca

Follow the build instructions for your platform, ensuring that the 'mlcplusplus' git directory is at the same level as the 'casablanca' git directory.

These instructions are listed here: https://github.com/Microsoft/cpprestsdk/wiki

Once built, continue below.

### Building the MLCPlusPlus library from source

Ensure first that all build scripts are executable:-
- chmod u+x \*.sh

To build the MLCPlusPlus library for your platform, execute the appropriate shell script, and use the build tool
for your platform. E.g.:-

- On a Mac, type './gen-mac.sh' and hit <enter>. This generates an XCode project you can use to build the library
- On Linux, type './gen-kdevelop.sh' and hit <enter>. This generates a KDevelop project you can use to build the library
- On other \*nix, type './gen-unix.sh' and hit <enter> Then type 'make' and hit <enter>. Optionally run 'sudo make install' to install the library on your system
- On Windows, TODO - Coming Soon for Visual Studio
- For cross platform Eclipse CDT, type './gen-eclipse.sh' and hit <enter>. Then open Eclipse to build the library

To remove all built files, execute './clean.sh' and hit <enter>

### Using the MLCPlusPlus library in your C++ application

Start with the Connection class. This provides a connect function and callbacks for all MarkLogic REST API functions.

This class also abstracts the underlying security mechanism used to authenticate to the server.

Simply create a Connection class, call configure to set up the connection parameters, then call a function!

TODO API Documentation pending

### Compiling the tests

These are built by the above build process. A lot of the tests have hardcoded values like usernames, hostnames, and
passwords that mean they can't immediately be executed on your own system. They should provide a good set of code to
work on your own projects though.

### Feature prioritisation

- Basic functionality first, or strong compliance
- MarkLogic version support - V7, V8, earlier?
- Communication data types - XML or JSON for call configuration?
- Depth - just wrapping REST calls? Multiple calls per endpoint? Helper utilities (caching, query/options builders)?


## Getting involved

Please email adam dot fowler at marklogic.com if you are interested in helping out.
