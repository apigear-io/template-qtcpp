cmake_minimum_required(VERSION 3.20)
project(tb_simple_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(tb_simple QUIET COMPONENTS tb_simple_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_SIMPLE_MQTT_SOURCES
    mqttfactory.cpp
    mqttvoidinterface.cpp
    mqttvoidinterfaceadapter.cpp
    mqttsimpleinterface.cpp
    mqttsimpleinterfaceadapter.cpp
    mqttsimplearrayinterface.cpp
    mqttsimplearrayinterfaceadapter.cpp
    mqttnopropertiesinterface.cpp
    mqttnopropertiesinterfaceadapter.cpp
    mqttnooperationsinterface.cpp
    mqttnooperationsinterfaceadapter.cpp
    mqttnosignalsinterface.cpp
    mqttnosignalsinterfaceadapter.cpp
)


# dynamic library
add_library(tb_simple_mqtt SHARED ${TB_SIMPLE_MQTT_SOURCES})
add_library(tb_simple::tb_simple_mqtt ALIAS tb_simple_mqtt)

target_include_directories(tb_simple_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/tb_simple>
)

target_link_libraries(tb_simple_mqtt PUBLIC tb_simple::tb_simple_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(tb_simple_mqtt PRIVATE TB_SIMPLE_MQTT_LIBRARY)


