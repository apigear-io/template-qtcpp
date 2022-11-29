find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
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
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(jsonrpc_core)
endif()

set (TB_SAME2_API_SOURCES
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
    ../../shared/agentclient.cpp
    ../../shared/simulationclient.cpp
)

# dynamic library

add_library(tb_same2_api SHARED ${TB_SAME2_API_SOURCES})
target_link_libraries(tb_same2_api PUBLIC nlohmann_json::nlohmann_json jsonrpc_core PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets)
target_compile_definitions(tb_same2_api PRIVATE TB_SAME2_LIBRARY)
