{{- $module_id := printf "%s_api" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}
find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$SOURCES}}
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
    ../../shared/agentclient.cpp
    ../../shared/simulationclient.cpp
)

# dynamic library

add_library({{$module_id}} SHARED ${ {{- $SOURCES -}} })
target_link_libraries({{$module_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets jsonrpc_lib)
target_compile_definitions({{$module_id}} PRIVATE {{ SNAKE .Module.Name }}_LIBRARY)
