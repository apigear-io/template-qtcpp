cmake_minimum_required(VERSION 3.20)
project(monitor_qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)

find_package(Qt5 REQUIRED COMPONENTS Core WebSockets)


set (SOURCES
    agentclient.cpp
)

FILE(GLOB_RECURSE INCLUDES *.h)

add_library(monitor_qt SHARED ${SOURCES})
add_library(apigear::monitor_qt ALIAS monitor_qt)


target_include_directories(monitor_qt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(monitor_qt PUBLIC apigear::utilities_qt Qt5::Core Qt5::WebSockets)
target_compile_definitions(monitor_qt PRIVATE COMPILING_MONITOR_QT)

# install binary files
install(TARGETS monitor_qt
        EXPORT  monitor_qtTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib           COMPONENT Development)
# install includes
install(FILES ${INCLUDES}
        DESTINATION include/apigear/monitor)

export(EXPORT monitor_qtTargets
  NAMESPACE apigear::
)

