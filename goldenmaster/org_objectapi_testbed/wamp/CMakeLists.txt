find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (ORG_OBJECTAPI_TESTBED_WAMP_SOURCES
    ../../shared/wampclient.cpp
    wampfactory.cpp
    wampinterface1.cpp
    wampinterface1adapter.cpp
    wampinterface2.cpp
    wampinterface2adapter.cpp
)

# dynamic library
add_library(org_objectapi_testbed_wamp STATIC ${ORG_OBJECTAPI_TESTBED_WAMP_SOURCES})
target_include_directories(org_objectapi_testbed_wamp PRIVATE ../org_objectapi_testbed)
target_link_libraries(org_objectapi_testbed_wamp PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets org_objectapi_testbed_api wamp_lib qtpromise)
