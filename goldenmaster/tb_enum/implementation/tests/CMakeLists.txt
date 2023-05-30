
cmake_minimum_required(VERSION 3.20)
project(tb_enum_tests)

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
find_package(tb_enum QUIET COMPONENTS tb_enum_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_tb_enum_enuminterface test_enuminterface.cpp)
target_link_libraries(test_tb_enum_enuminterface tb_enum_impl Qt5::Test)
add_test(NAME test_tb_enum_enuminterface COMMAND $<TARGET_FILE:test_tb_enum_enuminterface>)
add_dependencies(check test_tb_enum_enuminterface)

endif() # BUILD_TESTING
