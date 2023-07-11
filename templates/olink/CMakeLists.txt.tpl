{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_olink" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_OLINK_SOURCES" $MODULE_ID -}}
project({{$lib_id}})

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set ({{$MODULE_ID}}_OLINK_SOURCES
    olinkfactory.cpp
{{- range .Module.Interfaces }}
    olink{{lower .Name}}.cpp
    olink{{lower .Name}}adapter.cpp
{{- end }}
)

add_library({{$lib_id}} STATIC ${ {{- $SOURCES -}} })
target_include_directories({{$lib_id}}
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)

target_link_libraries({{$lib_id}} PUBLIC {{$module_id}}::{{$module_id}}_api olink_qt Qt6::Concurrent qtpromise)
