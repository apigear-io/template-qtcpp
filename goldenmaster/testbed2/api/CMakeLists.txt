find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
find_package(apigear QUIET COMPONENTS monitor_qt simulation_qt)
find_package(monitor_qt)
find_package(simulation_qt)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

find_package(jsonrpc_core QUIET)
if(NOT jsonrpc_core)
  message(STATUS "jsonrpc_core NOT FOUND, fetching the release package")
  set(JSONRPC_Install ON)
    FetchContent_Declare(jsonrpc_core
      GIT_REPOSITORY https://github.com/apigear-io/jsonrpc-core-cpp.git
      GIT_TAG v0.1.1
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(jsonrpc_core)
endif()

set (TESTBED2_API_SOURCES
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
)

# dynamic library

add_library(testbed2_api SHARED ${TESTBED2_API_SOURCES})
add_library(testbed2::testbed2_api ALIAS testbed2_api)

target_include_directories(testbed2_api
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed2_api PRIVATE  Qt5::Core Qt5::Qml Qt5::WebSockets jsonrpc_core nlohmann_json::nlohmann_json monitor_qt simulation_qt)
target_compile_definitions(testbed2_api PRIVATE TESTBED2_LIBRARY)
