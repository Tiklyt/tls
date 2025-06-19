cmake_minimum_required(VERSION 3.19)
project(tls C)

set(CMAKE_C_STANDARD 17)

add_executable(tls
        http.c)
