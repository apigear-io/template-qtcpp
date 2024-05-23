cmake_minimum_required(VERSION 3.20)
project(tb_enum_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(tb_enum QUIET COMPONENTS tb_enum_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_ENUM_MQTT_SOURCES
    mqttfactory.cpp
    mqttenuminterface.cpp
    mqttenuminterfaceadapter.cpp
)


# dynamic library
add_library(tb_enum_mqtt SHARED ${TB_ENUM_MQTT_SOURCES})
add_library(tb_enum::tb_enum_mqtt ALIAS tb_enum_mqtt)

target_include_directories(tb_enum_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/tb_enum>
)

target_link_libraries(tb_enum_mqtt PUBLIC tb_enum::tb_enum_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(tb_enum_mqtt PRIVATE TB_ENUM_MQTT_LIBRARY)


