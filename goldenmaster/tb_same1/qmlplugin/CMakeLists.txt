

cmake_minimum_required(VERSION 3.20)
project(tb_same1_qml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

find_package(nlohmann_json REQUIRED)

set (TB_SAME1_QML_SOURCES
    qml_api.cpp
    apifactory.cpp
    qmlsamestruct1interface.cpp
    qmlsamestruct2interface.cpp
    qmlsameenum1interface.cpp
    qmlsameenum2interface.cpp
)

# dynamic library

add_library(tb_same1_qml SHARED ${TB_SAME1_QML_SOURCES})
add_library(tb_same1::tb_same1_qml ALIAS tb_same1_qml)

qt_add_qml_module(tb_same1_qml
    URI "tb_same1"
    VERSION 1.0
    OUTPUT_DIRECTORY ${LIBRARY_PATH}/tb_same1
)

target_include_directories(tb_same1_qml
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same1_qml PUBLIC tb_same1::tb_same1_api PRIVATE Qt6::Qml )

target_compile_definitions(tb_same1_qml PRIVATE TB_SAME1_QML_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_same1_qml PRIVATE /bigobj)
endif ()
