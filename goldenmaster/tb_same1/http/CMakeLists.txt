find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TB_SAME1_HTTP_SOURCES
    httpfactory.cpp
    httpsamestruct1interface.cpp
    httpsamestruct2interface.cpp
    httpsameenum1interface.cpp
    httpsameenum2interface.cpp
)

# dynamic library

add_library(tb_same1_http STATIC ${TB_SAME1_HTTP_SOURCES})
target_include_directories(tb_same1_http PRIVATE ../tb_same1)
target_link_libraries(tb_same1_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network tb_same1_api)
