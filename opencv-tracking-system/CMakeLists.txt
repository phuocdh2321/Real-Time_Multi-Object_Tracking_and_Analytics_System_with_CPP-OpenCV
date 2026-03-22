cmake_minimum_required(VERSION 3.10)
project(OpenCVTrackingSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} include)

add_executable(main
    src/main.cpp
    src/VideoCapture.cpp
    src/FrameProcessor.cpp
    src/Detector.cpp
    src/Tracker.cpp
)

target_link_libraries(main ${OpenCV_LIBS})