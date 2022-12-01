project(OLinkClient)
cmake_minimum_required(VERSION 3.1)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets Gui)
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

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkClient
    ${SOURCES}
)


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_lib testbed2_olink)
find_package(tb_enum QUIET COMPONENTS tb_enum_api tb_enum_lib tb_enum_olink)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_lib tb_same1_olink)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api tb_same2_lib tb_same2_olink)
find_package(tb_simple QUIET COMPONENTS tb_simple_api tb_simple_lib tb_simple_olink)
find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_lib testbed1_olink)
target_link_libraries(OLinkClient
    testbed2_api
    testbed2_lib
    testbed2_olink
    tb_enum_api
    tb_enum_lib
    tb_enum_olink
    tb_same1_api
    tb_same1_lib
    tb_same1_olink
    tb_same2_api
    tb_same2_lib
    tb_same2_olink
    tb_simple_api
    tb_simple_lib
    tb_simple_olink
    testbed1_api
    testbed1_lib
    testbed1_olink
Qt5::Core Qt5::Qml Qt5::WebSockets Qt5::Gui
olink_qt
olink_core
)
install(TARGETS OLinkClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
