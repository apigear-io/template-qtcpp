cmake_minimum_required(VERSION 3.20)
project(tb_same1_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(Qt5 REQUIRED COMPONENTS Core)

set (TB_SAME1_IMPL_SOURCES
    factory.cpp
    samestruct1interface.cpp
    samestruct2interface.cpp
    sameenum1interface.cpp
    sameenum2interface.cpp
)

# dynamic library
add_library(tb_same1_impl SHARED ${TB_SAME1_IMPL_SOURCES})
add_library(tb_same1::tb_same1_impl ALIAS tb_same1_impl)

target_include_directories(tb_same1_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same1_impl PUBLIC tb_same1::tb_same1_api)
target_compile_definitions(tb_same1_impl PRIVATE TB_SAME1_IMPL_LIBRARY)

add_subdirectory(tests)
