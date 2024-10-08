
cmake_minimum_required(VERSION 3.20)
project(test_tb_names_generated_mqtt)

set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TESTING)
include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Test Core)
find_package(apigear QUIET COMPONENTS apigear_mqtt)
find_package(tb_names QUIET COMPONENTS tb_names_impl tb_names_mqtt)

find_package(Catch2 REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set(TEST_TB_NAMES_GENERATED_MQTT_SOURCES
    test_main.cpp
    )

include_directories(test_tb_names_generated_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(test_tb_names_generated_mqtt ${TEST_TB_NAMES_GENERATED_MQTT_SOURCES})
add_test(NAME test_tb_names_generated_mqtt COMMAND $<TARGET_FILE:test_tb_names_generated_mqtt>)
add_dependencies(check test_tb_names_generated_mqtt)

target_link_libraries(test_tb_names_generated_mqtt PRIVATE
    apigear_mqtt
    tb_names_impl
    tb_names_mqtt
    Catch2::Catch2
    Qt::Test)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)

install(TARGETS test_tb_names_generated_mqtt
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

endif() # BUILD_TESTING
