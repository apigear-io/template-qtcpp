cmake_minimum_required(VERSION 3.20)
project(testbed1_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_IMPL_SOURCES
    factory.cpp
    structinterface.cpp
    structarrayinterface.cpp
)

# dynamic library
add_library(testbed1_impl SHARED ${TESTBED1_IMPL_SOURCES})
add_library(testbed1::testbed1_impl ALIAS testbed1_impl)

target_include_directories(testbed1_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed1_impl PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1::testbed1_api)
target_compile_definitions(testbed1_impl PRIVATE TESTBED1_IMPL_LIBRARY)

# add test targets

## test for StructInterface
#add_executable(test_testbed1_impl_structinterface
#    tst_structinterface.cpp
#)
#
#target_link_libraries(test_testbed1_impl_structinterface PRIVATE Qt5::Test testbed1::testbed1_impl)
#target_compile_definitions(test_testbed1_impl_structinterface PRIVATE TESTBED1_IMPL_LIBRARY)
#add_test(test_testbed1_impl_structinterface test_testbed1_impl_structinterface)
#

## test for StructArrayInterface
#add_executable(test_testbed1_impl_structarrayinterface
#    tst_structarrayinterface.cpp
#)
#
#target_link_libraries(test_testbed1_impl_structarrayinterface PRIVATE Qt5::Test testbed1::testbed1_impl)
#target_compile_definitions(test_testbed1_impl_structarrayinterface PRIVATE TESTBED1_IMPL_LIBRARY)
#add_test(test_testbed1_impl_structarrayinterface test_testbed1_impl_structarrayinterface)
#
