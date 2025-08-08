cmake_minimum_required(VERSION 3.16)
project(file_opener LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

add_executable(file_opener
    main.cpp
    folderopener.cpp
)

target_link_libraries(file_opener
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
)

configure_file(main.qml ${CMAKE_CURRENT_BINARY_DIR}/main.qml COPYONLY)
