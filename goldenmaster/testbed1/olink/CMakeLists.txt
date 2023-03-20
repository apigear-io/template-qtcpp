project(testbed1_olink)

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
    olinkfactory.cpp
    olinkstructinterface.cpp
    olinkstructinterfaceadapter.cpp
    olinkstructarrayinterface.cpp
    olinkstructarrayinterfaceadapter.cpp
)

add_library(testbed1_olink STATIC ${TESTBED1_OLINK_SOURCES})
target_include_directories(testbed1_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/testbed1>
)

target_link_libraries(testbed1_olink 
PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1::testbed1_api 
PUBLIC olink_qt nlohmann_json::nlohmann_json qtpromise)
