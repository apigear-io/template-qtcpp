project(MqttClient)
cmake_minimum_required(VERSION 3.20)

find_package(Qt6 REQUIRED COMPONENTS Gui)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(MqttClient
    ${SOURCES}
)


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_impl testbed2_mqtt testbed2_monitor)
find_package(tb_enum QUIET COMPONENTS tb_enum_api tb_enum_impl tb_enum_mqtt tb_enum_monitor)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_impl tb_same1_mqtt tb_same1_monitor)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api tb_same2_impl tb_same2_mqtt tb_same2_monitor)
find_package(tb_simple QUIET COMPONENTS tb_simple_api tb_simple_impl tb_simple_mqtt tb_simple_monitor)
find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_impl testbed1_mqtt testbed1_monitor)
target_link_libraries(MqttClient PUBLIC
    testbed2_api
    testbed2_impl
    testbed2_mqtt
    testbed2_monitor
    tb_enum_api
    tb_enum_impl
    tb_enum_mqtt
    tb_enum_monitor
    tb_same1_api
    tb_same1_impl
    tb_same1_mqtt
    tb_same1_monitor
    tb_same2_api
    tb_same2_impl
    tb_same2_mqtt
    tb_same2_monitor
    tb_simple_api
    tb_simple_impl
    tb_simple_mqtt
    tb_simple_monitor
    testbed1_api
    testbed1_impl
    testbed1_mqtt
    testbed1_monitor
Qt6::Gui
)
install(TARGETS MqttClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
