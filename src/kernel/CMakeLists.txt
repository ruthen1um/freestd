target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            kernel.cppm
)

if(FREESTD_OS_LINUX)
    add_subdirectory(linux)
endif()
