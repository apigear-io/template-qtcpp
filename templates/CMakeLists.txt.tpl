cmake_minimum_required(VERSION 3.14)

project({{.System.Name}} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Qt5 COMPONENTS Test REQUIRED)

enable_testing()

set(LIBRARY_PATH "${CMAKE_BINARY_DIR}/libs" CACHE STRING "Path where the libraries are deployed")
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")

include_directories(thirdparty)

add_subdirectory(thirdparty/jsonrpc)
add_subdirectory(thirdparty/nlohmann)
add_subdirectory(thirdparty/qtpromise)
add_subdirectory(thirdparty/objectlink)
{{- range .System.Modules }}
{{- $moduleId := snake .Name }}
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/{{ $moduleId }}/api" )
    add_subdirectory({{ $moduleId }}/api)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/{{ $moduleId }}/lib" )
    add_subdirectory({{ $moduleId }}/lib)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/{{ $moduleId }}/plugin" )
    add_subdirectory({{ $moduleId }}/plugin)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/{{ $moduleId }}/http" )
    add_subdirectory({{ $moduleId }}/http)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/{{ $moduleId }}/olink" )
    add_subdirectory({{ $moduleId }}/olink)
ENDIF()
{{- end }}

