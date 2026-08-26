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
            syscalls.mpp
            types.mpp
)
