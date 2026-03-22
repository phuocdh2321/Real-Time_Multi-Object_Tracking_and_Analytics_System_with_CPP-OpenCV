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

5. Build & Run

- mkdir build
- cd build
- cmake ..
- make
- ./main

## Input

The system captures video input from a webcam.

- **Source**
  - Default camera device (e.g., webcam)
  - Configured via camera index (e.g., `0`)

- **Frame Data**
  - Continuous video frames captured using OpenCV `VideoCapture`

- **Resolution & FPS**
  - Depends on camera hardware and driver
  - Typically 20–30 FPS

- **Platform**
  - Linux / Windows with OpenCV installed

## Output

The system produces real-time visual output through an OpenCV display window.

### 1. Object Detection

- Moving objects are detected using background subtraction (MOG2)
- Each object is represented by a bounding region (internally)

### 2. Object Tracking

- Each detected object is assigned a unique ID
- Objects are tracked across frames using centroid-based tracking

### 3. Visualization

- Display window shows:
  - Object centroids (green circles)
  - Object IDs (text labels near centroids)

### 4. Real-Time Processing

- Continuous frame processing loop
- Near real-time performance depending on hardware

### 5. System Behavior

- Objects are removed if not detected for a number of frames
- Tracking is based on distance between object centroids
