{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_impl" (snake .Module.Name) }}
{{- $LIB_ID := printf "%s_IMPL" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $LIB_ID -}}

cmake_minimum_required(VERSION 3.20)
project({{ $lib_id }} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(Qt5 REQUIRED COMPONENTS Core)

set ({{$LIB_ID}}_SOURCES
    factory.cpp
{{- range .Module.Interfaces }}
    {{.Name|lower}}.cpp
{{- end }}
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

target_link_libraries({{$lib_id}} PUBLIC {{$module_id}}::{{snake .Module.Name}}_api)
target_compile_definitions({{$lib_id}} PRIVATE {{ $LIB_ID }}_LIBRARY)

add_subdirectory(tests)
