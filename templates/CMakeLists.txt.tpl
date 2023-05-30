{{- $features := .Features -}}

cmake_minimum_required(VERSION 3.20)

project({{.System.Name}} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(JSON_BuildTests OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# on Windows it is helpful to have all binary files next to each other
# it is intentionally not set as part of BUILD_TESTING to have a consistent behavior
# this can be removed once there is a better option than modifying the PATH env for unit testing
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_TESTING "Enable this option to build the test targets" OFF)

if(BUILD_TESTING)
find_package(Qt5 COMPONENTS Test REQUIRED)
enable_testing()
endif() # BUILD_TESTING

set(LIBRARY_PATH "${CMAKE_BINARY_DIR}/libs" CACHE STRING "Path where the libraries are deployed")
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")

include_directories(thirdparty)
{{- if $features.apigear }}
add_subdirectory(apigear)
{{- end}}
add_subdirectory(thirdparty/qtpromise)
{{- range .System.Modules }}
{{- $moduleId := snake .Name }}
add_subdirectory({{ $moduleId }}/api)
{{- if $features.stubs }}
add_subdirectory({{ $moduleId }}/implementation)
{{- end}}
{{- if $features.qmlplugin }}
add_subdirectory({{ $moduleId }}/plugin)
{{- end}}
{{- if $features.http }}
add_subdirectory({{ $moduleId }}/http)
{{- end}}
{{- if $features.olink }}
add_subdirectory({{ $moduleId }}/olink)
{{- end}}
{{- if $features.monitor }}
add_subdirectory({{ $moduleId }}/monitor)
{{- end}}
{{- end }}
{{- if $features.examples }}
add_subdirectory(examples/olinkserver)
add_subdirectory(examples/olinkclient)
add_subdirectory(examples/qml)
{{- end }}
