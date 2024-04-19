cmake_minimum_required(VERSION 3.20)
project(testbed1_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(testbed1 QUIET COMPONENTS testbed1_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TESTBED1_MQTT_SOURCES
    mqttfactory.cpp
    mqttstructinterface.cpp
    mqttstructinterfaceadapter.cpp
    mqttstructarrayinterface.cpp
    mqttstructarrayinterfaceadapter.cpp
)


# dynamic library
add_library(testbed1_mqtt SHARED ${TESTBED1_MQTT_SOURCES})
add_library(testbed1::testbed1_mqtt ALIAS testbed1_mqtt)

target_include_directories(testbed1_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/testbed1>
)

target_link_libraries(testbed1_mqtt PUBLIC testbed1::testbed1_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(testbed1_mqtt PRIVATE TESTBED1_MQTT_LIBRARY)


