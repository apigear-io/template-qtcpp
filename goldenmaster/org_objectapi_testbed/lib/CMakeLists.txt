find_package(Qt5 REQUIRED COMPONENTS Core Qml WebSockets)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (ORG_OBJECTAPI_TESTBED_LIB_SOURCES
    factory.cpp
    interface1.cpp
    qmlinterface1.cpp
    interface2.cpp
    qmlinterface2.cpp
)

# dynamic library
add_library(org_objectapi_testbed_lib STATIC ${ORG_OBJECTAPI_TESTBED_LIB_SOURCES})
target_link_libraries(org_objectapi_testbed_lib PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets org_objectapi_testbed_api)
target_compile_definitions(org_objectapi_testbed_lib PRIVATE ORG_OBJECTAPI_TESTBED_LIB_LIBRARY)

# add test targets

# test for Interface1
add_executable(test_org_objectapi_testbed_lib_interface1
    tst_interface1.cpp
)

target_link_libraries(test_org_objectapi_testbed_lib_interface1 PRIVATE Qt5::Test org_objectapi_testbed_lib)
target_compile_definitions(test_org_objectapi_testbed_lib_interface1 PRIVATE ORG_OBJECTAPI_TESTBED_LIB_LIBRARY)
add_test(test_org_objectapi_testbed_lib_interface1 test_org_objectapi_testbed_lib_interface1)

# test for Interface2
add_executable(test_org_objectapi_testbed_lib_interface2
    tst_interface2.cpp
)

target_link_libraries(test_org_objectapi_testbed_lib_interface2 PRIVATE Qt5::Test org_objectapi_testbed_lib)
target_compile_definitions(test_org_objectapi_testbed_lib_interface2 PRIVATE ORG_OBJECTAPI_TESTBED_LIB_LIBRARY)
add_test(test_org_objectapi_testbed_lib_interface2 test_org_objectapi_testbed_lib_interface2)
