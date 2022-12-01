find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME1_LIB_SOURCES
    factory.cpp
    samestruct1interface.cpp
    qmlsamestruct1interface.cpp
    samestruct2interface.cpp
    qmlsamestruct2interface.cpp
    sameenum1interface.cpp
    qmlsameenum1interface.cpp
    sameenum2interface.cpp
    qmlsameenum2interface.cpp
)

# dynamic library
add_library(tb_same1_lib SHARED ${TB_SAME1_LIB_SOURCES})
add_library(tb_same1::tb_same1_lib ALIAS tb_same1_lib)

target_include_directories(tb_same1_lib
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_same1_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_same1::tb_same1_api)
target_compile_definitions(tb_same1_lib PRIVATE TB_SAME1_LIB_LIBRARY)

# add test targets

## test for SameStruct1Interface
#add_executable(test_tb_same1_lib_samestruct1interface
#    tst_samestruct1interface.cpp
#)
#
#target_link_libraries(test_tb_same1_lib_samestruct1interface PRIVATE Qt5::Test tb_same1::tb_same1_lib)
#target_compile_definitions(test_tb_same1_lib_samestruct1interface PRIVATE TB_SAME1_LIB_LIBRARY)
#add_test(test_tb_same1_lib_samestruct1interface test_tb_same1_lib_samestruct1interface)
#

## test for SameStruct2Interface
#add_executable(test_tb_same1_lib_samestruct2interface
#    tst_samestruct2interface.cpp
#)
#
#target_link_libraries(test_tb_same1_lib_samestruct2interface PRIVATE Qt5::Test tb_same1::tb_same1_lib)
#target_compile_definitions(test_tb_same1_lib_samestruct2interface PRIVATE TB_SAME1_LIB_LIBRARY)
#add_test(test_tb_same1_lib_samestruct2interface test_tb_same1_lib_samestruct2interface)
#

## test for SameEnum1Interface
#add_executable(test_tb_same1_lib_sameenum1interface
#    tst_sameenum1interface.cpp
#)
#
#target_link_libraries(test_tb_same1_lib_sameenum1interface PRIVATE Qt5::Test tb_same1::tb_same1_lib)
#target_compile_definitions(test_tb_same1_lib_sameenum1interface PRIVATE TB_SAME1_LIB_LIBRARY)
#add_test(test_tb_same1_lib_sameenum1interface test_tb_same1_lib_sameenum1interface)
#

## test for SameEnum2Interface
#add_executable(test_tb_same1_lib_sameenum2interface
#    tst_sameenum2interface.cpp
#)
#
#target_link_libraries(test_tb_same1_lib_sameenum2interface PRIVATE Qt5::Test tb_same1::tb_same1_lib)
#target_compile_definitions(test_tb_same1_lib_sameenum2interface PRIVATE TB_SAME1_LIB_LIBRARY)
#add_test(test_tb_same1_lib_sameenum2interface test_tb_same1_lib_sameenum2interface)
#
