find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SIMPLE_HTTP_SOURCES
    httpfactory.cpp
    httpsimpleinterface.cpp
    httpsimplearrayinterface.cpp
)

# dynamic library

add_library(tb_simple_http STATIC ${TB_SIMPLE_HTTP_SOURCES})
target_include_directories(tb_simple_http PRIVATE ../tb_simple)
target_link_libraries(tb_simple_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network tb_simple_api)
