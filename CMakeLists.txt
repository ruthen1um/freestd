cmake_minimum_required(VERSION 4.2)

project(
    freestd
    LANGUAGES CXX ASM
    VERSION 0.1.0
)

option(
    FREESTD_BUILD_EXAMPLES
    "Build example programs"
    FALSE
)

add_library(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS FALSE
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<COMPILE_LANGUAGE:CXX>:
            -ffreestanding
        >
)

target_link_options(${PROJECT_NAME}
    PRIVATE
        -nostdlib
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(FREESTD_OS_LINUX TRUE)
endif()

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    set(FREESTD_ARCH_X86_64 TRUE)
endif()

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

add_subdirectory(src)

if(FREESTD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
