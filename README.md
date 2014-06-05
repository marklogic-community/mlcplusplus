This repository contains a C++ cross platform wrapper for the MarkLogic Server REST API.

## Quick Start

You can build from source then use in your projects.

### Get Casablanca

Follow the build instructions for your platform, ensuring that the 'mlcplusplus' git directory is at the same level as the 'casablanca' git directory.

These instructions are listed here: https://casablanca.codeplex.com/documentation

Once built, continue below.

### Building the MLCPlusPlus library from source

Ensure first that all build scripts are executable:-
- chmod u+x *.sh

To build the MLCPlusPlus library for your platform, execute the appropriate shell script, and use the build tool
for your platform. E.g.:-

- On a Mac, type './gen-mac.sh' and hit <enter>. This generates an XCode project you can use to build the library
- On Linux, type './gen-kdevelop.sh' and hit <enter>. This generates a KDevelop project you can use to build the library
- On other *nix, type './gen-unix.sh' and hit <enter> Then type 'make' and hit <enter>. Optionally run 'sudo make install' to install the library on your system
- On Windows, TODO - Coming Soon for Visual Studio
- For cross platform Eclipse CDT, type './gen-eclipse.sh' and hit <enter>. Then open Eclipse to build the library

To remove all built files, execute './clean.sh' and hit <enter>

### Using the MLCPlusPlus library in your C++ application

Start with the Connection class. This provides a connect function and callbacks for all MarkLogic REST API functions.

This class also abstracts the underlying security mechanism used to authenticate to the server.

Simply create a Connection class, call configure to set up the connection parameters, then call a function!

TODO API Documentation pending

## Decisions outstanding

This is a new project with many decisions that yet need to be taken.
Before we can begin we need to decide on the below. Please comment on these in the Issues Tracker on GitHub

### Project organisation

- Which build system(s) to use
- Which IDEs to use on each platform
- What additional tools (testing, docs, etc.) to use

### Design decisions

- Which REST libraries to use (Casablanca? Windows and other native?)
- How to model callbacks for asynchronouse use
- How to handle authentication (none, Basic, Digest, Kerberos)
- How to take advantage of local platforms (Kerberos on Windows for SSO)

### Feature prioritisation

- Basic functionality first, or strong compliance
- MarkLogic version support - V7, V8, earlier?
- Communication data types - XML or JSON for call configuration?
- Depth - just wrapping REST calls? Multiple calls per endpoint? Helper utilities (caching, query/options builders)?


## Getting involved

Please email adam dot fowler at marklogic.com if you are interested in helping out.
