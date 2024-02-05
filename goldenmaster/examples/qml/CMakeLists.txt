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

find_package(Qt5 REQUIRED COMPONENTS Gui Quick QuickControls2 QuickWidgets)


find_package(testbed2 QUIET COMPONENTS testbed2_impl testbed2_olink plugin_testbed2 testbed2_monitor)
find_package(tb_enum QUIET COMPONENTS tb_enum_impl tb_enum_olink plugin_tb_enum tb_enum_monitor)
find_package(tb_same1 QUIET COMPONENTS tb_same1_impl tb_same1_olink plugin_tb_same1 tb_same1_monitor)
find_package(tb_same2 QUIET COMPONENTS tb_same2_impl tb_same2_olink plugin_tb_same2 tb_same2_monitor)
find_package(tb_simple QUIET COMPONENTS tb_simple_impl tb_simple_olink plugin_tb_simple tb_simple_monitor)
find_package(testbed1 QUIET COMPONENTS testbed1_impl testbed1_olink plugin_testbed1 testbed1_monitor)
find_package(tb_names QUIET COMPONENTS tb_names_impl tb_names_olink plugin_tb_names tb_names_monitor)
target_link_libraries(QmlExamlple
    testbed2_impl
    testbed2_olink
    plugin_testbed2
    testbed2_monitor
    tb_enum_impl
    tb_enum_olink
    plugin_tb_enum
    tb_enum_monitor
    tb_same1_impl
    tb_same1_olink
    plugin_tb_same1
    tb_same1_monitor
    tb_same2_impl
    tb_same2_olink
    plugin_tb_same2
    tb_same2_monitor
    tb_simple_impl
    tb_simple_olink
    plugin_tb_simple
    tb_simple_monitor
    testbed1_impl
    testbed1_olink
    plugin_testbed1
    testbed1_monitor
    tb_names_impl
    tb_names_olink
    plugin_tb_names
    tb_names_monitor
Qt5::Gui Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
)


install(TARGETS QmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
