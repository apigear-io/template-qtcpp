find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TESTBED2_SOURCES
    plugin.cpp
)

add_library(plugin_testbed2 SHARED ${PLUGIN_TESTBED2_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/testbed2)

set_target_properties(plugin_testbed2 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_testbed2 PRIVATE Qt5::Core Qt5::Qml testbed2_lib testbed2_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
