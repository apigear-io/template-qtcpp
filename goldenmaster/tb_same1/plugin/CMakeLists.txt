find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TB_SAME1_SOURCES
    plugin.cpp
)

add_library(plugin_tb_same1 SHARED ${PLUGIN_TB_SAME1_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/tb/same1)

set_target_properties(plugin_tb_same1 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_tb_same1 PRIVATE Qt5::Core Qt5::Qml tb_same1_lib tb_same1_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
