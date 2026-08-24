target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            collections.cppm
            array.cppm
)

install(DIRECTORY .
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/freestd/collections
    FILES_MATCHING PATTERN "*.cppm"
)
