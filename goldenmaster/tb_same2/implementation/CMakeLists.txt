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

add_subdirectory(tests)
