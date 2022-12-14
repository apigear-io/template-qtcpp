find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_LIB_SOURCES
    factory.cpp
    simpleinterface.cpp
    qmlsimpleinterface.cpp
    simplearrayinterface.cpp
    qmlsimplearrayinterface.cpp
)

# dynamic library
add_library(tb_simple_lib SHARED ${TB_SIMPLE_LIB_SOURCES})
add_library(tb_simple::tb_simple_lib ALIAS tb_simple_lib)

target_include_directories(tb_simple_lib
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(tb_simple_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_simple::tb_simple_api)
target_compile_definitions(tb_simple_lib PRIVATE TB_SIMPLE_LIB_LIBRARY)

# add test targets

## test for SimpleInterface
#add_executable(test_tb_simple_lib_simpleinterface
#    tst_simpleinterface.cpp
#)
#
#target_link_libraries(test_tb_simple_lib_simpleinterface PRIVATE Qt5::Test tb_simple::tb_simple_lib)
#target_compile_definitions(test_tb_simple_lib_simpleinterface PRIVATE TB_SIMPLE_LIB_LIBRARY)
#add_test(test_tb_simple_lib_simpleinterface test_tb_simple_lib_simpleinterface)
#

## test for SimpleArrayInterface
#add_executable(test_tb_simple_lib_simplearrayinterface
#    tst_simplearrayinterface.cpp
#)
#
#target_link_libraries(test_tb_simple_lib_simplearrayinterface PRIVATE Qt5::Test tb_simple::tb_simple_lib)
#target_compile_definitions(test_tb_simple_lib_simplearrayinterface PRIVATE TB_SIMPLE_LIB_LIBRARY)
#add_test(test_tb_simple_lib_simplearrayinterface test_tb_simple_lib_simplearrayinterface)
#
