cmake_minimum_required(VERSION 3.20)
project(custom_types_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(custom_types QUIET COMPONENTS custom_types_api)

set (CUSTOM_TYPES_IMPL_SOURCES
    factory.cpp
)

# dynamic library
add_library(custom_types_impl SHARED ${CUSTOM_TYPES_IMPL_SOURCES})
add_library(custom_types::custom_types_impl ALIAS custom_types_impl)

target_include_directories(custom_types_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(custom_types_impl PUBLIC custom_types::custom_types_api)
target_compile_definitions(custom_types_impl PRIVATE CUSTOM_TYPES_IMPL_LIBRARY)

add_subdirectory(tests)
