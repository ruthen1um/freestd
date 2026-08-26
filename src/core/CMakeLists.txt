target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            core.cppm
            concepts.cppm
            ref.cppm
            result.cppm
            traits.cppm
)

if(FREESTD_OS_LINUX)
    add_subdirectory(linux)
endif()
