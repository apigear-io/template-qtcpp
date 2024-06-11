cmake_minimum_required(VERSION 3.20)
project(tb_simple_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(tb_simple QUIET COMPONENTS tb_simple_api)

set (TB_SIMPLE_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    voidinterfacetraced.cpp
    simpleinterfacetraced.cpp
    simplearrayinterfacetraced.cpp
    nopropertiesinterfacetraced.cpp
    nooperationsinterfacetraced.cpp
    nosignalsinterfacetraced.cpp
)

add_library(tb_simple_monitor SHARED ${TB_SIMPLE_MONITOR_SOURCES})
target_include_directories(tb_simple_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_simple>
)

target_link_libraries(tb_simple_monitor PUBLIC tb_simple::tb_simple_api apigear::monitor_qt)
target_compile_definitions(tb_simple_monitor PRIVATE TB_SIMPLE_MONITOR_LIBRARY)
