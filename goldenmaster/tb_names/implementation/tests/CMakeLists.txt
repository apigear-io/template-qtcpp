
cmake_minimum_required(VERSION 3.20)
project(tb_names_tests)

include(CTest)

if(BUILD_TESTING)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Test)
find_package(tb_names QUIET COMPONENTS tb_names_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_tb_names_nam_es test_nam_es.cpp)
target_link_libraries(test_tb_names_nam_es tb_names_impl Qt5::Test)
add_test(NAME test_tb_names_nam_es COMMAND $<TARGET_FILE:test_tb_names_nam_es>)
add_dependencies(check test_tb_names_nam_es)

endif() # BUILD_TESTING
