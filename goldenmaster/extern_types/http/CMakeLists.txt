cmake_minimum_required(VERSION 3.20)
project(extern_types_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (EXTERN_TYPES_HTTP_SOURCES
    httpfactory.cpp
)

# dynamic library

add_library(extern_types_http STATIC ${EXTERN_TYPES_HTTP_SOURCES})
target_include_directories(extern_types_http PRIVATE ../extern_types)
target_link_libraries(extern_types_http PUBLIC apigear::utilities_qt Qt6::Network extern_types_api)
