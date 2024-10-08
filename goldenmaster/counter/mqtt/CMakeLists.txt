cmake_minimum_required(VERSION 3.20)
project(counter_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(counter QUIET COMPONENTS counter_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (COUNTER_MQTT_SOURCES
    mqttfactory.cpp
    mqttcounter.cpp
    mqttcounteradapter.cpp
)


# dynamic library
add_library(counter_mqtt SHARED ${COUNTER_MQTT_SOURCES})
add_library(counter::counter_mqtt ALIAS counter_mqtt)

target_include_directories(counter_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/counter>
)

if (ENABLE_MQTT_TEST_FOR_NON_LINUX_OS OR ((NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin") AND (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")))
add_subdirectory(tests)
endif()

target_link_libraries(counter_mqtt PUBLIC counter::counter_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(counter_mqtt PRIVATE COUNTER_MQTT_LIBRARY)


