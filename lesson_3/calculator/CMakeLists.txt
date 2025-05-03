cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(calculator LANGUAGES CXX VERSION 1.0)

# 98, 11, 14, 17, 20, 23
SET(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(src)

