{{- $module_id := printf "%s" (snake .Module.Name) }}
{{- $MODULE_ID := printf "%s" (SNAKE .Module.Name) }}
cmake_minimum_required(VERSION 3.20)
project(test_{{$module_id}}_generated_olink)

set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TESTING)
include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Test Core)
find_package(apigear QUIET COMPONENTS olink_qt)
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_impl {{$module_id}}_olink)

find_package(Catch2 REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set(TEST_{{$MODULE_ID}}_GENERATED_OLINK_SOURCES
{{- range .Module.Interfaces }}
    test_olink{{lower .Name}}.cpp
{{- end }}
    test_main.cpp
    )

include_directories(test_{{$module_id}}_generated_olink
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(test_{{$module_id}}_generated_olink ${TEST_{{$MODULE_ID}}_GENERATED_OLINK_SOURCES})
add_test(NAME test_{{$module_id}}_generated_olink COMMAND $<TARGET_FILE:test_{{$module_id}}_generated_olink>)
add_dependencies(check test_{{$module_id}}_generated_olink)

target_link_libraries(test_{{$module_id}}_generated_olink PRIVATE
    olink_qt
    {{$module_id}}_impl
    {{$module_id}}_olink
    Catch2::Catch2
    Qt::Test)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)

install(TARGETS test_{{$module_id}}_generated_olink
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

endif() # BUILD_TESTING
