cmake_minimum_required(VERSION 3.20)
project(apigear_mqtt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(FetchContent)

find_package(Qt6 REQUIRED COMPONENTS Core WebSockets Mqtt)
find_package(apigear QUIET COMPONENTS utilities_qt)

find_package(nlohmann_json QUIET)
if(NOT nlohmann_json_FOUND)
  # pull nlohmann json as dependency
  message(STATUS "nlohmann_json NOT FOUND, fetching the release package")
  include(FetchContent)
  set(JSON_Install ON)
  FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.7.3)
  FetchContent_MakeAvailable(json)
endif()

set (SOURCES
    mqttclient.cpp
    payloadconverter.cpp
    mqttservice.cpp
)

add_library(apigear_mqtt SHARED ${SOURCES}
)
add_library(apigear::apigear_mqtt ALIAS apigear_mqtt)

target_include_directories(apigear_mqtt
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../..>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(apigear_mqtt PUBLIC apigear::utilities_qt Qt6::Core Qt6::WebSockets Qt6::Mqtt nlohmann_json::nlohmann_json)
target_compile_definitions(apigear_mqtt PRIVATE APIGEAR_MQTT_QT)

# install binary files
install(TARGETS apigear_mqtt
        EXPORT  apigear_mqttTargets
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib           COMPONENT Development)
# install includes
install(FILES ${INCLUDES}
        DESTINATION include/apigear/mqtt)

export(EXPORT apigear_mqttTargets
  NAMESPACE apigear::
)
