cmake_minimum_required(VERSION 3.20)
project(tb_simple_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core WebSockets)
find_package(apigear QUIET COMPONENTS monitor_qt )

set (TB_SIMPLE_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    simpleinterfacetraced.cpp
    simplearrayinterfacetraced.cpp
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

target_link_libraries(tb_simple_monitor PRIVATE tb_simple::tb_simple_api Qt5::Core Qt5::WebSockets apigear::monitor_qt)
target_compile_definitions(tb_simple_monitor PRIVATE TB_SIMPLE_MONITOR_LIBRARY)
