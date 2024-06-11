cmake_minimum_required(VERSION 3.20)
project(custom_types_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (CUSTOM_TYPES_HTTP_SOURCES
    httpfactory.cpp
)

# dynamic library

add_library(custom_types_http STATIC ${CUSTOM_TYPES_HTTP_SOURCES})
target_include_directories(custom_types_http PRIVATE ../custom_types)
target_link_libraries(custom_types_http PUBLIC apigear::utilities_qt Qt6::Network custom_types_api)
