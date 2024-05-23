{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_mqtt" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_MQTT" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

cmake_minimum_required(VERSION 3.20)
project({{$lib_id}})


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(apigear QUIET COMPONENTS apigear_mqtt utilities)
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_api )
find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set ({{$SOURCES}}
    mqttfactory.cpp
{{- range .Module.Interfaces }}
    mqtt{{lower .Name}}.cpp
    mqtt{{lower .Name}}adapter.cpp
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
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)

target_link_libraries({{$lib_id}} PUBLIC {{$module_id}}::{{$module_id}}_api apigear::apigear_mqtt Qt6::Concurrent)
target_compile_definitions({{$lib_id}} PRIVATE {{$MODULE_ID}}_LIBRARY)


