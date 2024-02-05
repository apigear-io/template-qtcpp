cmake_minimum_required(VERSION 3.20)
project(tb_names_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(Qt5 REQUIRED COMPONENTS Core)

set (TB_NAMES_IMPL_SOURCES
    factory.cpp
    nam_es.cpp
)

# dynamic library
add_library(tb_names_impl SHARED ${TB_NAMES_IMPL_SOURCES})
add_library(tb_names::tb_names_impl ALIAS tb_names_impl)

target_include_directories(tb_names_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_names_impl PUBLIC tb_names::tb_names_api)
target_compile_definitions(tb_names_impl PRIVATE TB_NAMES_IMPL_LIBRARY)

add_subdirectory(tests)
