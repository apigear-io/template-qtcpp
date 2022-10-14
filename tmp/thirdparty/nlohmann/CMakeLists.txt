
set (NLOHMANN_SOURCES
    json.hpp
)

add_library(nlohmann_lib STATIC ${NLOHMANN_SOURCES})

set(OUTPUT_PATH ${IMPORTS_PATH}/libs)

set_target_properties(nlohmann_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
)
