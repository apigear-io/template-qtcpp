cmake_minimum_required(VERSION 3.14)

option(BUILD_EXAMPLES "Build examples" FALSE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(objectlink-core-cpp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory (src)
add_subdirectory (tests)


if(BUILD_EXAMPLES)
    add_subdirectory (examples/app)
    add_subdirectory (examples/server)
endif()
