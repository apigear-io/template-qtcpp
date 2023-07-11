cmake_minimum_required(VERSION 3.20)
project(testbed1_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(testbed1 QUIET COMPONENTS testbed1_api)

set (TESTBED1_IMPL_SOURCES
    factory.cpp
    structinterface.cpp
    structarrayinterface.cpp
)

# dynamic library
add_library(testbed1_impl SHARED ${TESTBED1_IMPL_SOURCES})
add_library(testbed1::testbed1_impl ALIAS testbed1_impl)

target_include_directories(testbed1_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed1_impl PUBLIC testbed1::testbed1_api)
target_compile_definitions(testbed1_impl PRIVATE TESTBED1_IMPL_LIBRARY)

add_subdirectory(tests)
