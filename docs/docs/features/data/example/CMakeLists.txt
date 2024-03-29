project(QmlExamlple)
cmake_minimum_required(VERSION 3.20)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
    main.qml
    resources.qrc
)

set(QML_IMPORT_PATH  "${CMAKE_BINARY_DIR}/imports" CACHE STRING "" FORCE)
set(QML2_IMPORT_PATH "${CMAKE_BINARY_DIR}/imports" CACHE STRING "" FORCE)

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
      GIT_TAG v0.2.4
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()


find_package(io_world QUIET COMPONENTS io_world_api io_world_impl io_world_olink plugin_io_world io_world_monitor)
target_link_libraries(QmlExamlple
    io_world_api
    io_world_impl
    io_world_olink
    plugin_io_world
    io_world_monitor
Qt5::Core Qt5::Qml Qt5::WebSockets Qt5::Gui Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
olink_qt
olink_core
)


install(TARGETS QmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
