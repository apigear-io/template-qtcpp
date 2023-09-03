cmake_minimum_required(VERSION 3.20)
project(tb_same1_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_SAME1_MQTT_SOURCES
    mqttfactory.cpp
    mqttsamestruct1interface.cpp
    mqttsamestruct1interfaceadapter.cpp
    mqttsamestruct2interface.cpp
    mqttsamestruct2interfaceadapter.cpp
    mqttsameenum1interface.cpp
    mqttsameenum1interfaceadapter.cpp
    mqttsameenum2interface.cpp
    mqttsameenum2interfaceadapter.cpp
)


# dynamic library
add_library(tb_same1_mqtt SHARED ${TB_SAME1_MQTT_SOURCES})
add_library(tb_same1::tb_same1_mqtt ALIAS tb_same1_mqtt)

target_include_directories(tb_same1_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/tb_same1>
)

target_link_libraries(tb_same1_mqtt PUBLIC tb_same1::tb_same1_api apigear::apigear_mqtt Qt6::Concurrent qtpromise)
target_compile_definitions(tb_same1_mqtt PRIVATE TB_SAME1_MQTT_LIBRARY)


