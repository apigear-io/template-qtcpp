cmake_minimum_required(VERSION 3.20)
project(tb_same2_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

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

set (TB_SAME2_API_SOURCES
    api.cpp
)

# dynamic library

add_library(tb_same2_api SHARED ${TB_SAME2_API_SOURCES})
add_library(tb_same2::tb_same2_api ALIAS tb_same2_api)

target_include_directories(tb_same2_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same2_api PUBLIC nlohmann_json::nlohmann_json Qt6::Core)

target_compile_definitions(tb_same2_api PRIVATE TB_SAME2_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_same2_api PRIVATE /bigobj)
endif ()
