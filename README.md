# Real-Time Multi-Object Tracking & Analytics System (C++ / OpenCV)
Developed a real-time multi-object detection and tracking system using C++ and OpenCV, capable of processing live video streams with high FPS.

Implemented image processing pipelines including preprocessing, object detection, feature extraction, and tracking, with performance optimization for real-time execution.

Designed modular and scalable architecture with multithreading to separate frame capture, processing, and visualization.

Optimized memory usage and processing latency, achieving stable real-time performance.

1. Demo GIF/video
- demo.mp4

2. Architecture diagram
- Camera → Preprocessing → Detection → Tracking → Analytics → Display

4. Performance
- FPS: 25–30
- Resolution: 720p

4. Features
- Multi-object tracking
- Real-time processing
- Line crossing detection

5. Struct project

opencv-tracking-system/

│

├── src/

│   ├── main.cpp

│   ├── VideoCapture.cpp

│   ├── FrameProcessor.cpp

│   ├── Detector.cpp

│   ├── Tracker.cpp

│   ├── Analytics.cpp

│

├── include/

│   ├── Detector.h

│   ├── Tracker.h

│

├── CMakeLists.txt

├── README.md

├── demo.mp4

6. Build & Run

- mkdir build
- cd build
- cmake ..
- make
- ./main
