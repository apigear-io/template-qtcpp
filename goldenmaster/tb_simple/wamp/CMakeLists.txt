find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampsimpleinterface.cpp
    wampsimpleinterfaceadapter.cpp
    wampsimplearrayinterface.cpp
    wampsimplearrayinterfaceadapter.cpp
)

# dynamic library
add_library(tb_simple_wamp STATIC ${TB_SIMPLE_WAMP_SOURCES})
target_include_directories(tb_simple_wamp PRIVATE ../tb_simple)
target_link_libraries(tb_simple_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_simple_api wamp_lib qtpromise)
