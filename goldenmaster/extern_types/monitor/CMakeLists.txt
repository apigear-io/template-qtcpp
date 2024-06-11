cmake_minimum_required(VERSION 3.20)
project(extern_types_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(extern_types QUIET COMPONENTS extern_types_api)

set (EXTERN_TYPES_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
)

add_library(extern_types_monitor SHARED ${EXTERN_TYPES_MONITOR_SOURCES})
target_include_directories(extern_types_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/extern_types>
)

target_link_libraries(extern_types_monitor PUBLIC extern_types::extern_types_api apigear::monitor_qt)
target_compile_definitions(extern_types_monitor PRIVATE EXTERN_TYPES_MONITOR_LIBRARY)
