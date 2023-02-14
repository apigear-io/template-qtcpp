
project(testbed1_tests)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_testbed1_structinterface test_structinterface.cpp)
add_executable(test_testbed1_structarrayinterface test_structarrayinterface.cpp)


find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_impl )
target_link_libraries(test_testbed1_structinterface  testbed1_api testbed1_impl Qt5::Core Qt5::Test)
target_link_libraries(test_testbed1_structarrayinterface  testbed1_api testbed1_impl Qt5::Core Qt5::Test)
