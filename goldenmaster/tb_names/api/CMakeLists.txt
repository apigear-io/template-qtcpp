cmake_minimum_required(VERSION 3.20)
project(tb_names_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_NAMES_API_SOURCES
    api.cpp
)

# dynamic library

add_library(tb_names_api SHARED ${TB_NAMES_API_SOURCES})
add_library(tb_names::tb_names_api ALIAS tb_names_api)

target_include_directories(tb_names_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_names_api PUBLIC nlohmann_json::nlohmann_json Qt6::Core)

target_compile_definitions(tb_names_api PRIVATE TB_NAMES_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_names_api PRIVATE /bigobj)
endif ()
