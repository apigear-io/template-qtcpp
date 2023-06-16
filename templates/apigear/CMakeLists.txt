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
add_subdirectory(olink)
add_subdirectory(monitor)

if(BUILD_TESTING)
enable_testing()
    add_subdirectory(tests/olink)
endif() # BUILD_TESTING
