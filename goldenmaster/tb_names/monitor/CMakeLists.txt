cmake_minimum_required(VERSION 3.20)
project(tb_names_monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(apigear QUIET COMPONENTS monitor_qt )

set (TB_NAMES_MONITOR_SOURCES
    tracedapifactory.cpp
    agent.cpp
    nam_estraced.cpp
)

add_library(tb_names_monitor SHARED ${TB_NAMES_MONITOR_SOURCES})
target_include_directories(tb_names_monitor
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_names>
)

target_link_libraries(tb_names_monitor PUBLIC tb_names::tb_names_api apigear::monitor_qt)
target_compile_definitions(tb_names_monitor PRIVATE TB_NAMES_MONITOR_LIBRARY)
