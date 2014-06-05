include_directories(../src)
link_directories(..)
add_executable(mlcpptest main.cpp AuthenticatingProxyTest.cpp CredentialsTest.cpp)

target_link_libraries(../libMLCPlusPlus.dylib libcppunit.dylib libcasablanca.dylib)