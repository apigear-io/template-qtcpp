project(tb_same2_olink)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets)

set (TB_SAME2_OLINK_SOURCES
    olinkfactory.cpp
    olinksamestruct1interface.cpp
    olinksamestruct1interfaceadapter.cpp
    olinksamestruct2interface.cpp
    olinksamestruct2interfaceadapter.cpp
    olinksameenum1interface.cpp
    olinksameenum1interfaceadapter.cpp
    olinksameenum2interface.cpp
    olinksameenum2interfaceadapter.cpp
)

add_library(tb_same2_olink STATIC ${TB_SAME2_OLINK_SOURCES})
target_include_directories(tb_same2_olink
    PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include/tb_same2>
)

target_link_libraries(tb_same2_olink 
PRIVATE Qt5::Core Qt5::Qml Qt5::WebSockets tb_same2::tb_same2_api 
PUBLIC olink_qt qtpromise)
