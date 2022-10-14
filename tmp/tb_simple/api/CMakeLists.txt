find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_API_SOURCES
    api.cpp
    apifactory.cpp
    simu.cpp
    agent.cpp
    ../../shared/agentclient.cpp
    ../../shared/simulationclient.cpp
)

# dynamic library

add_library(tb_simple_api SHARED ${TB_SIMPLE_API_SOURCES})
target_link_libraries(tb_simple_api PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets jsonrpc_lib)
target_compile_definitions(tb_simple_api PRIVATE TB_SIMPLE_LIBRARY)
