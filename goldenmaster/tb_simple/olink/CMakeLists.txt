project(tb_simple_olink)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (TB_SIMPLE_OLINK_SOURCES
    olinkfactory.cpp
    olinkvoidinterface.cpp
    olinkvoidinterfaceadapter.cpp
    olinksimpleinterface.cpp
    olinksimpleinterfaceadapter.cpp
    olinksimplearrayinterface.cpp
    olinksimplearrayinterfaceadapter.cpp
    olinknopropertiesinterface.cpp
    olinknopropertiesinterfaceadapter.cpp
    olinknooperationsinterface.cpp
    olinknooperationsinterfaceadapter.cpp
    olinknosignalsinterface.cpp
    olinknosignalsinterfaceadapter.cpp
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

add_subdirectory(tests)

target_link_libraries(tb_simple_olink PUBLIC tb_simple::tb_simple_api olink_qt Qt6::Concurrent)
