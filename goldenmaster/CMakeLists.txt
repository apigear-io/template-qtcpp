cmake_minimum_required(VERSION 3.14)

project(test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Test REQUIRED)

enable_testing()

set(LIBRARY_PATH "${CMAKE_BINARY_DIR}/libs" CACHE STRING "Path where the libraries are deployed")
set(IMPORTS_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "Path where the plugins are deployed")

include_directories(thirdparty)

add_subdirectory(thirdparty/jsonrpc)
add_subdirectory(thirdparty/nlohmann)
add_subdirectory(thirdparty/wamp)
add_subdirectory(thirdparty/qtpromise)
add_subdirectory(thirdparty/objectlink)
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/api" )
    add_subdirectory(org_objectapi_testbed/api)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/lib" )
    add_subdirectory(org_objectapi_testbed/lib)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/plugin" )
    add_subdirectory(org_objectapi_testbed/plugin)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/http" )
    add_subdirectory(org_objectapi_testbed/http)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/wamp" )
    add_subdirectory(org_objectapi_testbed/wamp)
ENDIF()
IF( IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/org_objectapi_testbed/olink" )
    add_subdirectory(org_objectapi_testbed/olink)
ENDIF()

