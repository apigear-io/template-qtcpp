find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampmanyparaminterface.cpp
    wampmanyparaminterfaceadapter.cpp
    wampnestedstruct1interface.cpp
    wampnestedstruct1interfaceadapter.cpp
    wampnestedstruct2interface.cpp
    wampnestedstruct2interfaceadapter.cpp
    wampnestedstruct3interface.cpp
    wampnestedstruct3interfaceadapter.cpp
)

# dynamic library
add_library(testbed2_wamp STATIC ${TESTBED2_WAMP_SOURCES})
target_include_directories(testbed2_wamp PRIVATE ../testbed2)
target_link_libraries(testbed2_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed2_api wamp_lib qtpromise)
