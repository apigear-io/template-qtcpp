cmake_minimum_required(VERSION 3.20)
project(custom_types_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(custom_types QUIET COMPONENTS custom_types_api)

set (CUSTOM_TYPES_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
)

add_library(custom_types_monitor SHARED ${CUSTOM_TYPES_MONITOR_SOURCES})
target_include_directories(custom_types_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/custom_types>
)

target_link_libraries(custom_types_monitor PUBLIC custom_types::custom_types_api apigear::monitor_qt)
target_compile_definitions(custom_types_monitor PRIVATE CUSTOM_TYPES_MONITOR_LIBRARY)
