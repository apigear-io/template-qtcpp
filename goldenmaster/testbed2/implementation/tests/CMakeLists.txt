
cmake_minimum_required(VERSION 3.20)
project(testbed2_tests)

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
find_package(testbed2 QUIET COMPONENTS testbed2_impl)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
add_executable(test_testbed2_manyparaminterface test_manyparaminterface.cpp)
add_executable(test_testbed2_nestedstruct1interface test_nestedstruct1interface.cpp)
add_executable(test_testbed2_nestedstruct2interface test_nestedstruct2interface.cpp)
add_executable(test_testbed2_nestedstruct3interface test_nestedstruct3interface.cpp)
target_link_libraries(test_testbed2_manyparaminterface testbed2_impl Qt6::Test)
target_link_libraries(test_testbed2_nestedstruct1interface testbed2_impl Qt6::Test)
target_link_libraries(test_testbed2_nestedstruct2interface testbed2_impl Qt6::Test)
target_link_libraries(test_testbed2_nestedstruct3interface testbed2_impl Qt6::Test)
add_test(NAME test_testbed2_manyparaminterface COMMAND $<TARGET_FILE:test_testbed2_manyparaminterface>)
add_dependencies(check test_testbed2_manyparaminterface)
add_test(NAME test_testbed2_nestedstruct1interface COMMAND $<TARGET_FILE:test_testbed2_nestedstruct1interface>)
add_dependencies(check test_testbed2_nestedstruct1interface)
add_test(NAME test_testbed2_nestedstruct2interface COMMAND $<TARGET_FILE:test_testbed2_nestedstruct2interface>)
add_dependencies(check test_testbed2_nestedstruct2interface)
add_test(NAME test_testbed2_nestedstruct3interface COMMAND $<TARGET_FILE:test_testbed2_nestedstruct3interface>)
add_dependencies(check test_testbed2_nestedstruct3interface)

endif() # BUILD_TESTING
