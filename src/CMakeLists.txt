target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            freestd.cppm
)

add_subdirectory(containers)
add_subdirectory(core)
add_subdirectory(kernel)
