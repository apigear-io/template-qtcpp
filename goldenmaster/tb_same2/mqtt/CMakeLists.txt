cmake_minimum_required(VERSION 3.20)
project(tb_same2_mqtt)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_SAME2_MQTT_SOURCES
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
add_library(tb_same2_mqtt SHARED ${TB_SAME2_MQTT_SOURCES})
add_library(tb_same2::tb_same2_mqtt ALIAS tb_same2_mqtt)

target_include_directories(tb_same2_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include/tb_same2>
)

if (ENABLE_MQTT_TEST_FOR_NON_LINUX_OS OR ((NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin") AND (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")))
add_subdirectory(tests)
endif()

target_link_libraries(tb_same2_mqtt PUBLIC tb_same2::tb_same2_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions(tb_same2_mqtt PRIVATE TB_SAME2_MQTT_LIBRARY)


