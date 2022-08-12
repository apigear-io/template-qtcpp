find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (TESTBED1_OLINK_SOURCES
    ../../shared/olinkclient.cpp
    olinkfactory.cpp
    olinkstructinterface.cpp
    olinkstructinterfaceadapter.cpp
    olinkstructarrayinterface.cpp
    olinkstructarrayinterfaceadapter.cpp
)

# dynamic library
add_library(testbed1_olink STATIC ${TESTBED1_OLINK_SOURCES})
target_include_directories(testbed1_olink PRIVATE ../testbed1)
target_link_libraries(testbed1_olink PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets testbed1_api INTERFACE olink_core PUBLIC qtpromise)
