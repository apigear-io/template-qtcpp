{{- $features := .Features -}}

project(OLinkServer)
cmake_minimum_required(VERSION 3.20)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkServer
    ${SOURCES}
)

find_package(Qt6 REQUIRED COMPONENTS Gui)

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl {{$module_id}}_olink{{ if $features.monitor }} {{$module_id}}_monitor{{ end}})
{{- end }}
target_link_libraries(OLinkServer PUBLIC
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_impl
    {{$module_id}}_olink{{ if $features.monitor }}
    {{$module_id}}_monitor{{ end -}}
{{- end }}
Qt6::Gui)

install(TARGETS OLinkServer
        RUNTIME DESTINATION bin COMPONENT Runtime)
