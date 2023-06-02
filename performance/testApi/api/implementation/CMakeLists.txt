cmake_minimum_required(VERSION 3.20)
project(api_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_PATH ${LIBRARY_PATH}/)

set (API_IMPL_SOURCES
    factory.cpp
    testapi0.cpp
    testapi1.cpp
    testapi2.cpp
    testapi3.cpp
    testapi4.cpp
    testapi5.cpp
    testapi6.cpp
    testapi7.cpp
    testapi8.cpp
    testapi9.cpp
    testapi10.cpp
    testapi11.cpp
    testapi12.cpp
    testapi13.cpp
    testapi14.cpp
    testapi15.cpp
    testapi16.cpp
    testapi17.cpp
    testapi18.cpp
    testapi19.cpp
    testapi20.cpp
    testapi21.cpp
    testapi22.cpp
    testapi23.cpp
    testapi24.cpp
    testapi25.cpp
    testapi26.cpp
    testapi27.cpp
    testapi28.cpp
    testapi29.cpp
    testapi30.cpp
    testapi31.cpp
    testapi32.cpp
    testapi33.cpp
    testapi34.cpp
    testapi35.cpp
    testapi36.cpp
    testapi37.cpp
    testapi38.cpp
    testapi39.cpp
    testapi40.cpp
    testapi41.cpp
    testapi42.cpp
    testapi43.cpp
    testapi44.cpp
    testapi45.cpp
    testapi46.cpp
    testapi47.cpp
    testapi48.cpp
    testapi49.cpp
    testapi50.cpp
    testapi51.cpp
    testapi52.cpp
    testapi53.cpp
    testapi54.cpp
    testapi55.cpp
    testapi56.cpp
    testapi57.cpp
    testapi58.cpp
    testapi59.cpp
    testapi60.cpp
    testapi61.cpp
    testapi62.cpp
    testapi63.cpp
    testapi64.cpp
    testapi65.cpp
    testapi66.cpp
    testapi67.cpp
    testapi68.cpp
    testapi69.cpp
    testapi70.cpp
    testapi71.cpp
    testapi72.cpp
    testapi73.cpp
    testapi74.cpp
    testapi75.cpp
    testapi76.cpp
    testapi77.cpp
    testapi78.cpp
    testapi79.cpp
    testapi80.cpp
    testapi81.cpp
    testapi82.cpp
    testapi83.cpp
    testapi84.cpp
    testapi85.cpp
    testapi86.cpp
    testapi87.cpp
    testapi88.cpp
    testapi89.cpp
    testapi90.cpp
    testapi91.cpp
    testapi92.cpp
    testapi93.cpp
    testapi94.cpp
    testapi95.cpp
    testapi96.cpp
    testapi97.cpp
    testapi98.cpp
    testapi99.cpp
)

# dynamic library
add_library(api_impl SHARED ${API_IMPL_SOURCES})
add_library(api::api_impl ALIAS api_impl)

target_include_directories(api_impl
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(api_impl PUBLIC api::api_api)
target_compile_definitions(api_impl PRIVATE API_IMPL_LIBRARY)

add_subdirectory(tests)
