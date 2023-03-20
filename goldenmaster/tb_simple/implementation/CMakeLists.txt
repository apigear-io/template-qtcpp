cmake_minimum_required(VERSION 3.20)
project(tb_simple_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_IMPL_SOURCES
    factory.cpp
    simpleinterface.cpp
    simplearrayinterface.cpp
)

# dynamic library
add_library(tb_simple_impl SHARED ${TB_SIMPLE_IMPL_SOURCES})
add_library(tb_simple::tb_simple_impl ALIAS tb_simple_impl)

target_include_directories(tb_simple_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_simple_impl PRIVATE tb_simple::tb_simple_api)
target_compile_definitions(tb_simple_impl PRIVATE TB_SIMPLE_IMPL_LIBRARY)

add_subdirectory(tests)
