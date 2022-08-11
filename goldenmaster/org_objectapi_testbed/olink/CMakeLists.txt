find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (ORG_OBJECTAPI_TESTBED_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinkinterface1.cpp
    olinkinterface1adapter.cpp
    olinkinterface2.cpp
    olinkinterface2adapter.cpp
)

# dynamic library
add_library(org_objectapi_testbed_olink STATIC ${ORG_OBJECTAPI_TESTBED_OLINK_SOURCES})
target_include_directories(org_objectapi_testbed_olink PRIVATE ../org_objectapi_testbed)
target_link_libraries(org_objectapi_testbed_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets org_objectapi_testbed_api INTERFACE olink_core PUBLIC qtpromise)
