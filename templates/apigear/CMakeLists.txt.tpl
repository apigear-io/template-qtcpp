cmake_minimum_required(VERSION 3.20)
project(apigear_with_tests)

set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(utilities)
{{- if  .Features.olink }}
add_subdirectory(olink)
{{- end}}
{{- if  .Features.monitor }}
add_subdirectory(monitor)
{{- end}}
{{- if  .Features.mqtt }}
add_subdirectory(mqtt)
{{- end}}

if(BUILD_TESTING)
enable_testing()
{{- if  .Features.olink }}
    add_subdirectory(tests/olink)
{{- end}}
endif() # BUILD_TESTING
