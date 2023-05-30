project(tb_simple_olink)

find_package(Qt5 REQUIRED COMPONENTS Core)

set (TB_SIMPLE_OLINK_SOURCES
    olinkfactory.cpp
    olinksimpleinterface.cpp
    olinksimpleinterfaceadapter.cpp
    olinksimplearrayinterface.cpp
    olinksimplearrayinterfaceadapter.cpp
)

add_library(tb_simple_olink STATIC ${TB_SIMPLE_OLINK_SOURCES})
target_include_directories(tb_simple_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_simple>
)

target_link_libraries(tb_simple_olink PUBLIC tb_simple::tb_simple_api olink_qt qtpromise)
