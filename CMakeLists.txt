cmake_minimum_required(VERSION 4.0)
project(tls C)

set(CMAKE_C_STANDARD 11)

add_executable(tls
        http.c)
