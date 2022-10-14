{{- $module_id := printf "%s_wamp" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_WAMP" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$MODULE_ID}}_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
{{- range .Module.Interfaces }}
    wamp{{lower .Name}}.cpp
    wamp{{lower .Name}}adapter.cpp
{{- end }}
)

# dynamic library
add_library({{$module_id}} STATIC ${ {{- $SOURCES -}} })
target_include_directories({{$module_id}} PRIVATE ../{{snake .Module.Name}})
target_link_libraries({{$module_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets {{snake .Module.Name}}_api wamp_lib qtpromise)
