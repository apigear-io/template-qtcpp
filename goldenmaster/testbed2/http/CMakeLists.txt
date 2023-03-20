cmake_minimum_required(VERSION 3.20)
project(testbed2_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_HTTP_SOURCES
    httpfactory.cpp
    httpmanyparaminterface.cpp
    httpnestedstruct1interface.cpp
    httpnestedstruct2interface.cpp
    httpnestedstruct3interface.cpp
)

# dynamic library

add_library(testbed2_http STATIC ${TESTBED2_HTTP_SOURCES})
target_include_directories(testbed2_http PRIVATE ../testbed2)
target_link_libraries(testbed2_http PRIVATE Qt5::Network testbed2_api)
