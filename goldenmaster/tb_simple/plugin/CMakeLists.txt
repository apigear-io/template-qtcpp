find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TB_SIMPLE_SOURCES
    plugin.cpp
)

add_library(plugin_tb_simple SHARED ${PLUGIN_TB_SIMPLE_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/tb/simple)

set_target_properties(plugin_tb_simple PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_tb_simple PRIVATE Qt5::Core Qt5::Qml tb_simple::tb_simple_lib tb_simple::tb_simple_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
