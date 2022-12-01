find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TB_SAME2_SOURCES
    plugin.cpp
)

add_library(plugin_tb_same2 SHARED ${PLUGIN_TB_SAME2_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/tb/same2)

set_target_properties(plugin_tb_same2 PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_tb_same2 PRIVATE Qt5::Core Qt5::Qml tb_same2::tb_same2_lib tb_same2::tb_same2_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
