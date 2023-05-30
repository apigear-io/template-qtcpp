{{- $module_id := snake .Module.Name }}
{{- $project_name_id := printf "%s_tests" (snake .Module.Name) }}
cmake_minimum_required(VERSION 3.20)
project({{$project_name_id}})

include(CTest)

if(BUILD_TESTING)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Test)
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})


{{- range .Module.Interfaces }}
add_executable(test_{{$module_id}}_{{.Name|lower}} test_{{.Name|lower}}.cpp)
{{- end }}



{{- range .Module.Interfaces }}
target_link_libraries(test_{{$module_id}}_{{.Name|lower}} {{$module_id}}_impl Qt5::Test)
{{- end }}

{{- range .Module.Interfaces }}
add_test(NAME test_{{$module_id}}_{{.Name|lower}} COMMAND $<TARGET_FILE:test_{{$module_id}}_{{.Name|lower}}>)
add_dependencies(check test_{{$module_id}}_{{.Name|lower}})
{{- end }}

endif() # BUILD_TESTING
