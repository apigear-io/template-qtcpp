set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)

Include(FetchContent)

# pull catch2 as dependency
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

set(TEST_OLINK_SOURCES
    test_main.cpp
    test_olink.cpp
    test_protocol.cpp
    sinkobject.hpp
    sourceobject.hpp
    mocksink.hpp
    mocksource.hpp
)

add_executable(tst_olink ${TEST_OLINK_SOURCES})
target_link_libraries(tst_olink PRIVATE olink_core Catch2::Catch2)

