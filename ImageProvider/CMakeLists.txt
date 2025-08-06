cmake_minimum_required(VERSION 3.16)
project(QMLImageWithCPP)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

add_executable(app
    main.cpp
    ImageProvider.cpp
    ImageProvider.h
)

target_link_libraries(app
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)
