{{- $features := .Features -}}

project(MqttClient)
cmake_minimum_required(VERSION 3.20)

find_package(Qt6 REQUIRED COMPONENTS Gui)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(MqttClient
    ${SOURCES}
)

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_api {{$module_id}}_impl {{$module_id}}_mqtt{{ if $features.monitor }} {{$module_id}}_monitor{{ end}})
{{- end }}
target_link_libraries(MqttClient PUBLIC
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_api
    {{$module_id}}_impl
    {{$module_id}}_mqtt{{ if $features.monitor }}
    {{$module_id}}_monitor{{ end -}}
{{- end }}
Qt6::Gui
)
install(TARGETS MqttClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
