cmake_minimum_required(VERSION 3.20)
project(testbed2_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_IMPL_SOURCES
    factory.cpp
    manyparaminterface.cpp
    nestedstruct1interface.cpp
    nestedstruct2interface.cpp
    nestedstruct3interface.cpp
)

# dynamic library
add_library(testbed2_impl SHARED ${TESTBED2_IMPL_SOURCES})
add_library(testbed2::testbed2_impl ALIAS testbed2_impl)

target_include_directories(testbed2_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed2_impl PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed2::testbed2_api)
target_compile_definitions(testbed2_impl PRIVATE TESTBED2_IMPL_LIBRARY)

# add test targets

## test for ManyParamInterface
#add_executable(test_testbed2_impl_manyparaminterface
#    tst_manyparaminterface.cpp
#)
#
#target_link_libraries(test_testbed2_impl_manyparaminterface PRIVATE Qt5::Test testbed2::testbed2_impl)
#target_compile_definitions(test_testbed2_impl_manyparaminterface PRIVATE TESTBED2_IMPL_LIBRARY)
#add_test(test_testbed2_impl_manyparaminterface test_testbed2_impl_manyparaminterface)
#

## test for NestedStruct1Interface
#add_executable(test_testbed2_impl_nestedstruct1interface
#    tst_nestedstruct1interface.cpp
#)
#
#target_link_libraries(test_testbed2_impl_nestedstruct1interface PRIVATE Qt5::Test testbed2::testbed2_impl)
#target_compile_definitions(test_testbed2_impl_nestedstruct1interface PRIVATE TESTBED2_IMPL_LIBRARY)
#add_test(test_testbed2_impl_nestedstruct1interface test_testbed2_impl_nestedstruct1interface)
#

## test for NestedStruct2Interface
#add_executable(test_testbed2_impl_nestedstruct2interface
#    tst_nestedstruct2interface.cpp
#)
#
#target_link_libraries(test_testbed2_impl_nestedstruct2interface PRIVATE Qt5::Test testbed2::testbed2_impl)
#target_compile_definitions(test_testbed2_impl_nestedstruct2interface PRIVATE TESTBED2_IMPL_LIBRARY)
#add_test(test_testbed2_impl_nestedstruct2interface test_testbed2_impl_nestedstruct2interface)
#

## test for NestedStruct3Interface
#add_executable(test_testbed2_impl_nestedstruct3interface
#    tst_nestedstruct3interface.cpp
#)
#
#target_link_libraries(test_testbed2_impl_nestedstruct3interface PRIVATE Qt5::Test testbed2::testbed2_impl)
#target_compile_definitions(test_testbed2_impl_nestedstruct3interface PRIVATE TESTBED2_IMPL_LIBRARY)
#add_test(test_testbed2_impl_nestedstruct3interface test_testbed2_impl_nestedstruct3interface)
#
