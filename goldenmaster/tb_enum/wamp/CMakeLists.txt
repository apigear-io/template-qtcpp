find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampenuminterface.cpp
    wampenuminterfaceadapter.cpp
)

# dynamic library
add_library(tb_enum_wamp STATIC ${TB_ENUM_WAMP_SOURCES})
target_include_directories(tb_enum_wamp PRIVATE ../tb_enum)
target_link_libraries(tb_enum_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_enum_api wamp_lib qtpromise)
