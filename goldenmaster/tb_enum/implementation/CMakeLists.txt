cmake_minimum_required(VERSION 3.20)
project(tb_enum_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_IMPL_SOURCES
    factory.cpp
    enuminterface.cpp
)

# dynamic library
add_library(tb_enum_impl SHARED ${TB_ENUM_IMPL_SOURCES})
add_library(tb_enum::tb_enum_impl ALIAS tb_enum_impl)

target_include_directories(tb_enum_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_enum_impl PRIVATE tb_enum::tb_enum_api)
target_compile_definitions(tb_enum_impl PRIVATE TB_ENUM_IMPL_LIBRARY)

add_subdirectory(tests)
