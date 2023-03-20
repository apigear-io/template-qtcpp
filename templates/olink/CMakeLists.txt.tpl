{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_olink" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_OLINK_SOURCES" $MODULE_ID -}}
project({{$lib_id}})

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

set ({{$MODULE_ID}}_OLINK_SOURCES
    olinkfactory.cpp
{{- range .Module.Interfaces }}
    olink{{lower .Name}}.cpp
    olink{{lower .Name}}adapter.cpp
{{- end }}
)

add_library({{$lib_id}} STATIC ${ {{- $SOURCES -}} })
target_include_directories({{$lib_id}}
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/{{$module_id}}>
)

target_link_libraries({{$lib_id}} 
PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets {{$module_id}}::{{$module_id}}_api 
PUBLIC olink_qt nlohmann_json::nlohmann_json qtpromise)
