{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $lib_id := printf "%s_api" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s_API" (SNAKE .Module.Name) }}
{{- $module_path := (path .Module.Name) }}
{{- $SOURCES := printf "%s_SOURCES" $MODULE_ID -}}
{{- $features := .Features -}}

cmake_minimum_required(VERSION 3.20)
project({{ $lib_id }} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(apigear QUIET COMPONENTS utilities_qt)

{{ $externs :=  .Module.Externs }}
{{- $listqtExterns := qtExterns .Module.Externs}}
{{- $listPackage := (collectFields $listqtExterns  "Package")}}
{{- $listPackage = (appendList $listPackage "Qt6") }}
{{- $listPackage = (appendList $listPackage "nlohmann_json") }}
{{- $listPackage = unique $listPackage }}
{{- $link_libraries_list := getEmptyStringList }}
{{- range $listPackage}}
{{- $package := . }}
{{- $components := getEmptyStringList }}
{{- range $listqtExterns }}
{{- if (eq .Package $package) }}
{{- $components = (appendList $components .Component) }}
{{- end }}
{{- end }}
{{- if (eq "Qt6" $package) }}
{{- $components = (appendList $components "Core") }}
{{- end}}
{{- $packageOnly := 0 }}
{{- if  (contains $components "" )}}
{{- $packageOnly = 1 }}
find_package({{$package}} REQUIRED )
{{- $link_libraries_list = (appendList $link_libraries_list $package) }}
{{- end }}
{{- $components = unique $components }}
{{- if not  (and (eq $packageOnly  1)  (eq (len $components)  1)) }}
find_package({{$package}} REQUIRED {{ range $components }}{{.}} {{ end}})
{{- end }}
{{- range $components }}
{{- $item:= printf "%s::%s"  $package .}}
{{- $link_libraries_list = (appendList $link_libraries_list $item) }}
{{- end}}
{{- end }}

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set ({{$SOURCES}}
    api.cpp
)

# dynamic library

add_library({{$lib_id}} SHARED ${ {{- $SOURCES -}} })
add_library({{$module_id}}::{{$lib_id}} ALIAS {{$lib_id}})

target_include_directories({{$lib_id}}
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

{{- $link_libraries_list = (appendList $link_libraries_list "nlohmann_json::nlohmann_json") }}

target_link_libraries({{$lib_id}} PUBLIC apigear::utilities_qt {{ range .Module.Imports }}{{snake .Name}}_api {{ end }}{{ range $link_libraries_list }}{{.}} {{ end }})

target_compile_definitions({{$lib_id}} PRIVATE {{ $MODULE_ID }}_LIBRARY)

# some module files can potentially lead to too big object files
# therefore we enable the necessary compiler flags to support them
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options({{$lib_id}} PRIVATE /bigobj)
endif ()
