cmake_minimum_required(VERSION 3.20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(performace_tests LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(JSON_BuildTests OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_BuildTests OFF)


include(FetchContent)

FetchContent_Declare(qtpromise
  GIT_REPOSITORY https://github.com/simonbrunel/qtpromise.git
  GIT_TAG v0.6.0
  GIT_SHALLOW true
)

# CMake v3.14+
FetchContent_MakeAvailable(qtpromise)


add_subdirectory(testApi)
include_directories(testApi/thirdparty)



find_package(api COMPONENTS  api_impl api_olink)
#find_package(apigear COMPONENTS olink_qt )

add_executable(single_server_for_tests "tests_single_object/server_for_tests.cpp")
add_executable(test_single_client_set_int_property "tests_single_object/test_client_set_int_property.cpp" )
add_executable(test_single_client_set_string_property "tests_single_object/test_client_set_string_property.cpp" )
add_executable(test_clients_set_int "tests_many_objects/test_client_set_int.cpp" )
add_executable(test_clients_set_float "tests_many_objects/test_client_set_float.cpp" )
add_executable(test_clients_set_string "tests_many_objects/test_client_set_string.cpp" )
add_executable(servers_for_tests "tests_many_objects/server_for_tests.cpp" "tests_many_objects/prepare_test_services.cpp" )


target_link_libraries(single_server_for_tests  api::api_olink api::api_impl)
target_link_libraries(test_single_client_set_int_property api::api_olink)
target_link_libraries(test_single_client_set_string_property api::api_olink)
target_link_libraries(test_clients_set_int api::api_olink)
target_link_libraries(test_clients_set_float api::api_olink)
target_link_libraries(test_clients_set_string api::api_olink)
target_link_libraries(servers_for_tests api::api_olink  api::api_impl)

