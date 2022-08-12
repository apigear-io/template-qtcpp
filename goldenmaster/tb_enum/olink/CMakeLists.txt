find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (TB_ENUM_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinkenuminterface.cpp
    olinkenuminterfaceadapter.cpp
)

# dynamic library
add_library(tb_enum_olink STATIC ${TB_ENUM_OLINK_SOURCES})
target_include_directories(tb_enum_olink PRIVATE ../tb_enum)
target_link_libraries(tb_enum_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_enum_api INTERFACE olink_core PUBLIC qtpromise)
