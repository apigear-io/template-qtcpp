
cmake_minimum_required(VERSION 3.20)
project(counter_tests)

include(CTest)

if(BUILD_TESTING)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test)
find_package(counter QUIET COMPONENTS counter_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_counter_counter test_counter.cpp)
target_link_libraries(test_counter_counter counter_impl Qt6::Test)
add_test(NAME test_counter_counter COMMAND $<TARGET_FILE:test_counter_counter>)
add_dependencies(check test_counter_counter)

endif() # BUILD_TESTING
