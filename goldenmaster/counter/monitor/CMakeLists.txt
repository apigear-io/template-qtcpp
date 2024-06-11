cmake_minimum_required(VERSION 3.20)
project(counter_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(counter QUIET COMPONENTS counter_api)

set (COUNTER_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    countertraced.cpp
)

add_library(counter_monitor SHARED ${COUNTER_MONITOR_SOURCES})
target_include_directories(counter_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/counter>
)

target_link_libraries(counter_monitor PUBLIC counter::counter_api apigear::monitor_qt)
target_compile_definitions(counter_monitor PRIVATE COUNTER_MONITOR_LIBRARY)
