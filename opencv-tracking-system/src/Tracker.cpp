#include "Tracker.h"
#include <cmath>

Tracker::Tracker() : nextID(0) {}

cv::Point Tracker::getCentroid(const cv::Rect& r) {
    return cv::Point(r.x + r.width / 2, r.y + r.height / 2);
}

void Tracker::update(const std::vector<cv::Rect>& detections) {
    std::map<int, bool> updated;

    for (auto& [id, track] : tracks) {
        updated[id] = false;
    }

    for (const auto& det : detections) {
        cv::Point c = getCentroid(det);

        int bestID = -1;
        double minDist = 1e9;

        for (auto& [id, track] : tracks) {
            double dist = cv::norm(track.centroid - c);
            if (dist < minDist && dist < 50) {
                minDist = dist;
                bestID = id;
            }
        }

        if (bestID != -1) {
            tracks[bestID].centroid = c;
            tracks[bestID].missedFrames = 0;
            updated[bestID] = true;
        } else {
            Track t;
            t.id = nextID++;
            t.centroid = c;
            t.missedFrames = 0;
            tracks[t.id] = t;
            updated[t.id] = true;
        }
    }

    for (auto it = tracks.begin(); it != tracks.end();) {
        if (!updated[it->first]) {
            it->second.missedFrames++;
            if (it->second.missedFrames > 10) {
                it = tracks.erase(it);
                continue;
            }
        }
        ++it;
    }
}

const std::map<int, Track>& Tracker::getTracks() const {
    return tracks;
}