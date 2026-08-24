target_sources(${PROJECT_NAME}
    PRIVATE
        syscalls.cpp
        syscalls.s
)

target_sources(${PROJECT_NAME}
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src
        FILES
            syscalls.cppm
            types.cppm
)

install(DIRECTORY .
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/freestd/kernel/linux/x86_64
    FILES_MATCHING PATTERN "*.cppm"
)
