cmake_minimum_required(VERSION 3.20)
project(counter_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(counter QUIET COMPONENTS counter_api)

set (COUNTER_IMPL_SOURCES
    factory.cpp
    counter.cpp
)

# dynamic library
add_library(counter_impl SHARED ${COUNTER_IMPL_SOURCES})
add_library(counter::counter_impl ALIAS counter_impl)

target_include_directories(counter_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(counter_impl PUBLIC counter::counter_api)
target_compile_definitions(counter_impl PRIVATE COUNTER_IMPL_LIBRARY)

add_subdirectory(tests)
