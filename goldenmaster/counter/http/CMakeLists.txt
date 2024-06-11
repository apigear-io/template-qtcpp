cmake_minimum_required(VERSION 3.20)
project(counter_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (COUNTER_HTTP_SOURCES
    httpfactory.cpp
    httpcounter.cpp
)

# dynamic library

add_library(counter_http STATIC ${COUNTER_HTTP_SOURCES})
target_include_directories(counter_http PRIVATE ../counter)
target_link_libraries(counter_http PUBLIC apigear::utilities_qt Qt6::Network counter_api)
