cmake_minimum_required(VERSION 3.28)
project(threads C)

set(CMAKE_C_STANDARD 11)

add_executable(threads main.c
        "${CMAKE_CURRENT_SOURCE_DIR}/files/file_management.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/files/file_management.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/threads/threads.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/threads/threads.c"
)
