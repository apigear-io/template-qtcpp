cmake_minimum_required(VERSION 3.20)
project(tb_same1_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

set (TB_SAME1_API_SOURCES
    api.cpp
    apifactory.cpp
    qmlsamestruct1interface.cpp
    qmlsamestruct2interface.cpp
    qmlsameenum1interface.cpp
    qmlsameenum2interface.cpp
)

# dynamic library

add_library(tb_same1_api SHARED ${TB_SAME1_API_SOURCES})
add_library(tb_same1::tb_same1_api ALIAS tb_same1_api)

target_include_directories(tb_same1_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same1_api PUBLIC
Qt5::Core
Qt5::Qml
nlohmann_json::nlohmann_json)

target_compile_definitions(tb_same1_api PRIVATE TB_SAME1_API_LIBRARY)
