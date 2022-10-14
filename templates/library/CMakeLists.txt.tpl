{{- $module_id := printf "%s_lib" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_LIB" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$MODULE_ID}}_SOURCES
    factory.cpp
{{- range .Module.Interfaces }}
    {{.Name|lower}}.cpp
    qml{{.Name|lower}}.cpp
{{- end }}
)

# dynamic library
add_library({{$module_id}} STATIC ${ {{- $SOURCES -}} })
target_link_libraries({{$module_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets {{snake .Module.Name}}_api)
target_compile_definitions({{$module_id}} PRIVATE {{ $MODULE_ID }}_LIBRARY)

# add test targets
{{- range .Module.Interfaces }}
{{- $test_name := (lower .Name) }}

# test for {{.Name}}
add_executable(test_{{$module_id}}_{{$test_name}}
    tst_{{$test_name}}.cpp
)

target_link_libraries(test_{{$module_id}}_{{$test_name}} PRIVATE Qt5::Test {{$module_id}})
target_compile_definitions(test_{{$module_id}}_{{$test_name}} PRIVATE {{$MODULE_ID}}_LIBRARY)
add_test(test_{{$module_id}}_{{$test_name}} test_{{$module_id}}_{{$test_name}})
{{- end }}
