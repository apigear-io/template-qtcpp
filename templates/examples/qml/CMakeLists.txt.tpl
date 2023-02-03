project(QmlExamlple)
cmake_minimum_required(VERSION 3.1)

# append local binary directory for conan packages to be found
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    main.cpp
    main.qml
    resources.qrc
)
add_executable(QmlExamlple
    ${SOURCES}
)

find_package(Qt5 REQUIRED COMPONENTS Core Qml Network WebSockets Gui Quick QuickControls2 QuickWidgets)
find_package(apigear QUIET COMPONENTS olink_qt)

find_package(apigear QUIET COMPONENTS olink_core)
if(NOT olink_core_FOUND)
  # pull objectlink-core-cpp as dependency
  message(STATUS "objectlink-core-cpp NOT FOUND, fetching the git repository")
  FetchContent_Declare(olink_core
      GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp.git
      GIT_TAG v0.2.2
      GIT_SHALLOW TRUE
      EXCLUDE_FROM_ALL FALSE
  )
  FetchContent_MakeAvailable(olink_core)
endif()

{{ range .System.Modules }}
{{- $module_id := snake .Name }}
find_package({{$module_id}} QUIET COMPONENTS {{$module_id}}_api {{$module_id}}_lib {{$module_id}}_olink plugin_{{$module_id}})
{{- end }}
target_link_libraries(QmlExamlple
{{- range .System.Modules }}
{{- $module_id := snake .Name }}
    {{$module_id}}_api
    {{$module_id}}_lib
    {{$module_id}}_olink
    plugin_{{$module_id}}
{{- end }}
Qt5::Core Qt5::Qml Qt5::WebSockets Qt5::Gui Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
olink_qt
olink_core
)


install(TARGETS QmlExamlple
        RUNTIME DESTINATION bin COMPONENT Runtime)
