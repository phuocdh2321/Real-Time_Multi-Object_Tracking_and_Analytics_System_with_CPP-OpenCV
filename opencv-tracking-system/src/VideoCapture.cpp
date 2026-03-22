#include "VideoCapture.h"

VideoCaptureModule::VideoCaptureModule(int camIndex) {
    cap.open(camIndex);
}

void VideoCaptureModule::run() {
    while (true) {
        cv::Mat temp;
        cap >> temp;
        if (temp.empty()) continue;

        std::lock_guard<std::mutex> lock(mtx);
        frame = temp.clone();
    }
}

bool VideoCaptureModule::getFrame(cv::Mat& outFrame) {
    std::lock_guard<std::mutex> lock(mtx);
    if (frame.empty()) return false;
    outFrame = frame.clone();
    return true;
}