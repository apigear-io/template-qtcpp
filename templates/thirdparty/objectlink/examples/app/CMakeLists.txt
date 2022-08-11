
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick WebSockets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick WebSockets REQUIRED)

set(APP_SOURCES
        main.cpp
        ../qtolink/olinkclient.cpp
        calcsink.cpp
        qml.qrc
)


set(APP_HEADERS
        ../qtolink/olinkclient.h
        calcsink.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(olink_example_app
        ${APP_SOURCES} ${APP_HEADERS}
    )
else()
    if(ANDROID)
        add_library(olink_example_app SHARED
            ${APP_SOURCES} ${APP_HEADERS}
        )
    else()
        add_executable(olink_example_app
          ${APP_SOURCES} ${APP_HEADERS}
        )
    endif()
endif()

target_compile_definitions(olink_example_app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(olink_example_app
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::WebSockets)


target_link_libraries(olink_example_app PRIVATE olink_core)
