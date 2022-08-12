find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)

set (PLUGIN_TB_ENUM_SOURCES
    plugin.cpp
)

add_library(plugin_tb_enum SHARED ${PLUGIN_TB_ENUM_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/tb/enum)

set_target_properties(plugin_tb_enum PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)

target_link_libraries(plugin_tb_enum PRIVATE Qt5::Core Qt5::Qml tb_enum_lib tb_enum_api)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${OUTPUT_PATH}/qmldir COPYONLY)
