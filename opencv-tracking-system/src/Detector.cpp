#include "Detector.h"

Detector::Detector() {
    bgSub = cv::createBackgroundSubtractorMOG2();
}

std::vector<cv::Rect> Detector::detect(const cv::Mat& frame) {
    cv::Mat fgMask;
    bgSub->apply(frame, fgMask);

    cv::threshold(fgMask, fgMask, 200, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(fgMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<cv::Rect> boxes;
    for (auto& c : contours) {
        if (cv::contourArea(c) > 500) {
            boxes.push_back(cv::boundingRect(c));
        }
    }

    return boxes;
}