project(tb_simple_olink)

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

find_package(olink_core)
if(NOT olink_core_FOUND)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.1.4
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()

set (TB_SIMPLE_OLINK_SOURCES
    olinkfactory.cpp
    olinksimpleinterface.cpp
    olinksimpleinterfaceadapter.cpp
    olinksimplearrayinterface.cpp
    olinksimplearrayinterfaceadapter.cpp
)

# dynamic library
add_library(tb_simple_olink STATIC ${TB_SIMPLE_OLINK_SOURCES})
target_include_directories(tb_simple_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_simple>
)

target_link_libraries(tb_simple_olink PRIVATE olink_core Qt5::Core Qt5::Qml Qt5::WebSockets tb_simple::tb_simple_api PUBLIC nlohmann_json::nlohmann_json qtpromise)
