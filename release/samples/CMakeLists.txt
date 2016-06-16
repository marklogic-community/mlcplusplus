

IF (WITH_SAMPLES)


include_directories(../src ${OPENSSL_INCLUDE_DIR} ${CPPUNIT_INCLUDE_DIR})

add_executable(getdoc
    getdoc.cpp
    ConnectionFactory.cpp
)
add_executable(cgetdoc
    cgetdoc.c
    ConnectionFactory.cpp
    ConnectionFactoryWrapper.cpp
)
add_executable(cgetasstruct
    cgetasstruct.c
    ConnectionFactory.cpp
    ConnectionFactoryWrapper.cpp
    CStructWrapper.cpp
)
target_link_libraries(getdoc mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cgetdoc mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cgetasstruct mlclient ${Casablanca_LIBRARIES})

else()
  message("-- NOT building Samples (edit ./bin/build-deps-settings.sh|bat with WITH_SAMPLES=1 to enable)")
endif()
