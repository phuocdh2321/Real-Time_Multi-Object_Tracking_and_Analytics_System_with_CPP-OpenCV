#pragma once
#include <opencv2/opencv.hpp>
#include <mutex>

class VideoCaptureModule {
public:
    VideoCaptureModule(int camIndex);

    void run();
    bool getFrame(cv::Mat& outFrame);

private:
    cv::VideoCapture cap;
    cv::Mat frame;
    std::mutex mtx;
};