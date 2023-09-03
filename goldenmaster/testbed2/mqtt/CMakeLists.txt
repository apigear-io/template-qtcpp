cmake_minimum_required(VERSION 3.20)
project(testbed2_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(testbed2 QUIET COMPONENTS testbed2_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TESTBED2_MQTT_SOURCES
    mqttfactory.cpp
    mqttmanyparaminterface.cpp
    mqttmanyparaminterfaceadapter.cpp
    mqttnestedstruct1interface.cpp
    mqttnestedstruct1interfaceadapter.cpp
    mqttnestedstruct2interface.cpp
    mqttnestedstruct2interfaceadapter.cpp
    mqttnestedstruct3interface.cpp
    mqttnestedstruct3interfaceadapter.cpp
)


# dynamic library
add_library(testbed2_mqtt SHARED ${TESTBED2_MQTT_SOURCES})
add_library(testbed2::testbed2_mqtt ALIAS testbed2_mqtt)

target_include_directories(testbed2_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/testbed2>
)

target_link_libraries(testbed2_mqtt PUBLIC testbed2::testbed2_api apigear::apigear_mqtt Qt6::Concurrent qtpromise)
target_compile_definitions(testbed2_mqtt PRIVATE TESTBED2_MQTT_LIBRARY)


