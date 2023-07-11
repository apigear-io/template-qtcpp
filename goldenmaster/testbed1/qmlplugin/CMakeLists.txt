

cmake_minimum_required(VERSION 3.20)
project(testbed1_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

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

set (TESTBED1_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlstructinterface.cpp
    qmlstructarrayinterface.cpp
)

# dynamic library

add_library(testbed1_qml SHARED ${TESTBED1_QML_SOURCES})
add_library(testbed1::testbed1_qml ALIAS testbed1_qml)

qt_add_qml_module(testbed1_qml
    URI "testbed1"
    VERSION 1.0
    RESOURCE_PREFIX ${OUTPUT_PATH}/testbed1/qml
)

target_include_directories(testbed1_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed1_qml PUBLIC testbed1::testbed1_api PRIVATE Qt6::Qml )

target_compile_definitions(testbed1_qml PRIVATE TESTBED1_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(testbed1_qml PRIVATE /bigobj)
endif ()
