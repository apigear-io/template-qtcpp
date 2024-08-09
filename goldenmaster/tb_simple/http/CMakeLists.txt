cmake_minimum_required(VERSION 3.20)
project(tb_simple_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_HTTP_SOURCES
    httpfactory.cpp
    httpvoidinterface.cpp
    httpsimpleinterface.cpp
    httpsimplearrayinterface.cpp
    httpnopropertiesinterface.cpp
    httpnooperationsinterface.cpp
    httpnosignalsinterface.cpp
)

# dynamic library

add_library(tb_simple_http STATIC ${TB_SIMPLE_HTTP_SOURCES})
target_include_directories(tb_simple_http PRIVATE ../tb_simple)
target_link_libraries(tb_simple_http PUBLIC apigear::utilities_qt Qt6::Network tb_simple_api)
