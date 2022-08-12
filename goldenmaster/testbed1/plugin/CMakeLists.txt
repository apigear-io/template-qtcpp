find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TESTBED1_SOURCES
    plugin.cpp
)

add_library(plugin_testbed1 SHARED ${PLUGIN_TESTBED1_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/testbed1)

set_target_properties(plugin_testbed1 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_testbed1 PRIVATE Qt5::Core Qt5::Qml testbed1_lib testbed1_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
