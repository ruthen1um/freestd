project(
    hello_world
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS FALSE
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -ffreestanding
        -fno-stack-protector
)

target_link_options(${PROJECT_NAME}
    PRIVATE
        -nostdlib
        --entry _start
)

target_link_libraries(${PROJECT_NAME} freestd)

add_subdirectory(src)
