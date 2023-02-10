cmake_minimum_required(VERSION 3.14)

project(WeChat LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets  )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_compile_definitions(QT_DISABLE_DEPRECATED_BEFORE=0x060000)
add_compile_options("/utf-8")

aux_source_directory(./ Src_Root)
aux_source_directory(./SMainWindow Src_SMainWindow)

add_executable(WeChat
  ${Src_Root}
  ${Src_SMainWindow}
 "assets.qrc")

target_link_libraries(WeChat Qt${QT_VERSION_MAJOR}::Widgets )
