
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(CodeVis LANGUAGES CXX VERSION 0.1)

find_package(UniMacedonia REQUIRED)

add_executable(hello_world_with_lib main.cpp)
target_link_libraries(hello_world_with_lib UniMacedonia::hello_lib)