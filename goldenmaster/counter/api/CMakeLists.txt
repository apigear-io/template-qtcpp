cmake_minimum_required(VERSION 3.20)
project(counter_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS utilities_qt)


find_package(Qt6 REQUIRED Core )
find_package(nlohmann_json REQUIRED )

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (COUNTER_API_SOURCES
    api.cpp
)

# dynamic library

add_library(counter_api SHARED ${COUNTER_API_SOURCES})
add_library(counter::counter_api ALIAS counter_api)

target_include_directories(counter_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(counter_api PUBLIC apigear::utilities_qt custom_types_api extern_types_api Qt6::Core nlohmann_json::nlohmann_json )

target_compile_definitions(counter_api PRIVATE COUNTER_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(counter_api PRIVATE /bigobj)
endif ()
