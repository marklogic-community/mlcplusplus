PLUGIN_NAME = groupandaggregate
PLUGIN_VERSION = 0.1
PLUGIN_PROVIDER = MarkLogic
PLUGIN_DESCRIPTION = Example group by and calculation aggregate

PLUGIN_SRCS = \
  groupandaggregateudf.cpp

ZIP_NAME = $(PLUGIN_NAME).zip
PLUGIN_OBJS = ${PLUGIN_SRCS:.cpp=.o}

all: $(PLUGIN_NAME)

ifneq "$(WINDIR)" ""

-include defs.win32

CPPFLAGS = \
	-nologo \
	-W3 \
	-GR \
	-GS- \
	-EHsc \
	-wd4996 \
	-Zi -MTd -bigobj \
	-O2 -Oy- \
	-D_WIN32_WINNT=0x501 \
	-D_SECURE_SCL=0

FULL_LIB_NAME = $(PLUGIN_NAME).dll

DLL_LIBS="$(ProgramW6432)/MarkLogic/MarkLogic.lib"
INCLUDES=-I "$(ProgramW6432)/MarkLogic/include"

$(FULL_LIB_NAME): $(PLUGIN_OBJS)
	$(LINK) $(PLUGIN_OBJS) $(DLL_LIBS) \
	  -nologo -incremental:no -dll -out:$@ -largeaddressaware

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) -Fo$@ -I. -c $<

clean::
	rm -rf $(FULL_LIB_NAME:.dll=.lib)
	rm -rf $(FULL_LIB_NAME).manifest
	rm -rf $(FULL_LIB_NAME:.dll=.exp)
	rm -rf $(FULL_LIB_NAME:.dll=.pdb)
	rm -rf ${PLUGIN_SRCS:.cpp=.lib}
	rm -rf ${PLUGIN_SRCS:.cpp=.exp}
	rm -rf ${PLUGIN_SRCS:.cpp=.pdb}
	rm -rf vc90.pdb
else

ifeq "$(shell uname -s)" "SunOS"
MARKLOGIC = /opt/MARKlogic
FULL_LIB_NAME = lib$(PLUGIN_NAME).so
CPP = g++41
LIB_FLAGS = -m64 -fPIC -shared -h $(FULL_LIB_NAME) -lpthread -lthread -lresolv -lsocket -lnsl -lrt \
  -lkstat -lm -lc -ldl -nodefaultlibs $(MARKLOGIC)/lib/libstdc++.so.6 $(MARKLOGIC)/lib/libgcc_s.so.1
endif

ifeq "$(shell uname -s)" "Linux"
MARKLOGIC = /opt/MarkLogic
FULL_LIB_NAME = lib$(PLUGIN_NAME).so
CPP=g++
LIB_FLAGS = -m64 -fPIC -shared
endif

ifeq "$(shell uname -s)" "Darwin"
MARKLOGIC = $(shell cd ~; pwd)/Library/MarkLogic
FULL_LIB_NAME = lib$(PLUGIN_NAME).dylib
CPP=g++
LIB_FLAGS = -m64 -dynamiclib -Wl,-undefined,dynamic_lookup
endif

$(FULL_LIB_NAME): $(PLUGIN_OBJS)
	$(CPP) $(LIB_FLAGS) -o $(FULL_LIB_NAME) $(PLUGIN_OBJS)

%.o: %.cpp
	$(CPP) -m64 -std=c++11 -fPIC -O2 -Woverloaded-virtual -I. -I$(MARKLOGIC)/include -o $@ -c $<
endif

clean::
	rm -rf $(ZIP_NAME)
	rm -rf $(FULL_LIB_NAME)
	rm -rf $(PLUGIN_OBJS)
	rm -rf manifest.xml

manifest.xml:
	echo '<?xml version="1.0" encoding="UTF-8"?>' > manifest.xml
	echo '<plugin xmlns="http://marklogic.com/extension/plugin">' >> manifest.xml
	echo '  <name>$(PLUGIN_NAME)</name>' >> manifest.xml
	echo '  <id>$(PLUGIN_NAME)</id>' >> manifest.xml
	echo '  <version>$(PLUGIN_VERSION)</version>' >> manifest.xml
	echo '  <provider-name>$(PLUGIN_PROVIDER)</provider-name>' >> manifest.xml
	echo '  <description>$(PLUGIN_DESCRIPTION)</description>' >> manifest.xml
	echo '  <native>' >> manifest.xml
	echo '    <path>$(FULL_LIB_NAME)</path>' >> manifest.xml
	echo '  </native>' >> manifest.xml
	echo '</plugin>' >> manifest.xml

$(ZIP_NAME): $(FULL_LIB_NAME) manifest.xml
	zip $(ZIP_NAME) $(FULL_LIB_NAME) manifest.xml

$(PLUGIN_NAME): $(ZIP_NAME)

.PHONY: $(PLUGIN_NAME)
