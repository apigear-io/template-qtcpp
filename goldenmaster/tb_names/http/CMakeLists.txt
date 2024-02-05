cmake_minimum_required(VERSION 3.20)
project(tb_names_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_NAMES_HTTP_SOURCES
    httpfactory.cpp
    httpnam_es.cpp
)

# dynamic library

add_library(tb_names_http STATIC ${TB_NAMES_HTTP_SOURCES})
target_include_directories(tb_names_http PRIVATE ../tb_names)
target_link_libraries(tb_names_http PUBLIC apigear::utilities_qt Qt5::Network tb_names_api)
