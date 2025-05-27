cmake_minimum_required(VERSION 3.5)

project(VGraphIDE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar AUTOMOC, AUTOUIC, AUTORCC para Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Buscar Qt5 Widgets
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Buscar qtermwidget5 usando pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(QTERM REQUIRED qtermwidget5)

add_executable(vgraph_ide main.cpp)

target_include_directories(vgraph_ide PRIVATE ${QTERM_INCLUDE_DIRS})

target_link_libraries(vgraph_ide PRIVATE Qt5::Widgets ${QTERM_LIBRARIES})

# En caso de que quieras agregar más configuraciones, aquí va

