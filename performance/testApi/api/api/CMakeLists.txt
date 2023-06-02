cmake_minimum_required(VERSION 3.20)
project(api_api LANGUAGES CXX)

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

set (API_API_SOURCES
    api.cpp
    apifactory.cpp
    qmltestapi0.cpp
    qmltestapi1.cpp
    qmltestapi2.cpp
    qmltestapi3.cpp
    qmltestapi4.cpp
    qmltestapi5.cpp
    qmltestapi6.cpp
    qmltestapi7.cpp
    qmltestapi8.cpp
    qmltestapi9.cpp
    qmltestapi10.cpp
    qmltestapi11.cpp
    qmltestapi12.cpp
    qmltestapi13.cpp
    qmltestapi14.cpp
    qmltestapi15.cpp
    qmltestapi16.cpp
    qmltestapi17.cpp
    qmltestapi18.cpp
    qmltestapi19.cpp
    qmltestapi20.cpp
    qmltestapi21.cpp
    qmltestapi22.cpp
    qmltestapi23.cpp
    qmltestapi24.cpp
    qmltestapi25.cpp
    qmltestapi26.cpp
    qmltestapi27.cpp
    qmltestapi28.cpp
    qmltestapi29.cpp
    qmltestapi30.cpp
    qmltestapi31.cpp
    qmltestapi32.cpp
    qmltestapi33.cpp
    qmltestapi34.cpp
    qmltestapi35.cpp
    qmltestapi36.cpp
    qmltestapi37.cpp
    qmltestapi38.cpp
    qmltestapi39.cpp
    qmltestapi40.cpp
    qmltestapi41.cpp
    qmltestapi42.cpp
    qmltestapi43.cpp
    qmltestapi44.cpp
    qmltestapi45.cpp
    qmltestapi46.cpp
    qmltestapi47.cpp
    qmltestapi48.cpp
    qmltestapi49.cpp
    qmltestapi50.cpp
    qmltestapi51.cpp
    qmltestapi52.cpp
    qmltestapi53.cpp
    qmltestapi54.cpp
    qmltestapi55.cpp
    qmltestapi56.cpp
    qmltestapi57.cpp
    qmltestapi58.cpp
    qmltestapi59.cpp
    qmltestapi60.cpp
    qmltestapi61.cpp
    qmltestapi62.cpp
    qmltestapi63.cpp
    qmltestapi64.cpp
    qmltestapi65.cpp
    qmltestapi66.cpp
    qmltestapi67.cpp
    qmltestapi68.cpp
    qmltestapi69.cpp
    qmltestapi70.cpp
    qmltestapi71.cpp
    qmltestapi72.cpp
    qmltestapi73.cpp
    qmltestapi74.cpp
    qmltestapi75.cpp
    qmltestapi76.cpp
    qmltestapi77.cpp
    qmltestapi78.cpp
    qmltestapi79.cpp
    qmltestapi80.cpp
    qmltestapi81.cpp
    qmltestapi82.cpp
    qmltestapi83.cpp
    qmltestapi84.cpp
    qmltestapi85.cpp
    qmltestapi86.cpp
    qmltestapi87.cpp
    qmltestapi88.cpp
    qmltestapi89.cpp
    qmltestapi90.cpp
    qmltestapi91.cpp
    qmltestapi92.cpp
    qmltestapi93.cpp
    qmltestapi94.cpp
    qmltestapi95.cpp
    qmltestapi96.cpp
    qmltestapi97.cpp
    qmltestapi98.cpp
    qmltestapi99.cpp
)

# dynamic library

add_library(api_api SHARED ${API_API_SOURCES})
add_library(api::api_api ALIAS api_api)

target_include_directories(api_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(api_api PUBLIC
Qt5::Core
Qt5::Qml
nlohmann_json::nlohmann_json)

target_compile_definitions(api_api PRIVATE API_API_LIBRARY)
