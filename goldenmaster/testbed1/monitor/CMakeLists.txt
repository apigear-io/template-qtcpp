cmake_minimum_required(VERSION 3.20)
project(testbed1_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core WebSockets)
find_package(apigear QUIET COMPONENTS monitor_qt )

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

target_link_libraries(testbed1_monitor PRIVATE testbed1::testbed1_api Qt5::Core Qt5::WebSockets apigear::monitor_qt)
target_compile_definitions(testbed1_monitor PRIVATE TESTBED1_MONITOR_LIBRARY)
