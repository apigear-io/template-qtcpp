find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (ORG_OBJECTAPI_TESTBED_HTTP_SOURCES
    httpfactory.cpp
    httpinterface1.cpp
    httpinterface2.cpp
)

# dynamic library

add_library(org_objectapi_testbed_http STATIC ${ORG_OBJECTAPI_TESTBED_HTTP_SOURCES})
target_include_directories(org_objectapi_testbed_http PRIVATE ../org_objectapi_testbed)
target_link_libraries(org_objectapi_testbed_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network org_objectapi_testbed_api)
