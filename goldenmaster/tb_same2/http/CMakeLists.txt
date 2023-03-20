cmake_minimum_required(VERSION 3.20)
project(tb_same2_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME2_HTTP_SOURCES
    httpfactory.cpp
    httpsamestruct1interface.cpp
    httpsamestruct2interface.cpp
    httpsameenum1interface.cpp
    httpsameenum2interface.cpp
)

# dynamic library

add_library(tb_same2_http STATIC ${TB_SAME2_HTTP_SOURCES})
target_include_directories(tb_same2_http PRIVATE ../tb_same2)
target_link_libraries(tb_same2_http PRIVATE Qt5::Network tb_same2_api)
