
project(tb_simple_tests)
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
add_executable(test_tb_simple_simpleinterface test_simpleinterface.cpp)
add_executable(test_tb_simple_simplearrayinterface test_simplearrayinterface.cpp)


find_package(tb_simple QUIET COMPONENTS tb_simple_impl )
target_link_libraries(test_tb_simple_simpleinterface tb_simple_impl Qt5::Test)
target_link_libraries(test_tb_simple_simplearrayinterface tb_simple_impl Qt5::Test)
