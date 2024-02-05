project(tb_names_olink)

find_package(Qt5 REQUIRED COMPONENTS Core)

set (TB_NAMES_OLINK_SOURCES
    olinkfactory.cpp
    olinknam_es.cpp
    olinknam_esadapter.cpp
)

add_library(tb_names_olink STATIC ${TB_NAMES_OLINK_SOURCES})
target_include_directories(tb_names_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_names>
)

target_link_libraries(tb_names_olink PUBLIC tb_names::tb_names_api olink_qt qtpromise)
