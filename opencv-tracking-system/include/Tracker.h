#pragma once
#include <opencv2/opencv.hpp>
#include <map>

struct Track {
    int id;
    cv::Point centroid;
    int missedFrames;
};

class Tracker {
public:
    Tracker();

    void update(const std::vector<cv::Rect>& detections);
    const std::map<int, Track>& getTracks() const;

private:
    int nextID;
    std::map<int, Track> tracks;

    cv::Point getCentroid(const cv::Rect& r);
};