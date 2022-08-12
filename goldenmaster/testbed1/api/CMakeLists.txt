find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_API_SOURCES
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
    ../../shared/agentclient.cpp
    ../../shared/simulationclient.cpp
)

# dynamic library

add_library(testbed1_api SHARED ${TESTBED1_API_SOURCES})
target_link_libraries(testbed1_api PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets jsonrpc_lib)
target_compile_definitions(testbed1_api PRIVATE TESTBED1_LIBRARY)
