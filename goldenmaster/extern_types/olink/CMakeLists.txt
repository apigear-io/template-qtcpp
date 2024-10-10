project(extern_types_olink)

find_package(Qt6 REQUIRED COMPONENTS Concurrent)

set (EXTERN_TYPES_OLINK_SOURCES
    olinkfactory.cpp
)

add_library(extern_types_olink STATIC ${EXTERN_TYPES_OLINK_SOURCES})
target_include_directories(extern_types_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/extern_types>
)

add_subdirectory(tests)

target_link_libraries(extern_types_olink PUBLIC extern_types::extern_types_api olink_qt Qt6::Concurrent)
