cmake_minimum_required(VERSION 3.16)

project(AltromonLauncher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES AltromonLauncher_ru_RU.ts)

set(PROJECT_SOURCES
        main.cpp



        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AltromonLauncher
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        resources.qrc

        icon.rc
        basewindow.h basewindow.cpp basewindow.ui
        authwindow.h authwindow.cpp authwindow.ui
        mainwindow.h mainwindow.cpp mainwindow.ui
        headerpanel.h headerpanel.cpp headerpanel.ui
        windowframe.h windowframe.cpp





    )


    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(AltromonLauncher SHARED
            ${PROJECT_SOURCES}
        )

    else()
        add_executable(AltromonLauncher
            ${PROJECT_SOURCES}
            icon.rc
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(AltromonLauncher PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AltromonLauncher)
endif()
set_target_properties(AltromonLauncher PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AltromonLauncher
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AltromonLauncher)
endif()
