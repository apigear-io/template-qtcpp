project(OLinkServer)
cmake_minimum_required(VERSION 3.20)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkServer
    ${SOURCES}
)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets Gui)
find_package(apigear QUIET COMPONENTS olink_qt)

find_package(apigear QUIET COMPONENTS olink_core)
if(NOT olink_core_FOUND)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.2.4
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_impl testbed2_olink testbed2_monitor)
find_package(tb_enum QUIET COMPONENTS tb_enum_api tb_enum_impl tb_enum_olink tb_enum_monitor)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_impl tb_same1_olink tb_same1_monitor)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api tb_same2_impl tb_same2_olink tb_same2_monitor)
find_package(tb_simple QUIET COMPONENTS tb_simple_api tb_simple_impl tb_simple_olink tb_simple_monitor)
find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_impl testbed1_olink testbed1_monitor)
target_link_libraries(OLinkServer
    testbed2_api
    testbed2_impl
    testbed2_olink
    testbed2_monitor
    tb_enum_api
    tb_enum_impl
    tb_enum_olink
    tb_enum_monitor
    tb_same1_api
    tb_same1_impl
    tb_same1_olink
    tb_same1_monitor
    tb_same2_api
    tb_same2_impl
    tb_same2_olink
    tb_same2_monitor
    tb_simple_api
    tb_simple_impl
    tb_simple_olink
    tb_simple_monitor
    testbed1_api
    testbed1_impl
    testbed1_olink
    testbed1_monitor
Qt5::Core Qt5::Qml Qt5::WebSockets Qt5::Gui
olink_qt
olink_core
)


install(TARGETS OLinkServer
        RUNTIME DESTINATION bin COMPONENT Runtime)
