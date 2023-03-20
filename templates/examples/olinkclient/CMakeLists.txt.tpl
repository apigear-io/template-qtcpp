{{- $features := .Features -}}

project(OLinkClient)
cmake_minimum_required(VERSION 3.20)

find_package(Qt5 REQUIRED COMPONENTS Gui)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkClient
    ${SOURCES}
)

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_api {{$module_id}}_impl {{$module_id}}_olink{{ if $features.monitor }} {{$module_id}}_monitor{{ end}})
{{- end }}
target_link_libraries(OLinkClient
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_api
    {{$module_id}}_impl
    {{$module_id}}_olink{{ if $features.monitor }}
    {{$module_id}}_monitor{{ end -}}
{{- end }}
Qt5::Gui
)
install(TARGETS OLinkClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
