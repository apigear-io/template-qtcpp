{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_api" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}
{{- $features := .Features -}}

cmake_minimum_required(VERSION 3.20)
project({{ $lib_id }} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$SOURCES}}
    api.cpp
)

# dynamic library

add_library({{$lib_id}} SHARED ${ {{- $SOURCES -}} })
add_library({{$module_id}}::{{$lib_id}} ALIAS {{$lib_id}})

target_include_directories({{$lib_id}}
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries({{$lib_id}} PUBLIC nlohmann_json::nlohmann_json Qt6::Core)

target_compile_definitions({{$lib_id}} PRIVATE {{ $MODULE_ID }}_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options({{$lib_id}} PRIVATE /bigobj)
endif ()
