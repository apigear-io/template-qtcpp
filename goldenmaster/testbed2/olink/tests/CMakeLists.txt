
cmake_minimum_required(VERSION 3.20)
project(test_testbed2_generated_olink)

set(SPDLOG_DEBUG_ON true)
set(SPDLOG_TRACE_ON true)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TESTING)
include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Test Core)
find_package(apigear QUIET COMPONENTS olink_qt)
find_package(testbed2 QUIET COMPONENTS testbed2_impl testbed2_olink)

find_package(Catch2 REQUIRED)

set(CMAKE_CTEST_COMMAND ctest -V)
if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set(TEST_TESTBED2_GENERATED_OLINK_SOURCES
    test_olinkmanyparaminterface.cpp
    test_olinknestedstruct1interface.cpp
    test_olinknestedstruct2interface.cpp
    test_olinknestedstruct3interface.cpp
    test_main.cpp
    )

include_directories(test_testbed2_generated_olink
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(test_testbed2_generated_olink ${TEST_TESTBED2_GENERATED_OLINK_SOURCES})
add_test(NAME test_testbed2_generated_olink COMMAND $<TARGET_FILE:test_testbed2_generated_olink>)
add_dependencies(check test_testbed2_generated_olink)

target_link_libraries(test_testbed2_generated_olink PRIVATE
    olink_qt
    testbed2_impl
    testbed2_olink
    Catch2::Catch2
    Qt::Test)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)

install(TARGETS test_testbed2_generated_olink
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

endif() # BUILD_TESTING
