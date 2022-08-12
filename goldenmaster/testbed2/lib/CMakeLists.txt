find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED2_LIB_SOURCES
    factory.cpp
    manyparaminterface.cpp
    qmlmanyparaminterface.cpp
    nestedstruct1interface.cpp
    qmlnestedstruct1interface.cpp
    nestedstruct2interface.cpp
    qmlnestedstruct2interface.cpp
    nestedstruct3interface.cpp
    qmlnestedstruct3interface.cpp
)

# dynamic library
add_library(testbed2_lib STATIC ${TESTBED2_LIB_SOURCES})
target_link_libraries(testbed2_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed2_api)
target_compile_definitions(testbed2_lib PRIVATE TESTBED2_LIB_LIBRARY)

# add test targets

# test for ManyParamInterface
add_executable(test_testbed2_lib_manyparaminterface
    tst_manyparaminterface.cpp
)

target_link_libraries(test_testbed2_lib_manyparaminterface PRIVATE Qt5::Test testbed2_lib)
target_compile_definitions(test_testbed2_lib_manyparaminterface PRIVATE TESTBED2_LIB_LIBRARY)
add_test(test_testbed2_lib_manyparaminterface test_testbed2_lib_manyparaminterface)

# test for NestedStruct1Interface
add_executable(test_testbed2_lib_nestedstruct1interface
    tst_nestedstruct1interface.cpp
)

target_link_libraries(test_testbed2_lib_nestedstruct1interface PRIVATE Qt5::Test testbed2_lib)
target_compile_definitions(test_testbed2_lib_nestedstruct1interface PRIVATE TESTBED2_LIB_LIBRARY)
add_test(test_testbed2_lib_nestedstruct1interface test_testbed2_lib_nestedstruct1interface)

# test for NestedStruct2Interface
add_executable(test_testbed2_lib_nestedstruct2interface
    tst_nestedstruct2interface.cpp
)

target_link_libraries(test_testbed2_lib_nestedstruct2interface PRIVATE Qt5::Test testbed2_lib)
target_compile_definitions(test_testbed2_lib_nestedstruct2interface PRIVATE TESTBED2_LIB_LIBRARY)
add_test(test_testbed2_lib_nestedstruct2interface test_testbed2_lib_nestedstruct2interface)

# test for NestedStruct3Interface
add_executable(test_testbed2_lib_nestedstruct3interface
    tst_nestedstruct3interface.cpp
)

target_link_libraries(test_testbed2_lib_nestedstruct3interface PRIVATE Qt5::Test testbed2_lib)
target_compile_definitions(test_testbed2_lib_nestedstruct3interface PRIVATE TESTBED2_LIB_LIBRARY)
add_test(test_testbed2_lib_nestedstruct3interface test_testbed2_lib_nestedstruct3interface)
