cmake_minimum_required(VERSION 3.20)
project(extern_types_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(extern_types QUIET COMPONENTS extern_types_api)

set (EXTERN_TYPES_IMPL_SOURCES
    factory.cpp
)

# dynamic library
add_library(extern_types_impl SHARED ${EXTERN_TYPES_IMPL_SOURCES})
add_library(extern_types::extern_types_impl ALIAS extern_types_impl)

target_include_directories(extern_types_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(extern_types_impl PUBLIC extern_types::extern_types_api)
target_compile_definitions(extern_types_impl PRIVATE EXTERN_TYPES_IMPL_LIBRARY)

add_subdirectory(tests)
