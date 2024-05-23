

cmake_minimum_required(VERSION 3.20)
project(testbed2_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.11.3)
  FetchContent_MakeAvailable(json)
endif()

set (TESTBED2_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlmanyparaminterface.cpp
    qmlnestedstruct1interface.cpp
    qmlnestedstruct2interface.cpp
    qmlnestedstruct3interface.cpp
)

# dynamic library

add_library(testbed2_qml SHARED ${TESTBED2_QML_SOURCES})
add_library(testbed2::testbed2_qml ALIAS testbed2_qml)

qt_add_qml_module(testbed2_qml
    URI "testbed2"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/testbed2
)

target_include_directories(testbed2_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed2_qml PUBLIC testbed2::testbed2_api PRIVATE Qt6::Qml )

target_compile_definitions(testbed2_qml PRIVATE TESTBED2_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(testbed2_qml PRIVATE /bigobj)
endif ()
