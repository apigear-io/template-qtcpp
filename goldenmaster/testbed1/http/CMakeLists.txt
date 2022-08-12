find_package(Qt5 REQUIRED COMPONENTS Core Qml Network)
set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (TESTBED1_HTTP_SOURCES
    httpfactory.cpp
    httpstructinterface.cpp
    httpstructarrayinterface.cpp
)

# dynamic library

add_library(testbed1_http STATIC ${TESTBED1_HTTP_SOURCES})
target_include_directories(testbed1_http PRIVATE ../testbed1)
target_link_libraries(testbed1_http PRIVATE Qt5::Core Qt5::Qml Qt5::Network testbed1_api)
