find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_LIB_SOURCES
    factory.cpp
    structinterface.cpp
    qmlstructinterface.cpp
    structarrayinterface.cpp
    qmlstructarrayinterface.cpp
)

# dynamic library
add_library(testbed1_lib SHARED ${TESTBED1_LIB_SOURCES})
add_library(testbed1::testbed1_lib ALIAS testbed1_lib)

target_include_directories(testbed1_lib
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(testbed1_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1::testbed1_api)
target_compile_definitions(testbed1_lib PRIVATE TESTBED1_LIB_LIBRARY)

# add test targets

## test for StructInterface
#add_executable(test_testbed1_lib_structinterface
#    tst_structinterface.cpp
#)
#
#target_link_libraries(test_testbed1_lib_structinterface PRIVATE Qt5::Test testbed1::testbed1_lib)
#target_compile_definitions(test_testbed1_lib_structinterface PRIVATE TESTBED1_LIB_LIBRARY)
#add_test(test_testbed1_lib_structinterface test_testbed1_lib_structinterface)
#

## test for StructArrayInterface
#add_executable(test_testbed1_lib_structarrayinterface
#    tst_structarrayinterface.cpp
#)
#
#target_link_libraries(test_testbed1_lib_structarrayinterface PRIVATE Qt5::Test testbed1::testbed1_lib)
#target_compile_definitions(test_testbed1_lib_structarrayinterface PRIVATE TESTBED1_LIB_LIBRARY)
#add_test(test_testbed1_lib_structarrayinterface test_testbed1_lib_structarrayinterface)
#
