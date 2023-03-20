project(tb_enum_olink)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (TB_ENUM_OLINK_SOURCES
    olinkfactory.cpp
    olinkenuminterface.cpp
    olinkenuminterfaceadapter.cpp
)

add_library(tb_enum_olink STATIC ${TB_ENUM_OLINK_SOURCES})
target_include_directories(tb_enum_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_enum>
)

target_link_libraries(tb_enum_olink 
PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_enum::tb_enum_api 
PUBLIC olink_qt qtpromise)
