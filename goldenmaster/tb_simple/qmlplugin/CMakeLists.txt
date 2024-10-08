

cmake_minimum_required(VERSION 3.20)
project(tb_simple_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json REQUIRED)

set (TB_SIMPLE_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlvoidinterface.cpp
    qmlsimpleinterface.cpp
    qmlsimplearrayinterface.cpp
    qmlnopropertiesinterface.cpp
    qmlnooperationsinterface.cpp
    qmlnosignalsinterface.cpp
)

# dynamic library

add_library(tb_simple_qml SHARED ${TB_SIMPLE_QML_SOURCES})
add_library(tb_simple::tb_simple_qml ALIAS tb_simple_qml)

qt_add_qml_module(tb_simple_qml
    URI "tb_simple"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/tb_simple
)

target_include_directories(tb_simple_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_simple_qml PUBLIC tb_simple::tb_simple_api PRIVATE Qt6::Qml )

target_compile_definitions(tb_simple_qml PRIVATE TB_SIMPLE_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_simple_qml PRIVATE /bigobj)
endif ()
