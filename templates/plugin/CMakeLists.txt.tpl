{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_{{$SOURCES}}
    plugin.cpp
)

add_library(plugin_{{$module_id}} SHARED ${ {{- $SOURCES -}} })

set(OUTPUT_PATH ${IMPORTS_PATH}/{{$module_path}})

set_target_properties(plugin_{{$module_id}} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_{{$module_id}} PRIVATE Qt5::Core Qt5::Qml {{$module_id}}_lib {{$module_id}}_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
