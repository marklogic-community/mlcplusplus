
IF (WITH_TESTS)


include_directories(${CPPUNIT_INCLUDE_DIR})

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
target_link_libraries(mlcpptest mlclient cppunit ${GLOG_LIB})


else()
  message("-- NOT building Tests (edit ./bin/build-deps-settings.sh|bat with WITH_TESTS=1 to enable)")
endif()
