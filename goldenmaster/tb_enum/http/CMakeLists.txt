find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_ENUM_HTTP_SOURCES
    httpfactory.cpp
    httpenuminterface.cpp
)

# dynamic library

add_library(tb_enum_http STATIC ${TB_ENUM_HTTP_SOURCES})
target_include_directories(tb_enum_http PRIVATE ../tb_enum)
target_link_libraries(tb_enum_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network tb_enum_api)
