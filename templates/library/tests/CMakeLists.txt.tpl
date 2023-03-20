{{- $module_id := snake .Module.Name }}
{{- $project_name_id := printf "%s_tests" (snake .Module.Name) }}
project({{$project_name_id}})
cmake_minimum_required(VERSION 3.20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})


{{- range .Module.Interfaces }}
add_executable(test_{{$module_id}}_{{.Name|lower}} test_{{.Name|lower}}.cpp)
{{- end }}


find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl )

{{- range .Module.Interfaces }}
target_link_libraries(test_{{$module_id}}_{{.Name|lower}} {{$module_id}}_impl Qt5::Test)
{{- end }}
