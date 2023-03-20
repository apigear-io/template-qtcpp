project(tb_enum_olink)

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

set (TB_ENUM_OLINK_SOURCES
    olinkfactory.cpp
    olinkenuminterface.cpp
    olinkenuminterfaceadapter.cpp
)

add_library(tb_enum_olink STATIC ${TB_ENUM_OLINK_SOURCES})
target_include_directories(tb_enum_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_enum>
)

target_link_libraries(tb_enum_olink 
PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_enum::tb_enum_api 
PUBLIC olink_qt nlohmann_json::nlohmann_json qtpromise)
