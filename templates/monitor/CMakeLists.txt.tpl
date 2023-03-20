{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_monitor" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_MONITOR" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}
cmake_minimum_required(VERSION 3.20)
project({{$lib_id}})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS monitor_qt )

set ({{$SOURCES}}
    tracedapifactory.cpp
    agent.cpp
{{- range .Module.Interfaces }}
    {{lower .Name}}traced.cpp
{{- end }}
)

add_library({{$lib_id}} SHARED ${ {{- $SOURCES -}} })
target_include_directories({{$lib_id}}
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)

target_link_libraries({{$lib_id}} PRIVATE {{$module_id}}::{{$module_id}}_api apigear::monitor_qt)
target_compile_definitions({{$lib_id}} PRIVATE {{ $MODULE_ID }}_LIBRARY)
