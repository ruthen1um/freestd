target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            types.cppm
)

install(DIRECTORY .
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/freestd/core/linux/x86_64
    FILES_MATCHING PATTERN "*.cppm"
)
