cmake_minimum_required(VERSION 3.20)
project(tb_names_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(tb_names QUIET COMPONENTS tb_names_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_NAMES_MQTT_SOURCES
    mqttfactory.cpp
    mqttnam_es.cpp
    mqttnam_esadapter.cpp
)


# dynamic library
add_library(tb_names_mqtt SHARED ${TB_NAMES_MQTT_SOURCES})
add_library(tb_names::tb_names_mqtt ALIAS tb_names_mqtt)

target_include_directories(tb_names_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/tb_names>
)

target_link_libraries(tb_names_mqtt PUBLIC tb_names::tb_names_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(tb_names_mqtt PRIVATE TB_NAMES_MQTT_LIBRARY)


