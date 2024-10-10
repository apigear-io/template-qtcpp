project(custom_types_olink)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (CUSTOM_TYPES_OLINK_SOURCES
    olinkfactory.cpp
)

add_library(custom_types_olink STATIC ${CUSTOM_TYPES_OLINK_SOURCES})
target_include_directories(custom_types_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/custom_types>
)

add_subdirectory(tests)

target_link_libraries(custom_types_olink PUBLIC custom_types::custom_types_api olink_qt Qt6::Concurrent)
