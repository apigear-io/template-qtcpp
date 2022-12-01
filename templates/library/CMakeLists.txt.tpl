{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_lib" (snake .Module.Name) }}
{{- $LIB_ID := printf "%s_LIB" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $LIB_ID -}}

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$LIB_ID}}_SOURCES
    factory.cpp
{{- range .Module.Interfaces }}
    {{.Name|lower}}.cpp
    qml{{.Name|lower}}.cpp
{{- end }}
)

# dynamic library
add_library({{$lib_id}} STATIC ${ {{- $SOURCES -}} })
add_library({{$module_id}}::{{$lib_id}} ALIAS {{$lib_id}})

target_include_directories({{$lib_id}}
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries({{$lib_id}} PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets {{$module_id}}::{{snake .Module.Name}}_api)
target_compile_definitions({{$lib_id}} PRIVATE {{ $LIB_ID }}_LIBRARY)

# add test targets
{{- range .Module.Interfaces }}
{{- $test_name := (lower .Name) }}

# test for {{.Name}}
add_executable(test_{{$lib_id}}_{{$test_name}}
    tst_{{$test_name}}.cpp
)

target_link_libraries(test_{{$lib_id}}_{{$test_name}} PRIVATE Qt5::Test {{$module_id}}::{{$lib_id}})
target_compile_definitions(test_{{$lib_id}}_{{$test_name}} PRIVATE {{$LIB_ID}}_LIBRARY)
add_test(test_{{$lib_id}}_{{$test_name}} test_{{$lib_id}}_{{$test_name}})
{{- end }}
