{{- $module_id := printf "%s_http" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_HTTP" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$MODULE_ID}}_SOURCES
    httpfactory.cpp
{{- range .Module.Interfaces }}
    http{{lower .Name}}.cpp
{{- end }}}
)

# dynamic library

add_library({{$module_id}} STATIC { {{- $SOURCES -}} })
target_include_directories({{$module_id}} PRIVATE ../{{$module_id}})
target_link_libraries({{$module_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::Network {{$module_id}}_api)
