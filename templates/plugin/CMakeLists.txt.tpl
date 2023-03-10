{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "PLUGIN_%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_api )
{{- end }}

set ({{$SOURCES}}
    plugin.cpp
)

add_library(plugin_{{$module_id}} SHARED ${ {{- $SOURCES -}} })

set(OUTPUT_PATH ${IMPORTS_PATH}/{{$module_path}})

set_target_properties(plugin_{{$module_id}} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_{{$module_id}} PRIVATE Qt5::Core Qt5::Qml {{$module_id}}::{{$module_id}}_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)

target_compile_definitions(plugin_{{$module_id}} PRIVATE {{$MODULE_ID}}_PLUGIN_LIBRARY)
