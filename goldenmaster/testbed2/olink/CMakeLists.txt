project(testbed2_olink)

set (TESTBED2_OLINK_SOURCES
    olinkfactory.cpp
    olinkmanyparaminterface.cpp
    olinkmanyparaminterfaceadapter.cpp
    olinknestedstruct1interface.cpp
    olinknestedstruct1interfaceadapter.cpp
    olinknestedstruct2interface.cpp
    olinknestedstruct2interfaceadapter.cpp
    olinknestedstruct3interface.cpp
    olinknestedstruct3interfaceadapter.cpp
)

add_library(testbed2_olink STATIC ${TESTBED2_OLINK_SOURCES})
target_include_directories(testbed2_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/testbed2>
)

target_link_libraries(testbed2_olink PUBLIC testbed2::testbed2_api olink_qt qtpromise)
