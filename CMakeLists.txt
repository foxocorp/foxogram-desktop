cmake_minimum_required(VERSION 3.14)
project(foxogram
        VERSION 1.0.0
        DESCRIPTION "Desktop client for foxogram"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOUIC_SEARCH_PATHS src/ui)
set(CMAKE_AUTOUIC ON)
find_package(OpenSSL COMPONENTS SSL Crypto REQUIRED)
set(LIBFOXOGRAM_INSTALL OFF)
set(IXWEBSOCKET_INSTALL OFF)

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

qt_standard_project_setup()
qt_add_executable(foxogram)

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
        include/IconButton.h
        include/DigitInput.h
        include/FoxogramLoginForm.h
        include/FoxogramSignupForm.h
        include/FoxogramMainWindow.h
        include/FoxogramModal.h
        include/FoxogramVerifyEmailModal.h
        src/IconButton.cpp
        src/DigitInput.cpp
        src/FoxogramLoginForm.cpp
        src/FoxogramSignupForm.cpp
        src/FoxogramMainWindow.cpp
        src/FoxogramModal.cpp
        src/FoxogramVerifyEmailModal.cpp
        src/main.cpp
        src/ui/FoxogramSignup.ui
        src/ui/FoxogramLogin.ui
        src/ui/FoxogramModal.ui

)
target_include_directories(foxogram
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

set_target_properties(foxogram PROPERTIES
        MACOSX_BUNDLE TRUE
)

include(CMakePackageConfigHelpers)

target_sources(foxogram PRIVATE ${sources})

qt_generate_deploy_app_script(
        TARGET foxogram
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)

set_target_properties(foxogram PROPERTIES
        SOVERSION ${PROJECT_VERSION})

install(TARGETS foxogram
        BUNDLE  DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(SCRIPT ${deploy_script})
if (WIN32)
    if(OPENSSL_VERSION VERSION_GREATER_EQUAL "3.0.0")
        set(openssldlls "${OPENSSL_INCLUDE_DIR}/../libssl-3-x64.dll;${OPENSSL_INCLUDE_DIR}/../libcrypto-3-x64.dll")
    else ()
        set(openssldlls "${OPENSSL_INCLUDE_DIR}/../libssl-1_1-x64.dll;${OPENSSL_INCLUDE_DIR}/../libcrypto-1_1-x64.dll")
    endif ()
    install(FILES ${openssldlls}
            DESTINATION ${CMAKE_INSTALL_BINDIR})
elseif (UNIX)
    install(FILES ${OPENSSL_LIBRARIES}
            DESTINATION ${CMAKE_INSTALL_BINDIR})
elseif (APPLE)
    install(CODE "execute_process(COMMAND cp \"${OPENSSL_SSL_LIBRARY}\" \"${CMAKE_INSTALL_PREFIX}/foxogram.app/Contents/Frameworks/libssl.3.dylib\")
execute_process(COMMAND cp \"${OPENSSL_CRYPTO_LIBRARY}\" \"${CMAKE_INSTALL_PREFIX}/foxogram.app/Contents/Frameworks/libcrypto.3.dylib\")")
endif()
set(CPACK_BUNDLE_STARTUP_COMMAND ${PROJECT_BINARY_DIR}/startup.sh)