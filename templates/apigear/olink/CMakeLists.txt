cmake_minimum_required(VERSION 3.20)
project(olink_qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)

find_package(Qt5 REQUIRED COMPONENTS Core WebSockets)

find_package(apigear QUIET COMPONENTS olink_core)
if(NOT olink_core_FOUND)
  # disable olink core tests
  set(BUILD_TESTING OFF)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.2.6
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()

set (SOURCES
    olinkhost.cpp
    olinkclient.cpp
    olinkremote.cpp
)

FILE(GLOB_RECURSE INCLUDES *.h)

add_library(olink_qt SHARED ${SOURCES})
add_library(apigear::olink_qt ALIAS olink_qt)

target_include_directories(olink_qt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(olink_qt PUBLIC apigear::utilities_qt olink_core Qt5::Core Qt5::WebSockets)
target_compile_definitions(olink_qt PRIVATE OLINK_QT)

# install binary files
install(TARGETS olink_qt
        EXPORT  olink_qtTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib           COMPONENT Development)
# install includes
install(FILES ${INCLUDES}
        DESTINATION include/apigear/olink)

export(EXPORT olink_qtTargets
  NAMESPACE apigear::
)
