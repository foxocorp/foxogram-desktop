cmake_minimum_required(VERSION 3.14)
project(foxogram
        VERSION 1.0.0
        DESCRIPTION "Desktop client for foxogram"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

qt_standard_project_setup()
qt_add_executable(foxogram)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include(FetchContent)
FetchContent_Declare(libfoxogram GIT_REPOSITORY https://github.com/Foxocorp/foxogram-lib
        GIT_TAG main
)
FetchContent_MakeAvailable(libfoxogram)
target_link_libraries(foxogram PUBLIC libfoxogram
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

set(sources
        src/FoxogramLoginForm.h
        src/FoxogramSignupForm.h
        src/FoxogramLoginForm.cpp
        src/FoxogramSignupForm.cpp
        src/main.cpp
        src/FoxogramSignup.ui
        src/FoxogramLogin.ui

)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

set_target_properties(foxogram PROPERTIES
        MACOSX_BUNDLE TRUE
)

include(CMakePackageConfigHelpers)

target_sources(foxogram PRIVATE ${sources})
set_target_properties(foxogram PROPERTIES
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION})

install(TARGETS foxogram
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
qt_generate_deploy_app_script(
        TARGET foxogram
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})