project(counter_olink)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (COUNTER_OLINK_SOURCES
    olinkfactory.cpp
    olinkcounter.cpp
    olinkcounteradapter.cpp
)

add_library(counter_olink STATIC ${COUNTER_OLINK_SOURCES})
target_include_directories(counter_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/counter>
)

target_link_libraries(counter_olink PUBLIC counter::counter_api olink_qt Qt6::Concurrent)
