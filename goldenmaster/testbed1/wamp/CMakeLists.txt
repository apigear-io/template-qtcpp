find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampstructinterface.cpp
    wampstructinterfaceadapter.cpp
    wampstructarrayinterface.cpp
    wampstructarrayinterfaceadapter.cpp
)

# dynamic library
add_library(testbed1_wamp STATIC ${TESTBED1_WAMP_SOURCES})
target_include_directories(testbed1_wamp PRIVATE ../testbed1)
target_link_libraries(testbed1_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1_api wamp_lib qtpromise)
