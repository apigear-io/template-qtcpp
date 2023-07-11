cmake_minimum_required(VERSION 3.20)
project(tb_same1_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(apigear QUIET COMPONENTS monitor_qt)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api)

set (TB_SAME1_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    samestruct1interfacetraced.cpp
    samestruct2interfacetraced.cpp
    sameenum1interfacetraced.cpp
    sameenum2interfacetraced.cpp
)

add_library(tb_same1_monitor SHARED ${TB_SAME1_MONITOR_SOURCES})
target_include_directories(tb_same1_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_same1>
)

target_link_libraries(tb_same1_monitor PUBLIC tb_same1::tb_same1_api apigear::monitor_qt)
target_compile_definitions(tb_same1_monitor PRIVATE TB_SAME1_MONITOR_LIBRARY)
