set (WAMP_SOURCES
    listeners.cpp
    messages.cpp
    protocol.cpp
    session.cpp
    types.cpp
)
set(OUTPUT_PATH ${IMPORTS_PATH}/libs)

# dynamic library
add_library(wamp_lib STATIC ${WAMP_SOURCES})
target_link_libraries(wamp_lib PRIVATE)
set_target_properties(wamp_lib PROPERTIES
LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)
