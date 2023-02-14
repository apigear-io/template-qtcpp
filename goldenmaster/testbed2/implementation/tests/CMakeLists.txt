
project(testbed2_tests)
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
add_executable(test_testbed2_manyparaminterface test_manyparaminterface.cpp)
add_executable(test_testbed2_nestedstruct1interface test_nestedstruct1interface.cpp)
add_executable(test_testbed2_nestedstruct2interface test_nestedstruct2interface.cpp)
add_executable(test_testbed2_nestedstruct3interface test_nestedstruct3interface.cpp)


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_impl )
target_link_libraries(test_testbed2_manyparaminterface  testbed2_api testbed2_impl Qt5::Core Qt5::Test)
target_link_libraries(test_testbed2_nestedstruct1interface  testbed2_api testbed2_impl Qt5::Core Qt5::Test)
target_link_libraries(test_testbed2_nestedstruct2interface  testbed2_api testbed2_impl Qt5::Core Qt5::Test)
target_link_libraries(test_testbed2_nestedstruct3interface  testbed2_api testbed2_impl Qt5::Core Qt5::Test)
