

cmake_minimum_required(VERSION 3.20)
project(tb_names_qml LANGUAGES CXX)

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

set (TB_NAMES_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlnam_es.cpp
)

# dynamic library

add_library(tb_names_qml SHARED ${TB_NAMES_QML_SOURCES})
add_library(tb_names::tb_names_qml ALIAS tb_names_qml)

qt_add_qml_module(tb_names_qml
    URI "tb_names"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/tb_names
)

target_include_directories(tb_names_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_names_qml PUBLIC tb_names::tb_names_api PRIVATE Qt6::Qml )

target_compile_definitions(tb_names_qml PRIVATE TB_NAMES_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_names_qml PRIVATE /bigobj)
endif ()
