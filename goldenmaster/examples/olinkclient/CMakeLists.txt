project(OLinkClient)
cmake_minimum_required(VERSION 3.20)

find_package(Qt6 REQUIRED COMPONENTS Gui)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
)
add_executable(OLinkClient
    ${SOURCES}
)


find_package(testbed2 QUIET COMPONENTS testbed2_api testbed2_impl testbed2_olink testbed2_monitor)
find_package(tb_enum QUIET COMPONENTS tb_enum_api tb_enum_impl tb_enum_olink tb_enum_monitor)
find_package(tb_same1 QUIET COMPONENTS tb_same1_api tb_same1_impl tb_same1_olink tb_same1_monitor)
find_package(tb_same2 QUIET COMPONENTS tb_same2_api tb_same2_impl tb_same2_olink tb_same2_monitor)
find_package(tb_simple QUIET COMPONENTS tb_simple_api tb_simple_impl tb_simple_olink tb_simple_monitor)
find_package(testbed1 QUIET COMPONENTS testbed1_api testbed1_impl testbed1_olink testbed1_monitor)
find_package(tb_names QUIET COMPONENTS tb_names_api tb_names_impl tb_names_olink tb_names_monitor)
find_package(custom_types QUIET COMPONENTS custom_types_api custom_types_impl custom_types_olink custom_types_monitor)
find_package(extern_types QUIET COMPONENTS extern_types_api extern_types_impl extern_types_olink extern_types_monitor)
find_package(counter QUIET COMPONENTS counter_api counter_impl counter_olink counter_monitor)
target_link_libraries(OLinkClient PUBLIC
    testbed2_api
    testbed2_impl
    testbed2_olink
    testbed2_monitor
    tb_enum_api
    tb_enum_impl
    tb_enum_olink
    tb_enum_monitor
    tb_same1_api
    tb_same1_impl
    tb_same1_olink
    tb_same1_monitor
    tb_same2_api
    tb_same2_impl
    tb_same2_olink
    tb_same2_monitor
    tb_simple_api
    tb_simple_impl
    tb_simple_olink
    tb_simple_monitor
    testbed1_api
    testbed1_impl
    testbed1_olink
    testbed1_monitor
    tb_names_api
    tb_names_impl
    tb_names_olink
    tb_names_monitor
    custom_types_api
    custom_types_impl
    custom_types_olink
    custom_types_monitor
    extern_types_api
    extern_types_impl
    extern_types_olink
    extern_types_monitor
    counter_api
    counter_impl
    counter_olink
    counter_monitor
Qt6::Gui
)
install(TARGETS OLinkClient
        RUNTIME DESTINATION bin COMPONENT Runtime)
