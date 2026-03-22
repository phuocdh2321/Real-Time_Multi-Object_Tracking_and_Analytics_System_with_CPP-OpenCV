#include "VideoCapture.h"
#include "FrameProcessor.h"
#include <thread>

int main() {
    VideoCaptureModule cap(0);
    FrameProcessor processor;

    std::thread t1(&VideoCaptureModule::run, &cap);
    std::thread t2(&FrameProcessor::run, &processor, &cap);

    t1.join();
    t2.join();

    return 0;
}