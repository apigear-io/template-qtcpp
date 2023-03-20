{{- $features := .Features -}}
project(QmlExamlple)
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

add_executable(QmlExamlple
    ${SOURCES}
)

find_package(Qt5 REQUIRED COMPONENTS Gui Quick QuickControls2 QuickWidgets)

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl {{$module_id}}_olink plugin_{{$module_id}}{{ if $features.monitor }} {{$module_id}}_monitor{{ end}})
{{- end }}
target_link_libraries(QmlExamlple
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_impl
    {{$module_id}}_olink
    plugin_{{$module_id}}{{ if $features.monitor }}
    {{$module_id}}_monitor{{ end -}}
{{- end }}
Qt5::Gui Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
{{- if $features.monitor }}
monitor_qt
{{- end}}
)


install(TARGETS QmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
