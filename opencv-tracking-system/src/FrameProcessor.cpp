#include "FrameProcessor.h"
#include <opencv2/opencv.hpp>

void FrameProcessor::run(VideoCaptureModule* cap) {
    cv::Mat frame;

    while (true) {
        if (!cap->getFrame(frame)) continue;

        auto detections = detector.detect(frame);
        tracker.update(detections);

        for (const auto& [id, track] : tracker.getTracks()) {
            cv::circle(frame, track.centroid, 5, {0,255,0}, -1);
            cv::putText(frame, std::to_string(id),
                        track.centroid,
                        cv::FONT_HERSHEY_SIMPLEX,
                        0.5, {0,255,0}, 2);
        }

        cv::imshow("Tracking", frame);
        if (cv::waitKey(1) == 27) break;
    }
}