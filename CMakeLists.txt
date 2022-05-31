cmake_minimum_required(VERSION 3.21)
project(c_workspace C)

set(CMAKE_C_STANDARD 11)

add_executable(c_workspace
        ipc/exo1.c
        ipc/exo2.c
        ipc/exo3.c
        ipc/exo4.c)
