cmake_minimum_required(VERSION 3.14)

project(WeChat LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_compile_definitions(QT_DISABLE_DEPRECATED_BEFORE=0x060000)
add_compile_options("/utf-8")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

aux_source_directory(./ Src_Root)
aux_source_directory(./SMainWindow Src_SMainWindow)
aux_source_directory(./SContacts Src_SContacts)
aux_source_directory(./SCustomWidgets Src_SCustomWidgets)
aux_source_directory(./SUtil Src_SUtil)

add_executable(WeChat
  ${Src_Root}
  ${Src_SMainWindow}
  ${Src_SContacts}
  ${Src_SCustomWidgets}
  ${Src_SUtil}
 "assets.qrc"
 "SContacts/ContactsAssets.qrc")

target_link_libraries(WeChat Qt${QT_VERSION_MAJOR}::Widgets)
