cmake_minimum_required(VERSION 3.20)
project(tb_enum_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_HTTP_SOURCES
    httpfactory.cpp
    httpenuminterface.cpp
)

# dynamic library

add_library(tb_enum_http STATIC ${TB_ENUM_HTTP_SOURCES})
target_include_directories(tb_enum_http PRIVATE ../tb_enum)
target_link_libraries(tb_enum_http PUBLIC apigear::utilities_qt Qt5::Network tb_enum_api)
