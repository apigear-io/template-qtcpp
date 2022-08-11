set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)

# pull nlohmann json as dependency
include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.9.1)

FetchContent_MakeAvailable(json)

set(OLINK_SOURCES
    olink/core/types.cpp
    olink/core/node.cpp
    olink/core/protocol.cpp
    olink/consolelogger.cpp
    olink/clientnode.cpp
    olink/remotenode.cpp
)

SET(OLINK_HEADERS
    olink/core/types.h
    olink/core/node.h
    olink/core/protocol.h
    olink/consolelogger.h
    olink/clientnode.h
    olink/remotenode.h
)


add_library (olink_core STATIC ${OLINK_SOURCES} ${OLINK_HEADERS})

target_include_directories (olink_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(olink_core PUBLIC nlohmann_json::nlohmann_json)
