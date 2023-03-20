cmake_minimum_required(VERSION 3.20)
project(testbed1_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_HTTP_SOURCES
    httpfactory.cpp
    httpstructinterface.cpp
    httpstructarrayinterface.cpp
)

# dynamic library

add_library(testbed1_http STATIC ${TESTBED1_HTTP_SOURCES})
target_include_directories(testbed1_http PRIVATE ../testbed1)
target_link_libraries(testbed1_http PRIVATE Qt5::Network testbed1_api)
