find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (TB_SIMPLE_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinksimpleinterface.cpp
    olinksimpleinterfaceadapter.cpp
    olinksimplearrayinterface.cpp
    olinksimplearrayinterfaceadapter.cpp
)

# dynamic library
add_library(tb_simple_olink STATIC ${TB_SIMPLE_OLINK_SOURCES})
target_include_directories(tb_simple_olink PRIVATE ../tb_simple)
target_link_libraries(tb_simple_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_simple_api INTERFACE olink_core PUBLIC qtpromise)
