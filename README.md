This repository contains a C++ cross platform wrapper for the MarkLogic Server REST API.

This is a new project with many decisions that yet need to be taken.

## Decisions outstanding

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
