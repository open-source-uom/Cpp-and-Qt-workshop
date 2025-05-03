cmake_minimum_required(VERSION 3.18)
project(UniMacedonia CXX)

find_package(Qt5 REQUIRED Core Widgets Gui)

set(CMAKE_AUTOMOC ON)

add_executable(UniMacedonia main.cpp mainwindow.cpp)

target_link_libraries(
    UniMacedonia
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)
