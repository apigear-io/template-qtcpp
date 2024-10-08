cmake_minimum_required(VERSION 3.20)

project(test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(JSON_BuildTests OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions(QT_DISABLE_DEPRECATED_UP_TO=0x050F00)

# on Windows it is helpful to have all binary files next to each other
# it is intentionally not set as part of BUILD_TESTING to have a consistent behavior
# this can be removed once there is a better option than modifying the PATH env for unit testing
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTING "Enable this option to build the test targets" OFF)

if(BUILD_TESTING)
find_package(Qt6 COMPONENTS Test REQUIRED)
enable_testing()
endif() # BUILD_TESTING

set(LIBRARY_PATH "${CMAKE_BINARY_DIR}/libs" CACHE STRING "Path where the libraries are deployed")
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.11.3
  OVERRIDE_FIND_PACKAGE)
  FetchContent_MakeAvailable(nlohmann_json)
endif()
add_subdirectory(apigear)
add_subdirectory(testbed2/api)
add_subdirectory(testbed2/implementation)
add_subdirectory(testbed2/http)
add_subdirectory(testbed2/olink)
add_subdirectory(testbed2/mqtt)
add_subdirectory(testbed2/monitor)
add_subdirectory(testbed2/qmlplugin)
add_subdirectory(tb_enum/api)
add_subdirectory(tb_enum/implementation)
add_subdirectory(tb_enum/http)
add_subdirectory(tb_enum/olink)
add_subdirectory(tb_enum/mqtt)
add_subdirectory(tb_enum/monitor)
add_subdirectory(tb_enum/qmlplugin)
add_subdirectory(tb_same1/api)
add_subdirectory(tb_same1/implementation)
add_subdirectory(tb_same1/http)
add_subdirectory(tb_same1/olink)
add_subdirectory(tb_same1/mqtt)
add_subdirectory(tb_same1/monitor)
add_subdirectory(tb_same1/qmlplugin)
add_subdirectory(tb_same2/api)
add_subdirectory(tb_same2/implementation)
add_subdirectory(tb_same2/http)
add_subdirectory(tb_same2/olink)
add_subdirectory(tb_same2/mqtt)
add_subdirectory(tb_same2/monitor)
add_subdirectory(tb_same2/qmlplugin)
add_subdirectory(tb_simple/api)
add_subdirectory(tb_simple/implementation)
add_subdirectory(tb_simple/http)
add_subdirectory(tb_simple/olink)
add_subdirectory(tb_simple/mqtt)
add_subdirectory(tb_simple/monitor)
add_subdirectory(tb_simple/qmlplugin)
add_subdirectory(testbed1/api)
add_subdirectory(testbed1/implementation)
add_subdirectory(testbed1/http)
add_subdirectory(testbed1/olink)
add_subdirectory(testbed1/mqtt)
add_subdirectory(testbed1/monitor)
add_subdirectory(testbed1/qmlplugin)
add_subdirectory(tb_names/api)
add_subdirectory(tb_names/implementation)
add_subdirectory(tb_names/http)
add_subdirectory(tb_names/olink)
add_subdirectory(tb_names/mqtt)
add_subdirectory(tb_names/monitor)
add_subdirectory(tb_names/qmlplugin)
add_subdirectory(custom_types/api)
add_subdirectory(custom_types/implementation)
add_subdirectory(custom_types/http)
add_subdirectory(custom_types/olink)
add_subdirectory(custom_types/mqtt)
add_subdirectory(custom_types/monitor)
add_subdirectory(custom_types/qmlplugin)
add_subdirectory(extern_types/api)
add_subdirectory(extern_types/implementation)
add_subdirectory(extern_types/http)
add_subdirectory(extern_types/olink)
add_subdirectory(extern_types/mqtt)
add_subdirectory(extern_types/monitor)
add_subdirectory(extern_types/qmlplugin)
add_subdirectory(counter/api)
add_subdirectory(counter/implementation)
add_subdirectory(counter/http)
add_subdirectory(counter/olink)
add_subdirectory(counter/mqtt)
add_subdirectory(counter/monitor)
add_subdirectory(counter/qmlplugin)
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
add_subdirectory(examples/qml)
add_subdirectory(examples/mqttservice)
add_subdirectory(examples/mqttclient)
add_subdirectory(examples/mqttqml)
