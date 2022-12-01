find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_LIB_SOURCES
    factory.cpp
    enuminterface.cpp
    qmlenuminterface.cpp
)

# dynamic library
add_library(tb_enum_lib SHARED ${TB_ENUM_LIB_SOURCES})
add_library(tb_enum::tb_enum_lib ALIAS tb_enum_lib)

target_include_directories(tb_enum_lib
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_enum_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_enum::tb_enum_api)
target_compile_definitions(tb_enum_lib PRIVATE TB_ENUM_LIB_LIBRARY)

# add test targets

## test for EnumInterface
#add_executable(test_tb_enum_lib_enuminterface
#    tst_enuminterface.cpp
#)
#
#target_link_libraries(test_tb_enum_lib_enuminterface PRIVATE Qt5::Test tb_enum::tb_enum_lib)
#target_compile_definitions(test_tb_enum_lib_enuminterface PRIVATE TB_ENUM_LIB_LIBRARY)
#add_test(test_tb_enum_lib_enuminterface test_tb_enum_lib_enuminterface)
#
