{{- $features := .Features -}}
project(MqttQmlExamlple)
cmake_minimum_required(VERSION 3.20)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
    main.qml
    resources.qrc
)

set(QML_IMPORT_PATH  "${CMAKE_BINARY_DIR}/imports" CACHE STRING "" FORCE)
set(QML2_IMPORT_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "" FORCE)

add_executable(MqttQmlExamlple
    ${SOURCES}
)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Gui Quick QuickControls2 QuickWidgets)

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl {{$module_id}}_mqtt {{ if $features.monitor }} {{$module_id}}_monitor{{ end}})
{{- end }}
target_link_libraries(MqttQmlExamlple PUBLIC
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_impl
    {{$module_id}}_qml
    {{$module_id}}_mqtt {{ if $features.monitor }}
    {{$module_id}}_monitor{{ end -}}
{{- end }}
PRIVATE Qt6::Qml Qt6::Gui Qt6::Quick Qt6::QuickControls2 Qt6::QuickWidgets
)


install(TARGETS MqttQmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
