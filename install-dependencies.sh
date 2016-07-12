#!/bin/bash

echo "-- Install dependencies for the Mac or Linux environments"

BASE="$(dirname "$PWD")"
ORIG=$PWD
CPPREST=cpprestsdk
CPPREST_FOLDER=$BASE/$CPPREST
echo "-- Base folder: $BASE . use export BASE=/some/path to override."

# Determine what platform we're on
# use local platforms package download tool to install what we need

platform=`uname -a`
curl=`curl --version`
if [[ "$platform" =~ ^Darwin.* ]]; then
  echo "-- Fetching dependencies for the Apple Mac"

  # Find which package manager is in use
  brew=`brew --version`
  if [[ "$brew" =~ ^Homebrew.* ]]; then
    echo " - Using Homebrew package manager"
    if [[ "$curl" =~ .*command.* ]]; then
      echo "  - Installing curl"
      brew install curl
    fi
    echo "  - Installing Git"
    brew install git
    echo "  - Installing CMake"
    brew install cmake
    echo "  - Installing OpenSSL (as Universal binary)"
    brew install openssl --universal
    echo "  - Installing boost (as Universal binary)"
    brew install boost --universal
    echo "  - Installing cppunit (as Universal binary)"
    brew install cppunit --universal
    echo "  - Installing libiconv (as Universal binary)"
    brew install libiconv --universal
    echo "  - Installing Mono (For SWIG CSharp Bindings)"
    brew install mono
  else
    port=`port --version`
    if [[ "$port" =~ ^port.* ]]; then
      echo " - Using Macports package manager - will prompt for sudo password"
      if [[ "$curl" =~ .*command.* ]]; then
        echo "  - Installing curl"
        sudo port install curl
      fi
      echo "  - Installing Git"
      sudo port install git
      echo "  - Installing CMake"
      sudo port install cmake
      echo "  - Installing OpenSSL (as Universal binary)"
      sudo port install openssl +universal
      echo "  - Installing boost (as Universal binary)"
      sudo port install boost +universal
      echo "  - Installing cppunit (as Universal binary) - WARNING: The cppunit port may not support universal mode - you may get linker errors"
      sudo port install cppunit +universal
      echo "  - Installing libiconv (as Universal binary)"
      sudo port install libiconv +universal
      echo "  - Installing Mono (For SWIG CSharp Bindings)"
      sudo port install mono
    else
      echo " - FAILURE: Unknown Mac package manager (neither Homebrew or Macports installed)"
      exit 1
    fi
  fi
fi
if [[ "$platform" =~ ^Linux.* ]]; then
  echo "-- On a Linux machine"

  if [[ "$platform" =~ .*Ubuntu.* ]]; then
    echo "-- Fetching dependencies for Ubuntu - will prompt for sudo password"
    sudo apt-get install g++ git make libboost-all-dev libssl-dev cmake
  else
    redhat=`cat /etc/redhat-release`
    yum=`yum --version`
    if [[ "$redhat" =~ ^CentOS.* ]]; then
      echo "-- Fetching dependencies for CentOS"
    fi
    if [[ "$redhat" =~ ^Redhat.* ]]; then
      echo "-- Fetching dependencies for Redhat Enterprise Linux"
    fi
    if [[ "$yum" =~ ^yum.* ]]; then
      echo " - Using the Yum package manager - will prompt for sudo password"
      sudo yum install boost gcc git make boost-devel openssl openssl-devel cmake
    else
      echo " - FAILURE: No yum package manager installed"
      exit 1
    fi
  fi
fi

# Install cpprest from GitHub
git=`git --version`
echo "-- Downloading Microsoft's cpprest SDK (aka casablanca)"
if [[ "$git" =~ ^git.* ]]; then
  echo " - Fetching repository master using git"
  cd $BASE
  git clone https://github.com/Microsoft/cpprestsdk.git $CPPREST
  cd $ORIG
else
  if [[ "$curl" =~ ^curl.* ]]; then
    echo " - Fetching repository using curl - NOT YET SUPPORTED"
  else
    echo " - FAILURE: Neither git nor curl is installed - cannot fetch remote repository"
  fi
fi

OSXU=
if [[ "$platform" =~ ^Darwin.* ]]; then
  # Patch cpprest's CMake file to support OS X universal builds
  echo "-- Patching cpprest to support Mac OS X Universal builds"
  OSXU=-DOSX_UNIVERSAL=1
  sed -E -i -e '/.*Compiler.*/r release/dependencies/cpprest-cmake.txt' $CPPREST_FOLDER/Release/CMakeLists.txt
fi

# Build dependencies
echo "-- Building and installing Microsoft's cpprest SDK (aka casablanca) - will prompt for sudo password to install"
cd $CPPREST_FOLDER
mkdir build.debug
cd build.debug
cmake ../Release $OSXU -DCMAKE_BUILD_TYPE=Debug
make -j 4
echo " - Installing..."
sudo make install
cd $ORIG

# Test dependencies where possible (E.g. build and execute sample CPP file)

# Output patchs to ./bin/build-deps-settings.sh
F=$ORIG/bin/build-deps-settings.sh
printf '#!/bin/sh\n' > $F
printf '# USER EDITABLE SETTINGS BEGIN\n' >> $F
printf '# General SWIG enabling' >> $F
printf 'WITH_SWIG=0\n' >> $F
printf '# Specific SWIG wrapper enabling' >> $F
printf 'WITH_PYTHON=0\n' >> $F
printf 'WITH_CSHARP=0\n' >> $F
printf '# Other settings' >> $F
printf 'WITH_TESTS=0\n' >> $F
printf 'WITH_DOCS=0\n' >> $F
printf 'WITH_SAMPLES=0\n' >> $F
printf '# BUILD_TYPE can be Debug or Release. Release uses compiler optimisations.\n' >> $F
printf 'BUILD_TYPE=Debug\n' >> $F
printf '# USER EDITABLE SETTINGS END\n' >> $F
printf 'echo "-- Setting MLCPlusPlus dependency settings"\n' >> $F
printf 'export CPPRESTSDK_HOME=%s\n' "$CPPREST_FOLDER" >> $F
printf 'export MLCPLUSPLUS_HOME=%s\n' "$ORIG" >> $F
printf 'export CMAKE_OPTIONS="%s -DWITH_SWIG=$WITH_SWIG -DWITH_CSHARP=$WITH_CSHARP -DWITH_PYTHON=$WITH_PYTHON -DWITH_TESTS=$WITH_TESTS -DWITH_DOCS=$WITH_DOCS -DWITH_SAMPLES=$WITH_SAMPLES -DCMAKE_BUILD_TYPE=$BUILD_TYPE"\n' "$OSXU" >> $F
printf 'echo "-- Done"\n' >> $F
#printf 'exit 0\n' >> $F

echo "-- Done."
exit 0
