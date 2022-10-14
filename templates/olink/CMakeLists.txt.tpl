{{- $module_id := printf "%olink" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_OLINK" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set ({{$MODULE_ID}}_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
{{- range .Module.Interfaces }}
    olink{{lower .Name}}.cpp
    olink{{lower .Name}}adapter.cpp
{{- end }}
)

# dynamic library
add_library({{$module_id}} STATIC ${ {{- $SOURCES -}} })
target_include_directories({{$module_id}} PRIVATE ../{{$module_id}})
target_link_libraries({{$module_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets {{$module_id}}_api INTERFACE olink_core PUBLIC qtpromise)
