cmake_minimum_required(VERSION 3.20)
project(testbed1_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(testbed1 QUIET COMPONENTS testbed1_api)

set (TESTBED1_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    structinterfacetraced.cpp
    structarrayinterfacetraced.cpp
)

add_library(testbed1_monitor SHARED ${TESTBED1_MONITOR_SOURCES})
target_include_directories(testbed1_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/testbed1>
)

target_link_libraries(testbed1_monitor PUBLIC testbed1::testbed1_api apigear::monitor_qt)
target_compile_definitions(testbed1_monitor PRIVATE TESTBED1_MONITOR_LIBRARY)
