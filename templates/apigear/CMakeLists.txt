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

IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/olink" )
    add_subdirectory(olink)
ENDIF()
add_subdirectory(monitor)
add_subdirectory(simulation)

if(BUILD_TESTING)
enable_testing()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tests/olink" )
    add_subdirectory(tests/olink)
ENDIF()
endif() # BUILD_TESTING
