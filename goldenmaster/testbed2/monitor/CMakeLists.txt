cmake_minimum_required(VERSION 3.20)
project(testbed2_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(testbed2 QUIET COMPONENTS testbed2_api)

set (TESTBED2_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    manyparaminterfacetraced.cpp
    nestedstruct1interfacetraced.cpp
    nestedstruct2interfacetraced.cpp
    nestedstruct3interfacetraced.cpp
)

add_library(testbed2_monitor SHARED ${TESTBED2_MONITOR_SOURCES})
target_include_directories(testbed2_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/testbed2>
)

target_link_libraries(testbed2_monitor PUBLIC testbed2::testbed2_api apigear::monitor_qt)
target_compile_definitions(testbed2_monitor PRIVATE TESTBED2_MONITOR_LIBRARY)
