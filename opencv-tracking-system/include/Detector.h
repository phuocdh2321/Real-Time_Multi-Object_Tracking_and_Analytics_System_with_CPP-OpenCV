#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class Detector {
public:
    Detector();
    std::vector<cv::Rect> detect(const cv::Mat& frame);

private:
    cv::Ptr<cv::BackgroundSubtractor> bgSub;
};