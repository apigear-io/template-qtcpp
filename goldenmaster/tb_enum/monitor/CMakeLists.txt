cmake_minimum_required(VERSION 3.20)
project(tb_enum_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS monitor_qt )

set (TB_ENUM_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    enuminterfacetraced.cpp
)

add_library(tb_enum_monitor SHARED ${TB_ENUM_MONITOR_SOURCES})
target_include_directories(tb_enum_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_enum>
)

target_link_libraries(tb_enum_monitor PUBLIC tb_enum::tb_enum_api apigear::monitor_qt)
target_compile_definitions(tb_enum_monitor PRIVATE TB_ENUM_MONITOR_LIBRARY)
