{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_qml" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_QML" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}
{{- $features := .Features }}

cmake_minimum_required(VERSION 3.20)
project({{ $lib_id }} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Qml)

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

set ({{$SOURCES}}
    qml_api.cpp
    apifactory.cpp
{{- range .Module.Interfaces }}
    qml{{.Name|lower}}.cpp
{{- end }}
)

# dynamic library

add_library({{$lib_id}} SHARED ${ {{- $SOURCES -}} })
add_library({{$module_id}}::{{$lib_id}} ALIAS {{$lib_id}})

qt_add_qml_module({{$lib_id}}
    URI "{{$module_id}}"
    VERSION {{ .Module.Version.Major }}.{{ .Module.Version.Minor }}
)

target_include_directories({{$lib_id}}
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries({{$lib_id}} PUBLIC {{$module_id}}::{{$module_id}}_api PRIVATE Qt6::Qml )

target_compile_definitions({{$lib_id}} PRIVATE {{ $MODULE_ID }}_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options({{$lib_id}} PRIVATE /bigobj)
endif ()
