cmake_minimum_required(VERSION 3.20)
project(extern_types_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(extern_types QUIET COMPONENTS extern_types_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (EXTERN_TYPES_MQTT_SOURCES
    mqttfactory.cpp
)


# dynamic library
add_library(extern_types_mqtt SHARED ${EXTERN_TYPES_MQTT_SOURCES})
add_library(extern_types::extern_types_mqtt ALIAS extern_types_mqtt)

target_include_directories(extern_types_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/extern_types>
)

if (ENABLE_MQTT_TEST_FOR_NON_LINUX_OS OR ((NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin") AND (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")))
add_subdirectory(tests)
endif()

target_link_libraries(extern_types_mqtt PUBLIC extern_types::extern_types_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(extern_types_mqtt PRIVATE EXTERN_TYPES_MQTT_LIBRARY)


