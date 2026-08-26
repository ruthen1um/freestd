target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            linux.cppm
)

if(FREESTD_ARCH_X86_64)
    add_subdirectory(x86_64)
endif()
