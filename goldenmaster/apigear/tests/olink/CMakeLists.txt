cmake_minimum_required(VERSION 3.20)
project(test_olink)

set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)


if(BUILD_TESTING)
enable_testing()

Include(FetchContent)

find_package(Qt5 REQUIRED COMPONENTS Test Core Qml Network WebSockets)
find_package(apigear QUIET COMPONENTS olink_qt)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.8
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS)

FetchContent_Declare(
    trompeloeil
    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_TAG        8480eda8bcda5ac85ef18866047f485d7d2392f5
    )
FetchContent_MakeAvailable(Catch2 trompeloeil)

find_package(Catch2 REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set(TEST_OLINK_SOURCES
    olink_connection.test.cpp
    olinkhost.test.cpp
    private/messagestorage.cpp
    private/test_server/testserver.cpp
    test_main.cpp
    )


include_directories(test_olink
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(test_olink ${TEST_OLINK_SOURCES})

# do not automatically run this test on MacOS
# see https://github.com/apigear-io/template-qtcpp/issues/38
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
add_test(NAME test_olink COMMAND $<TARGET_FILE:test_olink>)
add_dependencies(check test_olink)
endif() # NOT Darwin

target_link_libraries(test_olink PRIVATE
    olink_qt
    Catch2::Catch2
    trompeloeil::trompeloeil
    Qt::Test)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)

install(TARGETS test_olink
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

endif() # BUILD_TESTING
