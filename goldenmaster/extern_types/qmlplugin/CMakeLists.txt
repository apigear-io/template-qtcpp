

cmake_minimum_required(VERSION 3.20)
project(extern_types_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json REQUIRED)

set (EXTERN_TYPES_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
)

# dynamic library

add_library(extern_types_qml SHARED ${EXTERN_TYPES_QML_SOURCES})
add_library(extern_types::extern_types_qml ALIAS extern_types_qml)

qt_add_qml_module(extern_types_qml
    URI "extern_types"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/extern_types
)

target_include_directories(extern_types_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(extern_types_qml PUBLIC extern_types::extern_types_api PRIVATE Qt6::Qml )

target_compile_definitions(extern_types_qml PRIVATE EXTERN_TYPES_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(extern_types_qml PRIVATE /bigobj)
endif ()
