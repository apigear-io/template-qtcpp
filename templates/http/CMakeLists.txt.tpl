{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_HTTP_SOURCES" $MODULE_ID -}}

cmake_minimum_required(VERSION 3.20)
project({{ $module_id }}_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$SOURCES}}
    httpfactory.cpp
{{- range .Module.Interfaces }}
    http{{lower .Name}}.cpp
{{- end }}
)

# dynamic library

add_library({{$module_id}}_http STATIC ${ {{- $SOURCES -}} })
target_include_directories({{$module_id}}_http PRIVATE ../{{$module_id}})
target_link_libraries({{$module_id}}_http PUBLIC apigear::utilities_qt Qt6::Network {{$module_id}}_api)
