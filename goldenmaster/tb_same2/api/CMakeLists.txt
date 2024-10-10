cmake_minimum_required(VERSION 3.20)
project(tb_same2_api LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS utilities_qt)


find_package(Qt6 REQUIRED Core )
find_package(nlohmann_json REQUIRED )

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME2_API_SOURCES
    api.cpp
    test_struct_helper.cpp
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

target_link_libraries(tb_same2_api PUBLIC apigear::utilities_qt Qt6::Core nlohmann_json::nlohmann_json )

target_compile_definitions(tb_same2_api PRIVATE TB_SAME2_API_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(tb_same2_api PRIVATE /bigobj)
endif ()
