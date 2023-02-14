
project(tb_same1_tests)
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
add_executable(test_tb_same1_samestruct1interface test_samestruct1interface.cpp)
add_executable(test_tb_same1_samestruct2interface test_samestruct2interface.cpp)
add_executable(test_tb_same1_sameenum1interface test_sameenum1interface.cpp)
add_executable(test_tb_same1_sameenum2interface test_sameenum2interface.cpp)


find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_impl )
target_link_libraries(test_tb_same1_samestruct1interface  tb_same1_api tb_same1_impl Qt5::Core Qt5::Test)
target_link_libraries(test_tb_same1_samestruct2interface  tb_same1_api tb_same1_impl Qt5::Core Qt5::Test)
target_link_libraries(test_tb_same1_sameenum1interface  tb_same1_api tb_same1_impl Qt5::Core Qt5::Test)
target_link_libraries(test_tb_same1_sameenum2interface  tb_same1_api tb_same1_impl Qt5::Core Qt5::Test)
