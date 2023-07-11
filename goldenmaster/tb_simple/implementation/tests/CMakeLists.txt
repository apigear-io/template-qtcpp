
cmake_minimum_required(VERSION 3.20)
project(tb_simple_tests)

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
find_package(tb_simple QUIET COMPONENTS tb_simple_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_tb_simple_simpleinterface test_simpleinterface.cpp)
add_executable(test_tb_simple_simplearrayinterface test_simplearrayinterface.cpp)
target_link_libraries(test_tb_simple_simpleinterface tb_simple_impl Qt6::Test)
target_link_libraries(test_tb_simple_simplearrayinterface tb_simple_impl Qt6::Test)
add_test(NAME test_tb_simple_simpleinterface COMMAND $<TARGET_FILE:test_tb_simple_simpleinterface>)
add_dependencies(check test_tb_simple_simpleinterface)
add_test(NAME test_tb_simple_simplearrayinterface COMMAND $<TARGET_FILE:test_tb_simple_simplearrayinterface>)
add_dependencies(check test_tb_simple_simplearrayinterface)

endif() # BUILD_TESTING
