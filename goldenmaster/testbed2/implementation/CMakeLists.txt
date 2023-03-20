cmake_minimum_required(VERSION 3.20)
project(testbed2_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_IMPL_SOURCES
    factory.cpp
    manyparaminterface.cpp
    nestedstruct1interface.cpp
    nestedstruct2interface.cpp
    nestedstruct3interface.cpp
)

# dynamic library
add_library(testbed2_impl SHARED ${TESTBED2_IMPL_SOURCES})
add_library(testbed2::testbed2_impl ALIAS testbed2_impl)

target_include_directories(testbed2_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed2_impl PRIVATE testbed2::testbed2_api)
target_compile_definitions(testbed2_impl PRIVATE TESTBED2_IMPL_LIBRARY)

add_subdirectory(tests)
