
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick WebSockets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick WebSockets REQUIRED)

set(OLINK_EXAMPLE_SERVER_SOURCE
        main.cpp
        calcsource.cpp
        ../qtolink/olinkhost.cpp
        ../qtolink/olinkremote.cpp
)

set(OLINK_EXAMPLE_SERVER_HEADERS
        main.cpp
        calcsource.h
        ../qtolink/olinkhost.h
        ../qtolink/olinkremote.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(olink_example_server
        ${OLINK_EXAMPLE_SERVER_SOURCE} ${OLINK_EXAMPLE_SERVER_HEADERS}
    )
else()
    if(ANDROID)
        add_library(olink_example_server SHARED
            ${OLINK_EXAMPLE_SERVER_SOURCE}
        )
    else()
        add_executable(olink_example_server
          ${OLINK_EXAMPLE_SERVER_SOURCE} ${OLINK_EXAMPLE_SERVER_HEADERS}
        )
    endif()
endif()

target_compile_definitions(olink_example_server
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(olink_example_server
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::WebSockets)


target_link_libraries(olink_example_server PRIVATE nlohmann_json::nlohmann_json olink_core)
