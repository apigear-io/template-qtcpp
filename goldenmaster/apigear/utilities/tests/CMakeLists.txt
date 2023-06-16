cmake_minimum_required(VERSION 3.20)
project(test_apigear_utilities)

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

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.8
    GIT_SHALLOW    TRUE
    FIND_PACKAGE_ARGS)

FetchContent_MakeAvailable(Catch2)


set(CMAKE_CTEST_COMMAND ctest -V)
if(NOT TARGET check)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
endif()

set(TEST_APIGEAR_UTILITIES_SOURCES
    test_main.cpp
    logger.test.cpp
    )

add_executable(test_apigear_utilities ${TEST_APIGEAR_UTILITIES_SOURCES})

# do not automatically run this test on MacOS
# see https://github.com/apigear-io/template-qtcpp/issues/38
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
add_test(NAME test_apigear_utilities COMMAND $<TARGET_FILE:test_apigear_utilities>)
add_dependencies(check test_apigear_utilities)
endif() # NOT Darwin

target_link_libraries(test_apigear_utilities PRIVATE apigear::utilities_qt Catch2::Catch2 Qt::Test)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(Catch)

install(TARGETS test_apigear_utilities
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)


endif() # BUILD_TESTING
