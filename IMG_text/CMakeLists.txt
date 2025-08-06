cmake_minimum_required(VERSION 3.16)
project(MyQtApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC OFF) 
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Qml
    Quick
    Gui
)

add_executable(app
    main.cpp
    Backend.h
    Backend.cpp
)

target_link_libraries(app PRIVATE
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick
    Qt6::Gui
)
