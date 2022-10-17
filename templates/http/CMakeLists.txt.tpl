{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_HTTP_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
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
target_link_libraries({{$module_id}}_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network {{$module_id}}_api)
