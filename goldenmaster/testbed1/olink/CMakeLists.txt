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

set (TESTBED1_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinkstructinterface.cpp
    olinkstructinterfaceadapter.cpp
    olinkstructarrayinterface.cpp
    olinkstructarrayinterfaceadapter.cpp
)

# dynamic library
add_library(testbed1_olink STATIC ${TESTBED1_OLINK_SOURCES})
target_include_directories(testbed1_olink PRIVATE ../testbed1)
target_link_libraries(testbed1_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1_api PUBLIC nlohmann_json::nlohmann_json olink_core qtpromise)
