cmake_minimum_required(VERSION 3.5)

project(VGraphIDE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt5 Widgets
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Manually include QTermWidget paths
include_directories(/usr/local/include/qtermwidget5)
link_directories(/usr/local/lib)

add_executable(vgraph_ide main.cpp)

target_link_libraries(vgraph_ide PRIVATE
    Qt5::Widgets
    qtermwidget5
)
