
set (JSONRPC_SOURCES
    jsonrpc.cpp
    rpcprotocol.cpp
    types.cpp
)

add_library(jsonrpc_lib STATIC ${JSONRPC_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/libs)

set_target_properties(jsonrpc_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)