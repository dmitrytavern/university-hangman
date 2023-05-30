cmake_minimum_required(VERSION 3.5)
project(Hangman VERSION 0.1 LANGUAGES CXX)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build/)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src/app)
add_subdirectory(src/widgets/homewidget)
add_subdirectory(src/widgets/aboutwidget)
add_subdirectory(src/widgets/gamewidget)
add_subdirectory(src/widgets/gamestartwidget)
add_subdirectory(src/widgets/gameoverwidget)
add_subdirectory(src/components/style)
