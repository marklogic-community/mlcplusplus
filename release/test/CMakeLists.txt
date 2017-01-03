
IF (WITH_TESTS)


include_directories(../src ${OPENSSL_INCLUDE_DIR} ${CPPUNIT_INCLUDE_DIR})

add_executable(mlcpptest
    main.cpp
    ConnectionFactory.cpp
    ConnectionCollectionsTest.cpp
    ConnectionRawHttpTest.cpp
    ConnectionValuesTest.cpp
    ConnectionDocumentCrudTest.cpp
    ConnectionSearchTest.cpp
    DocumentTraversalTest.cpp
    SearchBuilderTest.cpp
    SearchOptionsBuilderTest.cpp
    SearchResultSetTest.cpp
    ValuesResultSetTest.cpp
    DocumentBatchWriterTest.cpp
    PathNavigatorTest.cpp
)
target_link_libraries(mlcpptest mlclient cppunit ${Casablanca_LIBRARIES} ${GLOG_LIB})

# Compile under C++11
set_property(TARGET mlcpptest PROPERTY CXX_STANDARD 11)


else()
  message("-- NOT building Tests (edit ./bin/build-deps-settings.sh|bat with WITH_TESTS=1 to enable)")
endif()
