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

set (TB_SAME2_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinksamestruct1interface.cpp
    olinksamestruct1interfaceadapter.cpp
    olinksamestruct2interface.cpp
    olinksamestruct2interfaceadapter.cpp
    olinksameenum1interface.cpp
    olinksameenum1interfaceadapter.cpp
    olinksameenum2interface.cpp
    olinksameenum2interfaceadapter.cpp
)

# dynamic library
add_library(tb_same2_olink STATIC ${TB_SAME2_OLINK_SOURCES})
target_include_directories(tb_same2_olink PRIVATE ../tb_same2)
target_link_libraries(tb_same2_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_same2_api PUBLIC nlohmann_json::nlohmann_json olink_core qtpromise)
