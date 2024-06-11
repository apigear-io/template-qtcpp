cmake_minimum_required(VERSION 3.20)
project(custom_types_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(custom_types QUIET COMPONENTS custom_types_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (CUSTOM_TYPES_MQTT_SOURCES
    mqttfactory.cpp
)


# dynamic library
add_library(custom_types_mqtt SHARED ${CUSTOM_TYPES_MQTT_SOURCES})
add_library(custom_types::custom_types_mqtt ALIAS custom_types_mqtt)

target_include_directories(custom_types_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/custom_types>
)

target_link_libraries(custom_types_mqtt PUBLIC custom_types::custom_types_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(custom_types_mqtt PRIVATE CUSTOM_TYPES_MQTT_LIBRARY)


