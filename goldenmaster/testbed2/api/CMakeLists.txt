cmake_minimum_required(VERSION 3.20)
project(testbed2_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_API_SOURCES
    api.cpp
)

# dynamic library

add_library(testbed2_api SHARED ${TESTBED2_API_SOURCES})
add_library(testbed2::testbed2_api ALIAS testbed2_api)

target_include_directories(testbed2_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed2_api PUBLIC  nlohmann_json::nlohmann_json Qt6::Core)

target_compile_definitions(testbed2_api PRIVATE TESTBED2_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(testbed2_api PRIVATE /bigobj)
endif ()
