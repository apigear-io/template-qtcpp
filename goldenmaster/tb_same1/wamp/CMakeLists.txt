find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME1_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampsamestruct1interface.cpp
    wampsamestruct1interfaceadapter.cpp
    wampsamestruct2interface.cpp
    wampsamestruct2interfaceadapter.cpp
    wampsameenum1interface.cpp
    wampsameenum1interfaceadapter.cpp
    wampsameenum2interface.cpp
    wampsameenum2interfaceadapter.cpp
)

# dynamic library
add_library(tb_same1_wamp STATIC ${TB_SAME1_WAMP_SOURCES})
target_include_directories(tb_same1_wamp PRIVATE ../tb_same1)
target_link_libraries(tb_same1_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_same1_api wamp_lib qtpromise)
