cmake_minimum_required(VERSION 3.20)
project(simulation_qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

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

set (SOURCES
    simulationclient.cpp
)

FILE(GLOB_RECURSE INCLUDES *.h)

add_library(simulation_qt SHARED ${SOURCES})
add_library(apigear::simulation_qt ALIAS simulation_qt)

target_include_directories(simulation_qt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(simulation_qt PUBLIC nlohmann_json::nlohmann_json jsonrpc_core Qt5::Core Qt5::Qml Qt5::WebSockets)
target_compile_definitions(simulation_qt PRIVATE COMPILING_SIMULATION_QT)

# install binary files
install(TARGETS simulation_qt
        EXPORT  simulation_qtTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib           COMPONENT Development)
# install includes
install(FILES ${INCLUDES}
        DESTINATION include/apigear/simulation)

export(EXPORT simulation_qtTargets
  NAMESPACE apigear::
)
