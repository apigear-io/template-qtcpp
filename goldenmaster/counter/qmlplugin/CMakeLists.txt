

cmake_minimum_required(VERSION 3.20)
project(counter_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json REQUIRED)

set (COUNTER_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlcounter.cpp
)

# dynamic library

add_library(counter_qml SHARED ${COUNTER_QML_SOURCES})
add_library(counter::counter_qml ALIAS counter_qml)

qt_add_qml_module(counter_qml
    URI "counter"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/counter
)

target_include_directories(counter_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(counter_qml PUBLIC counter::counter_api PRIVATE Qt6::Qml )

target_compile_definitions(counter_qml PRIVATE COUNTER_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(counter_qml PRIVATE /bigobj)
endif ()
