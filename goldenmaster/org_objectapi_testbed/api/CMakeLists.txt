find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (ORG_OBJECTAPI_TESTBED_API_SOURCES
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
    ../../shared/agentclient.cpp
    ../../shared/simulationclient.cpp
)

# dynamic library

add_library(org_objectapi_testbed_api SHARED ${ORG_OBJECTAPI_TESTBED_API_SOURCES})
target_link_libraries(org_objectapi_testbed_api PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets jsonrpc_lib)
target_compile_definitions(org_objectapi_testbed_api PRIVATE ORG_OBJECTAPI_TESTBED_LIBRARY)
