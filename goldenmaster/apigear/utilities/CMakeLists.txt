cmake_minimum_required(VERSION 3.20)
project(utilities_qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core)

set (SOURCES
    logger.cpp
)
add_library(utilities_qt SHARED ${SOURCES})
add_library(apigear::utilities_qt ALIAS utilities_qt)
target_include_directories(utilities_qt
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(utilities_qt PUBLIC Qt5::Core)

# install binary files
install(TARGETS utilities_qt
        EXPORT  utilities_qtTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib           COMPONENT Development)
# install includes
install(FILES ${INCLUDES}
        DESTINATION include/apigear/utilities)

export(EXPORT utilities_qtTargets
  NAMESPACE apigear::
)

if(BUILD_TESTING)
add_subdirectory (tests)
endif() # BUILD_TESTING
