#pragma once
#include "VideoCapture.h"
#include "Detector.h"
#include "Tracker.h"

class FrameProcessor {
public:
    void run(VideoCaptureModule* cap);

private:
    Detector detector;
    Tracker tracker;
};