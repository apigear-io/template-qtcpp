project(testbed1_olink)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TESTBED1_OLINK_SOURCES
    olinkfactory.cpp
    olinkstructinterface.cpp
    olinkstructinterfaceadapter.cpp
    olinkstructarrayinterface.cpp
    olinkstructarrayinterfaceadapter.cpp
)

add_library(testbed1_olink STATIC ${TESTBED1_OLINK_SOURCES})
target_include_directories(testbed1_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/testbed1>
)

target_link_libraries(testbed1_olink PUBLIC testbed1::testbed1_api olink_qt Qt6::Concurrent qtpromise)
