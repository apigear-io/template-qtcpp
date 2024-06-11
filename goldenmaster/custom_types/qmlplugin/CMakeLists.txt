

cmake_minimum_required(VERSION 3.20)
project(custom_types_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json REQUIRED)

set (CUSTOM_TYPES_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
)

# dynamic library

add_library(custom_types_qml SHARED ${CUSTOM_TYPES_QML_SOURCES})
add_library(custom_types::custom_types_qml ALIAS custom_types_qml)

qt_add_qml_module(custom_types_qml
    URI "custom_types"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/custom_types
)

target_include_directories(custom_types_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(custom_types_qml PUBLIC custom_types::custom_types_api PRIVATE Qt6::Qml )

target_compile_definitions(custom_types_qml PRIVATE CUSTOM_TYPES_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(custom_types_qml PRIVATE /bigobj)
endif ()
