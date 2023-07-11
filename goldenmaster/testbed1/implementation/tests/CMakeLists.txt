
cmake_minimum_required(VERSION 3.20)
project(testbed1_tests)

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
find_package(testbed1 QUIET COMPONENTS testbed1_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_testbed1_structinterface test_structinterface.cpp)
add_executable(test_testbed1_structarrayinterface test_structarrayinterface.cpp)
target_link_libraries(test_testbed1_structinterface testbed1_impl Qt6::Test)
target_link_libraries(test_testbed1_structarrayinterface testbed1_impl Qt6::Test)
add_test(NAME test_testbed1_structinterface COMMAND $<TARGET_FILE:test_testbed1_structinterface>)
add_dependencies(check test_testbed1_structinterface)
add_test(NAME test_testbed1_structarrayinterface COMMAND $<TARGET_FILE:test_testbed1_structarrayinterface>)
add_dependencies(check test_testbed1_structarrayinterface)

endif() # BUILD_TESTING
