cmake_minimum_required(VERSION 3.20)
project(tb_same2_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS monitor_qt )

set (TB_SAME2_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    samestruct1interfacetraced.cpp
    samestruct2interfacetraced.cpp
    sameenum1interfacetraced.cpp
    sameenum2interfacetraced.cpp
)

add_library(tb_same2_monitor SHARED ${TB_SAME2_MONITOR_SOURCES})
target_include_directories(tb_same2_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_same2>
)

target_link_libraries(tb_same2_monitor PUBLIC tb_same2::tb_same2_api apigear::monitor_qt)
target_compile_definitions(tb_same2_monitor PRIVATE TB_SAME2_MONITOR_LIBRARY)
