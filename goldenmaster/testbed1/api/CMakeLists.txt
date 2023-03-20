cmake_minimum_required(VERSION 3.20)
project(testbed1_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

set (TESTBED1_API_SOURCES
    api.cpp
    apifactory.cpp
    qmlstructinterface.cpp
    qmlstructarrayinterface.cpp
)

# dynamic library

add_library(testbed1_api SHARED ${TESTBED1_API_SOURCES})
add_library(testbed1::testbed1_api ALIAS testbed1_api)

target_include_directories(testbed1_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed1_api PRIVATE  Qt5::Core Qt5::Qml Qt5::WebSockets
PUBLIC nlohmann_json::nlohmann_json)
target_compile_definitions(testbed1_api PRIVATE TESTBED1_API_LIBRARY)
