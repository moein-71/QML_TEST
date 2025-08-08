cmake_minimum_required(VERSION 3.16)
project(VideoRecorder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml)
find_package(OpenCV REQUIRED)

qt_add_executable(VideoRecorderApp
    main.cpp
    CameraRecorder.cpp
    CameraRecorder.h
    Camerahandler.cpp
    Camerahandler.h
    ImageProvider.cpp
    ImageProvider.h
    qml.qrc
)

target_link_libraries(VideoRecorderApp
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Qml
    ${OpenCV_LIBS}
)