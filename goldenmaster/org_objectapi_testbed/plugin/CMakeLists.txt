find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_ORG_OBJECTAPI_TESTBED_SOURCES
    plugin.cpp
)

add_library(plugin_org_objectapi_testbed SHARED ${PLUGIN_ORG_OBJECTAPI_TESTBED_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/org/objectapi/testbed)

set_target_properties(plugin_org_objectapi_testbed PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_org_objectapi_testbed PRIVATE Qt5::Core Qt5::Qml org_objectapi_testbed_lib org_objectapi_testbed_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
