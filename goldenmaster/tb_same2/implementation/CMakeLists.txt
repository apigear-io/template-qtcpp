cmake_minimum_required(VERSION 3.20)
project(tb_same2_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME2_IMPL_SOURCES
    factory.cpp
    samestruct1interface.cpp
    samestruct2interface.cpp
    sameenum1interface.cpp
    sameenum2interface.cpp
)

# dynamic library
add_library(tb_same2_impl SHARED ${TB_SAME2_IMPL_SOURCES})
add_library(tb_same2::tb_same2_impl ALIAS tb_same2_impl)

target_include_directories(tb_same2_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same2_impl PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_same2::tb_same2_api)
target_compile_definitions(tb_same2_impl PRIVATE TB_SAME2_IMPL_LIBRARY)

# add test targets

## test for SameStruct1Interface
#add_executable(test_tb_same2_impl_samestruct1interface
#    tst_samestruct1interface.cpp
#)
#
#target_link_libraries(test_tb_same2_impl_samestruct1interface PRIVATE Qt5::Test tb_same2::tb_same2_impl)
#target_compile_definitions(test_tb_same2_impl_samestruct1interface PRIVATE TB_SAME2_IMPL_LIBRARY)
#add_test(test_tb_same2_impl_samestruct1interface test_tb_same2_impl_samestruct1interface)
#

## test for SameStruct2Interface
#add_executable(test_tb_same2_impl_samestruct2interface
#    tst_samestruct2interface.cpp
#)
#
#target_link_libraries(test_tb_same2_impl_samestruct2interface PRIVATE Qt5::Test tb_same2::tb_same2_impl)
#target_compile_definitions(test_tb_same2_impl_samestruct2interface PRIVATE TB_SAME2_IMPL_LIBRARY)
#add_test(test_tb_same2_impl_samestruct2interface test_tb_same2_impl_samestruct2interface)
#

## test for SameEnum1Interface
#add_executable(test_tb_same2_impl_sameenum1interface
#    tst_sameenum1interface.cpp
#)
#
#target_link_libraries(test_tb_same2_impl_sameenum1interface PRIVATE Qt5::Test tb_same2::tb_same2_impl)
#target_compile_definitions(test_tb_same2_impl_sameenum1interface PRIVATE TB_SAME2_IMPL_LIBRARY)
#add_test(test_tb_same2_impl_sameenum1interface test_tb_same2_impl_sameenum1interface)
#

## test for SameEnum2Interface
#add_executable(test_tb_same2_impl_sameenum2interface
#    tst_sameenum2interface.cpp
#)
#
#target_link_libraries(test_tb_same2_impl_sameenum2interface PRIVATE Qt5::Test tb_same2::tb_same2_impl)
#target_compile_definitions(test_tb_same2_impl_sameenum2interface PRIVATE TB_SAME2_IMPL_LIBRARY)
#add_test(test_tb_same2_impl_sameenum2interface test_tb_same2_impl_sameenum2interface)
#
