project(QmlExamlple)
cmake_minimum_required(VERSION 3.1)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
    main.qml
    resources.qrc
)
add_executable(QmlExamlple
    ${SOURCES}
)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets Gui Quick QuickControls2 QuickWidgets)
find_package(apigear QUIET COMPONENTS olink_qt)

find_package(apigear QUIET COMPONENTS olink_core)
if(NOT olink_core_FOUND)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.2.2
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_lib testbed2_olink plugin_testbed2)
find_package(tb_enum QUIET COMPONENTS tb_enum_api tb_enum_lib tb_enum_olink plugin_tb_enum)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_lib tb_same1_olink plugin_tb_same1)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api tb_same2_lib tb_same2_olink plugin_tb_same2)
find_package(tb_simple QUIET COMPONENTS tb_simple_api tb_simple_lib tb_simple_olink plugin_tb_simple)
find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_lib testbed1_olink plugin_testbed1)
target_link_libraries(QmlExamlple
    testbed2_api
    testbed2_lib
    testbed2_olink
    plugin_testbed2
    tb_enum_api
    tb_enum_lib
    tb_enum_olink
    plugin_tb_enum
    tb_same1_api
    tb_same1_lib
    tb_same1_olink
    plugin_tb_same1
    tb_same2_api
    tb_same2_lib
    tb_same2_olink
    plugin_tb_same2
    tb_simple_api
    tb_simple_lib
    tb_simple_olink
    plugin_tb_simple
    testbed1_api
    testbed1_lib
    testbed1_olink
    plugin_testbed1
Qt5::Core Qt5::Qml Qt5::WebSockets Qt5::Gui Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
olink_qt
olink_core
)


install(TARGETS QmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
