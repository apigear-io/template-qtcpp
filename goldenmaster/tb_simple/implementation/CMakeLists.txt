cmake_minimum_required(VERSION 3.20)
project(tb_simple_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_IMPL_SOURCES
    factory.cpp
    simpleinterface.cpp
    simplearrayinterface.cpp
)

# dynamic library
add_library(tb_simple_impl SHARED ${TB_SIMPLE_IMPL_SOURCES})
add_library(tb_simple::tb_simple_impl ALIAS tb_simple_impl)

target_include_directories(tb_simple_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_simple_impl PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_simple::tb_simple_api)
target_compile_definitions(tb_simple_impl PRIVATE TB_SIMPLE_IMPL_LIBRARY)

# add test targets

## test for SimpleInterface
#add_executable(test_tb_simple_impl_simpleinterface
#    tst_simpleinterface.cpp
#)
#
#target_link_libraries(test_tb_simple_impl_simpleinterface PRIVATE Qt5::Test tb_simple::tb_simple_impl)
#target_compile_definitions(test_tb_simple_impl_simpleinterface PRIVATE TB_SIMPLE_IMPL_LIBRARY)
#add_test(test_tb_simple_impl_simpleinterface test_tb_simple_impl_simpleinterface)
#

## test for SimpleArrayInterface
#add_executable(test_tb_simple_impl_simplearrayinterface
#    tst_simplearrayinterface.cpp
#)
#
#target_link_libraries(test_tb_simple_impl_simplearrayinterface PRIVATE Qt5::Test tb_simple::tb_simple_impl)
#target_compile_definitions(test_tb_simple_impl_simplearrayinterface PRIVATE TB_SIMPLE_IMPL_LIBRARY)
#add_test(test_tb_simple_impl_simplearrayinterface test_tb_simple_impl_simplearrayinterface)
#
