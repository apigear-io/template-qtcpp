cmake_minimum_required(VERSION 3.20)
project(tb_enum_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED Core )
find_package(nlohmann_json REQUIRED )

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_API_SOURCES
    api.cpp
)

# dynamic library

add_library(tb_enum_api SHARED ${TB_ENUM_API_SOURCES})
add_library(tb_enum::tb_enum_api ALIAS tb_enum_api)

target_include_directories(tb_enum_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_enum_api PUBLIC Qt6::Core nlohmann_json::nlohmann_json )

target_compile_definitions(tb_enum_api PRIVATE TB_ENUM_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_enum_api PRIVATE /bigobj)
endif ()
